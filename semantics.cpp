#include "semantics.hpp"
//#include "SymbolTable.hpp"
#include "check.hpp"
#include <assert.h>
#include <stack>
namespace semantics
{
	int iscall;//为1时处于调用阶段，constantid不入栈
	int depth;			  // 记录语义层次，只有为0时才做语义动作
	int type_declaration; // 若该值为1，则表示当前处于type字段的record中，此时进入var_declaration不进行语义动作
	int var_record;		  // 若该值为1，说明当前正在var字段的record中，此时进入var_declaration会将数据保存到栈顶符号(必是一个record型变量)的数据域中
	// int var_para;//若该值为1，说明当前节点的父节点是
	SymbolTable stack_st;						// 开始语义分析之前，创建栈式符号表
	std::unique_ptr<llvm::LLVMContext> context; // llvm需要用的context智能指针
	std::unique_ptr<llvm::Module> mod;			// 同上
	std::unique_ptr<llvm::IRBuilder<>> builder;
	vector<string> exp_type;
	vector<string> exp_value;
	vector<string> exp_id;
	// vector<llvm::Value *> llvm_value;
	vector<int> index;	   //存放数组下标
	int is_assign;		   //为1时表示数组或记录在赋值号左侧，为2时表示在赋值号右侧
	int cur_range;		   //当前数组的维度
	vector<int> arr_index; //保存数组的下标
	int arr_or_rec;		   // 0表示都不是，1表示是数组，2表示记录
	string id;			   //当数组和记录在右侧时，保存他们的名字
	string record_id;	   //记录内元素的名字
	int id_varparts_num;   //记录当前是否是数组访问的最后一维
	vector<string> r_type;
	bool pass; //为1时是引用传参

	// struct record_elements r_ele;

}
void semanticsListener::enterProgram(PascalSParser::ProgramContext *ctx)
{
	// 初始化命名空间的相关数据
	semantics::depth = 0;
	semantics::iscall=0;
	semantics::type_declaration = 0;
	semantics::var_record = 0;
	semantics::is_assign = 0;
	semantics::index.push_back(0);
	semantics::cur_range = 0;
	semantics::pass = false;
	semantics::id_varparts_num = 0;
	// 初始化llvm以及设置目标机器
	llvm::InitializeNativeTarget();
	llvm::InitializeAllTargetInfos();
	llvm::InitializeAllTargets();
	llvm::InitializeAllTargetMCs();
	llvm::InitializeAllAsmParsers();
	llvm::InitializeAllAsmPrinters();
	// 初始化context以及module
	semantics::context = std::make_unique<llvm::LLVMContext>();
	semantics::mod = std::make_unique<llvm::Module>("main", *semantics::context);
	// 获取目标三元组并设置
	auto targetTriple = llvm::sys::getDefaultTargetTriple();
	semantics::mod->setTargetTriple(targetTriple);
	// 获取目标机数据类型并设置
	std::string targetError;
	auto target = llvm::TargetRegistry::lookupTarget(targetTriple, targetError);
	auto cpu = "generic";
	auto features = "";
	llvm::TargetOptions options;
	auto relocationModel = llvm::Reloc::Model::PIC_;
	auto theTargetMachine = target->createTargetMachine(targetTriple, cpu, features, options, relocationModel);
	semantics::mod->setDataLayout(theTargetMachine->createDataLayout());
}

void semanticsListener::enterProgram_head(PascalSParser::Program_headContext *ctx)
{
	// 进入主程序，为主程序创建符号
	std::string id = ctx->ID()->getText();
	table symbol(id, "main"); // 主程序类型用main标识

	// llvm创建主程序以及builder
	symbol.functiontype = llvm::FunctionType::get(llvm::Type::getInt32Ty(*semantics::context), false);
	symbol.function = llvm::Function::Create(symbol.functiontype, llvm::GlobalValue::ExternalLinkage, id, semantics::mod.get());
	symbol.block = llvm::BasicBlock::Create(*semantics::context, "", symbol.function);
	semantics::builder = std::make_unique<llvm::IRBuilder<>>(symbol.block);

	// 主程序入栈
	semantics::stack_st.insert_table(symbol);
}

void semanticsListener::enterSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext *ctx)
{
	// 若声明的深度不为0，则直接跳过语义动作
	if (semantics::depth != 0)
		return;

	// 常量声明
	std::string const_id = ctx->ID()->getText();
	// cout<<"here is: "<<const_id<<endl;
	std::string const_value = ctx->const_variable()->getText();
	std::string type = type_of(const_value);
	if ("integer" == type)
	{
		// 常量类型为整形
		table symbol(const_id, "integer", const_value);
		symbol.is_const = true;
		symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
		// 获取值
		auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(const_value.c_str()));
		// 将值存入该常量的分配空间中
		semantics::builder->CreateStore(value, symbol.all);
		// 符号入栈
		semantics::stack_st.insert_table(symbol);
	}
	else if ("real" == type)
	{
		// 常量类型为浮点
		table symbol(const_id, "real", const_value);
		symbol.is_const = true;
		symbol.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
		// 获取浮点值
		auto value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), atof(const_value.c_str()));

		semantics::builder->CreateStore(value, symbol.all);
		semantics::stack_st.insert_table(symbol);
	}
	else if ("char" == type)
	{
		// 常量类型为字符
		table symbol(const_id, "char", const_value);
		symbol.is_const = true;
		symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
		auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), const_value[1]);

		semantics::builder->CreateStore(value, symbol.all);
		semantics::stack_st.insert_table(symbol);
	}
	else if ("id" == type)
	{
		// 当类型为id时，实际上需要将符号表中的指定符号中的属性复制一份过来
		auto target_symbol = semantics::stack_st.locate_table(const_value);
		if ("err" == target_symbol.type)
		{
			// 返回的符号类型是err时表示没有找到该符号
			std::cout << "Line " << ctx->getStart()->getLine() << ": Undeclared symbol" << std::endl;
			return;
		}
		else
		{
			// 常量如果赋值为标识符，那么该标识符不能是函数、过程、type或结构体这种没有value属性的
			if (target_symbol.is_func or target_symbol.is_proc or target_symbol.is_type or target_symbol.is_record)
			{
				std::cout << "Line " << ctx->getStart()->getLine() << ": Illegal expression" << std::endl;
				return;
			}

			table symbol(const_id, target_symbol.type, target_symbol.value);
			symbol.is_const = true;
			if ("integer" == target_symbol.type)
			{
				symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				llvm::ConstantInt *value;
				if ('-' == const_value[0])
					value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), -atoi(target_symbol.value.c_str()));
				else
					value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(target_symbol.value.c_str()));
				semantics::builder->CreateStore(value, symbol.all);
				semantics::stack_st.insert_table(symbol);
			}
			else if ("real" == target_symbol.type)
			{
				symbol.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
				llvm::Constant *value;
				if ('-' == const_value[0])
					value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), -atof(target_symbol.value.c_str()));
				else
					value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), atof(target_symbol.value.c_str()));
				semantics::builder->CreateStore(value, symbol.all);
				semantics::stack_st.insert_table(symbol);
			}
			else if ("char" == target_symbol.type)
			{
				symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				if ('-' == const_value[0])
				{
					std::cout << "Line " << ctx->getStart()->getLine() << ": Illegal expression" << std::endl;
					return;
				}
				auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), target_symbol.value[1]);
				semantics::builder->CreateStore(value, symbol.all);
				semantics::stack_st.insert_table(symbol);
			}
		}
	}
}

