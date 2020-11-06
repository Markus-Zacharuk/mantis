#include "../Header.h"

std::string BinaryOpAST::graphgen(std::string origin) {
  std::string pos = std::to_string(counter);
  std::string result = std::to_string(counter) + " [label=\"" + get_op_string(op) + "\"];\n";
  result += origin + " -> " + std::to_string(counter++) + ";\n";
  result += lhs->graphgen(pos);
  result += rhs->graphgen(pos);
  return result;
}

shared_mts_obj add_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj sub_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj mul_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj div_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj rest_binary(               shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj smaller_binary(            shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj bigger_binary(             shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj smaller_or_equal_binary(   shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj bigger_or_equal_binary(    shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj unequal_binary(            shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj equal_binary(              shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj and_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj or_binary(                 shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj right_implication_binary(  shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj equivalent_binary(         shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj xor_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj pow_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj gcd_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj lcm_binary(                shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj rational_binary(           shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj is_prime_binary(           shared_mts_obj &lhs, shared_mts_obj &rhs);
shared_mts_obj is_key_binary(             shared_mts_obj &lhs, shared_mts_obj &rhs);

shared_mts_obj BinaryOpAST::eval(const shared_future_map *const arguments, shared_mts_obj_map *const variables) {
  auto lhs_future = std::async(
          std::launch::async,
          [arguments, variables](ExprAST *lhs) -> shared_mts_obj { return lhs->eval(arguments, variables); },
          lhs.get());
  auto rhs_future = std::async(
          std::launch::async,
          [arguments, variables](ExprAST *rhs) -> shared_mts_obj { return rhs->eval(arguments, variables); },
          rhs.get());
  auto lhs_eval = lhs_future.get();
  auto rhs_eval = rhs_future.get();
  switch (op) {
    case '+':	    return add_binary(                lhs_eval, rhs_eval);
    case '-':	    return sub_binary(                lhs_eval, rhs_eval);
    case '*':	    return mul_binary(                lhs_eval, rhs_eval);
    case '/':	    return div_binary(                lhs_eval, rhs_eval);
    case '%':	    return rest_binary(               lhs_eval, rhs_eval);
    case '<':	    return smaller_binary(            lhs_eval, rhs_eval);
    case '>':	    return bigger_binary(             lhs_eval, rhs_eval);
    case BEQL:	    return bigger_or_equal_binary(    lhs_eval, rhs_eval);
    case SEQL:      return smaller_or_equal_binary(   lhs_eval, rhs_eval);
    case EQL:	    return equal_binary(              lhs_eval, rhs_eval);
    case UNEQL:	    return unequal_binary(            lhs_eval, rhs_eval);

    case '&':	    return and_binary(                lhs_eval, rhs_eval);
    case '|':	    return or_binary(                 lhs_eval, rhs_eval);
    case RIMP:	    return right_implication_binary(  lhs_eval, rhs_eval);
    case EQV:	    return equivalent_binary(         lhs_eval, rhs_eval);
    case '^':	    return xor_binary(                lhs_eval, rhs_eval);

    case POW:	    return pow_binary(                lhs_eval, rhs_eval);
    case GCD:	    return gcd_binary(                lhs_eval, rhs_eval);
    case LCM:	    return lcm_binary(                lhs_eval, rhs_eval);
    case RATIONAL:  return rational_binary(           lhs_eval, rhs_eval);
    case ISPRIME:	return is_prime_binary(           lhs_eval, rhs_eval);
    case IS_KEY:    return is_key_binary(             lhs_eval, rhs_eval);
    default:
      return std::make_shared<mts_obj>(
              mts_error("ParsingError", "Unknown Binary Operand: " + get_op_string(op) + "\n"));
  }
}

shared_mts_obj add_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz += rhs_mpz;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpz += lhs_mpz;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz + rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz += int64_t(rhs_int);
                                   return lhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz + int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs.use_count() == 1) {
                                   rhs_mpz += int64_t(lhs_int);
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(int64_t(lhs_int) + rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpq += rhs_mpq;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpq += lhs_mpq;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpq_class(lhs_mpq + rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpreal += rhs_mpreal;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpreal += lhs_mpreal;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpreal(lhs_mpreal + rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint &lhs_safeint, safeint &rhs_safeint) -> shared_mts_obj {
                                 //                   std::cout << lhs_safeint << " + " << rhs_safeint << " | " << lhs.use_count() << "#, "
                                 //                           << rhs.use_count() << "#\n";
                                 if (lhs.use_count() == 1) {
                                   try {
                                     lhs_safeint = lhs_safeint + rhs_safeint;
                                     return lhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(
                                             mpz_class(mpz_class(int64_t(lhs_safeint)) + int64_t(rhs_safeint)));
                                   }
                                 } else if (rhs.use_count() == 1) {
                                   try {
                                     rhs_safeint = lhs_safeint + rhs_safeint;
                                     return rhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(
                                             mpz_class(mpz_class(int64_t(lhs_safeint)) + int64_t(rhs_safeint)));
                                   }
                                 }
                                 try {
                                   return std::make_shared<mts_obj>(safeint(lhs_safeint + rhs_safeint));
                                 } catch (const std::exception &e) {
                                   return std::make_shared<mts_obj>(
                                           mpz_class(mpz_class(int64_t(lhs_safeint)) + int64_t(rhs_safeint)));
                                 }
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '+'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj sub_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz -= rhs_mpz;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpz -= lhs_mpz;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz - rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz -= int64_t(rhs_int);
                                   return lhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz - int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs.use_count() == 1) {
                                   rhs_mpz -= int64_t(lhs_int);
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(int64_t(lhs_int) - rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpq -= rhs_mpq;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpq -= lhs_mpq;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpq_class(lhs_mpq - rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpreal -= rhs_mpreal;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpreal -= lhs_mpreal;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpreal(lhs_mpreal - rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint lhs_safeint, safeint rhs_safeint) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   try {
                                     *lhs = lhs_safeint - rhs_safeint;
                                     return lhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(
                                             mpz_class(int64_t(lhs_safeint) - int64_t(rhs_safeint)));
                                   }
                                 } else if (rhs.use_count() == 1) {
                                   try {
                                     *rhs = lhs_safeint - rhs_safeint;
                                     return rhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(
                                             mpz_class(mpz_class(int64_t(lhs_safeint)) - int64_t(rhs_safeint)));
                                   }
                                 }
                                 try {
                                   return std::make_shared<mts_obj>(safeint(lhs_safeint - rhs_safeint));
                                 } catch (const std::exception &e) {
                                   return std::make_shared<mts_obj>(
                                           mpz_class(mpz_class(int64_t(lhs_safeint)) - int64_t(rhs_safeint)));
                                 }
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '-'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj mul_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz *= rhs_mpz;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpz *= lhs_mpz;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz * rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz *= int64_t(rhs_int);
                                   return lhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz * int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs.use_count() == 1) {
                                   rhs_mpz *= int64_t(lhs_int);
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(int64_t(lhs_int) * rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpq *= rhs_mpq;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpq *= lhs_mpq;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpq_class(lhs_mpq * rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   lhs_mpreal *= rhs_mpreal;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpreal *= lhs_mpreal;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpreal(lhs_mpreal * rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint lhs_safeint, safeint rhs_safeint) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   try {
                                     *lhs = lhs_safeint * rhs_safeint;
                                     return lhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(
                                             mpz_class(int64_t(lhs_safeint) * int64_t(rhs_safeint)));
                                   }
                                 } else if (rhs.use_count() == 1) {
                                   try {
                                     *rhs = lhs_safeint * rhs_safeint;
                                     return rhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(
                                             mpz_class(mpz_class(int64_t(lhs_safeint)) * int64_t(rhs_safeint)));
                                   }
                                 }
                                 try {
                                   return std::make_shared<mts_obj>(lhs_safeint * rhs_safeint);
                                 } catch (const std::exception &e) {
                                   return std::make_shared<mts_obj>(
                                           mpz_class(mpz_class(int64_t(lhs_safeint)) * int64_t(rhs_safeint)));
                                 }
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '*'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj div_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs_mpz == 0)
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '%'"));
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz /= rhs_mpz;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpz /= lhs_mpz;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz / rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 if (rhs_int == 0)
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '%'"));
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz /= int64_t(rhs_int);
                                   return lhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz * int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs_mpz == 0)
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '%'"));
                                 if (rhs.use_count() == 1) {
                                   rhs_mpz /= int64_t(lhs_int);
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(int64_t(lhs_int) / rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 if (rhs_mpq == 0)
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '%'"));
                                 if (lhs.use_count() == 1) {
                                   lhs_mpq /= rhs_mpq;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpq /= lhs_mpq;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpq_class(lhs_mpq / rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 // IEEE?                    if (rhs_mpz == 0) return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '/'"));
                                 if (lhs.use_count() == 1) {
                                   lhs_mpreal /= rhs_mpreal;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpreal /= lhs_mpreal;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpreal(lhs_mpreal / rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint lhs_safeint, safeint rhs_safeint) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   try {
                                     *lhs = lhs_safeint / rhs_safeint;
                                     return lhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(mts_error("ZeroDivisionError"));
                                   }
                                 } else if (rhs.use_count() == 1) {
                                   try {
                                     *rhs = lhs_safeint / rhs_safeint;
                                     return rhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(mts_error("ZeroDivisionError"));
                                   }
                                 }
                                 try {
                                   return std::make_shared<mts_obj>(safeint(lhs_safeint / rhs_safeint));
                                 } catch (const std::exception &e) {
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError"));
                                 }
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '/'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj rest_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs_mpz == 0)
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '%'"));
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz %= rhs_mpz;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   rhs_mpz %= lhs_mpz;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz % rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 if (rhs_int == 0)
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '%'"));
                                 if (lhs.use_count() == 1) {
                                   lhs_mpz %= int64_t(rhs_int);
                                   return lhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(lhs_mpz % int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs_mpz == 0)
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError", "Operator '%'"));
                                 if (rhs.use_count() == 1) {
                                   rhs_mpz %= int64_t(lhs_int);
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(int64_t(lhs_int) % rhs_mpz));
                               },


                               [&lhs, &rhs](safeint lhs_safeint, safeint rhs_safeint) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   try {
                                     *lhs = lhs_safeint % rhs_safeint;
                                     return lhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(mts_error("ZeroDivisionError"));
                                   }
                                 } else if (rhs.use_count() == 1) {
                                   try {
                                     *rhs = lhs_safeint % rhs_safeint;
                                     return rhs;
                                   } catch (const std::exception &e) {
                                     return std::make_shared<mts_obj>(mts_error("ZeroDivisionError"));
                                   }
                                 }
                                 try {
                                   return std::make_shared<mts_obj>(safeint(lhs_safeint % rhs_safeint));
                                 } catch (const std::exception &e) {
                                   return std::make_shared<mts_obj>(mts_error("ZeroDivisionError"));
                                 }
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '%'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj smaller_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz < rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz < int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(int64_t(lhs_int) < rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpq < rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpreal < rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int < rhs_int));
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '<'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj bigger_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz > rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz > int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(int64_t(lhs_int) > rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpq > rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpreal > rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int > rhs_int));
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '>'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj smaller_or_equal_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz <= rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz <= int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(int64_t(lhs_int) <= rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpq <= rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpreal <= rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int <= rhs_int));
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '<='"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj bigger_or_equal_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz >= rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz >= int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(int64_t(lhs_int) >= rhs_mpz));
                               },

                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpq >= rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpreal >= rhs_mpreal));
                               },

                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int >= rhs_int));
                               },

                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '>='"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj unequal_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](bool lhs_bool, bool rhs_bool) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   *lhs = lhs_bool != rhs_bool;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   *rhs = lhs_bool != rhs_bool;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(bool(lhs_bool != rhs_bool));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz != rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz != int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(int64_t(lhs_int) != rhs_mpz));
                               },
                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpq != rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpreal != rhs_mpreal));
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int != rhs_int));
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '!='"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj equal_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](bool lhs_bool, bool rhs_bool) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   *lhs = lhs_bool == rhs_bool;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   *rhs = lhs_bool == rhs_bool;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(bool(lhs_bool == rhs_bool));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz == rhs_mpz));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz == int64_t(rhs_int)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(int64_t(lhs_int) == rhs_mpz));
                               },
                               [&lhs, &rhs](mpq_class &lhs_mpq, mpq_class &rhs_mpq) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpq == rhs_mpq));
                               },
                               [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpreal == rhs_mpreal));
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int == rhs_int));
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '=='"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj and_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](bool lhs_bool, bool rhs_bool) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   *lhs = lhs_bool && rhs_bool;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   *rhs = lhs_bool && rhs_bool;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(bool(lhs_bool && rhs_bool));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz == 1 && rhs_mpz == 1));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz == 1 && rhs_int == 1));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int == 1 && rhs_mpz == 1));
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int == 1 && rhs_int == 1));
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '&'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj or_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](bool lhs_bool, bool rhs_bool) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   *lhs = lhs_bool || rhs_bool;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   *rhs = lhs_bool || rhs_bool;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(bool(lhs_bool || rhs_bool));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz == 1 || rhs_mpz == 1));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_mpz == 1 || rhs_int == 1));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int == 1 || rhs_mpz == 1));
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(lhs_int == 1 || rhs_int == 1));
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '|'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj right_implication_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](bool lhs_bool, bool rhs_bool) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   *lhs = (!lhs_bool) || rhs_bool;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   *rhs = (!lhs_bool) || rhs_bool;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(bool((!lhs_bool) || rhs_bool));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool((lhs_mpz == 0) || (rhs_mpz == 1)));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool((lhs_mpz == 0) || (rhs_int == 1)));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool((lhs_int == 0) || (rhs_mpz == 1)));
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool((lhs_int == 0) || (rhs_int == 1)));
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '->'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj equivalent_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](bool lhs_bool, bool rhs_bool) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   *lhs = lhs_bool == rhs_bool;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   *rhs = lhs_bool == rhs_bool;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(bool(lhs_bool == rhs_bool));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_mpz == 1) && (rhs_mpz == 1)) ||
                                                                       ((lhs_mpz == 0) && (rhs_mpz == 0))));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_mpz == 1) && (rhs_int == 1)) ||
                                                                       ((lhs_mpz == 0) && (rhs_int == 0))));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_int == 1) && (rhs_mpz == 1)) ||
                                                                       ((lhs_int == 0) && (rhs_mpz == 0))));
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_int == 1) && (rhs_int == 1)) ||
                                                                       ((lhs_int == 0) && (rhs_int == 0))));
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '<->'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj xor_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](bool lhs_bool, bool rhs_bool) -> shared_mts_obj {
                                 if (lhs.use_count() == 1) {
                                   *lhs = lhs_bool != rhs_bool;
                                   return lhs;
                                 } else if (rhs.use_count() == 1) {
                                   *rhs = lhs_bool != rhs_bool;
                                   return rhs;
                                 }
                                 return std::make_shared<mts_obj>(bool(lhs_bool != rhs_bool));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_mpz == 1) && (rhs_mpz == 0)) ||
                                                                       ((lhs_mpz == 0) && (rhs_mpz == 1))));
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_mpz == 1) && (rhs_int == 0)) ||
                                                                       ((lhs_mpz == 0) && (rhs_int == 1))));
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_int == 1) && (rhs_mpz == 0)) ||
                                                                       ((lhs_int == 0) && (rhs_mpz == 1))));
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(bool(((lhs_int == 1) && (rhs_int == 0)) ||
                                                                       ((lhs_int == 0) && (rhs_int == 1))));
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '^'"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj pow_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(
          hana::overload(
                  [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                    auto exp = rhs_mpz.get_ui();
                    auto comparison = cmp(exp, abs(rhs_mpz));// Could be optimized.
                    if (comparison == 0) {
                      if (sgn(rhs_mpz) >= 0) {
                        if (lhs.use_count() == 1) {
                          mpz_pow_ui(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), exp);
                          return lhs;
                        } else if (rhs.use_count() == 1) {
                          mpz_pow_ui(rhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), exp);
                          return rhs;
                        } else {
                          auto result = std::make_shared<mts_obj>(mpz_class());
                          mpz_pow_ui(get<mpz_class>(*result).get_mpz_t(), lhs_mpz.get_mpz_t(), exp);
                          return result;
                        }
                      } else {
                        if (lhs.use_count() == 1) {
                          mpz_root(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), exp);
                          return lhs;
                        } else if (rhs.use_count() == 1) {
                          mpz_root(rhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), exp);
                          return rhs;
                        } else {
                          auto result = std::make_shared<mts_obj>(mpz_class());
                          mpz_root(get<mpz_class>(*result).get_mpz_t(), lhs_mpz.get_mpz_t(), exp);
                          return result;
                        }
                      }
                    } else
                      return std::make_shared<mts_obj>(mts_error(
                              "ValueError",
                              "Can't convert exponent to unsigned integer. Maybe the exponent is too big? exp = " +
                                      rhs_mpz.get_str()));
                  },
                  [&lhs, &rhs](mpz_class &lhs_mpz, safeint &rhs_int) -> shared_mts_obj {
                    if (rhs_int >= 0) {
                      if (lhs.use_count() == 1) {
                        mpz_pow_ui(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), int64_t(rhs_int));
                        return lhs;
                      } else {
                        auto result = std::make_shared<mts_obj>(mpz_class());
                        mpz_pow_ui(get<mpz_class>(*result).get_mpz_t(), lhs_mpz.get_mpz_t(), int64_t(rhs_int));
                        return result;
                      }
                    } else {
                      if (lhs.use_count() == 1) {
                        mpz_root(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), int64_t(rhs_int));
                        return lhs;
                      } else {
                        auto result = std::make_shared<mts_obj>(mpz_class());
                        mpz_root(get<mpz_class>(*result).get_mpz_t(), lhs_mpz.get_mpz_t(), int64_t(rhs_int));
                        return result;
                      }
                    }
                    return std::make_shared<mts_obj>(mts_error(
                            "ValueError",
                            "Can't convert exponent to unsigned integer. Maybe the exponent is too big? exp = " +
                                    std::to_string(int64_t(rhs_int))));
                  },

                  [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                    auto exp = rhs_mpz.get_ui();
                    auto comparison = cmp(exp, abs(rhs_mpz));
                    if (comparison == 0) {
                      if (sgn(rhs_mpz) >= 0) {
                        if (rhs.use_count() == 1) {
                          mpz_pow_ui(rhs_mpz.get_mpz_t(), mpz_class(int64_t(lhs_int)).get_mpz_t(), exp);
                          return rhs;
                        } else {
                          auto result = std::make_shared<mts_obj>();
                          mpz_pow_ui(get<mpz_class>(*result).get_mpz_t(), mpz_class(int64_t(lhs_int)).get_mpz_t(), exp);
                          return result;
                        }
                      } else {
                        if (rhs.use_count() == 1) {
                          mpz_root(rhs_mpz.get_mpz_t(), mpz_class(int64_t(lhs_int)).get_mpz_t(), exp);
                          return rhs;
                        } else {
                          auto result = std::make_shared<mts_obj>();
                          mpz_root(get<mpz_class>(*result).get_mpz_t(), mpz_class(int64_t(lhs_int)).get_mpz_t(), exp);
                          return result;
                        }
                      }
                    }
                    return std::make_shared<mts_obj>(mts_error(
                            "ValueError", "Can't convert exponent to unsigned integer. exp = " + rhs_mpz.get_str()));
                  },
                  [&lhs, &rhs](mpreal &lhs_mpreal, mpreal &rhs_mpreal) -> shared_mts_obj {
                    if (lhs.use_count() == 1) {
                      mpfr_pow(lhs_mpreal.mpfr_ptr(), lhs_mpreal.mpfr_ptr(), rhs_mpreal.mpfr_ptr(),
                               mpreal::get_default_rnd());
                      return lhs;
                    } else if (rhs.use_count() == 1) {
                      mpfr_pow(rhs_mpreal.mpfr_ptr(), lhs_mpreal.mpfr_ptr(), rhs_mpreal.mpfr_ptr(),
                               mpreal::get_default_rnd());
                      return rhs;
                    }
                    return std::make_shared<mts_obj>(mpreal(pow(lhs_mpreal, rhs_mpreal)));
                  },

                  [&lhs, &rhs](safeint &lhs_int, safeint &rhs_int) -> shared_mts_obj {
                    auto result = std::make_shared<mts_obj>(mpz_class());
                    if (rhs_int >= 0) mpz_ui_pow_ui(get<mpz_class>(*result).get_mpz_t(), int64_t(lhs_int), int64_t(rhs_int));
                    else if (lhs_int < 0)
                      mpz_root(get<mpz_class>(*result).get_mpz_t(), mpz_class(int64_t(lhs_int)).get_mpz_t(),
                               mpz_class(int64_t(rhs_int)).get_ui());
                    if (get<mpz_class>(*result).fits_slong_p()) {
                      if (lhs.use_count() == 1) {
                        lhs_int = get<mpz_class>(*result).get_si();
                        return lhs;
                      } else if (rhs.use_count() == 1) {
                        rhs_int = get<mpz_class>(*result).get_si();
                        return rhs;
                      } else {
                        return std::make_shared<mts_obj>(safeint(get<mpz_class>(*result).get_si()));
                      }
                    }
                    return result;
                  },
                  [](auto, auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '**'"));
                  }),
          *lhs, *rhs);
}

