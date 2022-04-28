CC=g++
antlr4I=-I/usr/local/include/antlr4-runtime
antlr4l=-lantlr4-runtime
llvmI=-I/usr/lib/llvm-10/include
llvml=-lLLVM-10
all:
	$(CC) *.cpp -o main $(antlr4I) $(antlr4l) $(llvmI) $(llvml) -std=c++14 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACRO