#include "../Header.h"

std::string UnaryOpAST::graphgen(std::string origin) { 
	std::string pos = std::to_string(counter);
	std::string result = std::to_string(counter) + " [label=\"" + get_op_string(op) + "\"];\n";
	result += origin + " -> " + std::to_string(counter++) + ";\n";
	result += rhs->graphgen(pos);
	return result;
}

shared_mts_obj sub_unary(              shared_mts_obj &arg);
shared_mts_obj inv_unary(              shared_mts_obj &arg);
shared_mts_obj faculty_unary(          shared_mts_obj &arg);
shared_mts_obj abs_unary(              shared_mts_obj &arg);
shared_mts_obj sqrt_unary(             shared_mts_obj &arg);
shared_mts_obj sgn_unary(              shared_mts_obj &arg);
shared_mts_obj fibo_unary(             shared_mts_obj &arg);
shared_mts_obj primorial_unary(        shared_mts_obj &arg);
shared_mts_obj num_unary(              shared_mts_obj &arg);
shared_mts_obj den_unary(              shared_mts_obj &arg);
shared_mts_obj rational_unary(         shared_mts_obj &arg);
shared_mts_obj int_unary(              shared_mts_obj &arg);
shared_mts_obj flt_unary(              shared_mts_obj &arg);
shared_mts_obj setprec_unary(          shared_mts_obj &arg);
shared_mts_obj setprecd_unary(         shared_mts_obj &arg);
shared_mts_obj getprecd_unary(         shared_mts_obj &arg);
shared_mts_obj setoutprec_unary(       shared_mts_obj &arg);
shared_mts_obj sopd_unary(             shared_mts_obj &arg);
shared_mts_obj is_prime_unary(         shared_mts_obj &arg);
shared_mts_obj next_prime_unary(       shared_mts_obj &arg);
shared_mts_obj reference_count_unary(  shared_mts_obj &arg);
shared_mts_obj address_of_unary(       shared_mts_obj &arg);

shared_mts_obj UnaryOpAST::eval(const shared_future_map * const arguments, shared_mts_obj_map * const variables) {
  auto rhs_eval = rhs->eval(arguments, variables);
  switch (op) {
    case '-':			return sub_unary(             rhs_eval);
    case '~':			return inv_unary(             rhs_eval);
    case '!':			return faculty_unary(         rhs_eval);
    case ABS:			return abs_unary(             rhs_eval);
    case SQRT:			return sqrt_unary(            rhs_eval);
    case SGN:			return sgn_unary(             rhs_eval);
    case FIBO:			return fibo_unary(            rhs_eval);
    case PRIMORIAL:		return primorial_unary(       rhs_eval);
    case NUM:			return num_unary(             rhs_eval);
    case DEN:			return den_unary(             rhs_eval);
    case RATIONAL:		return rational_unary(        rhs_eval);
    case INT_T:			return int_unary(             rhs_eval);
    case FLT_T:			return flt_unary(             rhs_eval);
    case SETPREC:		return setprec_unary(         rhs_eval);
    case GETPREC:		return std::make_shared<mts_obj>(safeint(mpreal::get_default_prec()));//std::numeric_limits<mpreal>::digits()));
    case SETPRECD:		return setprecd_unary(        rhs_eval);
    case SETOUTPREC:	return setoutprec_unary(      rhs_eval);
    case SOPD:			return sopd_unary(            rhs_eval);
    case ISPRIME:		return is_prime_unary(        rhs_eval);
    case NEXTPRIME:		return next_prime_unary(      rhs_eval);
    case REF_COUNT:		return reference_count_unary( rhs_eval);
    case ADDRESS_OF:	return address_of_unary(      rhs_eval);
    default:
      return std::make_shared<mts_obj>(mts_error("ParsingError", "Unknown Unary Operand: " + get_op_string(op)));
  }
}