shared_mts_obj gcd_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(
          hana::overload(
                  [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (lhs.use_count() == 1) {
                      mpz_gcd(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), rhs_mpz.get_mpz_t());
                      return lhs;
                    } else if (rhs.use_count() == 1) {
                      mpz_gcd(rhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), rhs_mpz.get_mpz_t());
                      return rhs;
                    }
                    return std::make_shared<mts_obj>(mpz_class(gcd(lhs_mpz, rhs_mpz)));
                  },
                  [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                    if (lhs.use_count() == 1) {
                      mpz_gcd(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), mpz_class(int64_t(rhs_int)).get_mpz_t());
                      return lhs;
                    } else if (rhs.use_count() == 1) {
                      auto result = std::make_shared<mts_obj>(mpz_class(gcd(lhs_mpz, mpz_class(int64_t(rhs_int)))));
                      if (get<mpz_class>(*result).fits_slong_p()) {
                        rhs_int = get<mpz_class>(*result).get_si();
                        return rhs;
                      }
                      return result;
                    }
                    return std::make_shared<mts_obj>(mpz_class(gcd(lhs_mpz, mpz_class(int64_t(rhs_int)))));
                  },
                  [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (lhs.use_count() == 1) {
                      auto result = std::make_shared<mts_obj>(mpz_class(gcd(mpz_class(int64_t(lhs_int)), rhs_mpz)));
                      if (get<mpz_class>(*result).fits_slong_p()) {
                        lhs_int = get<mpz_class>(*result).get_si();
                        return lhs;
                      }
                      return result;
                    } else if (rhs.use_count() == 1) {
                      mpz_gcd(rhs_mpz.get_mpz_t(), rhs_mpz.get_mpz_t(), mpz_class(int64_t(lhs_int)).get_mpz_t());
                      return rhs;
                    }
                    return std::make_shared<mts_obj>(mpz_class(gcd(rhs_mpz, mpz_class(int64_t(lhs_int)))));
                  },
                  [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                    auto result = std::make_shared<mts_obj>(
                            mpz_class(gcd(mpz_class(int64_t(lhs_int)), mpz_class(int64_t(rhs_int)))));
                    if (get<mpz_class>(*result).fits_slong_p()) {
                      if (lhs.use_count() == 1) {
                        lhs_int = get<mpz_class>(*result).get_si();
                        return lhs;
                      } else if (rhs.use_count() == 1) {
                        rhs_int = get<mpz_class>(*result).get_si();
                        return rhs;
                      }
                    }
                    return result;
                  },
                  [](auto, auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Function 'gcd'"));
                  }),
          *lhs, *rhs);
}

