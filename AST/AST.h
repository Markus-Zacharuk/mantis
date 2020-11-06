#ifndef AST_H
#define AST_H
#include "../Header.h"

struct ExprAST {
  virtual ~ExprAST() = default;
  virtual std::string graphgen(std::string origin) = 0;
  virtual shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) = 0;
  virtual mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) = 0;
};

struct AssignmentAST : public ExprAST {
  std::string name;
  std::unique_ptr<ExprAST> value;
  AssignmentAST(ExprAST *expr) : value(expr) {}
  AssignmentAST(std::string name, ExprAST *expr) : name(name), value(expr) {}
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct BinaryOpAST : public ExprAST {
  int op;
  std::unique_ptr<ExprAST> lhs, rhs;
  BinaryOpAST(ExprAST *lhs, int op, ExprAST *rhs) : lhs(lhs), op(op), rhs(rhs) {}
  std::string graphgen(std::string origin);
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct BlockAST : public ExprAST {
  std::vector<std::unique_ptr<ExprAST>> statements;
  BlockAST(ExprAST *expr) { statements.push_back(std::unique_ptr<ExprAST>(expr)); }
  BlockAST() {}
  void add_statement(ExprAST *expr) { statements.push_back(std::unique_ptr<ExprAST>(expr)); }
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct CallAST : public ExprAST {
  std::string name;
  std::vector<std::unique_ptr<ExprAST>> call_arguments;
  CallAST(const std::string &name) : name(name) {}
  void add_arg(ExprAST *expr) { call_arguments.push_back(std::unique_ptr<ExprAST>(expr)); }
  std::string graphgen(std::string origin);
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct DictAST : public ExprAST {
  std::vector<std::pair<std::unique_ptr<ExprAST>, std::unique_ptr<ExprAST>>> dict;
  DictAST() {}
  DictAST(ExprAST *from, ExprAST *to) { add_entry(from, to); }
  void add_entry(ExprAST *from, ExprAST *to);
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct FltAST : public ExprAST {
  shared_mts_obj value;
  FltAST(std::string value) : value(std::make_shared<mts_obj>(mpreal(value))) {}
  FltAST(mpreal value) : value(std::make_shared<mts_obj>(mpreal(value))) {}
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct ForAST : public ExprAST {
  std::vector<std::unique_ptr<ExprAST>> init;// Variable initialization. ( for (int i=0;	)		(C++ style)
  std::unique_ptr<ExprAST> condition;        // Loop condition.			( i<2;			)
  std::vector<std::unique_ptr<ExprAST>> tail;// Tail instructions.		( ++i)			)
  std::unique_ptr<BlockAST> body;            // Instruction body.		( { var += i; } )
  ForAST() {}
  ForAST(ExprAST *expr) { init.push_back(std::unique_ptr<ExprAST>(expr)); }
  void add_init(ExprAST *expr) { init.push_back(std::unique_ptr<ExprAST>(expr)); }
  void add_cond(ExprAST *expr) { condition = std::unique_ptr<ExprAST>(expr); }
  void add_end(ExprAST *expr) { tail.push_back(std::unique_ptr<ExprAST>(expr)); }
  void add_body(BlockAST *expr) { body = std::unique_ptr<BlockAST>(expr); }
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct FunctionAST {
  std::string name;
  std::vector<std::string> function_arguments;
  std::unique_ptr<ExprAST> body;
  FunctionAST(const std::string &name) : name(name) {}
  void add_arg(const std::string &argument) { function_arguments.push_back(argument); }
  void add_body(ExprAST *expr) { body = std::unique_ptr<ExprAST>(expr); }
  std::string graphgen(std::string origin);
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct IfAST : public ExprAST {
  std::vector<std::unique_ptr<ExprAST>> conditions;  // 	( if (...) {	  )		(C++ style)
  std::vector<std::unique_ptr<ExprAST>> implications;//  ( 	...   	      )
  std::unique_ptr<ExprAST>
          default_expression;//  ( } else { ... }  )		"default" is a reserved keyword in C++, so use "default_expression".
  IfAST(ExprAST *condition, ExprAST *implication) {
    conditions.push_back(std::unique_ptr<ExprAST>(condition));
    implications.push_back(std::unique_ptr<ExprAST>(implication));
  }
  void add_if(ExprAST *condition, ExprAST *implication) {
    conditions.push_back(std::unique_ptr<ExprAST>(condition));
    implications.push_back(std::unique_ptr<ExprAST>(implication));
  }
  void add_default(ExprAST *expr) { default_expression = std::unique_ptr<ExprAST>(expr); }
  std::string graphgen(std::string origin);
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct IntAST : public ExprAST {
  shared_mts_obj value;
  IntAST(std::string value) : value(std::make_shared<mts_obj>(mpz_class(value))) {}
  IntAST(mpz_class value) : value(std::make_shared<mts_obj>(mpz_class(value))) {}
  std::string graphgen(std::string origin);
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct ListAST : public ExprAST {
  std::vector<std::unique_ptr<ExprAST>> list;
  ListAST() {}
  ListAST(ExprAST *expr) { list.push_back(std::unique_ptr<ExprAST>(expr)); }
  void add_element(ExprAST *expr) { list.push_back(std::unique_ptr<ExprAST>(expr)); }
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

// This is like NIL or nullptr in other languages and is more or less a placeholder.
struct NoneAST : ExprAST {
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return std::make_shared<mts_obj>(mts_none());
  }
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};



struct ReturnAST : public ExprAST {
  std::unique_ptr<ExprAST> value;
  std::string graphgen(std::string origin) { return ""; }
  ReturnAST(ExprAST *expr) : value(expr) {}
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct SubscriptAST : public ExprAST {
  std::unique_ptr<ExprAST> argument;
  std::vector<std::vector<std::unique_ptr<ExprAST>>> subscript;
  SubscriptAST(ExprAST *arg, ExprAST *i) : argument(arg) { add_subscript(i); }
  SubscriptAST(ExprAST *arg, ExprAST *i, ExprAST *j) : argument(arg) { add_subscript(i, j); }
  SubscriptAST(ExprAST *arg, ExprAST *i, ExprAST *j, ExprAST *k) : argument(arg) { add_subscript(i, j, k); }
  void add_subscript(ExprAST *i);
  void add_subscript(ExprAST *i, ExprAST *j);
  void add_subscript(ExprAST *i, ExprAST *j, ExprAST *k);
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct SubscriptAssignmentAST : ExprAST {
  std::unique_ptr<ExprAST> argument, value;
  std::vector<std::vector<std::unique_ptr<ExprAST>>> subscript;
  SubscriptAssignmentAST(ExprAST *value, SubscriptAST *subscript)
      : argument(std::move(subscript->argument)), value(value), subscript(std::move(subscript->subscript)) {}
  void add_subscript(ExprAST *i);
  void add_subscript(ExprAST *i, ExprAST *j);
  void add_subscript(ExprAST *i, ExprAST *j, ExprAST *k);
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct StringAST : ExprAST {
  shared_mts_obj str;
  StringAST(const std::string &str) : str(std::make_shared<mts_obj>(str)) {}
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) { return str; }
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct PrintAST : ExprAST {
  std::vector<std::unique_ptr<ExprAST>> args;
  std::unique_ptr<ExprAST> seperator;
  std::unique_ptr<ExprAST> end;
  static std::mutex mutex;
  PrintAST() : seperator(new StringAST(" ")), end(new StringAST("\n")) {}
  PrintAST(ExprAST *expr) : seperator(new StringAST(" ")), end(new StringAST("\n")) {
    args.push_back(std::unique_ptr<ExprAST>(expr));
  }
  void add_argument(ExprAST *expr) { args.push_back(std::unique_ptr<ExprAST>(expr)); }
  void add_seperator(ExprAST *expr) { seperator = std::unique_ptr<ExprAST>(expr); }
  void add_end(ExprAST *expr) { end = std::unique_ptr<ExprAST>(expr); }
  std::string graphgen(std::string origin) { return ""; }
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct UnaryOpAST : public ExprAST {
  int op;
  std::unique_ptr<ExprAST> rhs;
  UnaryOpAST(int op, ExprAST *rhs) : op(op), rhs(rhs) {}
  std::string graphgen(std::string origin);
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

struct VarAST : public ExprAST {
  std::string name;
  VarAST(const std::string &name) : name(name) {}
  std::string graphgen(std::string origin);
  shared_mts_obj eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables);
  mts_obj eval_ref(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
    return *eval(arguments, variables);
  }
};

#endif