shared_mts_obj sub_unary(shared_mts_obj &arg) {
  return apply_visitor(hana::overload(
                               [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   arg_mpz *= -1;
                                   return arg;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(-arg_mpz));
                               },
                               [&arg](mpq_class &rhs_mpq) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   rhs_mpq *= -1;
                                   return arg;
                                 }
                                 return std::make_shared<mts_obj>(-rhs_mpq);
                               },
                               [&arg](mpreal &rhs_mpreal) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   mpfr_neg(rhs_mpreal.mpfr_ptr(), rhs_mpreal.mpfr_ptr(), mpreal::get_default_rnd());
                                   return arg;
                                 }
                                 auto result = std::make_shared<mts_obj>(mpreal());
                                 mpfr_neg(get<mpreal>(*result).mpfr_ptr(), get<mpreal>(*result).mpfr_ptr(), mpreal::get_default_rnd());
                                 return result;
                               },
                               [&arg](safeint &rhs_int) -> shared_mts_obj {
                                 try {
                                   if (arg.use_count() == 1) {
                                     rhs_int *= -1;
                                     return arg;
                                   }
                                   return std::make_shared<mts_obj>(safeint(-rhs_int));
                                 } catch (const std::exception &e) {
                                   return std::make_shared<mts_obj>(mpz_class(-mpz_class(int64_t(rhs_int))));
                                 }
                               },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '-' (unary)"));
                               }),
                       *arg);
}

shared_mts_obj inv_unary(shared_mts_obj &arg) {
  return apply_visitor(hana::overload(
                               [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   mpz_com(arg_mpz.get_mpz_t(), arg_mpz.get_mpz_t());
                                   return arg;
                                 }
                                 auto result = std::make_shared<mts_obj>(mpz_class());
                                 mpz_com(get<mpz_class>(*result).get_mpz_t(), get<mpz_class>(*result).get_mpz_t());
                                 return result;
                               },
                               [&arg](mpq_class &arg_mpq) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   mpq_inv(arg_mpq.get_mpq_t(), arg_mpq.get_mpq_t());
                                   return arg;
                                 }
                                 auto result = std::make_shared<mts_obj>(mpq_class());
                                 mpq_inv(get<mpq_class>(*result).get_mpq_t(), arg_mpq.get_mpq_t());
                                 return result;
                               },
                               [&arg](safeint &arg_int) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   arg_int = safeint(~arg_int);
                                   return arg;
                                 }
                                 return std::make_shared<mts_obj>(safeint(~arg_int));
                               },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '~' (unary)"));
                               }),
                       *arg);
}

shared_mts_obj faculty_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [&arg](mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (rhs_mpz < 0)
                      return std::make_shared<mts_obj>(
                              mts_error("ValueError",
                                        "Factorial is only defined for positive numbers. Your number is negative."));
                    if (arg.use_count() == 1) {
                      if (rhs_mpz.fits_ulong_p()) {
                        mpz_fac_ui(rhs_mpz.get_mpz_t(), rhs_mpz.get_ui());
                        return arg;
                      }
                      return std::make_shared<mts_obj>(
                              mts_error("ValueError",
                                        "Factorial is only defined for numbers n with 0 <= n < 2**64-1 (uint64_t)."));
                    }
                    return std::make_shared<mts_obj>(mpz_class(factorial(rhs_mpz)));
                  },
                  [&arg](safeint &rhs_int) -> shared_mts_obj {
                    if (rhs_int < 0)
                      return std::make_shared<mts_obj>(
                              mts_error("ValueError",
                                        "Factorial is only defined for numbers n with 0 <= n < 2**64-1 (uint64_t)."));
                    auto result = std::make_shared<mts_obj>(mpz_class(mpz_class::factorial(int64_t(rhs_int))));
                    if (get<mpz_class>(*result).fits_slong_p()) {
                      if (arg.use_count()) {
                        rhs_int = safeint(get<mpz_class>(*result).get_si());
                        return arg;
                      }
                      return std::make_shared<mts_obj>(get<mpz_class>(*result).get_si());
                    }
                    return result;
                  },
                  [](auto) -> shared_mts_obj { return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '!'")); }),
          *arg);
}