shared_mts_obj lcm_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(
          hana::overload(
                  [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (lhs.use_count() == 1) {
                      mpz_lcm(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), rhs_mpz.get_mpz_t());
                      return lhs;
                    } else if (rhs.use_count() == 1) {
                      mpz_lcm(rhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), rhs_mpz.get_mpz_t());
                      return rhs;
                    }
                    return std::make_shared<mts_obj>(mpz_class(gcd(lhs_mpz, rhs_mpz)));
                  },
                  [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                    if (lhs.use_count() == 1) {
                      mpz_lcm(lhs_mpz.get_mpz_t(), lhs_mpz.get_mpz_t(), mpz_class(int64_t(rhs_int)).get_mpz_t());
                      return lhs;
                    }
                    return std::make_shared<mts_obj>(mpz_class(lcm(lhs_mpz, mpz_class(int64_t(rhs_int)))));
                  },
                  [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (rhs.use_count() == 1) {
                      mpz_lcm(rhs_mpz.get_mpz_t(), rhs_mpz.get_mpz_t(), mpz_class(int64_t(lhs_int)).get_mpz_t());
                      return rhs;
                    }
                    return std::make_shared<mts_obj>(mpz_class(gcd(rhs_mpz, mpz_class(int64_t(lhs_int)))));
                  },
                  [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                    auto result = std::make_shared<mts_obj>(
                            mpz_class(lcm(mpz_class(int64_t(lhs_int)), mpz_class(int64_t(rhs_int)))));
                    if (get<mpz_class>(*result).fits_slong_p()) {
                      if (lhs.use_count() == 1) {
                        lhs_int = get<mpz_class>(*result).get_si();
                        return lhs;
                      } else if (rhs.use_count() == 1) {
                        rhs_int = get<mpz_class>(*result).get_si();
                        return rhs;
                      }
                    }
                    return result;
                  },
                  [](auto, auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Function 'lcm'"));
                  }),
          *lhs, *rhs);
}

