#ifndef MANTIS_FUNCTIONS_H
#define MANTIS_FUNCTIONS_H

#include "Includes.h"
#include "mts_Types.h"
#include "Parsing.h"

// Lexer.
extern int yylex();                          // This is the lexing-function.
extern char *yytext;                         // The current text from flex.
std::string unescape(const std::string &str);// Handles escape-sequences from string-input in the lexer.

// Error-handling of the parser.
void yyerror(char *msg);
void yyerror(const std::string &msg);

// Free global functions.
std::string get_op_string(int op);
void save_graph(ExprAST *expr);
void save_graph(FunctionAST *expr);
void print_eval(ExprAST *expr, const shared_future_map *const arguments = &empty_arg_evals,
                shared_mts_obj_map *const variables_ = &variables);
std::string get_op_string(int op);
std::ostream &operator<<(std::ostream &stream, const mts_dict &rhs);
std::ostream &operator<<(std::ostream &stream, const mts_list &rhs);
std::ostream &operator<<(std::ostream &stream, const mts_obj &rhs);

extern int counter;

#endif // MANTIS_FUNCTIONS_H
