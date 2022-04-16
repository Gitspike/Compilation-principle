#include "semantics.hpp"
#include "SymbolTable.hpp"
#include "check.hpp"

namespace semantics{
	int depth; // 记录语义层次，只有为0时才做语义动作
	int type_declaration;
	SymbolTable stack_st;	// 开始语义分析之前，创建栈式符号表
	std::unique_ptr<llvm::LLVMContext> context;	// llvm需要用的context智能指针
	std::unique_ptr<llvm::Module> mod;	// 同上
	std::unique_ptr<llvm::IRBuilder<>> builder;
}

void semanticsListener::enterProgram(PascalSParser::ProgramContext *ctx){
	// 初始化命名空间的相关数据
	semantics::depth = 0;
	semantics::type_declaration = 0;
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
	
	//type 字段声明的标识符不需要实际空间，故不用调用llvm api
	std::string type_id = ctx->ID()->getText();
	std::string type_value = ctx->type()->getText();

	// 对于记录型和数组型，一定会接下来进入 type 规则中的子规则，但是又不能分配空间
	// 所以将变量 semantics::type_declaration 设为1，以跳过某些语义动作
	// 当退出 type 规则时重新置为0
	if (0 == type_value.find("record")){
		// 当前type为记录型
		table symbol(type_id, "record", "record");
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
	else if(0 == type_value.find("array")){
		// 当前type为数组型
		table symbol(type_id, "array", "array");
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
	else {
		// 当前type为基础类型
		table symbol(type_id, type_value, type_value);
		symbol.is_type = true;
		semantics::stack_st.insert_table(symbol);
	}
	semantics::type_declaration = 1;
}

void semanticsListener::exitSingleTypeDeclaration(PascalSParser::SingleTypeDeclarationContext *ctx){
	semantics::type_declaration = 0;
}

void semanticsListener::enterSingleVarDeclaration(PascalSParser::SingleVarDeclarationContext *ctx){
	if (semantics::depth != 0)
		return;

	std::string id_list = ctx->identifier_list()->getText();	// 改变量是以逗号为分割的若干标识符
	std::string var_type = ctx->type()->getText();

	int split_pos;
	std::string id;
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
		else if (0 == var_type.find("record")){
			table symbol(id, "record", "record");
			// 对于一个 record 来说，在当前规则中只能先将该符号入栈
			// 记录里面的变量以及 llvm 能做的事必须要到 record_body 中才能做
			symbol.is_record = true;
		}
		else if (0 == var_type.find("array")){
			table symbol(id, "array", "array");
		}
		id_list = id_list.substr(split_pos + 1);	// 将处理后的id剔除出去
	}while(std::string::npos != split_pos);
}

void semanticsListener::exitProgram_body(PascalSParser::Program_bodyContext *ctx){
	semantics::stack_st.pint_table();
}
