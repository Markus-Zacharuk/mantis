#ifndef MANTIS_PARSING_H
#define MANTIS_PARSING_H

#include "AST_Declarations.h"
#include "mts_Types.h"

// These types get passed into the evaluation-methods of the ASTs.
// shared_future_map contains futures of function-arguments, the arguments get evaluated while the body executes.
using shared_future_map = std::map<std::string, std::shared_future<shared_mts_obj>>;
// shared_mts_obj_map contains the variables of the current namespace
// (which is the set of all variables defined in a function-body at the time).
using shared_mts_obj_map = std::pair<std::map<std::string, shared_mts_obj>, std::shared_mutex>;

#endif // MANTIS_PARSING_H