void semanticsListener::enterSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext *ctx)
{
	if (semantics::depth != 0)
		return;

	semantics::type_declaration = 1;
	// type 字段声明的标识符不需要实际空间，故不用调用llvm api
	std::string type_id = ctx->ID()->getText();
	std::string type_value = ctx->type()->getText();

	// 对于记录型和数组型，保存其等效的类型为value，之后在var部分若遇到该符号表示的类型，则用value替换
	if (0 == type_value.find("record"))
	{
		// 当前type为记录型
		table symbol(type_id, "record", type_value);
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
	else if (0 == type_value.find("array"))
	{
		// 当前type为数组型
		table symbol(type_id, "array", type_value);
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
	else
	{
		// 当前type为基础类型
		table symbol(type_id, type_value, type_value);
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
}

void semanticsListener::exitSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext *ctx)
{
	semantics::type_declaration = 0;
}

void semanticsListener::enterSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext *ctx)
{
	if (semantics::depth != 0 or semantics::type_declaration == 1)
		return;

	std::string id_list = ctx->identifier_list()->getText(); // 改变量是以逗号为分割的若干标识符
	std::string var_type = ctx->type()->getText();

	int split_pos;
	std::string id;

	// 如果var_record开关是打开的，表示当前处于var字段的record中的变量声明
	if (1 == semantics::var_record)
	{
		do
		{
			split_pos = id_list.find(',');
			id = id_list.substr(0, split_pos);		// 提取出每个单独的id
			id.erase(0, id.find_first_not_of(" ")); // 去除前空格
			id.erase(id.find_last_not_of(" ") + 1); // 去除后空格

			table symbol = semantics::stack_st.get_top_table();
			assert(true == symbol.is_record); // 从栈顶取出来的符号必然是一个record型变量

			struct record_elements element;
			if ("integer" == var_type)
			{
				element.type = "integer";
				element.value = "0";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if ("real" == var_type)
			{
				element.type = "real";
				element.value = "0.0";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
				auto value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), 0.0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if ("char" == var_type)
			{
				element.type = "char";
				element.value = "\0";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), 0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if ("boolean" == var_type)
			{
				element.type = "boolean";
				element.value = "false";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if (0 == var_type.find("array"))
			{
				// 这里的处理与后面对array符号的处理是基本一致的，但是类型不同，且不会入栈
				element.is_array = true;
				std::string array_type = ctx->type()->type()->getText();
				std::string array_range = ctx->type()->periods()->getText();
				element.type = array_type;
				// 接下来需要处理数组的维度，每一维度用逗号区分
				std::string period;					// period 表示每一维度的范围
				std::string range_begin, range_end; // 表示每一维的起止符号
				int range_split;
				do
				{
					range_split = array_range.find(',');
					period = array_range.substr(0, range_split);
					range_begin = period.substr(0, period.find(".."));
					range_end = period.substr(period.find("..") + 2);
					// 去除begin和end前后的空白字符
					range_begin.erase(0, range_begin.find_first_not_of(" "));
					range_end.erase(0, range_end.find_first_not_of(" "));
					range_begin.erase(range_begin.find_last_not_of(" ") + 1);
					range_end.erase(range_end.find_last_not_of(" ") + 1);

					if ("integer" == type_of(range_begin) and "integer" == type_of(range_end))
					{
						// 范围必须是整数型，且 end 大于 begin
						int begin = atoi(range_begin.c_str());
						int end = atoi(range_end.c_str());
						if (begin <= end)
						{
							element.range_type.push_back("integer");
							element.range.push_back(std::pair<int, int>(begin, end - begin + 1));
						}
						else
						{
							std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
						}
					}
					else if ("char" == type_of(range_begin) and "char" == type_of(range_end))
					{
						// 范围由单字符组成
						if (range_end[1] >= range_begin[1])
						{
							element.range_type.push_back("char");
							element.range.push_back(std::pair<int, int>(range_begin[1], range_end[1] - range_begin[1] + 1));
						}
						else
						{
							std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
						}
					}
					else
					{
						// 除了单字符和整数表示，其余的场景是无效的字符范围
						std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
					}

					array_range = array_range.substr(range_split + 1);
				} while (std::string::npos != range_split);
				// 处理完每一维度的之后，要为数组分配总空间
				int range = 1;
				for (auto iter = element.range.begin(); iter != element.range.end(); iter++)
				{
					range *= iter->second;
				}
				// int range = (element.range.end() - 1)->second;
				if ("integer" == array_type)
				{
					element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
				}
				else if ("char" == array_type)
				{
					element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt8Ty(*semantics::context), range), nullptr));
				}
				else if ("real" == array_type)
				{
					element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getFloatTy(*semantics::context), range), nullptr));
				}
				else if ("boolean" == array_type)
				{
					element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
				}
				else
				{
					// 目前该项目仅支持基础基础类型的数组
					std::cout << "Line " << ctx->getStart()->getLine() << ": Unsupported array type" << std::endl;
				}
			}
			symbol.push_record_elements(id, element);

			id_list = id_list.substr(split_pos + 1); // 将处理后的id剔除出去
		} while (std::string::npos != split_pos);

		return; //结束后直接返回，后续动作是针对普通的变量声明的
	}

	do
	{
		split_pos = id_list.find(',');
		id = id_list.substr(0, split_pos); // 提取出每个单独的id

		id.erase(0, id.find_first_not_of(" ")); // 去除前空格
		id.erase(id.find_last_not_of(" ") + 1); // 去除后空格

		// 对每个id，都要建立相应的符号并入栈
		if ("integer" == var_type)
		{
			table symbol(id, "integer", "0");
			// 分配空间后将默认初始化的值放入空间当中
			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
			auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
			semantics::builder->CreateStore(value, symbol.all);
			// 符号入栈
			semantics::stack_st.insert_table(symbol);
		}
		else if ("real" == var_type)
		{
			table symbol(id, "real", "0");

			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
			auto value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), 0.0);

			semantics::builder->CreateStore(value, symbol.all);
			semantics::stack_st.insert_table(symbol);
		}
		else if ("char" == var_type)
		{
			table symbol(id, "char", "\0");

			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
			auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), 0);

			semantics::builder->CreateStore(value, symbol.all);
			semantics::stack_st.insert_table(symbol);
		}
		else if ("boolean" == var_type)
		{
			// 对布尔值，看作是整形，并以0为false，非0为true
			table symbol(id, "boolean", "false");
			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
			auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
			semantics::builder->CreateStore(value, symbol.all);
			semantics::stack_st.insert_table(symbol);
		}
		else if (0 == var_type.find("record"))
		{
			table symbol(id, "record", "record");
			// 对于一个 record 来说，在当前规则中只能先将该符号入栈
			// record里面的变量以及 llvm 能做的事必须要到 record_body 中才能做
			symbol.is_record = true;
			semantics::stack_st.insert_table(symbol);
		}
		else if (0 == var_type.find("array"))
		{
			std::string array_type = ctx->type()->type()->getText();
			std::string array_range = ctx->type()->periods()->getText();
			table symbol(id, array_type, array_type);
			// cout<<"arr:"<<array_type<<endl;
			symbol.is_array = true;

			// 接下来需要处理数组的维度，每一维度用逗号区分
			std::string period;					// period 表示每一维度的范围
			std::string range_begin, range_end; // 表示每一维的起止符号
			int range_split;
			do
			{
				range_split = array_range.find(',');
				period = array_range.substr(0, range_split);
				range_begin = period.substr(0, period.find(".."));
				range_end = period.substr(period.find("..") + 2);
				// 去除begin和end前后的空白字符
				range_begin.erase(0, range_begin.find_first_not_of(" "));
				range_end.erase(0, range_end.find_first_not_of(" "));
				range_begin.erase(range_begin.find_last_not_of(" ") + 1);
				range_end.erase(range_end.find_last_not_of(" ") + 1);

				if ("integer" == type_of(range_begin) and "integer" == type_of(range_end))
				{
					// 范围必须是整数型，且 end 大于 begin
					int begin = atoi(range_begin.c_str());
					int end = atoi(range_end.c_str());
					if (begin <= end)
					{
						symbol.range_type.push_back("integer");
						symbol.range.push_back(std::pair<int, int>(begin, end - begin + 1));
					}
					else
					{
						std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
					}
				}
				else if ("char" == type_of(range_begin) and "char" == type_of(range_end))
				{
					// 范围由单字符组成
					if (range_end[1] >= range_begin[1])
					{
						symbol.range_type.push_back("char");
						symbol.range.push_back(std::pair<int, int>(range_begin[1], range_end[1] - range_begin[1] + 1));
					}
					else
					{
						std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
					}
				}
				else
				{
					// 除了单字符和整数表示，其余的场景是无效的字符范围
					std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
				}

				array_range = array_range.substr(range_split + 1);
			} while (std::string::npos != range_split);
			// 处理完所有维度的范围之后，要为数组分配总空间
			int range = 1;
			for (auto iter = symbol.range.begin(); iter != symbol.range.end(); iter++)
			{
				range *= iter->second;
			}
			// int range = (symbol.range.end() - 1)->second;
			symbol.arr_len = range;
			if ("integer" == array_type)
			{
				symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
			}
			else if ("char" == array_type)
			{
				symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt8Ty(*semantics::context), range), nullptr));
			}
			else if ("real" == array_type)
			{
				symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getFloatTy(*semantics::context), range), nullptr));
			}
			else if ("boolean" == array_type)
			{
				symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
			}
			else
			{
				// 目前该项目仅支持基础基础类型的数组
				std::cout << "Line " << ctx->getStart()->getLine() << ": Unsupported array type" << std::endl;
			}
			semantics::stack_st.insert_table(symbol);
		}
		id_list = id_list.substr(split_pos + 1); // 将处理后的id剔除出去
	} while (std::string::npos != split_pos);
}