shared_mts_obj abs_unary(shared_mts_obj &arg) {
  return apply_visitor(hana::overload(
                               [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   mpz_abs(arg_mpz.get_mpz_t(), arg_mpz.get_mpz_t());
                                   return arg;
                                 }
                                 return std::make_shared<mts_obj>(mpz_class(abs(arg_mpz)));
                               },
                               [&arg](mpq_class &arg_mpq) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   mpq_abs(arg_mpq.get_mpq_t(), arg_mpq.get_mpq_t());
                                   return arg;
                                 }
                                 return std::make_shared<mts_obj>(abs(arg_mpq));
                               },
                               [&arg](mpreal &arg_mpreal) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   mpfr_abs(arg_mpreal.mpfr_ptr(), arg_mpreal.mpfr_ptr(), mpreal::get_default_rnd());
                                   return arg;
                                 }
                                 return std::make_shared<mts_obj>(abs(arg_mpreal));
                               },
                               [&arg](safeint &arg_int) -> shared_mts_obj {
                                 if (arg_int == INT64_MIN)
                                   return std::make_shared<mts_obj>(mpz_class(-mpz_class(int64_t(arg_int))));
                                 if (arg.use_count() == 1) {
                                   arg_int = safeint(llabs(arg_int));
                                   return arg;
                                 }
                                 return std::make_shared<mts_obj>(llabs(arg_int));
                               },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(
                                         mts_error("TypeError", "Operator 'abs', '| |'  (unary)"));
                               }),
                       *arg);
}

shared_mts_obj sqrt_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                    if (arg_mpz < 0)
                      return std::make_shared<mts_obj>(mts_error("ValueError", "Can't take sqrt of negative number."));
                    if (arg.use_count() == 1) {
                      mpz_sqrt(arg_mpz.get_mpz_t(), arg_mpz.get_mpz_t());
                      return arg;
                    }
                    return std::make_shared<mts_obj>(mpz_class(sqrt(arg_mpz)));
                  },
                  [&arg](mpreal &arg_mpreal) -> shared_mts_obj {
                    if (arg_mpreal < 0)
                      return std::make_shared<mts_obj>(mts_error("ValueError", "Can't take sqrt of negative number."));
                    if (arg.use_count() == 1) {
                      mpfr_sqrt(arg_mpreal.mpfr_ptr(), arg_mpreal.mpfr_ptr(), mpreal::get_default_rnd());
                      return arg;
                    }
                    return std::make_shared<mts_obj>(sqrt(arg_mpreal));
                  },
                  [&arg](safeint &arg_int) -> shared_mts_obj {
                    if (arg_int < 0)
                      return std::make_shared<mts_obj>(mts_error("ValueError", "Can't take sqrt of negative number."));
                    mpz_class result = sqrt(mpz_class(int64_t(arg_int)));
                    if (arg.use_count() == 1) {
                      arg_int = safeint(result.get_si());
                      return arg;
                    }
                    return std::make_shared<mts_obj>(result.get_si());
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Operator 'sqrt'"));
                  }),
          *arg);
}

shared_mts_obj sgn_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [](mpz_class arg_mpz) -> shared_mts_obj { return std::make_shared<mts_obj>(safeint(sgn(arg_mpz))); },
                  [](mpq_class arg_mpq) -> shared_mts_obj { return std::make_shared<mts_obj>(safeint(sgn(arg_mpq))); },
                  [](mpreal arg_mpreal) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(safeint(sgn(arg_mpreal)));
                  },
                  [&arg](safeint &arg_int) -> shared_mts_obj {
                    if (arg.use_count()) {
                      if (arg_int == 0) {
                        arg_int = safeint(0);
                        return arg;
                      } else if (arg_int > 0) {
                        arg_int = safeint(1);
                        return arg;
                      } else {
                        arg_int = safeint(-1);
                        return arg;
                      }
                    }
                    if (arg_int == 0) return std::make_shared<mts_obj>(safeint(0));
                    else if (arg_int > 0)
                      return std::make_shared<mts_obj>(safeint(1));
                    else
                      return std::make_shared<mts_obj>(safeint(-1));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Operator 'sgn'"));
                  }),
          *arg);
}

