#include "../Header.h"

// Note, that shared_future_map doesn't get assigned any value. This results in call-by-value:
// If an argument gets assigned, it gets an entry in the variables.
// Reading a name first looks up the variables, then the arguments. See "AST/VarAST.cpp".
shared_mts_obj AssignmentAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  shared_mts_obj assigned_value;
  {
    std::shared_lock shared_lock(variables->second);
    assigned_value = value->eval(arguments, variables);
  }
  std::unique_lock unique_lock(variables->second);
  variables->first[name] = assigned_value;
  return std::make_shared<mts_obj>(mts_none());
}
