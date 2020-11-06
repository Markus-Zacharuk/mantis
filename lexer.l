%{
#include "Header.h"
#include "parser.tab.hpp"

bool _is_function(std::string Name) { if (functions.find(Name) != functions.end()) { return true; } else { return false; } }
%}

%option noyywrap

%%

is_key\(															{ return IS_KEY;																																									}
print\(																{ return PRINT; 																																									}
sep																		{ return SEP;																																											}
end																		{ return END;																																											}
(reference_count|ref_count|ref)\(			{ return REF_COUNT;																																							  }
(address_of|addr|adr|&)\(							{ return ADDRESS_OF;																																							}
(quotient|quot|qot|q|rational|rat)\(	{ return RATIONAL; 																																								}
num\(																	{ return NUM; 																																										}
den\(																	{ return DEN; 																																										}
int\(																	{ return INT_T; 																																									}
flt\(																	{ return FLT_T; 																																									}
(isprime|is_prime)\(									{ return ISPRIME; 																																								}
(nextprime|next_prime)\(							{ return NEXTPRIME;																																								}
(set_output_precision_d|sopd)\(		  	{ return SOPD; 																																										}
(set_output_precision|sop)\(					{ return SETOUTPREC; 																																							}
(set_precision|sp)\(									{ return SETPREC; 																																								}
(get_precision|gp)\(									{ return GETPREC; 																																								}
(set_precision_digits|spd)\(					{ return SETPRECD; 																																								}
(ret|return)													{ return RET; 																																										}
primorial\(														{ return PRIMORIAL; 																																							}
(fibo|fib|fibonacci)\(								{ return FIBO; 																																										}
gcd\(																	{ return GCD; 																																										}
lcm\(																	{ return LCM; 																																										}
sgn\(																	{ return SGN; 																																										}
sqrt\(																{ return SQRT; 																																										}
graph\(																{ return GRAPH; 																																									}
for																		{ return FOR; 																																										}
elif																	{ return ELIF; 																																										}
else																	{ return ELSE; 																																										}
if																		{ return IF; 																																											}
(!=)																	{ return UNEQL; 																																									}
(==)																	{ return EQL; 																																										}
(>=)																	{ return BEQL; 																																										}
(<=)																	{ return SEQL; 																																										}
(<->)																	{ return EQV; 																																										}
(->)																	{ return RIMP; 																																										}
(\*\*)																{ return POW; 																																										}
\"([^\\\"]|\\.)*\"										{ yylval.String = new StringAST(unescape(std::string(yytext, 1, yyleng - 2))); return STR; 				}
[0-9]+																{	yylval.Int = new IntAST(yytext); return INT; 																										}
[0-9]*\.[0-9]*([eE][0-9]+)?						{ yylval.Flt = new FltAST(std::string(yytext)); return FLT; 																			}
[-+*<&!|$<>/:%#~^();,={}\[\]]					{	return yytext[0];																																								}
[a-zA-Z_][a-zA-Z_0-9']*								{ yylval.Var = new VarAST(yytext); if (_is_function(yytext)) { return FUN; } else { return VAR; } }
[ \t\v\f]															{ ; 																																															}
\n																		{ std::cout << "> "; 																																							}

%%