shared_mts_obj fibo_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                    if (!arg_mpz.fits_ulong_p())
                      return std::make_shared<mts_obj>(mts_error(
                              "ValueError",
                              "Operator fibonacci requires argument int n  with 0 <= n <= 2**64-1 (uint64_t)."));
                    if (arg.use_count() == 1) {
                      mpz_fib_ui(arg_mpz.get_mpz_t(), arg_mpz.get_ui());
                      if (arg_mpz.fits_slong_p()) return std::make_shared<mts_obj>(safeint(arg_mpz.get_si()));
                      return arg;
                    }
                    auto result = std::make_shared<mts_obj>(mpz_class(fibonacci(arg_mpz)));
                    if (get<mpz_class>(*result).fits_slong_p()) return std::make_shared<mts_obj>(safeint(get<mpz_class>(*result).get_si()));
                    return result;
                  },
                  [&arg](safeint &arg_int) -> shared_mts_obj {
                    if (arg_int >= 0) {
                      auto result = std::make_shared<mts_obj>(mpz_class(mpz_class::fibonacci(int64_t(arg_int))));
                      if (get<mpz_class>(*result).fits_slong_p()) {
                        if (arg.use_count() == 1) {
                          arg_int = safeint(get<mpz_class>(*result).get_si());
                          return arg;
                        }
                        return std::make_shared<mts_obj>(safeint(get<mpz_class>(*result).get_si()));
                      }
                      return result;
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueErrorError", "fibonacci only takes positive integers."));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '-' (unary)"));
                  }),
          *arg);
}

shared_mts_obj primorial_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                    if (!arg_mpz.fits_ulong_p())
                      return std::make_shared<mts_obj>(mts_error(
                              "ValueError",
                              "Operator primorial ('#') requires argument int n  with 0 <= n <= 2**64-1 (uint64_t)."));
                    if (arg_mpz >= 0) {
                      if (arg.use_count() == 1) {
                        mpz_primorial_ui(arg_mpz.get_mpz_t(), arg_mpz.get_ui());
                        return arg;
                      }
                      return std::make_shared<mts_obj>(mpz_class(mpz_class::primorial(arg_mpz)));
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "primorial ('#') only takes positive integers."));
                  },
                  [&arg](safeint arg_int) -> shared_mts_obj {
                    if (arg_int >= 0) return std::make_shared<mts_obj>(mpz_class(mpz_class::primorial(int64_t(arg_int))));
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "primorial ('#') only takes positive integers."));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Operator '#' (unary)"));
                  }),
          *arg);
}

shared_mts_obj num_unary(shared_mts_obj &arg) {
  return apply_visitor(hana::overload(
                               [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                                 if (arg.use_count() == 1) return arg;
                                 return std::make_shared<mts_obj>(arg_mpz);
                               },
                               [](mpq_class &arg_mpq) -> shared_mts_obj {
                                 auto result = std::make_shared<mts_obj>(arg_mpq.get_num());
                                 if (get<mpz_class>(*result).fits_slong_p()) return std::make_shared<mts_obj>(get<mpz_class>(*result).get_si());
                                 return result;
                               },
                               [&arg](safeint arg_int) -> shared_mts_obj { return arg; },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Operator 'num' (unary)"));
                               }),
                       *arg);
}

shared_mts_obj den_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [](mpz_class &arg_mpz) -> shared_mts_obj { return std::make_shared<mts_obj>(safeint(1)); },
                  [](mpq_class &arg_mpq) -> shared_mts_obj { return std::make_shared<mts_obj>(arg_mpq.get_den()); },
                  [&arg](safeint &arg_int) -> shared_mts_obj {
                    if (arg.use_count() == 1) {
                      arg_int = safeint(1);
                      return arg;
                    }
                    return std::make_shared<mts_obj>(safeint(1));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeError", "Operator 'den' (unary)"));
                  }),
          *arg);
}

shared_mts_obj rational_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [](mpz_class &arg_mpz) -> shared_mts_obj { return std::make_shared<mts_obj>(mpq_class(arg_mpz)); },
                  [&arg](mpq_class arg_mpq) -> shared_mts_obj {
                    arg_mpq.canonicalize();
                    return arg;
                  },
                  [](mpreal &arg_mpreal) -> shared_mts_obj {
                    mpf_class intermediate;
                    mpfr_get_f(intermediate.get_mpf_t(), arg_mpreal.mpfr_srcptr(), mpreal::get_default_rnd());
                    return std::make_shared<mts_obj>(mpq_class(intermediate));
                  },
                  [](safeint arg_int) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mpq_class(int64_t(arg_int)));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(
                            mts_error("ConversionError",
                                      "Unknown type in conversion to rational. Candidates: (int), (flt), (rat)."));
                  }),
          *arg);
}

