#include "../Header.h"


//using shared_list 		= std::shared_ptr<std::vector<Wrapper>>;

shared_mts_obj ListAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  auto result = std::make_shared<mts_obj>(mts_list());
  auto &result_list = get<mts_list>(*result);
  result_list.reserve(list.size());
  std::vector<std::future<mts_obj>> futures;
  for (const auto &element : list) {
    futures.push_back(std::async(std::launch::async, [arguments, variables, &element]() -> mts_obj {
      return *(element->eval(arguments, variables));}));
  }

  for (auto &future : futures)  result_list.push_back(future.get());
  return result;
}
