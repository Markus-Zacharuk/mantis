#include "../Header.h"

// Each statement in the vector of statements gets evaluated.
// If a statement evaluates to a shared_return, the block is finished and returns what the shared_return contains.
// If no return is encountered, the block will return what the last statements evaluates to.
// An empty block returns a shared_none.
shared_mts_obj BlockAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  if (statements.size() > 0) {
    for (int i = 0; i < statements.size() - 1; ++i) {
      auto statement_eval = statements[i]->eval(arguments, variables);// std::shared_ptr<mts_obj>
      auto statement_eval_return = get<mts_return<mts_obj>>(statement_eval.get());
      if (statement_eval_return) return (statement_eval_return->value);
    }
    auto statement_eval = statements[statements.size() - 1]->eval(arguments, variables);
    auto statement_eval_return = get<mts_return<mts_obj>>(statement_eval.get());
    if (statement_eval_return)
      // See line 9.
      return (statement_eval_return->value);
    return statement_eval;
  }
  return std::make_shared<mts_obj>(mts_none());
}
