#ifndef HEADER_H
#define HEADER_H

#include <boost/hana.hpp>
#include <boost/safe_numerics/safe_integer.hpp>
#include <boost/variant.hpp>
#include <boost/variant/get.hpp>
#include <boost/variant/multivisitors.hpp>
#include <fstream>
#include <future>
#include <gmp.h>
#include <gmpxx.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <mpfr.h>
#include <mpreal.h>
#include <mutex>
#include <shared_mutex>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

using namespace boost;
using namespace boost::safe_numerics;
using mpfr::mpreal;

// Declaration of ASTs.
struct AssignmentAST;
struct BlockAST;
struct BinaryOpAST;
struct CallAST;
struct DictAST;
struct ExprAST;
struct FltAST;
struct ForAST;
struct FunctionAST;
struct IfAST;
struct IntAST;
struct ListAST;
struct NoneAST;
struct PrintAST;
struct ReturnAST;
struct StringAST;
struct SubscriptAST;
struct SubscriptAssignmentAST;
struct UnaryOpAST;
struct VarAST;

// A placeholder for "NIL", "none" etc.
struct mts_none {
  bool operator<(const mts_none &b) const { return false; }
};

// An error has a type and a message.
struct mts_error {
  std::string type, message;
  mts_error(const std::string &type = "Error", const std::string &message = "") : type(type), message(message) {}
  friend std::ostream &operator<<(std::ostream &stream, const mts_error &rhs) {
    if (rhs.type == "") stream << "Error (anonymous)";
    else
      stream << rhs.type;
    if (rhs.message != "") { stream << ": " << rhs.message; }
    return stream;
  }
  bool operator<(const mts_error &b) const {
    if (type < b.type) return true;
    if (type > b.type) return false;
    if (message < b.message) return true;
    return false;
  }
};

template<class T>
struct mts_return {
  std::shared_ptr<T> value;
  mts_return(const std::shared_ptr<T> &value) : value(value) {}
  bool operator<(const mts_return &b) const { return *value < *b.value; }
};

using safeint = safe<std::int64_t>;
using safeuint = safe<std::uint64_t>;

// This is polymorphic base-type of the language, realised as a variant.
typedef boost::make_recursive_variant<safeint, bool, mpz_class, mpq_class, mpreal, std::string, mts_none, mts_error,
                                      mts_return<recursive_variant_>, std::map<recursive_variant_, recursive_variant_>,
                                      std::vector<recursive_variant_>>::type mts_obj;
using shared_mts_obj = std::shared_ptr<mts_obj>;
using shared_mts_obj_future = std::future<shared_mts_obj>;
using mts_dict = std::map<mts_obj, mts_obj>;
using mts_list = std::vector<mts_obj>;
using shared_mts_dict = std::shared_ptr<mts_dict>;
using shared_mts_list = std::shared_ptr<mts_list>;

// These types get passed into the evaluation-methods of the ASTs.
// shared_future_map contains futures of function-arguments, the arguments get evaluated while the body executes.
using shared_future_map = std::map<std::string, std::shared_future<shared_mts_obj>>;
// shared_mts_obj_map contains the variables of the current namespace
// (which is the set of all variables defined in a function-body at the time).
using shared_mts_obj_map = std::pair<std::map<std::string, shared_mts_obj>, std::shared_mutex>;

// Global variables.
extern std::map<std::string, std::unique_ptr<FunctionAST>> functions;
extern shared_future_map empty_arg_evals;
extern shared_mts_obj_map variables;
extern shared_mts_obj_map empty_variables;
extern std::map<std::string, ExprAST *> empty_arg_vals;
extern int counter;// Used for graphgen, keeps track of the current node.

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

#include "AST.h"
#include "parser.tab.hpp"

#endif
