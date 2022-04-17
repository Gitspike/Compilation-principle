#include "semantics.hpp"
#include "SymbolTable.hpp"
#include "check.hpp"
#include <assert.h>

namespace semantics{
	int depth; // 记录语义层次，只有为0时才做语义动作
	int type_declaration;	// 若该值为1，则表示当前处于type字段的record中，此时进入var_declaration不进行语义动作
	int var_record;			// 若该值为1，说明当前正在var字段的record中，此时进入var_declaration会将数据保存到栈顶符号(必是一个record型变量)的数据域中
	SymbolTable stack_st;	// 开始语义分析之前，创建栈式符号表
	std::unique_ptr<llvm::LLVMContext> context;	// llvm需要用的context智能指针
	std::unique_ptr<llvm::Module> mod;	// 同上
	std::unique_ptr<llvm::IRBuilder<>> builder;
}

void semanticsListener::enterProgram(PascalSParser::ProgramContext *ctx){
	// 初始化命名空间的相关数据
	semantics::depth = 0;
	semantics::type_declaration = 0;
	semantics::var_record = 0;
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

void semanticsListener::enterProgram_head(PascalSParser::Program_headContext *ctx){
	// 进入主程序，为主程序创建符号
	std::string id = ctx->ID()->getText();
	table symbol(id, "main");	// 主程序类型用main标识
	
	// llvm创建主程序以及builder
	symbol.functiontype = llvm::FunctionType::get(llvm::Type::getInt32Ty(*semantics::context), false);
	symbol.function = llvm::Function::Create(symbol.functiontype, llvm::GlobalValue::ExternalLinkage, id, semantics::mod.get());
	symbol.block = llvm::BasicBlock::Create(*semantics::context, "", symbol.function);
	semantics::builder = std::make_unique<llvm::IRBuilder<>>(symbol.block);

	// 主程序入栈
	semantics::stack_st.insert_table(symbol);
}

void semanticsListener::enterSingleConstDeclaration(PascalSParser::SingleConstDeclarationContext *ctx){
	// 若声明的深度不为0，则直接跳过语义动作	
	if (semantics::depth != 0)
		return;

	// 常量声明
	std::string const_id = ctx->ID()->getText();
	std::string const_value = ctx->const_variable()->getText();
	std::string type = type_of(const_value);
	if ("integer" == type){
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
	else if ("real" == type){
		// 常量类型为浮点
		table symbol(const_id, "real", const_value);
		symbol.is_const = true;
		symbol.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
		// 获取浮点值
		auto value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), atof(const_value.c_str()));
		
		semantics::builder->CreateStore(value, symbol.all);
		semantics::stack_st.insert_table(symbol);
	}
	else if ("char" == type){
		// 常量类型为字符
		table symbol(const_id, "char", const_value);
		symbol.is_const = true;
		symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
		auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), const_value[1]);
		
		semantics::builder->CreateStore(value, symbol.all);
		semantics::stack_st.insert_table(symbol);
	}
	else if ("id" == type){
		// 当类型为id时，实际上需要将符号表中的指定符号中的属性复制一份过来
		auto target_symbol = semantics::stack_st.locate_table(const_value);
		if ("err" == target_symbol.type){
			// 返回的符号类型是err时表示没有找到该符号
			std::cout << "Line " << ctx->getStart()->getLine() << ": Undeclared symbol" << std::endl;
			return;
		}
		else{
			// 常量如果赋值为标识符，那么该标识符不能是函数、过程、type或结构体这种没有value属性的
			if (target_symbol.is_func or target_symbol.is_proc or target_symbol.is_type or target_symbol.is_record){
				std::cout << "Line " << ctx->getStart()->getLine() << ": Illegal expression" << std::endl;
				return;
			}

			table symbol(const_id, target_symbol.type, target_symbol.value);
			symbol.is_const = true;
			if ("integer" == target_symbol.type){
				symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				llvm::ConstantInt* value;
				if ('-' == const_value[0])
					value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), -atoi(target_symbol.value.c_str()));
				else
					value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), atoi(target_symbol.value.c_str()));
				semantics::builder->CreateStore(value, symbol.all);
				semantics::stack_st.insert_table(symbol);
			}
			else if ("real" == target_symbol.type){
				symbol.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
				llvm::Constant* value;
				if ('-' == const_value[0])
					value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), -atof(target_symbol.value.c_str()));
				else
					value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), atof(target_symbol.value.c_str()));
				semantics::builder->CreateStore(value, symbol.all);
				semantics::stack_st.insert_table(symbol);
			}
			else if ("char" == target_symbol.type){
				symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				if ('-' == const_value[0]){
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

void semanticsListener::enterSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext *ctx){
	if (semantics::depth != 0)
		return;
	
	semantics::type_declaration = 1;
	// type 字段声明的标识符不需要实际空间，故不用调用llvm api
	std::string type_id = ctx->ID()->getText();
	std::string type_value = ctx->type()->getText();

	// 对于记录型和数组型，保存其等效的类型为value，之后在var部分若遇到该符号表示的类型，则用value替换
	if (0 == type_value.find("record")){
		// 当前type为记录型
		table symbol(type_id, "record", type_value);
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
	else if(0 == type_value.find("array")){
		// 当前type为数组型
		table symbol(type_id, "array", type_value);
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
	else {
		// 当前type为基础类型
		table symbol(type_id, type_value, type_value);
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
}

void semanticsListener::exitSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext *ctx){
	semantics::type_declaration = 0;
}

void semanticsListener::enterSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext *ctx){
	if (semantics::depth != 0 or semantics::type_declaration == 1)
		return;

	std::string id_list = ctx->identifier_list()->getText();	// 改变量是以逗号为分割的若干标识符
	std::string var_type = ctx->type()->getText();
	
	int split_pos;
	std::string id;

	// 如果var_record开关是打开的，表示当前处于var字段的record中的变量声明
	if (1 == semantics::var_record){
		do{
			split_pos = id_list.find(',');
			id = id_list.substr(0, split_pos);  // 提取出每个单独的id
			id.erase(0, id.find_first_not_of(" ")); // 去除前空格
			id.erase(id.find_last_not_of(" ") + 1); // 去除后空格

			table symbol = semantics::stack_st.get_top_table();
			assert(true == symbol.is_record);	// 从栈顶取出来的符号必然是一个record型变量

			struct record_elements element;
			if ("integer" == var_type){
				element.type = "integer";
				element.value = "0";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if ("real" == var_type){
				element.type = "real";
				element.value = "0.0";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
				auto value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), 0.0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if ("char" == var_type){
				element.type = "char";
				element.value = "\0";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
				auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), 0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if ("boolean" == var_type){
				element.type = "boolean";
				element.value = "false";
				element.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
				auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
				semantics::builder->CreateStore(value, element.all);
			}
			else if (0 == var_type.find("array")){
                // 这里的处理与后面对array符号的处理是基本一致的，但是类型不同，且不会入栈
				element.is_array = true;
				std::string array_type = ctx->type()->type()->getText();
				std::string array_range = ctx->type()->periods()->getText();
                element.type = array_type;
                // 接下来需要处理数组的维度，每一维度用逗号区分
			    std::string period;	// period 表示每一维度的范围
			    std::string range_begin, range_end;	// 表示每一维的起止符号
			    int range_split;
                do{
				    range_split = array_range.find(',');
				    period = array_range.substr(0, range_split);
				    range_begin = period.substr(0, period.find(".."));
				    range_end = period.substr(period.find("..") + 2);
				    // 去除begin和end前后的空白字符
				    range_begin.erase(0, range_begin.find_first_not_of(" "));
				    range_end.erase(0, range_end.find_first_not_of(" "));
				    range_begin.erase(range_begin.find_last_not_of(" ") + 1);
				    range_end.erase(range_end.find_last_not_of(" ") + 1);

				    if ("integer" == type_of(range_begin) and "integer" == type_of(range_end)){
				    	// 范围必须是整数型，且 end 大于 begin
				    	int begin = atoi(range_begin.c_str());
				    	int end = atoi(range_end.c_str());
				    	if (begin <= end){
				    		element.range_type.push_back("integer");
				    		element.range.push_back(std::pair<int, int>(begin, end - begin + 1));
				    	}
				    	else{
				    		std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
				    	}
				    }
				    else if ("char" == type_of(range_begin) and "char" == type_of(range_end)){
				    	// 范围由单字符组成
				    	if (range_end[1] >= range_begin[1]){
				    		element.range_type.push_back("char");
				    		element.range.push_back(std::pair<int, int>(range_begin[1], range_end[1] - range_begin[1] + 1));
				    	}
				    	else{
				    		std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
				    	}
				    }
				    else{
				    	// 除了单字符和整数表示，其余的场景是无效的字符范围
				    	std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
				    }

				    // 处理完当前维的范围之后，要为当前维度分配空间
				    int range = (element.range.end() - 1)->second;
				    if ("integer" == array_type){
				    	element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
				    }
				    else if ("char" == array_type){
				    	element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt8Ty(*semantics::context), range), nullptr));
				    }
				    else if ("real" == array_type){
				    	element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getFloatTy(*semantics::context), range), nullptr));
				    }
				    else if ("boolean" == array_type){
				    	element.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
				    }
				    else{
				    	// 目前该项目仅支持基础基础类型的数组
				    	std::cout << "Line " << ctx->getStart()->getLine() << ": Unsupported array type" << std::endl;
				    }
				    array_range = array_range.substr(range_split + 1);
			    }while(std::string::npos != range_split);
			}
			symbol.push_record_elements(id, element);

			id_list = id_list.substr(split_pos + 1);    // 将处理后的id剔除出去
		}while(std::string::npos != split_pos);	
	
		return;		//结束后直接返回，后续动作是针对普通的变量声明的
	}

	do{
		split_pos = id_list.find(',');
        id = id_list.substr(0, split_pos);	// 提取出每个单独的id

		id.erase(0, id.find_first_not_of(" ")); // 去除前空格
        id.erase(id.find_last_not_of(" ") + 1); // 去除后空格
		
		// 对每个id，都要建立相应的符号并入栈
		if ("integer" == var_type){
			table symbol(id, "integer", "0");
			// 分配空间后将默认初始化的值放入空间当中
 	        symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
 	        auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
 	        semantics::builder->CreateStore(value, symbol.all);
 	        // 符号入栈
 	        semantics::stack_st.insert_table(symbol);
		}
		else if ("real" == var_type){
			table symbol(id, "real", "0");

			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
			auto value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), 0.0);
 
			semantics::builder->CreateStore(value, symbol.all);
			semantics::stack_st.insert_table(symbol);
		}
		else if ("char" == var_type){
			table symbol(id, "char", "\0");

			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt8Ty(*semantics::context), nullptr);
			auto value = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*semantics::context), 0);
 
			semantics::builder->CreateStore(value, symbol.all);
			semantics::stack_st.insert_table(symbol);
		}
		else if ("boolean" == var_type){
			// 对布尔值，看作是整形，并以0为false，非0为true
			table symbol(id, "boolean", "false");
			symbol.all = semantics::builder->CreateAlloca(llvm::Type::getInt32Ty(*semantics::context), nullptr);
			auto value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*semantics::context), 0);
			semantics::builder->CreateStore(value, symbol.all);
			semantics::stack_st.insert_table(symbol);
		}
		else if (0 == var_type.find("record")){
			table symbol(id, "record", "record");
			// 对于一个 record 来说，在当前规则中只能先将该符号入栈
			// record里面的变量以及 llvm 能做的事必须要到 record_body 中才能做
			symbol.is_record = true;
            semantics::stack_st.insert_table(symbol);
		}
		else if (0 == var_type.find("array")){
			std::string array_type = ctx->type()->type()->getText();
			std::string array_range = ctx->type()->periods()->getText();
			table symbol(id, array_type, array_type);
			symbol.is_array = true;

			// 接下来需要处理数组的维度，每一维度用逗号区分
			std::string period;	// period 表示每一维度的范围
			std::string range_begin, range_end;	// 表示每一维的起止符号
			int range_split;
			do{
				range_split = array_range.find(',');
				period = array_range.substr(0, range_split);
				range_begin = period.substr(0, period.find(".."));
				range_end = period.substr(period.find("..") + 2);
				// 去除begin和end前后的空白字符
				range_begin.erase(0, range_begin.find_first_not_of(" "));
				range_end.erase(0, range_end.find_first_not_of(" "));
				range_begin.erase(range_begin.find_last_not_of(" ") + 1);
				range_end.erase(range_end.find_last_not_of(" ") + 1);

				if ("integer" == type_of(range_begin) and "integer" == type_of(range_end)){
					// 范围必须是整数型，且 end 大于 begin
					int begin = atoi(range_begin.c_str());
					int end = atoi(range_end.c_str());
					if (begin <= end){
						symbol.range_type.push_back("integer");
						symbol.range.push_back(std::pair<int, int>(begin, end - begin + 1));
					}
					else{
						std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
					}
				}
				else if ("char" == type_of(range_begin) and "char" == type_of(range_end)){
					// 范围由单字符组成
					if (range_end[1] >= range_begin[1]){
						symbol.range_type.push_back("char");
						symbol.range.push_back(std::pair<int, int>(range_begin[1], range_end[1] - range_begin[1] + 1));
					}
					else{
						std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
					}
				}
				else{
					// 除了单字符和整数表示，其余的场景是无效的字符范围
					std::cout << "Line " << ctx->getStart()->getLine() << ": Unreasonable array range" << std::endl;
				}

				// 处理完当前维的范围之后，要为当前维度分配空间
				int range = (symbol.range.end() - 1)->second;
				if ("integer" == array_type){
					symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
				}
				else if ("char" == array_type){
					symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt8Ty(*semantics::context), range), nullptr));
				}
				else if ("real" == array_type){
					symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getFloatTy(*semantics::context), range), nullptr));
				}
				else if ("boolean" == array_type){
					symbol.all_item.push_back(semantics::builder->CreateAlloca(llvm::ArrayType::get(llvm::Type::getInt32Ty(*semantics::context), range), nullptr));
				}
				else{
					// 目前该项目仅支持基础基础类型的数组
					std::cout << "Line " << ctx->getStart()->getLine() << ": Unsupported array type" << std::endl;
				}
				array_range = array_range.substr(range_split + 1);
			}while(std::string::npos != range_split);
			semantics::stack_st.insert_table(symbol);
		}
		id_list = id_list.substr(split_pos + 1);	// 将处理后的id剔除出去
	}while(std::string::npos != split_pos);
}

void semanticsListener::exitProgram_body(PascalSParser::Program_bodyContext *ctx){
	semantics::stack_st.pint_table();
	if (0 != semantics::depth)
		semantics::depth--;
}

void semanticsListener::enterRecord_body(PascalSParser::Record_bodyContext *ctx){
	if (1 == semantics::type_declaration)
		return;
	
	// 如果这不是在type字段的record，就一定是在var字段的，要将var_record开关打开
	semantics::var_record = 1;
}

void semanticsListener::exitRecord_body(PascalSParser::Record_bodyContext *ctx){
	if (1 == semantics::var_record)
		semantics::var_record = 0;
}

void semanticsListener::exitFunctionDeclaration(PascalSParser::FunctionDeclarationContext *ctx){
	// 从子程序的声明头出来的时候，意味着即将进入子程序的声明体
	// 但是在声明这里我们是对子程序的程序体不做语义动作的，通过semantics::depth来控制是否跳过
	semantics::depth++;
}

void semanticsListener::exitProcedureDeclaration(PascalSParser::ProcedureDeclarationContext *ctx){
	// 同上
	semantics::depth++;
}
