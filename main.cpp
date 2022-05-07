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
	outfile += ".s";
	if (3 == argc)
		outfile = argv[2];
	std::string cmd = "mv .tmp.main.s " + outfile;
	system(cmd.c_str());

	return 0;
}