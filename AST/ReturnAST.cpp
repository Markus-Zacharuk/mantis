#include "../Header.h"

shared_mts_obj ReturnAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  return std::make_shared<mts_obj>(mts_return<mts_obj>(value->eval(arguments, variables)));
}