void semanticsListener::exitProgram(PascalSParser::ProgramContext *ctx)
{
	semantics::mod->print(llvm::outs(), nullptr); // 打印ir
}

void semanticsListener::exitProgram_body(PascalSParser::Program_bodyContext *ctx)
{
	semantics::stack_st.pint_table();
	if (0 != semantics::depth)
		semantics::depth--;
}

void semanticsListener::enterRecord_body(PascalSParser::Record_bodyContext *ctx)
{
	if (1 == semantics::type_declaration)
		return;

	// 如果这不是在type字段的record，就一定是在var字段的，要将var_record开关打开
	semantics::var_record = 1;
}

void semanticsListener::exitRecord_body(PascalSParser::Record_bodyContext *ctx)
{
	if (1 == semantics::var_record)
		semantics::var_record = 0;
}
void semanticsListener::exitSubprogram_declaration(PascalSParser::Subprogram_declarationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	table &temp = semantics::stack_st.get_top_table();
	temp.ctx = ctx->program_body();
}
void semanticsListener::exitFunctionDeclaration(PascalSParser::FunctionDeclarationContext *ctx)
{
	// 从子程序的声明头出来的时候，意味着即将进入子程序的声明体
	// 但是在声明这里我们是对子程序的程序体不做语义动作的，通过semantics::depth来控制是否跳过
	semantics::depth++;
}

void semanticsListener::exitProcedureDeclaration(PascalSParser::ProcedureDeclarationContext *ctx)
{
	// 同上
	semantics::depth++;
}

void semanticsListener::enterSubprogram_declaration(PascalSParser::Subprogram_declarationContext *ctx)
{
	// semantics::depth = 0;
}

