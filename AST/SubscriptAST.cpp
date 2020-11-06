#include "../Header.h"

void SubscriptAST::add_subscript(ExprAST *i) {
  std::vector<std::unique_ptr<ExprAST>> var;
  var.push_back(std::unique_ptr<ExprAST>(i));
  subscript.push_back(std::move(var));
}
void SubscriptAST::add_subscript(ExprAST *i, ExprAST *j) {
  std::vector<std::unique_ptr<ExprAST>> var;
  var.push_back(std::unique_ptr<ExprAST>(i));
  var.push_back(std::unique_ptr<ExprAST>(j));
  subscript.push_back(std::move(var));
}
void SubscriptAST::add_subscript(ExprAST *i, ExprAST *j, ExprAST *k) {
  std::vector<std::unique_ptr<ExprAST>> var;
  var.push_back(std::unique_ptr<ExprAST>(i));
  var.push_back(std::unique_ptr<ExprAST>(j));
  var.push_back(std::unique_ptr<ExprAST>(k));
  subscript.push_back(std::move(var));
}

shared_mts_obj SubscriptAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  auto argument_eval = argument->eval(arguments, variables);
  {
    auto *x = get<mts_list>(&*argument_eval);
    if (!x) return std::make_shared<mts_obj>(mts_error("TypeError", "Tried subscripting non-list"));
  }
  auto &argument_list = get<mts_list>(*argument_eval);

  // Indexing cases like [1,2,3][1] -> 2.
  if (subscript.size() == 1 && subscript[0].size() == 1) {
    return apply_visitor(hana::overload(
                                 [&argument_list](mpz_class &index) -> shared_mts_obj {
                                   int64_t i;
                                   if (index.fits_slong_p()) i = index.get_si();
                                   else
                                     return std::make_shared<mts_obj>(mts_error(
                                             "SubscriptError", "Can't access Element at position " + index.get_str() +
                                                                       ", list size is " +
                                                                       std::to_string(argument_list.size()) + "."));
                                   if (i >= 0 && i < int64_t(argument_list.size()))
                                     return std::make_shared<mts_obj>(argument_list[i]);
                                   if (i < 0 && i >= -int64_t(argument_list.size()))
                                     return std::make_shared<mts_obj>(argument_list[argument_list.size() + i]);
                                   return std::make_shared<mts_obj>(mts_error(
                                           "SubscriptError", "Can't access Element at position " + index.get_str() +
                                                                     ", list size is " +
                                                                     std::to_string(argument_list.size()) + "."));
                                 },
                                 [&argument_list](safeint index) -> shared_mts_obj {
                                   int64_t i = int64_t(index);
                                   if (i >= 0 && i < int64_t(argument_list.size()))
                                     return std::make_shared<mts_obj>(argument_list[i]);
                                   if (i < 0 && i >= -int64_t(argument_list.size()))
                                     return std::make_shared<mts_obj>(argument_list[argument_list.size() + i]);
                                   return std::make_shared<mts_obj>(mts_error(
                                           "SubscriptError", "Can't access Element at position " + std::to_string(i) +
                                                                     ", list size is " +
                                                                     std::to_string(argument_list.size()) + "."));
                                 },
                                 [&argument_eval](mts_error) -> shared_mts_obj { return argument_eval; },
                                 [](auto) -> shared_mts_obj {
                                   return std::make_shared<mts_obj>(
                                           mts_error("TypeError", "Tried indexing a list with wrong type."));
                                 }),
                         *subscript[0][0]->eval(arguments, variables));
  }

  auto result_shared_mts = std::make_shared<mts_obj>(mts_list());
  auto &result = get<mts_list>(*result_shared_mts);

  for (const auto &s : subscript) {
    switch (s.size()) {
      case 1:
        result.push_back(apply_visitor(
                hana::overload(
                        [&argument_list](mpz_class &index) -> mts_obj {
                          int64_t i;
                          if (index.fits_slong_p()) i = index.get_si();
                          else
                            return mts_error("SubscriptError", "Can't access Element at position " + index.get_str() +
                                                                       ", list size is " +
                                                                       std::to_string(argument_list.size()) + ".");
                          if (i >= 0 && i < int64_t(argument_list.size())) return argument_list[i];
                          if (i < 0 && i >= -int64_t(argument_list.size()))
                            return argument_list[argument_list.size() + i];
                          return mts_error("SubscriptError", "Can't access Element at position " + index.get_str() +
                                                                     ", list size is " +
                                                                     std::to_string(argument_list.size()) + ".");
                        },
                        [&argument_list](safeint index) -> mts_obj {
                          int64_t i = index;
                          if (i >= 0 && i < int64_t(argument_list.size())) return argument_list[i];
                          if (i < 0 && i >= -int64_t(argument_list.size()))
                            return argument_list[argument_list.size() + i];
                          return mts_error("SubscriptError", "Can't access Element at position " + std::to_string(i) +
                                                                     ", list size is " +
                                                                     std::to_string(argument_list.size()) + ".");
                        },
                        [](mts_error &error, auto) -> mts_obj { return error; },
                        [](auto) -> mts_obj {
                          return mts_error("TypeError", "Tried indexing a list with wrong type.");
                        }),
                *s[0]->eval(arguments, variables)));
        break;
      case 2: {
        auto var = apply_visitor(
                hana::overload(
                        [&result, &argument_list](safeint index_i, safeint index_j) -> shared_mts_obj {
                          int64_t i = index_i;
                          int64_t j = index_j;
                          if (i < 0) i = argument_list.size() + i;
                          if (j < 0) j = argument_list.size() + j;
                          if (i >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(i) = " + std::to_string(i) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (j >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(j) = " + std::to_string(j) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (i < j)// Normal case.
                            result.insert(result.end(), argument_list.begin() + i, argument_list.begin() + j + 1);
                          else// Backwards.
                            result.insert(result.end(), argument_list.rend() - (i + 1), argument_list.rend() - j);
                          return std::make_shared<mts_obj>(mts_none());
                        },
                        [&result, &argument_list](mts_none &n, safeint index_j) -> shared_mts_obj {
                          int64_t i = 0;
                          int64_t j = index_j;
                          if (j < 0) j = argument_list.size() + j;
                          if (i >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(i) = " + std::to_string(i) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (j >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(j) = " + std::to_string(j) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (i < j)// Normal case.
                            result.insert(result.end(), argument_list.begin() + i, argument_list.begin() + j + 1);
                          else// Backwards.
                            result.insert(result.end(), argument_list.rend() - (i + 1), argument_list.rend() - j);
                          return std::make_shared<mts_obj>(mts_none());
                        },
                        [&result, &argument_list](safeint index_i, mts_none &n) -> shared_mts_obj {
                          int64_t i = index_i;
                          int64_t j = argument_list.size() - 1;
                          if (i < 0) i = argument_list.size() + i;
                          if (i >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(i) = " + std::to_string(i) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (j >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(j) = " + std::to_string(j) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (i < j)// Normal case.
                            result.insert(result.end(), argument_list.begin() + i, argument_list.begin() + j + 1);
                          else// Backwards.
                            result.insert(result.end(), argument_list.rend() - (i + 1), argument_list.rend() - j);
                          return std::make_shared<mts_obj>(mts_none());
                        },
                        [&result, &argument_list](mts_none &n1, mts_none &n2) -> shared_mts_obj {
                          result.insert(result.end(), argument_list.begin(), argument_list.end());
                          return std::make_shared<mts_obj>(mts_none());
                        },
                        [](auto, auto) -> shared_mts_obj {
                          return std::make_shared<mts_obj>(
                                  mts_error("TypeError", "Tried subscripting a list with wrong type."));
                        }
                        //            [&argument_eval](mts_error error, auto, auto) -> shared_mts_obj { return argument_eval; },
                        ),
                *s[0]->eval(arguments, variables), *s[1]->eval(arguments, variables));
        if (auto error = get<mts_error>(&*var)) return var;
        break;
      }
      case 3: {
        auto var = apply_visitor(
                hana::overload(
                        [&result, &argument_list](safeint index_i, safeint index_j, safeint index_k) -> shared_mts_obj {
                          int64_t i = index_i;
                          int64_t j = index_j;
                          int64_t k = index_k;
                          if (i < 0) i = argument_list.size() + i;
                          if (j < 0) j = argument_list.size() + j;
                          if (i >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(i) = " + std::to_string(i) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (j >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(j) = " + std::to_string(j) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (i < j) {// Normal case.
                            if (k <= 0)
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "Negative or zero step with positive direction."));
                            for (; i <= j; i += k) result.push_back(argument_list[i]);
                          } else {// Backwards.
                            if (k >= 0)
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "positive or zero step with negative direction."));
                            for (; i >= j; i += k) result.push_back(argument_list[i]);
                          }
                          return std::make_shared<mts_obj>(mts_none());
                        },
                        [&result, &argument_list](mts_none, safeint index_j, safeint index_k) -> shared_mts_obj {
                          int64_t i = 0;
                          int64_t j = index_j;
                          int64_t k = index_k;
                          if (j < 0) j = argument_list.size() + j;
                          if (j >= argument_list.size())
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError",
                                    "pos(j) = " + std::to_string(j) +
                                            " in List[i:j] with size(List) = " + std::to_string(argument_list.size())));
                          if (i < j) {// Normal case.
                            if (k <= 0)
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "Negative or zero step with positive direction."));
                            for (; i <= j; i += k) result.push_back(argument_list[i]);
                          } else {// Backwards.
                            if (k >= 0)
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "positive or zero step with negative direction."));
                            for (; i >= j; i += k) result.push_back(argument_list[i]);
                          }
                          return std::make_shared<mts_obj>(mts_none());
                        },
                        [&result, &argument_list](mts_none, mts_none, safeint index_k) -> shared_mts_obj {
                          int64_t i = 0;
                          int64_t j = argument_list.size() - 1;
                          int64_t k = index_k;
                          if (k <= 0)
                            return std::make_shared<mts_obj>(
                                    mts_error("SubscriptError", "Negative or zero step with positive direction."));
                          for (; i <= j; i += k) result.push_back(argument_list[i]);
                          return std::make_shared<mts_obj>(mts_none());
                        },
                        [](auto, auto, auto) -> shared_mts_obj {
                          return std::make_shared<mts_obj>(
                                  mts_error("TypeError", "Tried subscripting a list with wrong type."));
                        }
                        //                       [&argument_eval](mts_error, auto, auto, auto) -> shared_mts_obj {
                        //                         return argument_eval;
                        //                       },
                        ),
                *s[0]->eval(arguments, variables), *s[1]->eval(arguments, variables),
                *s[2]->eval(arguments, variables));
        if (auto error = get<mts_error>(&*var)) return var;
        break;
      }
    }
  }
  return result_shared_mts;
}
