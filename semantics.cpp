#include "semantics.hpp"
//#include "SymbolTable.hpp"
#include "check.hpp"
#include <assert.h>
#include <stack>
namespace semantics
{
	int is_if;
	vector<int> condition;	   //根据if条件设置该变量
	vector<int> cur_condition; //通过比较该值和上面的值判断是否修改执行栈的动作
	vector<llvm::BasicBlock *> block;
	int is_while;
	int iscall;			  //为1时处于调用阶段，constantid不入栈
	int depth;			  // 记录语义层次，只有为0时才做语义动作
	int type_declaration; // 若该值为1，则表示当前处于type字段的record中，此时进入var_declaration不进行语义动作
	int var_record;		  // 若该值为1，说明当前正在var字段的record中，此时进入var_declaration会将数据保存到栈顶符号(必是一个record型变量)的数据域中
	// int var_para;//若该值为1，说明当前节点的父节点是
	SymbolTable stack_st;						// 开始语义分析之前，创建栈式符号表
	std::unique_ptr<llvm::LLVMContext> context; // llvm需要用的context智能指针
	std::unique_ptr<llvm::Module> mod;			// 同上
	std::unique_ptr<llvm::IRBuilder<>> builder;
	llvm::TargetMachine *theTargetMachine;
	vector<string> exp_type;
	vector<string> exp_value;		  // 该值仅是给人和符号表看的，在计算时不要用直接用这里的值
	vector<llvm::Value *> llvm_value; // llvm_value 保存 llvm 形式的值，当需要值的时候，可以取出来；保存时，可能需要用到 CreateLoad 等 api
	vector<int> index;				  //存放数组下标
	int is_assign;					  //为1时表示数组或记录在赋值号左侧，为2时表示在赋值号右侧
	int cur_range;					  //当前数组的维度
	vector<int> arr_index;			  //保存数组的下标
	int arr_or_rec;					  // 0表示都不是，1表示是数组，2表示记录
	string id;						  //当数组和记录在右侧时，保存他们的名字
	string record_id;				  //记录内元素的名字
	int id_varparts_num;			  //记录当前是否是数组访问的最后一维
	vector<string> r_type;
	bool pass;			  //为1时是引用传参
	bool is_array_access; //为true时表示当前数字或字符是数组下标，不需要入exp_value的栈

	// struct record_elements r_ele;

}
void semanticsListener::enterProgram(PascalSParser::ProgramContext *ctx)
{
	// 初始化命名空间的相关数据
	semantics::depth = 0;
	semantics::iscall = 0;
	semantics::type_declaration = 0;
	semantics::var_record = 0;
	semantics::is_assign = 0;
	semantics::index.push_back(0);
	semantics::cur_range = 0;
	semantics::pass = false;
	semantics::id_varparts_num = 0;
	semantics::is_array_access = false;
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
	// auto theTargetMachine = target->createTargetMachine(targetTriple, cpu, features, options, relocationModel);
	semantics::theTargetMachine = target->createTargetMachine(targetTriple, cpu, features, options, relocationModel);
	// semantics::mod->setDataLayout(theTargetMachine->createDataLayout());
	semantics::mod->setDataLayout(semantics::theTargetMachine->createDataLayout());
	// 创建 printf 函数
	llvm::SmallVector<llvm::Type *, 1> args;
	args.push_back(llvm::Type::getInt8PtrTy(*semantics::context));
	auto printfType = llvm::FunctionType::get(llvm::Type::getInt32Ty(*semantics::context), args, true);
	auto printfFunction = llvm::Function::Create(printfType, llvm::Function::ExternalLinkage, "printf", semantics::mod.get());
	// 创建 scanf 函数
	llvm::SmallVector<llvm::Type *, 1> args_out;
	args_out.push_back(llvm::Type::getInt8PtrTy(*semantics::context));
	auto scanfType = llvm::FunctionType::get(llvm::Type::getInt32Ty(*semantics::context), args_out, true);
	auto scanfFunction = llvm::Function::Create(scanfType, llvm::Function::ExternalLinkage, "scanf", semantics::mod.get());
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
	
	// 测试
	/*
	auto float_value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), 11.11);
	print_value("float(11.11): %lf\n", float_value);
	auto double_value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), 22.22);
	print_value("double(22.22): %lf\n", double_value);
	auto char_value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), 'a');
	print_value("char('a'): %c\n", char_value);
	auto int_value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 32);
	print_value("integer(32): %d\n", int_value);
	*/
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
		symbol.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
		// 获取浮点值
		auto value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), atof(const_value.c_str()));

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
				symbol.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
				llvm::Constant *value;
				if ('-' == const_value[0])
					value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), -atof(target_symbol.value.c_str()));
				else
					value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), atof(target_symbol.value.c_str()));
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

			table &symbol = semantics::stack_st.get_top_table();
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
				element.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
				auto value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), 0.0);
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
					element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getDoubleTy(*semantics::context), range), nullptr));
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

			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
			auto value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), 0.0);

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
				symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getDoubleTy(*semantics::context), range), nullptr));
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
	semantics::builder->CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0));

	// 输出汇编文件
	std::error_code errorCode;
	std::string filename = ".tmp.main.s"; // 汇编文件名
	llvm::raw_fd_ostream dest(filename, errorCode, llvm::sys::fs::OF_None);
	llvm::legacy::PassManager pass;
	llvm::CodeGenFileType type = llvm::CGFT_AssemblyFile; // 文件类型为汇编
	// llvm::CodeGenFileType type = llvm::CGFT_ObjectFile;  // 文件类型为可执行文件
	semantics::theTargetMachine->addPassesToEmitFile(pass, dest, nullptr, type);
	pass.run(*semantics::mod);
	dest.flush();

	semantics::mod->print(llvm::outs(), nullptr); // 打印ir
}

