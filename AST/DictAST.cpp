#include "../Header.h"

void DictAST::add_entry(ExprAST *from, ExprAST *to) {
  dict.push_back(std::make_pair(std::unique_ptr<ExprAST>(from), std::unique_ptr<ExprAST>(to)));
}

shared_mts_obj DictAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  auto result = std::make_shared<mts_obj>(mts_dict());
  auto &result_dict = get<mts_dict>(*result);
  std::vector<std::future<std::pair<mts_obj, mts_obj>>> futures;
  for (const auto &entry : dict) {
    futures.push_back(std::async(std::launch::async, [arguments, variables, &entry]() -> std::pair<mts_obj, mts_obj> {
      return std::make_pair(*(entry.first->eval(arguments, variables)), (*entry.second->eval(arguments, variables)));
    }));
  }

  for (auto &future : futures) result_dict.insert(future.get());
  return result;
}