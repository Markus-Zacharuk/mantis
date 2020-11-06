#include "../Header.h"

std::mutex PrintAST::mutex;

shared_mts_obj PrintAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {

  std::string seperator_string, end_string;

  auto seperator_eval = seperator->eval(arguments, variables);
  if (auto seperator_eval_string = get<std::string>(seperator_eval.get())) seperator_string = *seperator_eval_string;
  else
    return std::make_shared<mts_obj>(mts_error("TypeError", "Seperator in print-function has wrong type."));

  auto end_eval = end->eval(arguments, variables);
  if (auto end_eval_string = get<std::string>(end_eval.get())) end_string = *end_eval_string;
  else
    return std::make_shared<mts_obj>(mts_error("TypeError", "End in print-function has wrong type."));

  std::lock_guard<std::mutex> guard(mutex);

  if (args.size() < 1) {
    std::cout << end_string << std::flush;
    return std::make_shared<mts_obj>(mts_none());
  }

  for (int i = 0; i < args.size() - 1; ++i) {
    auto value = args[i]->eval(arguments, variables);
    apply_visitor(hana::overload([](auto arg) -> void { std::cout << arg; }), *value);
    std::cout << seperator_string;
  }

  auto value = args[args.size() - 1]->eval(arguments, variables);
  apply_visitor(hana::overload([](auto arg) -> void { std::cout << arg; }), *value);
  std::cout << end_string << std::flush;

  return std::make_shared<mts_obj>(mts_none());
}
