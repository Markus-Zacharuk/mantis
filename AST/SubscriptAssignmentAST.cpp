#include "../Header.h"

void SubscriptAssignmentAST::add_subscript(ExprAST *i) {
  std::vector<std::unique_ptr<ExprAST>> var;
  var.push_back(std::unique_ptr<ExprAST>(i));
  subscript.push_back(std::move(var));
}
void SubscriptAssignmentAST::add_subscript(ExprAST *i, ExprAST *j) {
  std::vector<std::unique_ptr<ExprAST>> var;
  var.push_back(std::unique_ptr<ExprAST>(i));
  var.push_back(std::unique_ptr<ExprAST>(j));
  subscript.push_back(std::move(var));
}
void SubscriptAssignmentAST::add_subscript(ExprAST *i, ExprAST *j, ExprAST *k) {
  std::vector<std::unique_ptr<ExprAST>> var;
  var.push_back(std::unique_ptr<ExprAST>(i));
  var.push_back(std::unique_ptr<ExprAST>(j));
  var.push_back(std::unique_ptr<ExprAST>(k));
  subscript.push_back(std::move(var));
}

shared_mts_obj SubscriptAssignmentAST::eval(const shared_future_map *const arguments,
                                            shared_mts_obj_map *const variables) {
  auto value_eval = value->eval(arguments, variables);
  auto argument_eval = argument->eval(arguments, variables);
  auto *argument_list_ptr = get<mts_list>(&*argument_eval);
  auto *argument_dict_ptr = get<mts_dict>(&*argument_eval);

  if (!(argument_list_ptr || argument_dict_ptr))
    return std::make_shared<mts_obj>(
            mts_error("TypeError", "Subscript of non-list/dict attempted (lhs of assignment '=')[1]."));

  if (argument_dict_ptr) {
    (*argument_dict_ptr)[*subscript[0][0]->eval(arguments, variables)] = *value_eval;
    return std::make_shared<mts_obj>(mts_none());
  }

  if (argument_list_ptr) {
    // Base case like "var[0] = var2", "var[1] = var[0]", etc.
    if (subscript.size() == 1 && subscript[0].size() == 1) {
      auto result = apply_visitor(
              hana::overload(
                      [&value_eval, argument_list_ptr](safeint index) -> shared_mts_obj {
                        int64_t i = index;
                        if (i >= 0 && i < int64_t(argument_list_ptr->size())) {
                          (*argument_list_ptr)[i] = *value_eval;
                          //					argument_list[i] = std::copy(Wrapper(value_eval_variant));
                          return std::make_shared<mts_obj>(mts_none());
                        }
                        if (i < 0 && i >= -int64_t(argument_list_ptr->size())) {
                          (*argument_list_ptr)[argument_list_ptr->size() + i] = *value_eval;
                          return std::make_shared<mts_obj>(mts_none());
                        }
                        return std::make_shared<mts_obj>(mts_error(
                                "TypeError", "Subscript indexed with wrong value: " + std::to_string(i) + "."));
                      },
                      [](auto) -> shared_mts_obj {
                        return std::make_shared<mts_obj>(mts_error("TypeError", "Subscript used with wrong type."));
                      }),
              *subscript[0][0]->eval(arguments, variables));
      if (auto result_error = get<mts_error>(&*result)) return result;
      return std::make_shared<mts_obj>(mts_none());
    }

    // Enhanced subscript-assignment requiring the rhs to be a list to. Looks like:
    // "var[0,1] = [1,2]", "var[:9] = var[-1:-10]", etc.
    auto value_list_ptr = get<mts_list>(&*value_eval);
    if (!value_list_ptr)
      return std::make_shared<mts_obj>(
              mts_error("TypeError", "Subscript of non-list attempted (rhs of assignment '='."));
    //    auto value_list_ptr = *value_eval_ptr;
    uint64_t counter = 0;

    for (const auto &s : subscript) {
      switch (s.size()) {
        case 1: {
          // counter keeps track of position on rhs.
          if (counter >= value_list_ptr->size())
            return std::make_shared<mts_obj>(
                    mts_error("SubscriptError", "Can't access Element (on rhs of assignment) at position " +
                                                        std::to_string(counter) + ", list size is " +
                                                        std::to_string(argument_list_ptr->size()) + "."));

          auto result = apply_visitor(
                  hana::overload(
                          [argument_list_ptr, value_list_ptr, counter](safeint index) -> shared_mts_obj {
                            int64_t i = index;
                            if (i >= 0 && i < int64_t(argument_list_ptr->size())) {
                              (*argument_list_ptr)[i] = (*value_list_ptr)[counter];
                              return nullptr;
                            }
                            if (i < 0 && i >= -int64_t(argument_list_ptr->size())) {
                              (*argument_list_ptr)[argument_list_ptr->size() + i] = (*value_list_ptr)[counter];
                              return nullptr;
                            }
                            return std::make_shared<mts_obj>(mts_error(
                                    "SubscriptError", "Can't access Element at position " + std::to_string(i) +
                                                              ", list size is " +
                                                              std::to_string(argument_list_ptr->size()) + "."));
                          },
                          [](auto) -> shared_mts_obj {
                            return std::make_shared<mts_obj>(mts_error("TypeError", "Subscript used with wrong type."));
                          }),
                  *s[0]->eval(arguments, variables));
          if (auto result_error = get<mts_error>(&*result)) return result;
          counter++;
          break;
        }
        case 2: {
          auto result = apply_visitor(
                  hana::overload(
                          [argument_list_ptr, value_list_ptr, &counter](safeint index_i,
                                                                        safeint index_j) -> shared_mts_obj {
                            int64_t i = index_i;
                            int64_t j = index_j;
                            if (i < 0) i = argument_list_ptr->size() + i;
                            if (j < 0) j = argument_list_ptr->size() + j;
                            if (i >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(i) = " + std::to_string(i) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (j >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(j) = " + std::to_string(j) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (i < j) {// Normal case.
                              // Handling out of range access on rhs.
                              if (j - i + counter > value_list_ptr->size())
                                return std::make_shared<mts_obj>(mts_error(
                                        "SubscriptError", "Can't access Element (on rhs of assignment) at positions " +
                                                                  std::to_string(counter) + " to " +
                                                                  std::to_string(counter + j - i) + ", list size is " +
                                                                  std::to_string(value_list_ptr->size()) + "."));

                              for (; i <= j; ++i) (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            } else {// Backwards.
                              // Handling out of range access on rhs.
                              if (i - j + counter > value_list_ptr->size())
                                return std::make_shared<mts_obj>(mts_error(
                                        "SubscriptError", "Can't access Element (on rhs of assignment) at positions " +
                                                                  std::to_string(counter) + " to " +
                                                                  std::to_string(counter + i - j) + ", list size is " +
                                                                  std::to_string(value_list_ptr->size()) + "."));

                              for (; i >= j; --i) (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            }
                            return nullptr;
                          },
                          [argument_list_ptr, value_list_ptr, &counter](mts_none n, safeint index_j) -> shared_mts_obj {
                            int64_t i = 0;
                            int64_t j = index_j;
                            if (j < 0) j = argument_list_ptr->size() + j;
                            if (i >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(i) = " + std::to_string(i) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (j >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(j) = " + std::to_string(j) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (i < j) {// Normal case.
                              // Handling out of range access on rhs.
                              if (j - i + counter > value_list_ptr->size())
                                return std::make_shared<mts_obj>(mts_error(
                                        "SubscriptError", "Can't access Element (on rhs of assignment) at positions " +
                                                                  std::to_string(counter) + " to " +
                                                                  std::to_string(counter + j - i) + ", list size is " +
                                                                  std::to_string(value_list_ptr->size()) + "."));

                              for (; i <= j; ++i) (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            } else {// Backwards.
                              // Handling out of range access on rhs.
                              if (i - j + counter > value_list_ptr->size())
                                return std::make_shared<mts_obj>(mts_error(
                                        "SubscriptError", "Can't access Element (on rhs of assignment) at positions " +
                                                                  std::to_string(counter) + " to " +
                                                                  std::to_string(counter + i - j) + ", list size is " +
                                                                  std::to_string(value_list_ptr->size()) + "."));

                              for (; i >= j; --i) (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            }
                            return nullptr;
                          },
                          [argument_list_ptr, value_list_ptr, &counter](safeint index_i, mts_none n) -> shared_mts_obj {
                            int64_t i = index_i;
                            int64_t j = argument_list_ptr->size() - 1;
                            if (i < 0) i = argument_list_ptr->size() + i;
                            if (i >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(i) = " + std::to_string(i) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (j >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(j) = " + std::to_string(j) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (i < j) {// Normal case.
                              // Handling out of range access on rhs.
                              if (j - i + counter > value_list_ptr->size())
                                return std::make_shared<mts_obj>(mts_error(
                                        "SubscriptError", "Can't access Element (on rhs of assignment) at positions " +
                                                                  std::to_string(counter) + " to " +
                                                                  std::to_string(counter + j - i) + ", list size is " +
                                                                  std::to_string(value_list_ptr->size()) + "."));

                              for (; i <= j; ++i) (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            } else {// Backwards.
                              // Handling out of range access on rhs.
                              if (i - j + counter > value_list_ptr->size())
                                return std::make_shared<mts_obj>(mts_error(
                                        "SubscriptError", "Can't access Element (on rhs of assignment) at positions " +
                                                                  std::to_string(counter) + " to " +
                                                                  std::to_string(counter + i - j) + ", list size is " +
                                                                  std::to_string(value_list_ptr->size()) + "."));

                              for (; i >= j; --i) (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            }
                            return nullptr;
                          },
                          [argument_list_ptr, value_list_ptr, &counter](mts_none, mts_none) -> shared_mts_obj {
                            int64_t i = 0;
                            int64_t j = argument_list_ptr->size() - 1;
                            for (; i <= j; ++i) (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            return nullptr;
                          },
                          [](auto, auto) -> shared_mts_obj {
                            return std::make_shared<mts_obj>(
                                    mts_error("TypeError", "Tried subscripting a list with wrong type."));
                          }),
                  *s[0]->eval(arguments, variables), *s[1]->eval(arguments, variables));
          if (auto result_error = get<mts_error>(&*result)) return result;
          break;
        }
        case 3: {
          auto result = apply_visitor(
                  hana::overload(
                          [argument_list_ptr, value_list_ptr, &counter](safeint index_i, safeint index_j,
                                                                        safeint index_k) -> shared_mts_obj {
                            int64_t i = index_i;
                            int64_t j = index_j;
                            int64_t k = index_k;
                            if (i < 0) i = argument_list_ptr->size() + i;
                            if (j < 0) j = argument_list_ptr->size() + j;
                            if (i >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(i) = " + std::to_string(i) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (j >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(j) = " + std::to_string(j) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (i < j) {// Normal case.
                              if (k <= 0)
                                return std::make_shared<mts_obj>(
                                        mts_error("SubscriptError", "Negative or zero step with positive direction."));
                              for (; i <= j; i += k) {
                                if (counter >= value_list_ptr->size())
                                  return std::make_shared<mts_obj>(mts_error(
                                          "SubscriptError", "Can't access Element (on rhs of assignment) at position " +
                                                                    std::to_string(counter) + ", list size is " +
                                                                    std::to_string(value_list_ptr->size()) + "."));
                                (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                              }
                            } else {// Backwards.
                              if (k >= 0)
                                return std::make_shared<mts_obj>(
                                        mts_error("SubscriptError", "positive or zero step with negative direction."));
                              for (; i >= j; i += k) {
                                if (counter >= value_list_ptr->size())
                                  return std::make_shared<mts_obj>(mts_error(
                                          "SubscriptError", "Can't access Element (on rhs of assignment) at position " +
                                                                    std::to_string(counter) + ", list size is " +
                                                                    std::to_string(value_list_ptr->size()) + "."));
                                (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                              }
                            }
                            return nullptr;
                          },
                          [argument_list_ptr, value_list_ptr, &counter](mts_none n, safeint index_j,
                                                                        safeint index_k) -> shared_mts_obj {
                            int64_t i = 0;
                            int64_t j = index_j;
                            int64_t k = index_k;
                            if (j < 0) j = argument_list_ptr->size() + j;
                            if (j >= argument_list_ptr->size())
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "pos(j) = " + std::to_string(j) +
                                                                          " in List[i:j] with size(List) = " +
                                                                          std::to_string(argument_list_ptr->size())));
                            if (i < j) {// Normal case.
                              if (k <= 0)
                                return std::make_shared<mts_obj>(
                                        mts_error("SubscriptError", "Negative or zero step with positive direction."));
                              for (; i <= j; i += k) {
                                if (counter >= value_list_ptr->size())
                                  return std::make_shared<mts_obj>(mts_error(
                                          "SubscriptError", "Can't access Element (on rhs of assignment) at position " +
                                                                    std::to_string(counter) + ", list size is " +
                                                                    std::to_string(value_list_ptr->size()) + "."));
                                (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                              }
                            } else {// Backwards.
                              if (k >= 0)
                                return std::make_shared<mts_obj>(
                                        mts_error("SubscriptError", "positive or zero step with negative direction."));
                              for (; i >= j; i += k) {
                                if (counter >= value_list_ptr->size())
                                  return std::make_shared<mts_obj>(mts_error(
                                          "SubscriptError", "Can't access Element (on rhs of assignment) at position " +
                                                                    std::to_string(counter) + ", list size is " +
                                                                    std::to_string(value_list_ptr->size()) + "."));
                                (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                              }
                            }
                            return nullptr;
                          },
                          [argument_list_ptr, value_list_ptr, &counter](mts_none n_1, mts_none n_2,
                                                                        safeint index_k) -> shared_mts_obj {
                            int64_t i = 0;
                            int64_t j = argument_list_ptr->size() - 1;
                            int64_t k = index_k;
                            if (k <= 0)
                              return std::make_shared<mts_obj>(
                                      mts_error("SubscriptError", "Negative or zero step with positive direction."));
                            for (; i <= j; i += k) {
                              if (counter >= value_list_ptr->size())
                                return std::make_shared<mts_obj>(mts_error(
                                        "SubscriptError", "Can't access Element (on rhs of assignment) at position " +
                                                                  std::to_string(counter) + ", list size is " +
                                                                  std::to_string(value_list_ptr->size()) + "."));
                              (*argument_list_ptr)[i] = (*value_list_ptr)[counter++];
                            }
                            return nullptr;
                          },

                          [](auto, auto, auto) -> shared_mts_obj {
                            return std::make_shared<mts_obj>(
                                    mts_error("TypeError", "Tried subscripting a list with wrong type."));
                          }),
                  *s[0]->eval(arguments, variables), *s[1]->eval(arguments, variables),
                  *s[2]->eval(arguments, variables));
          if (auto result_error = get<mts_error>(&*result)) return result;
          break;
        }
      }
    }
    //    return argument_list_ptr;

  } else {
    return std::make_shared<mts_obj>(
            mts_error("TypeError", "Subscript of non-list/dict attempted (lhs of assignment '=')."));
  }
  return std::make_shared<mts_obj>(mts_none());
}