shared_mts_obj int_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                    if (arg_mpz.fits_slong_p()) return std::make_shared<mts_obj>(arg_mpz.get_si());
                    return arg;
                  },
                  [](mpq_class &arg_mpq) -> shared_mts_obj { return std::make_shared<mts_obj>(mpz_class(arg_mpq)); },
                  [](bool arg_bool) -> shared_mts_obj { return std::make_shared<mts_obj>(safeint(arg_bool)); },
                  [](mpreal &arg_mpreal) -> shared_mts_obj {
                    mpf_class result;
                    mpfr_get_f(result.get_mpf_t(), arg_mpreal.mpfr_srcptr(), mpreal::get_default_rnd());
                    return std::make_shared<mts_obj>(mpz_class(result));
                  },
                  [&arg](safeint arg_int) -> shared_mts_obj { return arg; },
                  [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error(
                                         "ConversionError",
                                         "Unknown type in conversion to int. Candidates: (int), (flt), (rat), (bool)."));
                  }),
          *arg);
}

shared_mts_obj flt_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [](mpz_class &arg_mpz) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mpreal(arg_mpz.get_mpz_t()));
                  },
                  [](mpq_class &arg_mpq) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mpreal(arg_mpq.get_mpq_t()));
                  },
                  [](bool arg_bool) -> shared_mts_obj { return std::make_shared<mts_obj>(mpreal(int64_t(arg_bool))); },
                  [&arg](mpreal &arg_mpreal) -> shared_mts_obj { return arg; },
                  [](safeint arg_int) -> shared_mts_obj { return std::make_shared<mts_obj>(mpreal(int64_t(arg_int))); },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(
                            mts_error("ConversionError",
                                      "Unknown type in conversion to float. Candidates: (int), (flt), (rat), (bool)."));
                  }),
          *arg);
}

shared_mts_obj setprec_unary(shared_mts_obj &arg) {
  return apply_visitor(hana::overload(
                               [](mpz_class &rhs_mpz) -> shared_mts_obj {
                                 if (rhs_mpz.fits_ulong_p() && rhs_mpz > 0) {
                                   mpreal::set_default_prec(rhs_mpz.get_ui());
                                   return std::make_shared<mts_obj>(new mts_none);
                                 }
                                 return std::make_shared<mts_obj>(mts_error(
                                         "ValueError", "setprecision only takes onyl ints which fit uint64_t."));
                               },
                               [](safeint rhs_int) -> shared_mts_obj {
                                 if (rhs_int > 0) {
                                   mpreal::set_default_prec(rhs_int);
                                   return std::make_shared<mts_obj>(new mts_none);
                                 }
                                 return std::make_shared<mts_obj>(mts_error(
                                         "ValueError", "setprecision only takes only ints which fit uint64_t."));
                               },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeErrorError", "Function setprecision"));
                               }),
                       *arg);
}

shared_mts_obj setprecd_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [](mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (rhs_mpz.fits_ulong_p() && rhs_mpz > 0) {
                      mpreal::set_default_prec(mpfr::digits2bits(rhs_mpz.get_ui()));
                      return std::make_shared<mts_obj>(new mts_none);
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "set_precision_d only takes only ints which fit uint64_t."));
                  },
                  [](safeint rhs_int) -> shared_mts_obj {
                    if (rhs_int > 0) {
                      mpreal::set_default_prec(mpfr::digits2bits(int64_t(rhs_int)));
                      return std::make_shared<mts_obj>(new mts_none);
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "set_precision_d only takes only ints which fit uint64_t."));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeErrorError", "Function setprecisiond"));
                  }),
          *arg);
}

