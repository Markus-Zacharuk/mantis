#include "../Header.h"

shared_mts_obj ForAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  for (auto &x : init) x->eval(arguments, variables);

  auto condition_eval = condition->eval(arguments, variables);
  auto *condition_eval_boolean = get<bool>(condition_eval.get());
  if (!condition_eval_boolean)
    return std::make_shared<mts_obj>(mts_error("TypeError", "Condition of for-loop doesn't evalute to boolean.\n"));

  while (*condition_eval_boolean) {
    auto body_eval = body->eval(arguments, variables);
    auto body_eval_return = get<mts_return<mts_obj>>(body_eval.get());
    if (body_eval_return) {// std::cout << "Return reached in for-loop.\n";
      return body_eval_return->value;
    }
    for (auto &end : tail) end->eval(arguments, variables);
    condition_eval = condition->eval(arguments, variables);
    condition_eval_boolean = get<bool>(condition_eval.get());
    if (!condition_eval_boolean)
      return std::make_shared<mts_obj>(mts_error("TypeError", "Condition of for-loop doesn't evalute to boolean.\n"));
  }
  return std::make_shared<mts_obj>(mts_none());
}
