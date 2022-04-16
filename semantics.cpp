#include "semantics.hpp"
#include "SymbolTable.hpp"
#include "check.hpp"

namespace semantics{
	int depth; // 记录语义层次，只有为0时才做语义动作
	SymbolTable stack_st;	// 开始语义分析之前，创建栈式符号表
	std::unique_ptr<llvm::LLVMContext> context;	// llvm需要用的context智能指针
	std::unique_ptr<llvm::Module> mod;	// 同上
	std::unique_ptr<llvm::IRBuilder<>> builder;
}

void semanticsListener::enterProgram(PascalSParser::ProgramContext *ctx){
	// 初始化命名空间的相关数据
	semantics::depth = 0;
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
	// 常量声明
	std::string const_id = ctx->ID()->getText();
	std::string const_value = ctx->const_variable()->getText();
	//auto val_ctx = ctx->const_variable();
	std::string type = type_of(const_value);
	if ("integer" == type){
		// 常量类型为整形
		table symbol(const_id, "integer", const_value);
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
		symbol.all = semantics::builder->CreateAlloca(llvm::Type::getFloatTy(*semantics::context), nullptr);
		// 获取浮点值
		auto value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*semantics::context), atof(const_value.c_str()));
		
		semantics::builder->CreateStore(value, symbol.all);
		semantics::stack_st.insert_table(symbol);
	}
	else if ("char" == type){
		// 常量类型为字符
		table symbol(const_id, "char", const_value);
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
	}
}

void semanticsListener::exitProgram_body(PascalSParser::Program_bodyContext *ctx){
	semantics::stack_st.pint_table();
}