shared_mts_obj setoutprec_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [](mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (rhs_mpz.fits_ulong_p()) {
                      std::cout.precision(rhs_mpz.get_ui());
                      return std::make_shared<mts_obj>(new mts_none);
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "set_out_precision only takes only ints which fit uint64_t."));
                  },
                  [](safeint rhs_int) -> shared_mts_obj {
                    if (rhs_int >= 0) {
                      std::cout.precision(int64_t(rhs_int));
                      return std::make_shared<mts_obj>(new mts_none);
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "set_out_precision only takes only ints which fit uint64_t."));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeErrorError", "Function setprecisiond"));
                  }),
          *arg);
}

shared_mts_obj sopd_unary(shared_mts_obj &arg) {
  return apply_visitor(
          hana::overload(
                  [](mpz_class &rhs_mpz) -> shared_mts_obj {
                    if (rhs_mpz.fits_ulong_p() && rhs_mpz > 0) {
                      std::cout.precision(rhs_mpz.get_ui());
                      mpreal::set_default_prec(mpfr::digits2bits(rhs_mpz.get_ui()));
                      return std::make_shared<mts_obj>(new mts_none);
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "set_output_precision_d only takes only ints which fit uint64_t."));
                  },
                  [](safeint rhs_int) -> shared_mts_obj {
                    if (rhs_int > 0) {
                      std::cout.precision(int64_t(rhs_int));
                      mpreal::set_default_prec(mpfr::digits2bits(rhs_int));
                      return std::make_shared<mts_obj>(new mts_none);
                    }
                    return std::make_shared<mts_obj>(
                            mts_error("ValueError", "set_output_precision_d only takes only ints which fit uint64_t."));
                  },
                  [](auto) -> shared_mts_obj {
                    return std::make_shared<mts_obj>(mts_error("TypeErrorError", "Function set_output_precision_d"));
                  }),
          *arg);
}

shared_mts_obj is_prime_unary(shared_mts_obj &arg) {
  return apply_visitor(hana::overload(
                               [](mpz_class &rhs_mpz) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(safeint(mpz_probab_prime_p(rhs_mpz.get_mpz_t(), 15)));
                               },
                               [&arg](safeint &rhs_int) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   rhs_int = safeint(mpz_probab_prime_p(mpz_class(int64_t(rhs_int)).get_mpz_t(), 15));
                                 }
                                 return std::make_shared<mts_obj>(
                                         safeint(mpz_probab_prime_p(mpz_class(int64_t(rhs_int)).get_mpz_t(), 15)));
                               },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(mts_error("TypeError", "Function isprime (unary)"));
                               }),
                       *arg);
}

shared_mts_obj next_prime_unary(shared_mts_obj &arg) {
  return apply_visitor(hana::overload(
                               [&arg](mpz_class &arg_mpz) -> shared_mts_obj {
                                 if (arg.use_count() == 1) {
                                   mpz_nextprime(arg_mpz.get_mpz_t(), arg_mpz.get_mpz_t());
                                   return arg;
                                 }
                                 auto result = std::make_shared<mts_obj>(mpz_class());
                                 mpz_nextprime(get<mpz_class>(*result).get_mpz_t(), arg_mpz.get_mpz_t());
                                 return result;
                               },
                               [&arg](safeint &arg_int) -> shared_mts_obj {
                                 auto result = std::make_shared<mts_obj>(mpz_class(int64_t(arg_int)));
                                 mpz_nextprime(get<mpz_class>(*result).get_mpz_t(), get<mpz_class>(*result).get_mpz_t());
                                 if (get<mpz_class>(*result).fits_slong_p()) {
                                   if (arg.use_count() == 1) arg_int = safeint(get<mpz_class>(*result).get_si());
                                   return std::make_shared<mts_obj>(get<mpz_class>(*result).get_si());
                                 }
                                 return result;
                               },
                               [](auto) -> shared_mts_obj {
                                 return std::make_shared<mts_obj>(
                                         mts_error("TypeError", "Function next_prime (unary)"));
                               }),
                       *arg);
}

shared_mts_obj reference_count_unary(shared_mts_obj &arg) {
  return std::make_shared<mts_obj>(safeint(arg.use_count()));
}

shared_mts_obj address_of_unary(shared_mts_obj &arg) { return std::make_shared<mts_obj>(mpz_class(uint64_t(arg.get()))); }
