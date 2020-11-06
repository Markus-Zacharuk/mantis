#include "../Header.h"

shared_mts_obj IntAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  auto value_mpz_ptr = get<mpz_class>(value.get());
  if (value_mpz_ptr->fits_slong_p())
    return std::make_shared<mts_obj>(safeint(value_mpz_ptr->get_si()));
//    *value = safeint(value_mpz_ptr->get_si());
  return value;
}

std::string IntAST::graphgen(std::string origin) {
  std::string result = std::to_string(counter) + " [label=\"";
  result += get<mpz_class>(*value).get_str();
  result += "\"];\n";
  result += origin + " -> " + std::to_string(counter++) + ";\n";
  return result;
}
