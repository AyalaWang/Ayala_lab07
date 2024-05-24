# Compiler and flags
CXX = clang++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

testWordCount: lab06Test.o tddFuncs.o WordCount.o
	${CXX} $^ -o $@

clean: 
	/bin/rm -f *.o testWordCount