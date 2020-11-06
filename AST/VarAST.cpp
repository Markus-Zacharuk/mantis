#include "../Header.h"

shared_mts_obj VarAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  // Lookup in variables.
  {
    std::shared_lock shared_lock(variables->second);// Prevent data-race.
    auto variable = variables->first.find(name);
    if (variable != variables->first.end()) {
      return variable->second;
    }
  }
  // Lookup in arguments.
  auto argument_future = arguments->find(name);
  if (argument_future != arguments->end())
    return argument_future->second.get();
  // Nothing found. Return an error.
  return std::make_shared<mts_obj>(mts_error("NameResolutionError", name + " is no argument or variable in scope."));
}

std::string VarAST::graphgen(std::string origin) {
  std::string result = std::to_string(counter) + " [label=\"";
  result += name;
  result += "\"];\n";
  result += origin + " -> " + std::to_string(counter++) + ";\n";
  return result;
}