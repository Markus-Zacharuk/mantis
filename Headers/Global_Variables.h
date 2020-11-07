#ifndef MANTIS_GLOBAL_VARIABLES_H
#define MANTIS_GLOBAL_VARIABLES_H

#include "AST_Declarations.h"
#include "mts_Types.h"

// Global variables.
extern std::map<std::string, std::unique_ptr<FunctionAST>> functions;
extern shared_future_map empty_arg_evals;
extern shared_mts_obj_map variables;
extern shared_mts_obj_map empty_variables;
extern std::map<std::string, ExprAST *> empty_arg_vals;
extern int counter;

#endif // MANTIS_GLOBAL_VARIABLES_H