void semanticsListener::exitProgram_body(PascalSParser::Program_bodyContext *ctx)
{
	// semantics::stack_st.pint_table();
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
	string name = ctx->ID()->getText(); /*
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
				semantics::exp_value.pop_back();
				semantics::llvm_value.pop_back();
				return;
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

						semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					}
					else if ("real" == temp.type)
					{
						semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					}
					temp.value = semantics::exp_value.back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					}
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("real" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
					}
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{

					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					temp.value = semantics::exp_value.back();
				}
				semantics::llvm_value.pop_back();
				semantics::exp_type.pop_back();
				semantics::exp_value.pop_back();
			}
		}
		/* 函数返回值的赋值 */
		else if (temp.is_func && temp.name == var_name)
		{

			/* cout<<"TEMP: "<<temp.name<<"  TYPE: "<<temp.type<<endl;
			cout<<"FUNCTION "<<semantics::exp_type.size()<<endl;
			cout<<"TYPE: "<<semantics::exp_type.back()<<"  VALUE: "<<semantics::exp_value.back()<<endl; */
			if (temp.type != semantics::exp_type.back() && !("real" == temp.type && "integer" == semantics::exp_type.back()))
			{
				cout << "Line:" << ctx->variable()->getStart()->getLine() << "    Cannot assign values to variables of different types" << endl;
				semantics::exp_type.pop_back();
				semantics::exp_value.pop_back();
				semantics::llvm_value.pop_back();
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
						// int integer = atoi(semantics::exp_value.back().c_str());
						// cout<<"int:"<<integer<<endl;
						// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
						semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					}
					else if ("real" == temp.type)
					{
						// int integer = atoi(semantics::exp_value.back().c_str());
						// auto value = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), integer);
						semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					}
					temp.value = semantics::exp_value.back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					}
					// char ch = atoi(semantics::exp_value.back().c_str());
					// cout << "ch:" << ch << endl;
					// auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("real" == semantics::exp_type.back())
				{
					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
					}
					// double real = atof(semantics::exp_value.back().c_str());
					// auto value = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					temp.value = semantics::exp_value.back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{

					if (NULL == temp.all)
					{
						temp.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp.all);
					temp.value = semantics::exp_value.back();
				}

				semantics::exp_type.pop_back();
				semantics::exp_value.pop_back();
				semantics::llvm_value.pop_back();
			}
		}
		/* 函数参数的赋值,指引用，因为传值的参数会建立新的符号表，当作变量赋值即可 */
		else if (temp.is_arg)
		{
			temp.is_arg = false;
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
				cout << "Line:" << ctx->variable()->getStart()->getLine() << "    Cannot assign values to variables of different types:" << loc << endl;
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
						// int integer = atoi(semantics::exp_value.back().c_str());
						// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
						semantics::builder->CreateStore(semantics::llvm_value.back(), temp2.all);
					}
					else if ("real" == temp2.type)
					{
						// int integer = atoi(semantics::exp_value.back().c_str());
						// auto value = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), integer);
						semantics::builder->CreateStore(semantics::llvm_value.back(), temp2.all);
					}

					/* int integer = atoi(semantics::exp_value.back().c_str());
					auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
					semantics::builder->CreateStore(value, temp.all); */
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
					semantics::llvm_value.pop_back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					if (NULL == temp2.all)
					{
						temp2.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					}
					// char ch = atoi(semantics::exp_value.back().c_str());
					// cout << "ch:" << ch << endl;
					// auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp2.all);
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
					semantics::llvm_value.pop_back();
				}
				else if ("real" == semantics::exp_type.back())
				{
					if (NULL == temp2.all)
					{
						temp2.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
					}
					// double real = atof(semantics::exp_value.back().c_str());
					// auto value = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp2.all);
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
					semantics::llvm_value.pop_back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{
					if (NULL == temp2.all)
					{
						temp2.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					}
					// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					semantics::builder->CreateStore(semantics::llvm_value.back(), temp2.all);
					temp2.value = semantics::exp_value.back();
					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
					semantics::llvm_value.pop_back();
				}
			}
			semantics::cur_range = 0;

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
					periods.push_back(0);
				}
				list = list.substr(i + 1, list.size());
				i = list.find(',');
			}
			int len;
			llvm::Value *Len;
			// 不论数组有几维，llvm_value的栈顶一定是右值
			/* 数组只有一维 */
			if (1 == periods.size())
			{
				// print_value("value is : ", semantics::llvm_value[semantics::llvm_value.size() - 2]);
				// 一维数组中，llvm_value中从栈顶往下有2个可用值，分别是右值和左值
				Len = semantics::builder->CreateSub(semantics::llvm_value[semantics::llvm_value.size() - 2], llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[0].first));
				len = periods[0] - temp.range[0].first;
				// semantics::llvm_value.pop_back();
			}
			else
			{
				/* 多维数组 */
				int dep = temp.range.size() - 1;
				auto Dep = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range.size() - 1);
				int end = periods[dep - 1];
				auto End = semantics::llvm_value[semantics::llvm_value.size() - 2];     // 这是左值数组的从右往左的第一维
                auto End1 = semantics::llvm_value[semantics::llvm_value.size() - 3];    // 这是左值数组的从右往左的第二维

				auto templen = semantics::builder->CreateSub(End, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[dep].first));
				len = periods[dep] - temp.range[dep].first;

				auto Left = semantics::builder->CreateSub(End1, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[dep - 1].first)); //(end - temp.range[dep - 1].first)
				auto Right = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[dep].second);										 // temp.range[dep].second
				auto mul = semantics::builder->CreateMul(Left, Right);
				Len = semantics::builder->CreateAdd(templen, mul);
				len += (end - temp.range[dep - 1].first) * temp.range[dep].second;
			}
			int wid = 1;
			llvm::Value *Wid = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 1);
			int location = temp.range.size() - 3;
			while (location >= 0)
			{
				for (int i = temp.range.size() - 1; i > location; i--)
				{
					auto tempwid = Wid;
					Wid = semantics::builder->CreateMul(tempwid, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[i].second));
					wid *= temp.range[i].second;
				}
				auto offset = semantics::builder->CreateSub(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), periods[location]), llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context),temp.range[location].first));    // offset 是当前这一维的偏移量
				auto cur_offset = semantics::builder->CreateMul(offset, Wid);   // cur_offset 是当前这一维的起点在总空间中的偏移
				auto templen = Len;
				Len = semantics::builder->CreateAdd(cur_offset, templen);
				// auto templen = Len;
				// Len = semantics::builder->CreateAdd(Wid, templen);
				len += wid; // 这个 len 的计算目前是错误的，待修改
				wid = 1;
				Wid = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 1);
				location--;
				// semantics::llvm_value.pop_back();
			}
			
			if (temp.type != semantics::exp_type.back() && !("real" == temp.type && "integer" == semantics::exp_type.back()))
			{
				cout << "Line:" << ctx->variable()->getStart()->getLine() << "    Cannot assign values to variables of different types" << endl;
			}
			else
			{

				if ("integer" == semantics::exp_type.back())
				{

					/* real型可以兼容integer */
					if ("integer" == temp.type)
					{
						std::cout << "Line: " << ctx->getStart()->getLine() << " is integer and integer" << std::endl;
						std::cout << "len: " << len << std::endl;
						// int integer = atoi(semantics::exp_value.back().c_str());
						// cout<<"int:"<<integer<<endl;
						// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
						auto index0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
						auto index_end = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);

						auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, Len});
						semantics::builder->CreateStore(semantics::llvm_value.back(), addr0);
					}
					else if ("real" == temp.type)
					{
						// int integer = atoi(semantics::exp_value.back().c_str());
						// auto value = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), integer);
						auto index0 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), 0);
						auto index_end = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), len);
						auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getDoubleTy(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, Len});
						semantics::builder->CreateStore(semantics::llvm_value.back(), addr0);
					}
					temp.arr_val[len] = semantics::exp_value.back();
				}
				else if ("char" == semantics::exp_type.back())
				{
					// char ch = atoi(semantics::exp_value.back().c_str());
					//  cout << "ch:" << ch << endl;
					// auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					auto index0 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), 0);
					auto index_end = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), len);
					auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt8Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, Len});
					semantics::builder->CreateStore(semantics::llvm_value.back(), addr0);
					temp.arr_val[len] = semantics::exp_value.back();
				}
				else if ("real" == semantics::exp_type.back())
				{

					auto index0 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), 0);
					auto index_end = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), len);
					auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getDoubleTy(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, Len});
					semantics::builder->CreateStore(semantics::llvm_value.back(), addr0);
					temp.arr_val[len] = semantics::exp_value.back();
				}
				else if ("boolean" == semantics::exp_type.back())
				{

					// cout<<"int:"<<integer<<endl;
					// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
					auto index0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
					auto index_end = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
					auto addr0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index0, Len});
					semantics::builder->CreateStore(semantics::llvm_value.back(), addr0);
					temp.arr_val[len] = semantics::exp_value.back();
				}

			}
			for(int i = 0; i <= periods.size(); i++)
			{
				// 每一个维度，都对应了栈中一个值。且栈顶是右值，所以要多出一遍
				semantics::exp_type.pop_back();
                semantics::exp_value.pop_back();
                semantics::llvm_value.pop_back();
			} 
		}
		else if (temp.is_record)
		{
			/* 记录型变量 */
			struct record_elements &r_ele = temp.records[semantics::record_id];
			if (!r_ele.is_array)
			{
				/* 内容不是数组 */
				if (r_ele.type != semantics::exp_type.back() && !("real" == r_ele.type && "integer" == semantics::exp_type.back()))
				{
					cout << "Line:" << ctx->variable()->getStart()->getLine() << "    Cannot assign values to variables of different types" << endl;
					semantics::exp_type.pop_back();
					semantics::exp_type.pop_back();
					semantics::llvm_value.pop_back();
					return;
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
							// int integer = atoi(semantics::exp_value.back().c_str());
							//  cout<<"int:"<<integer<<endl;
							// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
							semantics::builder->CreateStore(semantics::llvm_value.back(), r_ele.all);
						}
						else if ("real" == r_ele.type)
						{
							// int integer = atoi(semantics::exp_value.back().c_str());
							// auto value = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), integer);
							semantics::builder->CreateStore(semantics::llvm_value.back(), r_ele.all);
						}
						r_ele.value = semantics::exp_value.back();
					}
					else if ("char" == semantics::exp_type.back())
					{
						if (NULL == r_ele.all)
						{
							r_ele.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
						}
						// char ch = atoi(semantics::exp_value.back().c_str());
						//  cout << "ch:" << ch << endl;
						// auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
						semantics::builder->CreateStore(semantics::llvm_value.back(), r_ele.all);
						r_ele.value = semantics::exp_value.back();
					}
					else if ("real" == semantics::exp_type.back())
					{
						if (NULL == r_ele.all)
						{
							r_ele.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
						}
						double real = atof(semantics::exp_value.back().c_str());
						auto value = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
						semantics::builder->CreateStore(semantics::llvm_value.back(), r_ele.all);
						r_ele.value = semantics::exp_value.back();
					}
					else if ("boolean" == semantics::exp_type.back())
					{

						if (NULL == r_ele.all)
						{
							r_ele.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
						}
						// auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), b);
						semantics::builder->CreateStore(semantics::llvm_value.back(), r_ele.all);
						r_ele.value = semantics::exp_value.back();
					}

					semantics::exp_type.pop_back();
					semantics::exp_value.pop_back();
					semantics::llvm_value.pop_back();
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
	llvm::Value *right_llvm = semantics::llvm_value.back();
	string right_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::llvm_value.pop_back();
	semantics::exp_type.pop_back();

	string left = semantics::exp_value.back();
	llvm::Value *left_llvm = semantics::llvm_value.back();
	string left_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::llvm_value.pop_back();
	semantics::exp_type.pop_back();

	if ("+" == addop)
	{
		/* 加法 */
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
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
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(right.c_str()));

			auto v = semantics::builder->CreateFAdd(left_llvm, right_llvm);
			double r = atof(left.c_str()) + atof(right.c_str());
			/* ostringstream os;
			os << r; */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
		}
		else if ("integer" == right_type && "integer" == left_type)
		{
			semantics::exp_type.push_back("integer");
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			auto v = semantics::builder->CreateAdd(left_llvm, right_llvm);
			int r = atoi(right.c_str()) + atoi(left.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
		}
	}
	else if ("-" == addop)
	{
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
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
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(right.c_str()));

			auto v = semantics::builder->CreateFSub(left_llvm, right_llvm);
			double r = atof(left.c_str()) - atof(right.c_str());
			/* ostringstream os;
			os << r; */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
		}
		else if ("integer" == right_type && "integer" == left_type)
		{
			semantics::exp_type.push_back("integer");
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			auto v = semantics::builder->CreateSub(left_llvm, right_llvm);
			int r = atoi(left.c_str()) - atoi(right.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
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
	llvm::Value *right_llvm = semantics::llvm_value.back();
	string right_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::llvm_value.pop_back();
	semantics::exp_type.pop_back();

	string left = semantics::exp_value.back();
	llvm::Value *left_llvm = semantics::llvm_value.back();
	string left_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::llvm_value.pop_back();
	semantics::exp_type.pop_back();

	if ("*" == mulop)
	{
		/* 乘法 */
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
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
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(right.c_str()));

			auto v = semantics::builder->CreateFMul(left_llvm, right_llvm);
			double r = atof(left.c_str()) * atof(right.c_str());
			/* ostringstream os;
			os << r; */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
		}
		else if ("integer" == right_type && "integer" == left_type)
		{
			semantics::exp_type.push_back("integer");
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			auto v = semantics::builder->CreateMul(left_llvm, right_llvm);
			int r = atoi(right.c_str()) * atoi(left.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
		}
	}
	else if ("/" == mulop)
	{
		/* 取商除法 */
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
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
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			auto v = semantics::builder->CreateSDiv(left_llvm, right_llvm);
			int r = atoi(left.c_str()) / atoi(right.c_str());
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
		}
		else if ("real" == right_type || "real" == left_type)
		{
			semantics::exp_type.push_back("real");
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), atof(right.c_str()));

			auto v = semantics::builder->CreateFDiv(left_llvm, right_llvm);
			// semantics::builder->CreateMod(value1, value2);
			double r = atof(left.c_str()) / atof(right.c_str());
			r = r / 1.0;
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
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
			// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(left.c_str()));
			// auto value2 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(right.c_str()));

			auto v = semantics::builder->CreateSRem(left_llvm, right_llvm);
			int r = atoi(left.c_str()) % atoi(right.c_str());
			/* ostringstream os;
			os << r;
			string result(os.str()); */
			string result = to_string(r);
			semantics::exp_value.push_back(result);
			semantics::llvm_value.push_back(v);
		}
	}
}
void semanticsListener::exitUnsignConstId(PascalSParser::UnsignConstIdContext *ctx)
{
	if (semantics::depth != 0)
		return;
	if (1 == semantics::iscall)
		return;
	string id = ctx->ID()->getText();
	if ("true" == id || "false" == id)
	{

		semantics::exp_type.push_back("boolean");
		// cout << "boolennn\n";
		if ("true" == id)
		{
			// 如果以true为标识符，可以获取int值1
			auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 1);
			semantics::llvm_value.push_back(value);
			semantics::exp_value.push_back("1");
		}
		else
		{
			auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
			semantics::llvm_value.push_back(value);
			semantics::exp_value.push_back("1");
		}
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
			temp.is_arg = false;
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
				semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), temp2.all));
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
			semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), temp.all));
			semantics::exp_type.push_back(temp.type);
			semantics::exp_value.push_back(temp.value);
		}

		else if (!temp.is_func && !temp.is_proc)
		{
			/* 变量 */
			if ("" == temp.value)
			{
				/* cout << "line: " << ctx->getStart()->getLine() << "    Variable has no value!\n";
				return; */
			}
			else
			{
				// cout << "value:" << temp.value << endl;
				semantics::exp_type.push_back(temp.type);
				semantics::exp_value.push_back(temp.value);
				if ("integer" == temp.type || "boolean" == temp.type)
				{
					semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), temp.all));
				}
				else if ("real" == temp.type)
				{
					semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), temp.all));
				}
				else if ("char" == temp.type)
				{
					semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), temp.all));
				}
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
	if (semantics::depth != 0 || 1 == semantics::iscall)
		return;

	string number = ctx->NUMBER()->getText();
	semantics::exp_value.push_back(number);
	// cout<<"Hii"
	if (number.find('.') != string::npos)
	{
		// cout << "real\n";
		semantics::exp_type.push_back("real");
		float value = atof(number.c_str());
		semantics::llvm_value.push_back(llvm::ConstantFP::get(llvm::Type::getDoubleTy(*semantics::context), value));
	}
	else
	{
		semantics::exp_type.push_back("integer");
		int value = atoi(number.c_str());
		semantics::llvm_value.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), value));
	}
}