void semanticsListener::enterProgram_body(PascalSParser::Program_bodyContext *ctx)
{
	return;
}
void semanticsListener::enterFunctionDeclaration(PascalSParser::FunctionDeclarationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string name = ctx->ID()->getText();/* 
	cout<<"DECLARE: "<<name<<endl; */
	string return_type = ctx->standard_type()->getText();
	table func(name, return_type, 1, 0);
	semantics::stack_st.insert_table(func);
}
void semanticsListener::enterProcedureDeclaration(PascalSParser::ProcedureDeclarationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string name = ctx->ID()->getText();
	table func(name, "", 0, 1);
	semantics::stack_st.insert_table(func);
}
void semanticsListener::enterVarPara(PascalSParser::VarParaContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::pass = true;
	table &temp = semantics::stack_st.get_top_table();

	string para_type = ctx->var_parameter()->value_parameter()->standard_type()->getText();
	if ("real" != para_type && "integer" != para_type && "boolean" != para_type && "char" != para_type)
	{
		cout << "Line: " << ctx->getStart()->getLine() << "  Wrong type of arguments (" << ctx->getText() << ")\n";
		return;
	}
	string paralist = ctx->var_parameter()->value_parameter()->identifier_list()->getText();

	// cout<<para_type<<endl<<paralist<<endl;
	string paralist_2 = paralist + ",";
	int i = paralist_2.find(',');
	while (string::npos != i)
	{
		string temppara = paralist_2.substr(0, i);
		struct Argument arg(temppara, para_type, true);
		temp.push_argument(arg);
		paralist_2 = paralist_2.substr(i + 1, paralist_2.size());
		i = paralist_2.find(',');
	}
}
void semanticsListener::exitVarPara(PascalSParser::VarParaContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::pass = false;
}
void semanticsListener::enterValuePara(PascalSParser::ValueParaContext *ctx)
{
	if (semantics::depth != 0)
		return;
	if (semantics::pass)
		return;
	table &temp = semantics::stack_st.get_top_table();

	string para_type = ctx->value_parameter()->standard_type()->getText();
	if ("real" != para_type && "integer" != para_type && "boolean" != para_type && "char" != para_type)
	{
		cout << "Line: " << ctx->getStart()->getLine() << "  Wrong type of arguments (" << ctx->getText() << ")\n";
		return;
	}
	string paralist = ctx->value_parameter()->identifier_list()->getText();

	string paralist_2 = paralist + ",";
	int i = paralist_2.find(',');
	while (string::npos != i)
	{
		string temppara = paralist_2.substr(0, i);
		struct Argument arg(temppara, para_type, false);
		temp.push_argument(arg);

		paralist_2 = paralist_2.substr(i + 1, paralist_2.size());
		i = paralist_2.find(',');
	}
}
void semanticsListener::enterAssign(PascalSParser::AssignContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::is_assign = 1;
	string var_name = ctx->variable()->ID()->getText();
	table &temp = semantics::stack_st.locate_table(var_name);
	if ("err" == temp.type)
	{
		cout << "Line: " << ctx->variable()->getStart()->getLine() << "  No declaration of " << var_name << endl;
		return;
	}
	if (temp.is_const)

	{
		cout << "Line: " << ctx->variable()->getStart()->getLine() << "  cannot change the value of the constant " << var_name << endl;
		return;
	}
}
void semanticsListener::exitAssign(PascalSParser::AssignContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string var_name = ctx->variable()->ID()->getText();
	table &temp = semantics::stack_st.locate_table(var_name);
	/* 普通变量的赋值 */
	if (0 == ctx->variable()->id_varparts()->getText().size())
	{
		/* 非函数的赋值 */
		if (!temp.is_func && !temp.is_proc)
		{
			if (temp.type != semantics::exp_type.back() && !("real" == temp.type && "integer" == semantics::exp_type.back()))
			{
				cout << "Line:" << ctx->variable()->getStart()->getLine() << "    Cannot assign values to variables of different types" << endl;
				semantics::exp_type.pop_back();
				semantics::exp_type.pop_back();
			}
			else
			{
				if ("integer" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					/* real型可以兼容integer */
					if ("integer" == temp.type)
					{
						int integer = atoi(semantics::exp_value.back().c_str());
						// cout<<"int:"<<integer<<endl;
						auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
						semantics::builder->CreateStore(value, temp.all);
					}
					else if ("real" == temp.type)
					{
						int integer = atoi(semantics::exp_value.back().c_str());
						auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), integer);
						semantics::builder->CreateStore(value, temp.all);
					}
					temp.value = semantics::exp_value.back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					}
					char ch = atoi(semantics::exp_value.back().c_str());
					// cout << "ch:" << ch << endl;
					auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					semantics::builder->CreateStore(value, temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("real" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
					}
					double real = atof(semantics::exp_value.back().c_str());
					auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), real);
					semantics::builder->CreateStore(value, temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{
					int b;
					string boolean = semantics::exp_value.back();
					if ("true" == boolean)
					{
						b = 1;
					}
					else if ("false" == boolean)
					{
						b = 0;
					}
					if ("true" != boolean && "false" != boolean)
					{
						cout << "Line:" << ctx->variable()->getStart()->getLine() << "  2.  Cannot assign values to variables of different types" << endl;
						return;
					}
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					semantics::builder->CreateStore(value, temp.all);
					temp.value = semantics::exp_value.back();
				}

				semantics::exp_type.pop_back();
				semantics::exp_value.pop_back();
				semantics::index.pop_back();
			}
		}
		/* 函数返回值的赋值 */
		else if (temp.is_func &&temp.name==var_name)
		{
			
			/* cout<<"TEMP: "<<temp.name<<"  TYPE: "<<temp.type<<endl;
			cout<<"FUNCTION "<<semantics::exp_type.size()<<endl;
			cout<<"TYPE: "<<semantics::exp_type.back()<<"  VALUE: "<<semantics::exp_value.back()<<endl; */
			if (temp.type != semantics::exp_type.back() && !("real" == temp.type && "integer" == semantics::exp_type.back()))
			{
				cout << "Line:" << ctx->variable()->getStart()->getLine() << "    Cannot assign values to variables of different types" << endl;
				semantics::exp_type.pop_back();
				semantics::exp_value.pop_back();
			}
			else
			{
				if ("integer" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					/* real型可以兼容integer */
					if ("integer" == temp.type)
					{
						int integer = atoi(semantics::exp_value.back().c_str());
						// cout<<"int:"<<integer<<endl;
						auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
						semantics::builder->CreateStore(value, temp.all);
					}
					else if ("real" == temp.type)
					{
						int integer = atoi(semantics::exp_value.back().c_str());
						auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), integer);
						semantics::builder->CreateStore(value, temp.all);
					}
					temp.value = semantics::exp_value.back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					}
					char ch = atoi(semantics::exp_value.back().c_str());
					// cout << "ch:" << ch << endl;
					auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					semantics::builder->CreateStore(value, temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("real" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
					}
					double real = atof(semantics::exp_value.back().c_str());
					auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), real);
					semantics::builder->CreateStore(value, temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{
					int b;
					string boolean = semantics::exp_value.back();
					if ("true" == boolean)
					{
						b = 1;
					}
					else if ("false" == boolean)
					{
						b = 0;
					}
					if ("true" != boolean && "false" != boolean)
					{
						cout << "Line:" << ctx->variable()->getStart()->getLine() << "   6. Cannot assign values to variables of different types" << endl;
						return;
					}
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					semantics::builder->CreateStore(value, temp.all);
					temp.value = semantics::exp_value.back();
				}

				semantics::exp_type.pop_back();
				semantics::exp_value.pop_back();
				semantics::index.pop_back();
			}
		}
		/* 函数参数的赋值,指引用，因为传值的参数会建立新的符号表，当作变量赋值即可 */
		else if (temp.is_arg)
		{	
			temp.is_arg=false;
			int loc = 0;
			for (int i = 0; i < temp.arguments_num; i++)
			{
				if (var_name == temp.arguments[i].name)
				{
					
					loc = temp.arguments[i].location;
					break;
				}
			}
			table &temp2 = semantics::stack_st.get_var_table(loc);
			if (temp2.type != semantics::exp_type.back() && !("real" == temp2.type && "integer" == semantics::exp_type.back()))
			{
				cout << "Line:" << ctx->variable()->getStart()->getLine() << "  3.  Cannot assign values to variables of different types:"<<loc << endl;
				semantics::exp_type.pop_back();
				semantics::exp_type.pop_back();
				return;
			}
			else
			{
				if ("integer" == semantics::exp_type.back())
				{
					if (NULL == temp2.all)
					{
						temp2.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					if ("integer" == temp2.type)
					{
						int integer = atoi(semantics::exp_value.back().c_str());
						auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
						semantics::builder->CreateStore(value, temp2.all);
					}
					else if ("real" == temp2.type)
					{
						int integer = atoi(semantics::exp_value.back().c_str());
						auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), integer);
						semantics::builder->CreateStore(value, temp2.all);
					}

					/* int integer = atoi(semantics::exp_value.back().c_str());
					auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
					semantics::builder->CreateStore(value, temp.all); */
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					if (NULL == temp2.all)
					{
						temp2.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					}
					char ch = atoi(semantics::exp_value.back().c_str());
					// cout << "ch:" << ch << endl;
					auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					semantics::builder->CreateStore(value, temp2.all);
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
				}
				else if ("real" == semantics::exp_type.back())
				{
					if (NULL == temp2.all)
					{
						temp2.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
					}
					double real = atof(semantics::exp_value.back().c_str());
					auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), real);
					semantics::builder->CreateStore(value, temp2.all);
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{
					int b;
					string boolean = semantics::exp_value.back();
					if ("true" == boolean)
					{
						b = 1;
					}
					else if ("false" == boolean)
					{
						b = 0;
					}
					if ("true" != boolean && "false" != boolean)
					{
						cout << "Line:" << ctx->variable()->getStart()->getLine() << "  4.  Cannot assign values to variables of different types" << endl;
						return;
					}
					if (NULL == temp2.all)
					{
						temp2.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					semantics::builder->CreateStore(value, temp2.all);
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
				}
			}

			semantics::index.pop_back();
			return;
		}
		
		
		/* 过程没有返回值，报错 */
		else
		{
			cout << "line:" << ctx->getStart()->getLine() << "    Procedure has no return value!\n";
			return;
		}
	}

	/* 数组和记录的赋值 */
	else
	{
		if (temp.is_array)
		{
			/* 数组型变量 */
			string list = ctx->variable()->id_varparts()->getText();
			vector<int> periods;
			int i = list.find('[');
			while (string::npos != i)
			{
				list = list.replace(i, 1, ",");
				i = list.find('[');
			}
			i = list.find(']');
			while (string::npos != i)
			{
				list = list.replace(i, 1, ",");
				i = list.find(']');
			}
			i = list.find(",,");
			while (string::npos != i)
			{
				list = list.replace(i, 2, ",");
				i = list.find(",,");
			}
			list.erase(0, 1);
			i = list.find(',');
			while (string::npos != i)
			{
				string temp_str = list.substr(0, i);
				if ("integer" == type_of(temp_str))
				{
					int r = atoi(temp_str.c_str());
					periods.push_back(r);
				}
				else if ("char" == type_of(temp_str))
				{
					char ch = temp_str[0];
					periods.push_back(ch);
				}
				else
				{
					cout << "Wrong type of period" << endl;
				}
				list = list.substr(i + 1, list.size());
				i = list.find(',');
			}

			int len;
			/* 数组只有一维 */
			if (1 == periods.size())
			{
				len = periods[0] - temp.range[0].first;
			}
			else
			{
				/* 多维数组 */
				/* 二维 */
				int dep = periods.size() - 1;
				int end = periods[dep - 1];
				len = periods[dep] - temp.range[dep].first + 1;
				len += (end - temp.range[dep - 1].first) * temp.range[dep].second;
				/* 三维及以上 */
				int wid = 1;
				int location = periods.size() - 3;
				while (location >= 0)
				{
					for (int i = periods.size() - 1; i > location; i--)
					{
						wid *= temp.range[1].second;
					}
					len += wid;
					wid = 1;
					location--;
				}
			}
			if (temp.type != semantics::exp_type.back() && !("real" == temp.type && "integer" == temp.type))
			{
				cout << "Line:" << ctx->variable()->getStart()->getLine() << "   7. Cannot assign values to variables of different types" << endl;
				semantics::exp_type.pop_back();
				semantics::exp_type.pop_back();
			}
			else
			{

				if ("integer" == semantics::exp_type.back())
				{

					/* real型可以兼容integer */
					if ("integer" == temp.type)
					{

						int integer = atoi(semantics::exp_value.back().c_str());
						// cout<<"int:"<<integer<<endl;
						auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
						auto index0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
						auto index_end = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);

						auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, index_end});
						semantics::builder->CreateStore(value, addr0);
					}
					else if ("real" == temp.type)
					{
						int integer = atoi(semantics::exp_value.back().c_str());
						auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), integer);
						auto index0 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), 0);
						auto index_end = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), len);
						auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getFloatTy(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, index_end});
						semantics::builder->CreateStore(value, addr0);
					}
					temp.arr_val[len] = semantics::exp_value.back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					char ch = atoi(semantics::exp_value.back().c_str());
					// cout << "ch:" << ch << endl;
					auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					auto index0 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), 0);
					auto index_end = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), len);
					auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, index_end});
					semantics::builder->CreateStore(value, addr0);
					temp.arr_val[len] = semantics::exp_value.back();
				}
				else if ("real" == semantics::exp_type.back())
				{

					double integer = atof(semantics::exp_value.back().c_str());
					auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), integer);
					auto index0 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), 0);
					auto index_end = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), len);
					auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getFloatTy(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, index_end});
					semantics::builder->CreateStore(value, addr0);
					temp.arr_val[len] = semantics::exp_value.back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{
					int b;
					string boolean = semantics::exp_value.back();
					if ("true" == boolean)
					{
						b = 1;
					}
					else if ("false" == boolean)
					{
						b = 0;
					}
					if ("true" != boolean && "false" != boolean)
					{
						cout << "Line:" << ctx->variable()->getStart()->getLine() << "   8. Cannot assign values to variables of different types" << endl;
						return;
					}

					// cout<<"int:"<<integer<<endl;
					auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					auto index0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
					auto index_end = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
					auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, index_end});
					semantics::builder->CreateStore(value, addr0);
					temp.arr_val[len] = semantics::exp_value.back();
				}

				semantics::exp_type.pop_back();
				semantics::exp_value.pop_back();
				semantics::index.pop_back();
			}
		}
		else if (temp.is_record)
		{
			/* 记录型变量 */
			struct record_elements &r_ele = temp.records[semantics::record_id];
			if (!r_ele.is_array)
			{
				/* 内容不是数组 */
				if (r_ele.type != semantics::exp_type.back() && !("real" == r_ele.type && "integer" == r_ele.type))
				{
					cout << "Line:" << ctx->variable()->getStart()->getLine() << "   9. Cannot assign values to variables of different types" << endl;
					semantics::exp_type.pop_back();
					semantics::exp_type.pop_back();
				}
				else
				{
					if ("integer" == semantics::exp_type.back())
					{
						if (NULL == r_ele.all)
						{
							r_ele.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
						}
						/* real型可以兼容integer */
						if ("integer" == r_ele.type)
						{
							int integer = atoi(semantics::exp_value.back().c_str());
							// cout<<"int:"<<integer<<endl;
							auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
							semantics::builder->CreateStore(value, r_ele.all);
						}
						else if ("real" == r_ele.type)
						{
							int integer = atoi(semantics::exp_value.back().c_str());
							auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), integer);
							semantics::builder->CreateStore(value, r_ele.all);
						}
						r_ele.value = semantics::exp_value.back();
					}
					else if ("char" == semantics::exp_type.back())
					{
						if (NULL == r_ele.all)
						{
							r_ele.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
						}
						char ch = atoi(semantics::exp_value.back().c_str());
						// cout << "ch:" << ch << endl;
						auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
						semantics::builder->CreateStore(value, r_ele.all);
						r_ele.value = semantics::exp_value.back();
					}
					else if ("real" == semantics::exp_type.back())
					{
						if (NULL == r_ele.all)
						{
							r_ele.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
						}
						double real = atof(semantics::exp_value.back().c_str());
						auto value = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), real);
						semantics::builder->CreateStore(value, r_ele.all);
						r_ele.value = semantics::exp_value.back();
					}
					else if ("boolean" == semantics::exp_type.back())
					{
						int b;
						string boolean = semantics::exp_value.back();
						if ("true" == boolean)
						{
							b = 1;
						}
						else if ("false" == boolean)
						{
							b = 0;
						}
						if ("true" != boolean && "false" != boolean)
						{
							cout << "Line:" << ctx->variable()->getStart()->getLine() << "   10. Cannot assign values to variables of different types" << endl;
							return;
						}
						if (NULL == r_ele.all)
						{
							r_ele.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
						}
						auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
						semantics::builder->CreateStore(value, r_ele.all);
						r_ele.value = semantics::exp_value.back();
					}

					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
					semantics::index.pop_back();
				}
			}
			else if (r_ele.is_array)
			{
				/* 内容是数组 */
			}
		}
		/* 记录型变量 */
		/* string id_var = ctx->variable()->id_varparts()->getText();
		cout << id_var << endl; */
	}
}
void semanticsListener::enterAddOperation(PascalSParser::AddOperationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	int end = semantics::exp_value.size();
	semantics::index.push_back(end);
}
void semanticsListener::exitAddOperation(PascalSParser::AddOperationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string addop = ctx->addop()->getText();

	string right = semantics::exp_value.back();
	string right_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::exp_type.pop_back();

	string left = semantics::exp_value.back();
	string left_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::exp_type.pop_back();

	semantics::index.pop_back();

	if ("+" == addop)
	{
		/* 加法 */
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || "integer" == right_type && "real" == left_type))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot multiply variables of different types" << endl;
			return;
		}
		if ("char" == right_type || "boolean" == right_type || "char" == left_type || "boolean" == left_type)
		{
			cout << "line:" << ctx->getStart()->getLine() << "    these variable cannot be multiplied" << endl;
			return;
		}
		if ("real" == right_type || "real" == left_type)
		{
			semantics::exp_type.push_back("real");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(right.c_str()));

			auto v = semantics::builder->CreateFAdd(value1, value2);
			double r = atof(left.c_str()) + atof(right.c_str());
			/* ostringstream os;
			os << r; */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
		else if ("integer" == right_type && "integer" == left_type)
		{
			semantics::exp_type.push_back("integer");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			semantics::builder->CreateAdd(value1, value2);
			int r = atoi(right.c_str()) + atoi(left.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
	}
	else if ("-" == addop)
	{
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || "integer" == right_type && "real" == left_type))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot multiply variables of different types" << endl;
			return;
		}
		if ("char" == right_type || "boolean" == right_type || "char" == left_type || "boolean" == left_type)
		{
			cout << "line:" << ctx->getStart()->getLine() << "    these variable cannot be multiplied" << endl;
			return;
		}
		if ("real" == right_type || "real" == left_type)
		{
			semantics::exp_type.push_back("real");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(right.c_str()));

			auto v = semantics::builder->CreateFSub(value1, value2);
			double r = atof(left.c_str()) - atof(right.c_str());
			/* ostringstream os;
			os << r; */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
		else if ("integer" == right_type && "integer" == left_type)
		{
			semantics::exp_type.push_back("integer");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			semantics::builder->CreateSub(value1, value2);
			int r = atoi(left.c_str()) - atoi(right.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
	}
}
void semanticsListener::enterMultiplyOperation(PascalSParser::MultiplyOperationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	int end = semantics::exp_value.size();
	semantics::index.push_back(end);
}
void semanticsListener::exitMultiplyOperation(PascalSParser::MultiplyOperationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string mulop = ctx->mulop()->getText();

	string right = semantics::exp_value.back();
	string right_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::exp_type.pop_back();

	string left = semantics::exp_value.back();
	string left_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::exp_type.pop_back();

	semantics::index.pop_back();

	if ("*" == mulop)
	{
		/* 乘法 */
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || "integer" == right_type && "real" == left_type))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot multiply variables of different types" << endl;
			return;
		}
		if ("char" == right_type || "boolean" == right_type || "char" == left_type || "boolean" == left_type)
		{
			cout << "line:" << ctx->getStart()->getLine() << "    these variable cannot be multiplied" << endl;
			return;
		}
		if ("real" == right_type || "real" == left_type)
		{
			semantics::exp_type.push_back("real");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(right.c_str()));

			semantics::builder->CreateFMul(value1, value2);
			double r = atof(left.c_str()) * atof(right.c_str());
			/* ostringstream os;
			os << r; */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
		else if ("integer" == right_type && "integer" == left_type)
		{
			semantics::exp_type.push_back("integer");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			semantics::builder->CreateMul(value1, value2);
			int r = atoi(right.c_str()) * atoi(left.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
	}
	else if ("/" == mulop)
	{
		/* 取商除法 */
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || "integer" == right_type && "real" == left_type))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot multiply variables of different types" << endl;
			return;
		}
		if ("char" == right_type || "boolean" == right_type || "char" == left_type || "boolean" == left_type)
		{
			cout << "line:" << ctx->getStart()->getLine() << "    these variable cannot be multiplied" << endl;
			return;
		}
		if ("integer" == left_type && "integer" == right_type)
		{

			semantics::exp_type.push_back("integer");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			semantics::builder->CreateSDiv(value1, value2);
			int r = atoi(left.c_str()) / atoi(right.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
		else if ("real" == right_type || "real" == left_type)
		{
			semantics::exp_type.push_back("real");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getFloatTy(*semantics::context), atof(right.c_str()));

			semantics::builder->CreateFDiv(value1, value2);
			// semantics::builder->CreateMod(value1, value2);
			double r = atof(left.c_str()) / atof(right.c_str());
			r = r / 1.0;
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
	}
	else if ("mod" == mulop)
	{
		if (left_type != right_type)
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot multiply variables of different types" << endl;
			return;
		}
		if ("char" == right_type || "boolean" == right_type || "char" == left_type || "boolean" == left_type || "real" == right_type || "real" == left_type)
		{
			cout << "line:" << ctx->getStart()->getLine() << "    these variable cannot be multiplied" << endl;
			return;
		}
		if ("integer" == left_type && "integer" == right_type)
		{

			semantics::exp_type.push_back("integer");
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			semantics::builder->CreateSRem(value1, value2);
			int r = atoi(left.c_str()) % atoi(right.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
		}
	}
}
void semanticsListener::exitUnsignConstId(PascalSParser::UnsignConstIdContext *ctx)
{
	if (semantics::depth != 0)
		return;
	if(1==semantics::iscall)
		return;
	string id = ctx->ID()->getText();
	if ("true" == id || "false" == id)
	{
		semantics::exp_value.push_back(id);
		semantics::exp_type.push_back("boolean");
		// cout << "boolennn\n";
	}
	/* 变量或者函数 */
	else
	{
		table &temp = semantics::stack_st.locate_table(id);
		if (temp.type == "err")
		{
			cout << "line: " << ctx->getStart()->getLine() << "    No declaration of variable: " << id << endl;
			return;
		}
		/* 引用传递的参数 */
		if (temp.is_arg)
		{
			temp.is_arg=false;
			int loc = 0;
			string var_name = id;
			for (int i = 0; i < temp.arguments_num; i++)
			{
				if (var_name == temp.arguments[i].name)
				{
					loc = temp.arguments[i].location;
					break;
				}
			}
			table &temp2 = semantics::stack_st.get_var_table(loc);
			if ("" == temp2.value)
			{
				cout << "line: " << ctx->getStart()->getLine() << "    Variable has no value!\n";
				return;
			}
			else
			{
				semantics::exp_type.push_back(temp2.type);
				semantics::exp_value.push_back(temp2.value);
			}
		}
		/* 过程 */
		else if (temp.is_proc)
		{
			cout << "line: " << ctx->getStart()->getLine() << "    Procedure has no return value!\n";
			return;
		}
		else if (temp.is_func)
		{
			/* 调用函数 */

			semantics::stack_st.update_top_table();
			semanticsListener listener;
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, temp.ctx);
			semantics::stack_st.pop_table();
			semantics::exp_type.push_back(temp.type);
			semantics::exp_value.push_back(temp.value);
		}

		else if (!temp.is_func && !temp.is_proc)
		{
			/* 变量 */
			if ("" == temp.value)
			{
				cout << "line: " << ctx->getStart()->getLine() << "    Variable has no value!\n";
				return;
			}
			else
			{
				// cout << "value:" << temp.value << endl;
				semantics::exp_type.push_back(temp.type);
				semantics::exp_value.push_back(temp.value);
			}
		}
		else
		{
			cout << "Program Wrong!" << endl;
			return;
		}
	}
}

void semanticsListener::exitUnsignConstNumber(PascalSParser::UnsignConstNumberContext *ctx)
{
	if (semantics::depth != 0)
		return;

	string number = ctx->NUMBER()->getText();
	semantics::exp_value.push_back(number);
	if (number.find('.') != string::npos)
	{
		// cout << "real\n";
		semantics::exp_type.push_back("real");
	}
	else
	{
		semantics::exp_type.push_back("integer");
	}
}

void semanticsListener::exitUnsignConstChar(PascalSParser::UnsignConstCharContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::exp_value.push_back(ctx->CONST_CHAR()->getText());
	semantics::exp_type.push_back("char");
}

/* 'not'运算 */
void semanticsListener::exitReverseFactor(PascalSParser::ReverseFactorContext *ctx)
{
	if (semantics::depth != 0)
		return;
	
	if ("real" == semantics::exp_type.back())
	{
		cout << "line:" << ctx->getStart()->getLine() << " Cannot perform 'not' operation on variable of type 'real'\n";
		return;
	}
	else if ("char" == semantics::exp_type.back())
	{
		cout << "line:" << ctx->getStart()->getLine() << " Cannot perform 'not' operation on variable of type 'char'\n";
		return;
	}
	else
	{
		int var = atoi(semantics::exp_value.back().c_str());
		// cout << var << endl;
		if ("boolean" == semantics::exp_type.back())
		{
			// cout<<"hiiiii\n";
			int temp = !var;
			var = temp;
		}
		else if ("integer" == semantics::exp_type.back())
		{
			// cout<<"hello\n";
			int temp = ~var;
			var = temp;
		}
		// cout<<"varrr:"<<var;
		ostringstream os;
		os << var;
		string result(os.str());
		// semantics::exp_type.pop_back();
		semantics::exp_value.pop_back();
		semantics::exp_value.push_back(result);
	}
}
void semanticsListener::enterFactorVariable(PascalSParser::FactorVariableContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::is_assign = 2;
}
void semanticsListener::exitFactorVariable(PascalSParser::FactorVariableContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::is_assign = 1;
}
void semanticsListener::enterVariable(PascalSParser::VariableContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string name = ctx->ID()->getText();
	table &temp = semantics::stack_st.locate_table(name);
	if ("err" == temp.type)
	{
		cout << "line: " << ctx->getStart()->getLine() << " No declaration of variable: " << name << endl;
		return;
	}
	else if (true == temp.is_array || true == temp.is_record)
	{
		semantics::id = name;
		if (temp.is_array)
		{
			semantics::r_type = temp.range_type;
			// cout<<"sum1:"<<semantics::r_type.size()<<"  sum2:"<<temp.range_type.size()<<endl;;
		}
		// cout<<"here"<<endl;
	}
}
void semanticsListener::exitVariable(PascalSParser::VariableContext *ctx)
{
	// semantics::cur_range = 0;
}
void semanticsListener::enterArrayAccess(PascalSParser::ArrayAccessContext *ctx)
{
	if (semantics::depth != 0)
		return;
	/* 检查数组下标是否合法 */
	semantics::cur_range++;
	// cout << "cur:" << semantics::cur_range << endl;
	table &temp = semantics::stack_st.locate_table(semantics::id);
	// cout<<"type:"<<temp.type<<endl;
	if (!temp.is_array)
	{
		cout << "line: " << ctx->getStart()->getLine() << "    This variable isn't an array" << endl;
		return;
	}
	pair<int, int> r = temp.range[semantics::cur_range - 1];
	semantics::r_type = temp.range_type;
	string ran = ctx->expression_list()->getText();
	// cout<<"ran:"<<ran<<endl;
	//  cout<<"tt:"<<type_of(ran)<<endl;
	// cout<<semantics::r_type.size()<<endl;
	if ("id" == type_of(ran.c_str()) || type_of(ran.c_str()) != semantics::r_type[semantics::cur_range - 1])
	{
		// cout<<"r_type:"<<semantics::r_type[semantics::cur_range]<<endl;
		cout << "line: " << ctx->getStart()->getLine() << "   Illegal access to array" << endl;
		return;
	}
	if ("integer" == type_of(ran.c_str()))
	{
		if (r.first > atoi(ran.c_str()) || r.second < (atoi(ran.c_str()) - r.first) || "integer" != semantics::r_type[semantics::cur_range - 1])
		{
			cout << "intline: " << ctx->getStart()->getLine() << "   Illegal access to array val: " << r.second << endl;
			return;
		}
		else
		{

			/* semantics::range_len *= r.second - r.first;
			semantics::len = semantics::range_len + r.second - r.first;
			semantics::arr_index.push_back(r.second - r.first); */
		}
	}
	if ("char" == type_of(ran.c_str()))
	{
		if (r.first > ran[0] || r.second < (int(ran[0]) - r.second))
		{
			cout << "line: " << ctx->getStart()->getLine() << "   Illegal access to array" << endl;
			return;
		}
	}

	// cout<<"array here"<<endl
}
void semanticsListener::enterId_varparts(PascalSParser::Id_varpartsContext *ctx)
{
	semantics::id_varparts_num++;
	// cout << "now: " << semantics::id_varparts_num << endl;
}
/* 处理完一个数组，初始化数据 */
void semanticsListener::exitId_varparts(PascalSParser::Id_varpartsContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::id_varparts_num--;
	int ran = semantics::cur_range;
	if (0 == semantics::id_varparts_num)
	{
		// cout << "here cur:" << semantics::cur_range << endl;
		semantics::cur_range = 0;
	}
	if (0 != semantics::id_varparts_num || 1 == semantics::is_assign)
		return;
	/* int ran=semantics::cur_range;
	if (0 == semantics::id_varparts_num)
	{
		cout << "here cur:" << semantics::cur_range << endl;
		semantics::cur_range=0;
	} */
	table &temp = semantics::stack_st.locate_table(semantics::id);
	if (ran != temp.range.size())
	{
		// cout << semantics::cur_range << "  " << ran << endl;
		cout << "line: " << ctx->getStart()->getLine() << "    illegal access to array!" << endl;
		return;
	}
	if (2 == semantics::is_assign && 0 == semantics::id_varparts_num)
	{

		// cout << "im here" << endl;
		//  cout<<"type:"<<temp.type<<endl;
		if (!temp.is_array)
		{
			cout << "line: " << ctx->getStart()->getLine() << "    This variable isn't an array" << endl;
			return;
		}
		string list = ctx->getText();
		// cout << "list:" << list << endl;
		vector<int> periods;
		int i = list.find('[');
		while (string::npos != i)
		{
			list = list.replace(i, 1, ",");
			i = list.find('[');
		}
		i = list.find(']');
		while (string::npos != i)
		{
			list = list.replace(i, 1, ",");
			i = list.find(']');
		}
		i = list.find(",,");
		while (string::npos != i)
		{
			list = list.replace(i, 2, ",");
			i = list.find(",,");
		}
		list.erase(0, 1);
		i = list.find(',');
		// cout << "here 2" << endl;
		while (string::npos != i)
		{
			string temp_str = list.substr(0, i);
			if ("integer" == type_of(temp_str))
			{
				int r = atoi(temp_str.c_str());
				periods.push_back(r);
			}
			else if ("char" == type_of(temp_str))
			{
				char ch = temp_str[0];
				periods.push_back(ch);
			}
			else
			{
				cout << "Wrong type of period" << endl;
			}
			list = list.substr(i + 1, list.size());
			i = list.find(',');
		}

		int len;
		/* 数组只有一维 */
		if (1 == periods.size())
		{
			len = periods[0] - temp.range[0].first;
		}
		else
		{
			/* 多维数组 */
			int dep = periods.size() - 1;
			int end = periods[dep - 1];
			len = periods[dep] - temp.range[dep].first + 1;
			len += (end - temp.range[dep - 1].first) * temp.range[dep].second;
		}
		int wid = 1;
		int location = periods.size() - 3;
		while (location >= 0)
		{
			for (int i = periods.size() - 1; i > location; i--)
			{
				wid *= temp.range[1].second;
			}
			len += wid;
			wid = 1;
			location--;
		}

		if ("" == temp.arr_val[len])
		{
			cout << "line: " << ctx->getStart()->getLine() << "    The elements has no value" << endl;
			return;
		}
		// cout<<"value: "<<temp.arr_val[len]<<endl;
		semantics::exp_type.push_back(temp.type);
		semantics::exp_value.push_back(temp.arr_val[len]);
	}
	semantics::r_type.clear();
	semantics::cur_range = 0;
}
void semanticsListener::enterRecordAccess(PascalSParser::RecordAccessContext *ctx)
{
	if (semantics::depth != 0)
		return;
	if (semantics::is_assign == 1)
	{
		table &temp = semantics::stack_st.locate_table(semantics::id);
		if (temp.records.find(ctx->ID()->getText()) == temp.records.end())
		{
			cout << "line: " << ctx->getStart()->getLine() << "   record doesn't has this member: " << ctx->ID()->getText() << endl;
			return;
		}
		struct record_elements &re = temp.records[ctx->ID()->getText()];
		if (!re.is_array)
		{
			/* 成员不是数组 */
			semantics::record_id = ctx->ID()->getText();
		}
		else
		{
			/* 成员是数组 */
		}
	}
	else if (2 == semantics::is_assign)
	{
		table &temp = semantics::stack_st.locate_table(semantics::id);
		if (temp.records.find(ctx->ID()->getText()) == temp.records.end())
		{
			cout << "line: " << ctx->getStart()->getLine() << "   record doesn't has this member: " << ctx->ID()->getText() << endl;
			return;
		}
		struct record_elements re = temp.records[ctx->ID()->getText()];
		if (!re.is_array)
		{
			/* 成员不是数组 */
			if (NULL == re.all)
			{
				cout << "line: " << ctx->getStart()->getLine() << "    variable has no value" << endl;
				return;
			}
			semantics::exp_type.push_back(re.type);
			semantics::exp_value.push_back(re.value);
		}
		else
		{
			/* 成员是数组，有缘再见 */
		}
	}
}
void semanticsListener::exitNegativeTerm(PascalSParser::NegativeTermContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string t = semantics::exp_type.back();
	string v = semantics::exp_value.back();
	if ("char" == t || "boolean" == t)
	{
		cout << "line:" << ctx->getStart()->getLine() << "    wrong type of negation" << endl;
		return;
	}
	else if ("integer" == t)
	{
		int integer = atoi(v.c_str());
		integer = -integer;
		string r = to_string(integer);
		semantics::exp_value.pop_back();
		semantics::exp_value.push_back(r);
	}
	else if ("real" == t)
	{
		double real = atoi(v.c_str());
		real = -real;
		string r = to_string(real);
		semantics::exp_value.pop_back();
		semantics::exp_value.push_back(r);
	}
	else
	{
		cout << "err in exitNegativeTerm" << endl;
		return;
	}
}
void semanticsListener::exitCallWithNoPara(PascalSParser::CallWithNoParaContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string name = ctx->ID()->getText();
	cout<<"CALL: "<<name<<endl;
	table &temp = semantics::stack_st.locate_table(name);
	if ("err" == temp.type)
	{
		cout << "line:" << ctx->getStart()->getLine() << "    No such function or procedure: " << endl;

		return;
	}
	semantics::stack_st.update_top_table();
	semanticsListener listener;
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, temp.ctx);
	semantics::stack_st.pop_table();
}
void semanticsListener::enterCallWithPara(PascalSParser::CallWithParaContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::iscall=1;
}
void semanticsListener::exitCallWithPara(PascalSParser::CallWithParaContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::iscall=0;
	semantics::stack_st.update_top_table();
	string lists = ctx->expression_list()->getText();
	vector<string> args;
	string name = ctx->ID()->getText();
	
	table &temp = semantics::stack_st.locate_table(name);
	if ((temp.is_arg) || "err" == temp.type)
	{
		cout << "line:" << ctx->getStart()->getLine() << "    No such function or procedure: " << endl;

		return;
	}
	if (0 == temp.arguments_num)
	{
		cout << "line:" << ctx->getStart()->getLine() << "   the function or procedure has no arguments" << endl;
		return;
	}
	/* 将参数提取出来 */
	lists = lists + ",";
	int i = lists.find(",");
	while (i != string::npos)
	{
		string t = lists.substr(0, i);
		args.push_back(t);
		lists = lists.substr(i + 1, lists.size());
		i = lists.find(",");
	}
	if (temp.arguments_num != args.size())
	{
		cout << "line:" << ctx->getStart()->getLine() << "   wrong number of parameters" << endl;
		return;
	}
	/* 处理参数 */
	for (i = 0; i < temp.arguments_num; i++)
	{

		struct Argument a = temp.arguments[i];
		string a_name = args[i];
		if ("integer" == type_of(a_name))
		{
			if (("integer" != a.type && "real" != a.type) || a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "   wrong type of parameter: " << a_name << endl;
				return;
			}
			table t(a.name, a.type, a_name);
			semantics::stack_st.insert_table(t);
		}
		else if ("real" == type_of(a_name))
		{
			if ("real" != a.type || a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "   wrong type of parameter: " << a_name << endl;
				return;
			}
			table t(a.name, a.type, a_name);
			semantics::stack_st.insert_table(t);
		}
		else
		{
			/* 传进来的是变量 */
			if (!a.pass_value)
			{
				/* 传值参数，需要新建符号表 */
				table &temp2 = semantics::stack_st.locate_table(a_name);
				if ("err" == temp2.type || (temp2.is_arg))
				{
					cout << "line:" << ctx->getStart()->getLine() << "   variable not declared: " << a_name << endl;
					return;
				}
				table t(a.name, a.type, temp2.value);
				semantics::stack_st.insert_table(t);
			}
			else if (a.pass_value)
			{
				/* 引用，需要获取真正的符号的位置 */
				table &temp2 = semantics::stack_st.locate_table(a_name);
				if ("err" == temp2.type || temp2.is_arg)
				{
					cout << "line:" << ctx->getStart()->getLine() << "   variable not declared: " << a_name << endl;
					return;
				}

				int r = semantics::stack_st.get_location(a_name);

				temp.arguments[i].location = r;
			}
		}
	}
	/* 调用子函数 */

	semanticsListener listener;
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, temp.ctx);

	semantics::stack_st.pop_table();
}
void semanticsListener::enterFactorReturn(PascalSParser::FactorReturnContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::iscall=1;
}
void semanticsListener::exitFactorReturn(PascalSParser::FactorReturnContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::iscall=0;
	semantics::stack_st.update_top_table();
	string lists = ctx->expression_list()->getText();
	vector<string> args;
	string name = ctx->ID()->getText();
	table &temp = semantics::stack_st.locate_table(name);
	if (temp.is_arg || "err" == temp.type)
	{
		cout << "line:" << ctx->getStart()->getLine() << "    No such function or procedure" << endl;
		return;
	}
	if (0 == temp.arguments_num)
	{
		cout << "line:" << ctx->getStart()->getLine() << "   the function or procedure has no arguments" << endl;
		return;
	}
	/* 将参数提取出来 */
	lists = lists + ",";
	int i = lists.find(",");
	while (i != string::npos)
	{
		string t = lists.substr(0, i);
		args.push_back(t);
		lists = lists.substr(i + 1, lists.size());
		i = lists.find(",");
	}
	if (temp.arguments_num != args.size())
	{
		cout << "line:" << ctx->getStart()->getLine() << "   wrong number of parameters" << endl;
		return;
	}
	/* 处理参数 */
	for (i = 0; i < temp.arguments_num; i++)
	{
		struct Argument a = temp.arguments[i];
		string a_name = args[i];
		if ("integer" == type_of(a_name))
		{
			if (("integer" != a.type && "real" != a.type) || a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "   wrong type of parameter: " << a_name << endl;
				return;
			}
			table t(a.name, a.type, a_name);
			semantics::stack_st.insert_table(t);
		}
		else if ("real" == type_of(a_name))
		{
			if ("real" != a.type || a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "   wrong type of parameter: " << a_name << endl;
				return;
			}
			table t(a.name, a.type, a_name);
			semantics::stack_st.insert_table(t);
		}
		else
		{
			/* 传进来的是变量 */
			if (!a.pass_value)
			{
				/* 传值参数，需要新建符号表 */
				table &temp2 = semantics::stack_st.locate_table(a_name);
				if ("err" == temp2.type || temp2.is_arg)
				{
					cout << "line:" << ctx->getStart()->getLine() << "   variable not declared: " << a_name << endl;
					return;
				}
				table t(a.name, a.type, temp2.value);
				semantics::stack_st.insert_table(t);
				for (int m = semantics::exp_value.size() - 1; m >= 0; m--)
				{
					cout << semantics::exp_value[m] << endl
						 << endl;
				}
			}
			else if (a.pass_value)
			{
				/* 引用，需要获取真正的符号的位置 */
				table &temp2 = semantics::stack_st.locate_table(a_name);
				if ("err" == temp2.type || temp2.is_arg)
				{
					cout << "line:" << ctx->getStart()->getLine() << "   variable not declared: " << a_name << endl;
					return;
				}
				vector<table> temp_symbol = semantics::stack_st.get_symbol_table();
				for (int j = temp_symbol.size() - 1; j >= 0; j--)
				{
					if (temp_symbol[j].name == a_name)
					{
						temp.arguments[i].location = j;
						break;
					}
				}
			}
		}
	}
	/* 调用子函数 */
	semanticsListener listener;
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, temp.ctx);
	semantics::exp_type.push_back(temp.type);
	semantics::exp_value.push_back(temp.value);
	// temp.value="";
	semantics::stack_st.pop_table();
}