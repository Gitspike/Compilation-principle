#include <iostream>

#include "antlr4-runtime.h"
#include "PascalSLexer.h"
#include "PascalSParser.h"
#include "semantics.hpp"
#include "SymbolTable.hpp"
//#include "PascalSBaseListener.h"

using namespace antlr4;

int main(int agrc, char* argv[]){
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

	return 0;
}
