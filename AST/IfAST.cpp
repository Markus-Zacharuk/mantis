#include "../Header.h"

std::string IfAST::graphgen(std::string origin) {
  std::string pos = std::to_string(counter);
  std::string result = std::to_string(counter) + " [label=\"if\"];\n";
  result += origin + " -> " + std::to_string(counter++) + ";\n";
  for (int i = 0; i < conditions.size(); ++i) {
    result += conditions[i]->graphgen(pos);
    result += implications[i]->graphgen(pos);
  }
  if (default_expression) result += default_expression->graphgen(pos);
  return result;
}

shared_mts_obj IfAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  if (conditions.size() != implications.size())
    return std::make_shared<mts_obj>(
            mts_error("ParsingError", "Conditions and implications have different count in if-expression.\n"));
  for (int i = 0; i < conditions.size(); ++i) {
    auto var = conditions[i]->eval(arguments, variables);
    auto boolean = get<bool>(var.get());
    if (boolean) {
      if (*boolean) return implications[i]->eval(arguments, variables);
    } else {
      return std::make_shared<mts_obj>(mts_error("TypeError", "Could not resolve Condition " + std::to_string(i) +
                                                                      " to boolean. Wrong type?\n"));
    }
  }
  if (default_expression) return default_expression->eval(arguments, variables);
  return std::make_shared<mts_obj>(mts_none());
}
