#include "../Header.h"

std::string CallAST::graphgen(std::string origin) {
  std::string pos = std::to_string(counter);
  std::string result = std::to_string(counter) + " [label=\"" + name + "()\"];\n";
  result += origin + " -> " + std::to_string(counter++) + ";\n";
  for (const auto &arg : call_arguments) result += arg->graphgen(pos);
  return result;
}

shared_mts_obj CallAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  auto function = functions.find(name);
  if (function != functions.end()) {
    if (call_arguments.size() != function->second->function_arguments.size())
      return std::make_shared<mts_obj>(mts_error(
              "CallError", "Function " + function->second->name + " called with " +
                                   std::to_string(call_arguments.size()) + " arguments, but has " +
                                   std::to_string(function->second->function_arguments.size()) + " arguments."));
    auto new_arguments = std::make_unique<shared_future_map>();
    auto new_variables = std::make_unique<shared_mts_obj_map>();

    {
      const std::string name_var = name;
      int counter = 0;
      for (const auto &arg : call_arguments) {
        std::string arg_name = function->second->function_arguments[counter];
        new_arguments->operator[](arg_name) =
                std::async(std::launch::async, [&arg, arguments, variables]() -> shared_mts_obj {
                  return arg->eval(arguments, variables);
                });
        ++counter;
      }
    }
    return function->second->eval(new_arguments.get(), new_variables.get());
  }

  return std::make_shared<mts_obj>(mts_error("CallError", "Function \"" + name + "\" not defined."));
}
