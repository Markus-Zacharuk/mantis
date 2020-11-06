mantis: lex.yy.cpp parser.tab.cpp AST/AssignmentAST.cpp AST/BinaryOpAST.cpp AST/BlockAST.cpp AST/CallAST.cpp AST/DictAST.cpp AST/FltAST.cpp AST/ForAST.cpp AST/FunctionAST.cpp AST/IfAST.cpp AST/IntAST.cpp AST/ListAST.cpp AST/PrintAST.cpp AST/ReturnAST.cpp AST/SubscriptAST.cpp AST/SubscriptAssignmentAST.cpp  AST/UnaryOpAST.cpp AST/VarAST.cpp Functions.cpp
	clang++ lex.yy.cpp parser.tab.cpp AST/AssignmentAST.cpp AST/BinaryOpAST.cpp AST/BlockAST.cpp AST/CallAST.cpp AST/DictAST.cpp AST/FltAST.cpp AST/ForAST.cpp AST/FunctionAST.cpp AST/IfAST.cpp AST/IntAST.cpp AST/ListAST.cpp AST/PrintAST.cpp AST/ReturnAST.cpp AST/SubscriptAST.cpp AST/SubscriptAssignmentAST.cpp AST/UnaryOpAST.cpp AST/VarAST.cpp Functions.cpp -lgmpxx -lgmp -lpthread -lmpfr -std=c++20 -O3 -I AST -o mantis

unoptimized: lex.yy.cpp parser.tab.cpp AST/AssignmentAST.cpp AST/BinaryOpAST.cpp AST/BlockAST.cpp AST/CallAST.cpp AST/DictAST.cpp AST/FltAST.cpp AST/ForAST.cpp AST/FunctionAST.cpp AST/IfAST.cpp AST/IntAST.cpp AST/ListAST.cpp AST/PrintAST.cpp AST/ReturnAST.cpp AST/SubscriptAST.cpp AST/SubscriptAssignmentAST.cpp  AST/UnaryOpAST.cpp AST/VarAST.cpp Functions.cpp
	clang++ lex.yy.cpp parser.tab.cpp AST/AssignmentAST.cpp AST/BinaryOpAST.cpp AST/BlockAST.cpp AST/CallAST.cpp AST/DictAST.cpp AST/FltAST.cpp AST/ForAST.cpp AST/FunctionAST.cpp AST/IfAST.cpp AST/IntAST.cpp AST/ListAST.cpp AST/PrintAST.cpp AST/ReturnAST.cpp AST/SubscriptAST.cpp AST/SubscriptAssignmentAST.cpp AST/UnaryOpAST.cpp AST/VarAST.cpp Functions.cpp -lgmpxx -lgmp -lpthread -lmpfr -std=c++20 -O1 -I AST -o mantis

parser.tab.cpp: parser.y
	bison -d --verbose --graph parser.y -o parser.tab.cpp

lex.yy.cpp: lexer.l
	flex lexer.l
	cp lex.yy.c lex.yy.cpp
	rm lex.yy.c

graph: parser.tab.cpp
	xdot parser.dot

conflicts:
	cat parser.output

clean:
	rm -rf mantis lex.yy.c lex.yy.cpp lex.yy.cc parser.tab.cpp parser.tab.c parser.tab.cc parser.tab.h parser.tab.hh parser.output parser.dot

