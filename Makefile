CC=g++
antlr4=java -jar /usr/local/lib/antlr-4.9.2-complete.jar
antlr4I=-I/usr/local/include/antlr4-runtime
antlr4l=-lantlr4-runtime
llvmI=-I/usr/lib/llvm-10/include
llvml=-lLLVM-10
all:
	$(antlr4) PascalS.g4
	$(CC) *.cpp -o main $(antlr4I) $(antlr4l) $(llvmI) $(llvml) -std=c++14 -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACRO
	g++ -I/usr/lib/llvm-project/llvm/include -std=c++14   -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -fPIC  -c -o ./optimizer/LocalOpts.o ./optimizer/LocalOpts.cpp
	g++ -dylib -shared -fPIC ./optimizer/LocalOpts.o -o ./optimizer/LocalOpts.so
	g++ -I/usr/lib/llvm-project/llvm/include -std=c++14   -fno-exceptions -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -fPIC  -c -o ./optimizer/loop_invariant_code_motion.o ./optimizer/loop_invariant_code_motion.cpp
	g++ -dylib -shared -fPIC ./optimizer/loop_invariant_code_motion.o -o ./optimizer/loop_invariant_code_motion.so