void semanticsListener::exitUnsignConstChar(PascalSParser::UnsignConstCharContext *ctx)
{
	if (semantics::depth != 0 || 1 == semantics::iscall)
		return;

	semantics::exp_value.push_back(ctx->CONST_CHAR()->getText());
	semantics::exp_type.push_back("char");
	semantics::llvm_value.push_back(llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ctx->CONST_CHAR()->getText()[1]));
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
		semantics::llvm_value.pop_back();
		semantics::llvm_value.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), var));
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
	table &temp = semantics::stack_st.locate_table(semantics::id);
	string ran = ctx->expression_list()->getText();
	/* if (ran.find('.') != string::npos)
	{
		cout << "NOPS: " << ran << endl;
		return;
	}
 */
	semantics::is_array_access = true;
	semantics::cur_range++;
	if (!temp.is_array)
	{
		cout << "line: " << ctx->getStart()->getLine() << "    This variable isn't an array" << endl;
		return;
	}
	pair<int, int> r = temp.range[semantics::cur_range - 1];
	semantics::r_type = temp.range_type;

	// cout<<"ran:"<<ran<<endl;
	//  cout<<"tt:"<<type_of(ran)<<endl;
	// cout<<semantics::r_type.size()<<endl;
	if (type_of(ran.c_str()) != semantics::r_type[semantics::cur_range - 1]&&!("id"==type_of(ran.c_str())))
	{

		cout << "line: " << ctx->getStart()->getLine() << "   Illegal access to array" << endl;
		return;
	}
	/* if ("integer" == type_of(ran.c_str()))
	{
		if (r.first > atoi(ran.c_str()) || r.second < (atoi(ran.c_str()) - r.first) || "integer" != semantics::r_type[semantics::cur_range - 1])
		{
			cout << "line: " << ctx->getStart()->getLine() << "   Illegal access to array" << endl;
			return;
		}
		else
		{


		}
	}
	if ("char" == type_of(ran.c_str()))
	{
		if (r.first > ran[0] || r.second < (int(ran[0]) - r.first))
		{
			cout << "line: " << ctx->getStart()->getLine() << " 3.0  Illegal access to array" << endl;
			return;
		}
	} */

	// cout<<"array here"<<endl
}
void semanticsListener::exitArrayAccess(PascalSParser::ArrayAccessContext *ctx)
{
	if (semantics::depth != 0)
		return;
	/* 检查数组下标是否合法 */
	semantics::is_array_access = false;
}
void semanticsListener::enterId_varparts(PascalSParser::Id_varpartsContext *ctx)
{
	if (semantics::depth != 0)
		return;
	table &temp = semantics::stack_st.locate_table(semantics::id);
	if (!temp.is_array || 1 == semantics::iscall)
		return;
	semantics::id_varparts_num++;
	// cout << "now: " << semantics::id_varparts_num << endl;
}
/* 处理完一个数组，初始化数据 */
void semanticsListener::exitId_varparts(PascalSParser::Id_varpartsContext *ctx)
{
	if (semantics::depth != 0 || 1 == semantics::iscall)
		return;
	table &temp = semantics::stack_st.locate_table(semantics::id);
	/* if (temp.name == ctx->parent->children[0]->getText())
		semantics::cur_range = 0; */
	if (!temp.is_array)
		return;
	semantics::id_varparts_num--;
	int ran = semantics::cur_range;
	if (0 == semantics::id_varparts_num)
	{
		semantics::cur_range = 0;
	}
	if (0 != semantics::id_varparts_num || 1 == semantics::is_assign)
		return;
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
				periods.push_back(0);
			}
			list = list.substr(i + 1, list.size());
			i = list.find(',');
		}

		int len;
		llvm::Value *Len;
		/* 数组只有一维 */
		if (1 == periods.size())
		{
			Len = semantics::builder->CreateSub(semantics::llvm_value.back(), llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[0].first));
			len = periods[0] - temp.range[0].first;
			semantics::llvm_value.pop_back();
		}
		else
		{
			/* 多维数组 */
			int dep = temp.range.size() - 1;
			auto Dep = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range.size() - 1);
			int end = periods[dep - 1];
			auto End = semantics::llvm_value.back();							 // periods[dep]
			auto End1 = semantics::llvm_value[semantics::llvm_value.size() - 2]; // end

			auto templen = semantics::builder->CreateSub(End, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[dep].first));
			len = periods[dep] - temp.range[dep].first + 1;

			auto Left = semantics::builder->CreateSub(End1, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[dep - 1].first)); //(end - temp.range[dep - 1].first)
			auto Right = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[dep].second);										 // temp.range[dep].second
			auto mul = semantics::builder->CreateMul(Left, Right);
			Len = semantics::builder->CreateAdd(templen, mul);
			len += (end - temp.range[dep - 1].first) * temp.range[dep].second;
			semantics::llvm_value.pop_back();
			semantics::llvm_value.pop_back();
		}
		int wid = 1; 
		llvm::Value *Wid = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 1);	// Wid 是右边所有维的总宽度
		int location = temp.range.size() - 3;
		while (location >= 0)
		{
			for (int i = temp.range.size() - 1; i > location; i--)
			{
				auto tempwid = Wid;
				Wid = semantics::builder->CreateMul(tempwid, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[i].second));
				wid *= temp.range[i].second;
			}
			auto offset = semantics::builder->CreateSub(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), periods[location]), llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), temp.range[location].first));	// offset 是当前这一维的偏移量
			auto cur_offset = semantics::builder->CreateMul(offset, Wid);	// cur_offset 是当前这一维的起点在总空间中的偏移
			auto templen = Len;
            Len = semantics::builder->CreateAdd(cur_offset, templen);
			len += wid;				// 这个 len 的计算目前是错误的，待修改
			wid = 1;
			Wid = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 1);
			location--;
			semantics::llvm_value.pop_back();
		}

		/* if ("" == temp.arr_val[len])
		{
			cout << "line: " << ctx->getStart()->getLine() << "    The elements has no value" << endl;
			return;
		} */
		// cout<<"value: "<<temp.arr_val[len]<<endl;

		semantics::exp_type.push_back(temp.type);
		semantics::exp_value.push_back(temp.arr_val[len]);

		auto index_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
		auto index_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
		auto addr_11 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index_0, Len});
		auto value = semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), addr_11);
		semantics::llvm_value.push_back(value);
		semantics::r_type.clear();
		semantics::cur_range = 0;
	}
}
void semanticsListener::enterRecordAccess(PascalSParser::RecordAccessContext *ctx)
{
	if (semantics::depth != 0 || 1 == semantics::iscall)
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
			semantics::llvm_value.push_back(re.all);
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
	llvm::Value *llvm_v = semantics::llvm_value.back();
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
		auto llvm_zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
		auto value = semantics::builder->CreateSub(llvm_zero, llvm_v);
		semantics::llvm_value.pop_back();
		semantics::llvm_value.push_back(value);
	}
	else if ("real" == t)
	{
		double real = atoi(v.c_str());
		real = -real;
		string r = to_string(real);
		semantics::exp_value.pop_back();
		semantics::exp_value.push_back(r);
		auto llvm_zero = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), 0.0);
		auto value = semantics::builder->CreateSub(llvm_zero, llvm_v);
		semantics::llvm_value.pop_back();
		semantics::llvm_value.push_back(value);
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
	semantics::iscall = 1;
}
void semanticsListener::exitCallWithPara(PascalSParser::CallWithParaContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::iscall = 0;
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
		if (a_name.find('.') != string::npos)
		{
			/* 传的是结构体元素 */
			int i = a_name.find('.');
			string record_id = a_name.substr(0, i);
			string ele_id = a_name.substr(i + 1, a_name.size());
			table &temp = semantics::stack_st.locate_table(record_id);
			if ("err" == temp.type)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    no declaration of record:" << temp.name << endl;
				return;
			}
			if (temp.records.find(ele_id) == temp.records.end())
			{
				cout << "line:" << ctx->getStart()->getLine() << "    records doesn't has this element" << endl;
				return;
			}
			struct record_elements re = temp.records[ele_id];
			if (a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    struct elements cannot be passed by reference" << endl;
				return;
			}
			if (a.type != re.type && !("real" == a.type && "integer" == re.type))
			{
				cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
				return;
			}
			table t(a.name, a.type, re.value);
			if ("real" == a.type)
			{
				double real = atof(re.value.c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), re.all), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("integer" == a.type || "boolean" == a.type)
			{
				int integer = atoi(re.value.c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), re.all), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("char" == a.type)
			{
				char ch = re.value[0];
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), re.all), t.all);
				semantics::stack_st.insert_table(t);
			}
			else
			{
				cout << "line:" << ctx->getStart()->getLine() << "    program error at callwithpara" << endl;
				return;
			}
		}
		else if (a_name.find('[') != string::npos || a_name.find(']') != string::npos)
		{
			/* 传递数组元素 */
			int i = a_name.find("[");
			string array_id = a_name.substr(0, i);
			string list = a_name.substr(i, a_name.size());
			table &temp = semantics::stack_st.locate_table(array_id);
			if ("err" == temp.type)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    no decalration of variable:" << array_id << endl;
				return;
			}
			if (a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    array elements cannot be passed by reference" << endl;
				return;
			}
			if (!temp.is_array)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    this variable isn't an array" << endl;
				return;
			}
			vector<int> periods;
			i = list.find('[');
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
				/* cout << "line: " << ctx->getStart()->getLine() << "    The elements has no value" << endl;
				return; */
			}
			table t(a.name, a.type, temp.arr_val[len]);
			if ("real" == a.type)
			{
				auto index_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				auto index_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
				auto addr_0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getDoubleTy(*semantics::context), temp.arr_len), temp.all_item.back(), {index_0, index_0});
				double real = atof(temp.arr_val[len].c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), addr_0), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("integer" == a.type || "boolean" == a.type)
			{
				auto index_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				auto index_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
				auto addr_0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index_0, index_0});
				int integer = atoi(temp.arr_val[len].c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), addr_0), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("char" == a.type)
			{
				auto index_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				auto index_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
				auto addr_0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt8Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index_0, index_0});
				char ch = temp.arr_val[len][0];
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), addr_0), t.all);
				semantics::stack_st.insert_table(t);
			}
			else
			{
				cout << "line:" << ctx->getStart()->getLine() << "    program error at callwithpara" << endl;
				return;
			}
		}
		else if ("integer" == type_of(a_name))
		{
			if (("integer" != a.type && "real" != a.type) || a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "   wrong type of parameter: " << a_name << endl;
				return;
			}
			table t(a.name, a.type, a_name);

			int integer = atoi(a_name.c_str());
			t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
			semantics::builder->CreateStore(value1, t.all);
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
			double real = atof(a_name.c_str());
			t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
			auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
			semantics::builder->CreateStore(value1, t.all);
			semantics::stack_st.insert_table(t);
		}
		else if ("char" == type_of(a_name))
		{
			table t(a.name, a.type, a_name);
			char ch = a_name[0];
			t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
			semantics::builder->CreateStore(value1, t.all);
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
				if (temp2.type != a.type)
				{

					cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
					return;
				}
				table t(a.name, a.type, temp2.value);
				if ("integer" == a.type || "boolean" == a.type)
				{
					int integer = atoi(a_name.c_str());
					t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
					semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), temp2.all), t.all);
				}
				else if ("real" == a.type)
				{
					double real = atof(a_name.c_str());
					t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
					// auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
					semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), temp2.all), t.all);
				}
				else if ("char" == a.type)
				{
					char ch = a_name[0];
					t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), temp2.all), t.all);
				}
				else
				{
					cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
					return;
				}
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
				if (temp2.type != a.type)
				{
					cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
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
	semantics::iscall = 1;
}
void semanticsListener::exitFactorReturn(PascalSParser::FactorReturnContext *ctx)
{
	if (semantics::depth != 0)
		return;
	semantics::iscall = 0;
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
		if (a_name.find('.') != string::npos)
		{
			/* 传的是结构体元素 */
			int i = a_name.find('.');
			string record_id = a_name.substr(0, i);
			string ele_id = a_name.substr(i + 1, a_name.size());
			table &temp = semantics::stack_st.locate_table(record_id);
			if ("err" == temp.type)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    no declaration of record:" << temp.name << endl;
				return;
			}
			if (temp.records.find(ele_id) == temp.records.end())
			{
				cout << "line:" << ctx->getStart()->getLine() << "    records doesn't has this element" << endl;
				return;
			}
			struct record_elements re = temp.records[ele_id];
			if (a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    struct elements cannot be passed by reference" << endl;
				return;
			}
			if (a.type != re.type && !("real" == a.type && "integer" == re.type))
			{
				cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
				return;
			}
			table t(a.name, a.type, re.value);
			if ("real" == a.type)
			{
				double real = atof(re.value.c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), re.all), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("integer" == a.type || "boolean" == a.type)
			{
				int integer = atoi(re.value.c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), re.all), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("char" == a.type)
			{
				char ch = re.value[0];
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), re.all), t.all);
				semantics::stack_st.insert_table(t);
			}
			else
			{
				cout << "line:" << ctx->getStart()->getLine() << "    program error at callwithpara" << endl;
				return;
			}
		}
		else if (a_name.find('[') != string::npos || a_name.find(']') != string::npos)
		{
			/* 传递数组元素 */
			int i = a_name.find("[");
			string array_id = a_name.substr(0, i);
			string list = a_name.substr(i, a_name.size());
			table &temp = semantics::stack_st.locate_table(array_id);
			if ("err" == temp.type)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    no decalration of variable:" << array_id << endl;
				return;
			}
			if (a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    array elements cannot be passed by reference" << endl;
				return;
			}
			if (!temp.is_array)
			{
				cout << "line:" << ctx->getStart()->getLine() << "    this variable isn't an array" << endl;
				return;
			}
			vector<int> periods;
			i = list.find('[');
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
				/* return; */
			}
			table t(a.name, a.type, temp.arr_val[len]);
			if ("real" == a.type)
			{
				auto index_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				auto index_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
				auto addr_0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getDoubleTy(*semantics::context), temp.arr_len), temp.all_item.back(), {index_0, index_0});
				double real = atof(temp.arr_val[len].c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), addr_0), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("integer" == a.type || "boolean" == a.type)
			{
				auto index_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				auto index_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
				auto addr_0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index_0, index_0});
				int integer = atoi(temp.arr_val[len].c_str());
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), addr_0), t.all);
				semantics::stack_st.insert_table(t);
			}
			else if ("char" == a.type)
			{
				auto index_0 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				auto index_1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), len);
				auto addr_0 = semantics::builder->CreateGEP(llvm::ArrayType::get(llvm::Type::getInt8Ty(*semantics::context), temp.arr_len), temp.all_item.back(), {index_0, index_0});
				char ch = temp.arr_val[len][0];
				t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
				semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), addr_0), t.all);
				semantics::stack_st.insert_table(t);
			}
			else
			{
				cout << "line:" << ctx->getStart()->getLine() << "    program error at callwithpara" << endl;
				return;
			}
		}
		else if ("integer" == type_of(a_name))
		{
			if (("integer" != a.type && "real" != a.type) || a.pass_value)
			{
				cout << "line:" << ctx->getStart()->getLine() << "   wrong type of parameter: " << a_name << endl;
				return;
			}
			table t(a.name, a.type, a_name);

			int integer = atoi(a_name.c_str());
			t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
			semantics::builder->CreateStore(value1, t.all);
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
			double real = atof(a_name.c_str());
			t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
			auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
			semantics::builder->CreateStore(value1, t.all);
			semantics::stack_st.insert_table(t);
		}
		else if ("char" == type_of(a_name))
		{
			table t(a.name, a.type, a_name);
			char ch = a_name[0];
			t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
			auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
			semantics::builder->CreateStore(value1, t.all);
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
				if (temp2.type != a.type)
				{

					cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
					return;
				}
				table t(a.name, a.type, temp2.value);
				if ("integer" == a.type || "boolean" == a.type)
				{
					int integer = atoi(a_name.c_str());
					t.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
					// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), integer);
					semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), temp2.all), t.all);
				}
				else if ("real" == a.type)
				{
					double real = atof(a_name.c_str());
					t.all = semantics::builder->CreateAlloca(llvm::Type::getDoubleTy(*semantics::context), nullptr);
					// auto value1 = llvm::ConstantInt::get(llvm::Type::getDoubleTy(*semantics::context), real);
					semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), temp2.all), t.all);
				}
				else if ("char" == a.type)
				{
					char ch = a_name[0];
					t.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
					// auto value1 = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), ch);
					semantics::builder->CreateStore(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), temp2.all), t.all);
				}
				else
				{
					cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
					return;
				}
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
				if (temp2.type != a.type)
				{
					cout << "line:" << ctx->getStart()->getLine() << "    wrong type of parameter" << endl;
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
	semantics::exp_type.push_back(temp.type);
	semantics::exp_value.push_back(temp.value);
	if ("integer" == temp.type || "boolean" == temp.type)
		semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getInt32Ty(*semantics::context), temp.all));
	else if ("char" == temp.type)
		semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getInt8Ty(*semantics::context), temp.all));
	else if ("real" == temp.type)
		semantics::llvm_value.push_back(semantics::builder->CreateLoad(llvm::Type::getDoubleTy(*semantics::context), temp.all));

	// temp.value="";
	semantics::stack_st.pop_table();
}
void semanticsListener::exitRelationOperation(PascalSParser::RelationOperationContext *ctx)
{
	if (semantics::depth != 0)
		return;
	string relop = ctx->relop()->getText();

	string right = semantics::exp_value.back();
	llvm::Value *right_llvm = semantics::llvm_value.back();
	string right_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::llvm_value.pop_back();
	semantics::exp_type.pop_back();

	string left = semantics::exp_value.back();
	llvm::Value *left_llvm = semantics::llvm_value.back();

	string left_type = semantics::exp_type.back();

	semantics::exp_value.pop_back();
	semantics::llvm_value.pop_back();
	semantics::exp_type.pop_back();
	if ("<" == relop || "<=" == relop)
	{
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot calculate variables of different types" << endl;
			return;
		}
		if ("char" == left_type && "char" == right_type)
		{
			char l = left[0];
			char r = right[0];

			if (l < r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");

				semantics::llvm_value.push_back(semantics::builder->CreateICmpSLT(left_llvm, right_llvm, "<"));
			}
			if (l == r && "<=" == relop)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");

				semantics::llvm_value.push_back(semantics::builder->CreateICmpSLE(left_llvm, right_llvm, "<="));
			}
			if (l == r && "<=" != relop)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");

				semantics::llvm_value.push_back(semantics::builder->CreateICmpSLT(left_llvm, right_llvm, "<"));
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");

				semantics::llvm_value.push_back(semantics::builder->CreateICmpSLT(left_llvm, right_llvm, "<"));
			}
		}
		else if ("integer" == left_type || "real" == left_type || "boolean" == left_type)
		{
			if (("integer" == left_type && "integer" == right_type) || ("boolean" == left_type && "boolean" == right_type))
			{
				int l = atoi(left.c_str());
				int r = atoi(right.c_str());

				if (l < r)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");

					semantics::llvm_value.push_back(semantics::builder->CreateICmpSLT(left_llvm, right_llvm, "<"));
				}
				if (l == r && "<=" == relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");

					semantics::llvm_value.push_back(semantics::builder->CreateICmpSLE(left_llvm, right_llvm, "<="));
				}
				if (l == r && "<=" != relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");

					semantics::llvm_value.push_back(semantics::builder->CreateICmpSLT(left_llvm, right_llvm, "<"));
				}
				else
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");
					auto value = semantics::builder->CreateICmpSLT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
			}
			else if ("real" == left_type || "real" == right_type)
			{
				double l = atof(left.c_str());
				double r = atof(right.c_str());

				if (l < r)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");
					auto value = semantics::builder->CreateFCmpOLT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
				if (l == r && "<=" == relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");
					auto value = semantics::builder->CreateFCmpOLE(left_llvm, right_llvm, "<=");
					semantics::llvm_value.push_back(value);
				}
				if (l == r && "<=" != relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");
					auto value = semantics::builder->CreateFCmpOLT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
				else
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");
					auto value = semantics::builder->CreateFCmpOLT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
			}
		}
	}
	else if (">" == relop || ">=" == relop)
	{
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot calculate variables of different types" << endl;
			return;
		}
		if ("char" == left_type && "char" == right_type)
		{
			char l = left[0];
			char r = right[0];

			if (l < r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateICmpSGT(left_llvm, right_llvm, "<");
				semantics::llvm_value.push_back(value);
			}
			if (l == r && "<=" == relop)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateICmpSGE(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
			if (l == r && "<=" != relop)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateICmpSGT(left_llvm, right_llvm, "<");
				semantics::llvm_value.push_back(value);
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateICmpSGT(left_llvm, right_llvm, "<");
				semantics::llvm_value.push_back(value);
			}
		}
		else if ("integer" == left_type || "real" == left_type || "boolean" == left_type)
		{
			if (("integer" == left_type && "integer" == right_type) || ("boolean" == left_type && "boolean" == right_type))
			{
				int l = atoi(left.c_str());
				int r = atoi(right.c_str());

				if (l < r)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");
					auto value = semantics::builder->CreateICmpSGT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
				if (l == r && "<=" == relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");
					auto value = semantics::builder->CreateICmpSGE(left_llvm, right_llvm, "<=");
					semantics::llvm_value.push_back(value);
				}
				if (l == r && "<=" != relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");
					auto value = semantics::builder->CreateICmpSGT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
				else
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");
					auto value = semantics::builder->CreateICmpSGT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
			}
			else if ("real" == left_type || "real" == right_type)
			{
				double l = atof(left.c_str());
				double r = atof(right.c_str());

				if (l < r)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");
					auto value = semantics::builder->CreateFCmpOGT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
				if (l == r && "<=" == relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("1");
					auto value = semantics::builder->CreateFCmpOGE(left_llvm, right_llvm, "<=");
					semantics::llvm_value.push_back(value);
				}
				if (l == r && "<=" != relop)
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");
					auto value = semantics::builder->CreateFCmpOGT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
				else
				{
					semantics::exp_type.push_back("boolean");
					semantics::exp_value.push_back("0");
					auto value = semantics::builder->CreateFCmpOGT(left_llvm, right_llvm, "<");
					semantics::llvm_value.push_back(value);
				}
			}
		}
	}
	else if ("=" == relop)
	{
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot calculate variables of different types" << endl;
			return;
		}
		if ("char" == left_type && "char" == right_type)
		{
			char l = left[0];
			char r = right[0];
			if (l == r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateICmpEQ(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateICmpEQ(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
		}
		else if (("integer" == left_type && "integer" == right_type) || ("boolean" == left_type && "boolean" == right_type))
		{
			int l = atoi(left.c_str());
			int r = atoi(right.c_str());
			if (l == r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateICmpEQ(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateICmpEQ(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
		}
		else if ("real" == left_type || "real" == right_type)
		{
			double l = atof(left.c_str());
			double r = atof(right.c_str());
			if (l == r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateFCmpOEQ(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateFCmpOEQ(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
		}
	}
	else if ("<>" == relop)
	{
		if (left_type != right_type && !(("integer" == left_type && "real" == right_type) || ("integer" == right_type && "real" == left_type)))
		{
			cout << "line:" << ctx->getStart()->getLine() << "   cannot calculate variables of different types" << endl;
			return;
		}
		if ("char" == left_type && "char" == right_type)
		{
			char l = left[0];
			char r = right[0];
			if (l != r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateICmpNE(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateICmpNE(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
		}
		else if (("integer" == left_type && "integer" == right_type) || ("boolean" == left_type && "boolean" == right_type))
		{
			int l = atoi(left.c_str());
			int r = atoi(right.c_str());
			if (l != r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateICmpNE(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateICmpNE(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
		}
		else if ("real" == left_type || "real" == right_type)
		{
			double l = atof(left.c_str());
			double r = atof(right.c_str());
			if (l != r)
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("1");
				auto value = semantics::builder->CreateFCmpONE(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
			else
			{
				semantics::exp_type.push_back("boolean");
				semantics::exp_value.push_back("0");
				auto value = semantics::builder->CreateFCmpONE(left_llvm, right_llvm, "<=");
				semantics::llvm_value.push_back(value);
			}
		}
	}
}
void semanticsListener::exitCallWriteln(PascalSParser::CallWritelnContext *ctx)
{
	if (semantics::depth != 0)
		return;
	std::string writeln_args = ctx->expression_list()->getText();
	// writeln_args 的参数需要转换成 llvm 的形式，然后传递给 llvm 中保存的 printf 函数
	int args_count = 1; // printf 至少应有一个字符串参数
	std::string printf_format = "";
	// std::cout << "number: " << semantics::exp_value.size() << std::endl;
	writeln_args.erase(0, writeln_args.find_first_not_of(" ")); // 去除前空格
	writeln_args.erase(writeln_args.find_last_not_of(" ") + 1); // 去除后空格
	if ("" == writeln_args)
	{
		// 当 writeln 没有任何参数时，看作输出一个换行 \n
		llvm::SmallVector<llvm::Value *, 1> printf_args;
		llvm::Value *formatStr = semantics::builder->CreateGlobalStringPtr("\n");
		printf_args.push_back(formatStr);
		semantics::builder->CreateCall(semantics::mod->getFunction("printf"), printf_args);
	}
	else
	{
		// 当 writeln 有参数时，需要转换成 printf 的参数
		// 根据每一个参数值构造成 llvm 的形式
		// llvm::SmallVector<llvm::Value*, 1> printf_args;
		std::vector<llvm::Value *> printf_args;
		int split_pos;
		std::string writeln_arg;
		do
		{
			split_pos = writeln_args.find(',');
			writeln_arg = writeln_args.substr(0, split_pos);		  // 提取出每个单独的参数
			writeln_arg.erase(0, writeln_arg.find_first_not_of(" ")); // 去除前空格
			writeln_arg.erase(writeln_arg.find_last_not_of(" ") + 1); // 去除后空格

			// std::cout << writeln_arg << std::endl;
			if ("integer" == type_of(writeln_arg) || "real" == type_of(writeln_arg))
			{
				// 对于数字常量，直接将其视为格式化参数的一部分
				printf_format += writeln_arg;
			}
			else if ("char" == type_of(writeln_arg))
			{
				// 字符型常量也视为格式化参数的一部分
				printf_format += writeln_arg[1];
			}
			else
			{
				// 除了上面三种情况外，当前的参数会被视作为一个表达式
				// 每个表达式会使 printf 的参数增加一个，且表达式结果按序保存在 semantics::exp_value、exp_type、llvm_value 中
				// 首先确认表达式返回的类型，添加至格式化参数中
				if ("integer" == semantics::exp_type[args_count - 1])
				{
					printf_format += "%d";
				}
				else if ("real" == semantics::exp_type[args_count - 1])
				{
					printf_format += "%f";
				}
				else if ("char" == semantics::exp_type[args_count - 1])
				{
					printf_format += "%c";
				}
				// printf_args.push_back(semantics::llvm_value.back());
				args_count++;
			}
			writeln_args = writeln_args.substr(split_pos + 1);
		} while (std::string::npos != split_pos);

		// 将构造好的所有参数入栈
		// 第一个是格式化参数 printf_format
		printf_format += "\n";
		// std::cout << printf_format << std::endl;
		printf_args.push_back(semantics::builder->CreateGlobalStringPtr(printf_format.c_str()));
		// 之后从 semantics::llvm_value 依次取得要入栈的值
		for (int i = 0; i < args_count - 1; i++)
		{
			printf_args.push_back(semantics::llvm_value[i]);
		}

		semantics::llvm_value.clear();
		semantics::exp_value.clear();
		semantics::exp_type.clear();

		semantics::builder->CreateCall(semantics::mod->getFunction("printf"), printf_args);
	}
}

void semanticsListener::exitCallReadln(PascalSParser::CallReadlnContext * ctx)
{
	if (semantics::depth != 0)
        return;

	// std::cout << "number : " << semantics::llvm_value.size() << std::endl;
	llvm::SmallVector<llvm::Value*, 2> scanf_args;
	std::string varparts = ctx->variable()->id_varparts()->getText();
    std::string id = ctx->variable()->ID()->getText();
    if ("" == varparts)
    {
        // 没有 varparts 就说明这只是一个普通的变量名
        table &symbol = semantics::stack_st.locate_table(id);
        if (symbol.is_const || symbol.is_type || symbol.is_record || symbol.is_array || symbol.is_arg)
        {
            // 如果给的符号在符号表中是不可赋值的，输出报错
            std::cerr << ctx->getStart()->getLine() << "Left value is must be modifiable" << std::endl;
        }
        else
        {
            if ("err" == symbol.type)
            {
                std::cerr << "Undefined variable: " << id << std::endl;
                return;
            }
            else if ("integer" == symbol.type || "boolean" == symbol.type)
            {
                // 注意 boolean 型变量的输入也得是整数
                scanf_args.push_back(semantics::builder->CreateGlobalStringPtr("%d"));
            }
            else if ("char" == symbol.type)
            {
                scanf_args.push_back(semantics::builder->CreateGlobalStringPtr("%c"));
            }
            else if ("real" == symbol.type)
            {
                scanf_args.push_back(semantics::builder->CreateGlobalStringPtr("%f"));
            }
            else
            {
                std::cerr << "no support" << std::endl;
                return;
            }
            scanf_args.push_back(symbol.all);
            semantics::builder->CreateCall(semantics::mod->getFunction("scanf"), scanf_args);
        }
    }
	else
    {
        // 若 varparts 不为空，则表示要从数组或者结构体中取值
        if (std::string::npos != varparts.find('[') && std::string::npos != varparts.find('.'))
        {
            // 不能出现结构体和数组的相互嵌套
            std::cerr << "Line " << ctx->getStart()->getLine() << ": Unsupported variable type" << std::endl;
            return;
        }
        else if (std::string::npos != varparts.find('.'))
        {
            // 如果是结构体，就只能是单层的
            if (varparts.find('.') != varparts.rfind('.'))
            {
                std::cerr << "Line " << ctx->getStart()->getLine() << ": Unsupported variable type" << std::endl;
                return;
            }
            else
            {
                // 如果是单层结构体，要给其对应元素赋值
                table &symbol = semantics::stack_st.locate_table(id);
                std::string element = ctx->variable()->id_varparts()->id_varpart()->getText();
				element = element.substr(1);
				// std::cout << "element: " << element << std::endl;
                if (0 == symbol.records.count(element))
                {
                    // 在记录型变量中找不到指定元素
                    std::cerr << "Line " << ctx->getStart()->getLine() << ": \'" << element << "\' is not a member of \'" << id << "\'" << std::endl;
                    return;
                }
                else
                {
                    std::string type = symbol.records[element].type;
                    if (type == "integer" || type == "boolean")
                        scanf_args.push_back(semantics::builder->CreateGlobalStringPtr("%d"));
                    else if (type == "real")
                        scanf_args.push_back(semantics::builder->CreateGlobalStringPtr("%f"));
                    else if (type == "char")
                        scanf_args.push_back(semantics::builder->CreateGlobalStringPtr("%c"));
                    else
                    {
                        std::cerr << "Line " << ctx->getStart()->getLine() << ": Wrong type" << std::endl;
                        return;
                    }

                    scanf_args.push_back(symbol.records[element].all);
                    semantics::builder->CreateCall(semantics::mod->getFunction("scanf"), scanf_args);
                }
            }
        }
		else if (std::string::npos != varparts.find('['))
        {
            // 仅找到 [ 的情况，说明要从数组中提取
			/*
			std::cout << "varparts: " << varparts << std::endl;
            semantics::id = id; // 为了在 ArrayAccess 中做下标的类型检查，需要把 id 传递过去
            table &symbol = semantics::stack_st.locate_table(id);
            for (int i = 0; i < varparts.size(); i++)
            {
                if ('[' == varparts[i] || ']' == varparts[i])
                    varparts[i] = ',';
                if (',' == varparts[i] && 0 != i && ',' == varparts[i - 1])
                    varparts[i] = ' ';
            }
            varparts.erase(0, 1);
			std::cout << "varparts after handle: " << varparts << std::endl;
            int offset = 0;
			std::cout << semantics::llvm_value.size() << std::endl;
			*/

			// 太过复杂，暂时放弃直接对数组使用read
			// 但是可以通过先给普通变量赋值，再赋给数组元素的方式间接读取输入
			std::cerr << "Line " << ctx->getStart()->getLine() << ": Reading for array is not be supported temporarily" << std::endl;
        }

    }
}

void semanticsListener::enterIf(PascalSParser::IfContext *ctx)
{
}

void semanticsListener::print_value(std::string mes, llvm::Value* value)
{
	llvm::SmallVector<llvm::Value*, 2> args;
	args.push_back(semantics::builder->CreateGlobalStringPtr(mes.c_str()));
	args.push_back(value);
	semantics::builder->CreateCall(semantics::mod->getFunction("printf"), args);
}

