#include <iostream>

#include "antlr4-runtime.h"
#include "PascalSLexer.h"
#include "PascalSParser.h"
#include "semantics.hpp"
#include "SymbolTable.hpp"
//#include "PascalSBaseListener.h"

using namespace antlr4;

int main(int argc, char* argv[]){
	if (argc != 2 && argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " input-file [output-file]" << std::endl;
		return 1;
	}

	std::ifstream stream(argv[1]);
	ANTLRInputStream input(stream);
	// Create antlr lexer
	PascalSLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	
	// Create antlr parser
	PascalSParser parser(&tokens);

	// Create parser tree and set initial rule
	tree::ParseTree *tree = parser.program();
	semanticsListener listener;
	//PascalSBaseListener listener;
	tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

	// 如果指定了第三个参数，即输出文件路径，则把临时的汇编文件 .tmp.main.s 改成该文件
	std::string infile = argv[1];
	std::string outfile = infile.substr(0, infile.rfind('.'));
	std::string pre = outfile;	// 文件名中不包括后缀的部分
	outfile += ".ll";
	if (3 == argc)
		outfile = argv[2];

	std::string cmd = "./optimizer/opt -mem2reg -load ./optimizer/LocalOpts.so -Local-Opts ./.tmp.main.ll -S -o ./opt.ll";	// 进行类型转换 删除公共子表达式等优化的命令
	system(cmd.c_str());
	cmd = "./optimizer/opt -mem2reg -load ./optimizer/loop_invariant_code_motion.so  -loop-invariant-code-motion ./opt.ll -S -o ./";
	cmd += outfile;		// 移除循环不变量的优化的命令
	system(cmd.c_str());	
	system("rm .tmp.main.ll opt.ll");
	
	cmd = "./llvm-as ";
	cmd += outfile;
	cmd += " -o ";
	cmd += pre;
	cmd += ".bc";
	system(cmd.c_str());	// 生成.bc文件
	cmd = "clang -S -fobjc-arc ";
	cmd += pre;
	cmd += ".bc -o ";
	cmd += pre;
	cmd += ".s";
	system(cmd.c_str());	// 生成.s文件

	return 0;
}