shared_mts_obj rational_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 auto result = std::make_shared<mts_obj>(mpq_class(lhs_mpz, rhs_mpz));
                                 get<mpq_class>(*result).canonicalize();
                                 return result;
                               },
                               [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                                 auto result = std::make_shared<mts_obj>(mpq_class(lhs_mpz, int64_t(rhs_int)));
                                 get<mpq_class>(*result).canonicalize();
                                 return result;
                               },
                               [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                                 auto result = std::make_shared<mts_obj>(mpq_class(int64_t(lhs_int), rhs_mpz));
                                 get<mpq_class>(*result).canonicalize();
                                 return result;
                               },
                               [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                                 auto result = std::make_shared<mts_obj>(mpq_class(int64_t(lhs_int), int64_t(rhs_int)));
                                 get<mpq_class>(*result).canonicalize();
                                 return result;
                               },
                               [](auto, auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(
                                         mts_error("TypeError", "Function 'rational' (conversion)"));
                               }),
                       *lhs, *rhs);
}

shared_mts_obj is_prime_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(
          hana::overload(
                  [&lhs, &rhs](mpz_class &lhs_mpz, mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (rhs_mpz < 1)
                      return std::make_shared<mts_obj>(
                              mts_error("ValueError", "Second arg of function 'isprime' must be >= 1"));
                    if (rhs_mpz.fits_sint_p())
                      return std::make_shared<mts_obj>(
                              safeint(mpz_probab_prime_p(lhs_mpz.get_mpz_t(), rhs_mpz.get_si())));
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "Second arg of function 'isprime' must fit int64_t"));
                  },
                  [&lhs, &rhs](mpz_class &lhs_mpz, safeint rhs_int) -> shared_mts_obj {
                    if (rhs_int < 1)
                      return std::make_shared<mts_obj>(
                              mts_error("ValueError", "Second arg of function 'isprime' must be >= 1"));
                    return std::make_shared<mts_obj>(safeint(mpz_probab_prime_p(lhs_mpz.get_mpz_t(), rhs_int)));
                  },
                  [&lhs, &rhs](safeint lhs_int, mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (rhs_mpz < 1)
                      return std::make_shared<mts_obj>(
                              mts_error("ValueError", "Second arg of function 'isprime' must be >= 1"));
                    if (rhs_mpz.fits_sint_p())
                      return std::make_shared<mts_obj>(
                              safeint(mpz_probab_prime_p(mpz_class(int64_t(lhs_int)).get_mpz_t(), rhs_mpz.get_si())));
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "Second arg of function 'isprime' must fit int64_t"));
                  },
                  [&lhs, &rhs](safeint lhs_int, safeint rhs_int) -> shared_mts_obj {
                    if (rhs_int < 1)
                      return std::make_shared<mts_obj>(
                              mts_error("ValueError", "Second arg of function 'isprime' must be >= 1"));
                    return std::make_shared<mts_obj>(
                            safeint(mpz_probab_prime_p(mpz_class(int64_t(lhs_int)).get_mpz_t(), int64_t(rhs_int))));
                  },
                  [](auto, auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Function 'is_prime' (conversion)"));
                  }),
          *lhs, *rhs);
}

shared_mts_obj is_key_binary(shared_mts_obj &lhs, shared_mts_obj &rhs) {
  return apply_visitor(hana::overload(
                               [&lhs](mts_dict &rhs_dict) -> shared_mts_obj {
                                 if (rhs_dict.find(*lhs) != rhs_dict.end()) return std::make_shared<mts_obj>(true);
                                 return std::make_shared<mts_obj>(false);
                               },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(
                                         mts_error("TypeError", "Function 'is_key' (expects dict on rhs)"));
                               }),
                       *rhs);
}