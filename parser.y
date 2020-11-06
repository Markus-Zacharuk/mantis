%{
#include "Header.h"

std::map<std::string, std::unique_ptr<FunctionAST>> functions;
shared_future_map empty_arg_evals;
shared_mts_obj_map variables;
shared_mts_obj_map empty_variables;
std::map<std::string, ExprAST *> empty_arg_vals;

int counter = 0;
int recurse_counter = 1;
%}

%union {
	ExprAST                * Expr;
	ReturnAST              * Return;
	ForAST                 * For;
	VarAST                 * Var;
	BlockAST               * Block;
	AssignmentAST          * Assignment;
	IntAST                 * Int;
	FltAST                 * Flt;
	BinaryOpAST            * Binary;
	UnaryOpAST             *  Unary;
	FunctionAST            * Function;
	CallAST                * Call;
	IfAST                  * If;
	ListAST                * List;
	DictAST                * Dict;
	SubscriptAST           * Subscript;
	SubscriptAssignmentAST * SubscriptAssignment;
	StringAST              * String;
	PrintAST               * Print;
}

%token                       EQL UNEQL BEQL SEQL LIMP RIMP EQV GRAPH POW SQRT SGN GCD LCM FIBO PRIMORIAL IF ELSE ELIF ABS FOR RET SETPREC GETPREC SETPRECD GETPRECD SETOUTPREC SOPD RATIONAL NUM DEN INT_T FLT_T ISPRIME NEXTPRIME PRINT SEP END REF_COUNT ADDRESS_OF IS_KEY
%token <Int>                 INT
%token <Flt>                 FLT
%token <Var>                 VAR FUN
%token <String>              STR

%type                        Source
%type  <Expr>                Expr TopExpr Op BlockExpr IfExpr SubscriptExpr //ListExpr SubscriptAssignmentExpr
%type  <Return>              Return
%type  <For>                 For Forinitbegin Forinit Forcond Forendbegin Forend
%type  <Block>               Block Blockbegin Blockmiddle
%type  <Assignment>          Assignment
%type  <Function>            Function FunctionName FunctionArgs Functionproto
%type  <Call>                Call Callbegin
%type  <If>                  Ifbegin If
%type  <List>                List Listbegin
%type  <Dict>                Dict Dictbegin
%type  <Subscript>           Subscript Subscriptbegin Subscriptmiddle
%type  <SubscriptAssignment> SubscriptAssignment
%type  <Print>               Print Printbegin

%left                        '^'
%left                        EQV
%left                        LIMP RIMP
%left                        '|'
%left                        '&'
%left	                     EQL UNEQL
%left                        '<' '>'
%left                        '+' '-'
%left                        '*' '/' '%'
%right                       POW
%left                        '!' '#' '~' UMINUS

%glr-parser

%%

Source              : GRAPH '(' TopExpr ')' ';'                   { save_graph($3); delete $3; YYACCEPT;                              }
                    | TopExpr ';'                                 { print_eval($1); delete $1; YYACCEPT;                              }
                    | Print ';'                                   { print_eval($1); delete $1; YYACCEPT;                              }
                    | Function                                    { functions[$1->name] = std::unique_ptr<FunctionAST>($1); YYACCEPT; }
                    ;

List                : '[' ']'                                    { $$ = new ListAST();                                               }
                    | Listbegin ']'                              { $$ = $1;}
				      ;
Listbegin           : Listbegin ',' Expr                         { $$ = $1; $$->add_element($3);                                     }
                    | '[' Expr                                   { $$ = new ListAST($2);                                             }
                    ;

Dict                : '{' '}'                                    { $$ = new DictAST();                                               }
                    | Dictbegin '}'                              { $$ = $1;                                                          }
                    ;
Dictbegin           : Dictbegin ',' Expr ':' Expr                { $$ = $1; $$->add_entry($3, $5);                                   }
                    | '{' Expr ':' Expr                          { $$ = new DictAST($2, $4);                                         }
                    ;

Subscript           : Subscriptmiddle ']'                        { $$ = $1;                                                          }
                    ;
Subscriptmiddle     : Subscriptbegin{ $$ = $1;}
                    | Subscriptmiddle ',' Expr                   { $$ = $1; $$->add_subscript($3);                                   }
                    | Subscriptmiddle ',' ':' Expr               { $$ = $1; $$->add_subscript(new NoneAST(), $4);                    }
                    | Subscriptmiddle ','  Expr ':'              { $$ = $1; $$->add_subscript($3, new NoneAST());                    }
                    | Subscriptmiddle ',' ':' ':'                { $$ = $1; $$->add_subscript(new NoneAST(), new NoneAST());         }
                    | Subscriptmiddle ',' Expr ':' Expr          { $$ = $1; $$->add_subscript($3, $5);                               }
                    | Subscriptmiddle ',' ':' ':' Expr           { $$ = $1; $$->add_subscript(new NoneAST(), new NoneAST(), $5);     }
                    | Subscriptmiddle ',' ':' Expr ':' Expr      { $$ = $1; $$->add_subscript(new NoneAST(), $4, $6);                }
                    | Subscriptmiddle ',' Expr ':' Expr ':' Expr { $$ = $1; $$->add_subscript($3, $5, $7);                           }
                    ;
Subscriptbegin      : SubscriptExpr '[' Expr                    { $$ = new SubscriptAST($1, $3);                                    }
                    | SubscriptExpr '[' ':' Expr                { $$ = new SubscriptAST($1, new NoneAST(), $4);                     }
                    | SubscriptExpr '[' Expr ':'                { $$ = new SubscriptAST($1, $3, new NoneAST());                     }
                    | SubscriptExpr '[' ':' ':'                 { $$ = new SubscriptAST($1, new NoneAST(), new NoneAST());          }
                    | SubscriptExpr '[' Expr ':' Expr           { $$ = new SubscriptAST($1, $3, $5);                                }
                    | SubscriptExpr '[' ':' ':' Expr            { $$ = new SubscriptAST($1, new NoneAST(), new NoneAST(), $5);      }
                    | SubscriptExpr '[' ':' Expr ':' Expr       { $$ = new SubscriptAST($1, new NoneAST(), $4, $6);                 }
                    | SubscriptExpr '[' Expr ':' Expr ':' Expr	{ $$ = new SubscriptAST($1, $3, $5, $7);                            }
                    ;
SubscriptExpr       : VAR                                       { $$ = $1;                                                          }
                    | List                                      { $$ = $1;                                                          }
                    | Subscript                                 { $$ = $1;                                                          }
                    | Call                                      { $$ = $1;                                                          }
                    ;

Return              : RET TopExpr                               { $$ = new ReturnAST($2);                                           }
                    ;

For                 : Forend Block                              { $$ = $1; $$->add_body($2);                                        }
                    ;

Forend              : Forendbegin ';'                           { $$ = $1;                                                          }
                    | Forcond ';'                               { $$ = $1;                                                          }
                    ;
							
Forendbegin         : Forcond Assignment                        { $$ = $1; $$->add_end($2);                                         }
                    | Forendbegin ',' Assignment                { $$ = $1; $$->add_end($3);                                         }
                    ;

Forcond             : Forinit TopExpr ';'                       { $$ = $1; $$->add_cond($2);                                        }
                    ;

Forinit             : FOR ';'                                   { $$ = new ForAST();                                                }
                    | Forinitbegin ';'                          { $$ = $1;                                                          }
                    ;
							
Forinitbegin        : FOR Assignment                            { $$ = new ForAST(); $$->add_init($2);                              }
                    | Forinitbegin ',' Assignment               { $$ = $1; $$->add_init($3);                                        }
                    ;

Block               : Blockbegin '}'                            { $$ = $1;                                                          }
                    | Blockmiddle '}'                           { $$ = $1;                                                          }
                     ;
Blockmiddle         : Blockbegin BlockExpr                      { $$ = $1; $$->add_statement($2);                                   }
                    | Blockmiddle BlockExpr                     { $$ = $1; $$->add_statement($2);                                   }
                    ;
Blockbegin          : '{'                                       { $$ = new BlockAST();                                              }
                    ;
BlockExpr           : TopExpr ';'                               { $$ = $1;                                                          }
                    | For                                       { $$ = $1;                                                          }
                    | Return ';'                                { $$ = $1;                                                          }
                    | Print ';'                                 { $$ = $1;                                                          }
                    ;

SubscriptAssignment : Subscript '=' Expr                        { $$ = new SubscriptAssignmentAST($3, $1); delete $1;               }
                    ;


Assignment          : VAR '=' Expr                              { $$ = new AssignmentAST($1->name, $3); delete $1;                  }
                    | FUN '=' Expr                              { $$ = new AssignmentAST($1->name, $3); delete $1;                  }
                    ;

Function            : Functionproto '=' Expr ';'                { $$ = $1; $$->add_body($3);                                        }
                    | Functionproto '=' If ';'                  { $$ = $1; $$->add_body($3);                                        }
                    | Functionproto '=' Block                   { $$ = $1; $$->add_body($3);                                        }
                    ;

Functionproto       : FunctionArgs ')'                          { $$ = $1;                                                          }
                    | FunctionName ')'                          { $$ = $1;                                                          }
                    ;
FunctionArgs        : FunctionName VAR                          { $$ = $1; $$->add_arg($2->name);                                   }
                    | FunctionArgs ',' VAR                      { $$ = $1; $$->add_arg($3->name); delete $3;                        }
                    ;
FunctionName        : VAR '('                                   { $$ = new FunctionAST($1->name);
                                                                  functions[$1->name] = std::make_unique<FunctionAST>($1->name); 
                                                                  delete $1;                                                        }
                    | FUN '('                                   { $$ = new FunctionAST($1->name); delete $1;                        }
                    ;

Call                : FUN '(' ')'                               { $$ = new CallAST($1->name); delete $1;                            }
                    | Callbegin ')'                             { $$ = $1;                                                          }
                    ;
Callbegin           : FUN '(' Expr                              { $$ = new CallAST($1->name); delete $1; $$->add_arg($3);           }
                    | Callbegin ',' Expr                        { $$ = $1; $$->add_arg($3);                                         }
                    ;

If                  : Ifbegin                                   { $$ = $1;                                                          }
                    | Ifbegin ELSE ':' IfExpr                   { $$ = $1; $$->add_default($4);                                     }
                    ;
Ifbegin             : IF Expr ':' IfExpr                        { $$ = new IfAST($2, $4);                                           }
                    | Ifbegin  ELIF Expr ':' IfExpr             { $$ = $1; $$->add_if($3, $5);                                      }
                    ;
IfExpr              : Expr                                      { $$ = $1;                                                          }
                    | Return                                    { $$ = $1;                                                          }
                    | Block                                     { $$ = $1;                                                          }
                    ;

Op                  : Expr '+' Expr                             { $$ = new BinaryOpAST($1, '+', $3);                                }
                    | Expr '-' Expr                             { $$ = new BinaryOpAST($1, '-', $3);                                }
                    | Expr '*' Expr                             { $$ = new BinaryOpAST($1, '*', $3);                                }
                    | Expr '/' Expr                             { $$ = new BinaryOpAST($1, '/', $3);                                }
                    | Expr '%' Expr                             { $$ = new BinaryOpAST($1, '%', $3);                                }
                    | Expr POW Expr                             { $$ = new BinaryOpAST($1, POW, $3);                                }
                    | Expr '<' Expr                             { $$ = new BinaryOpAST($1, '<', $3);                                }
                    | Expr '>' Expr                             { $$ = new BinaryOpAST($1, '>', $3);                                }
                    | Expr EQL Expr                             { $$ = new BinaryOpAST($1, EQL, $3);                                }
                    | Expr UNEQL Expr                           { $$ = new BinaryOpAST($1, UNEQL, $3);                              }
                    | Expr SEQL Expr                            { $$ = new BinaryOpAST($1, SEQL, $3);                               }
                    | Expr BEQL Expr                            { $$ = new BinaryOpAST($1, BEQL, $3);                               }
                    | Expr '&' Expr                             { $$ = new BinaryOpAST($1, '&', $3);                                }
                    | Expr '|' Expr                             { $$ = new BinaryOpAST($1, '|', $3);                                }
                    | Expr LIMP Expr                            { $$ = new BinaryOpAST($1, LIMP, $3);                               }
                    | Expr RIMP Expr                            { $$ = new BinaryOpAST($1, RIMP, $3);                               }
                    | Expr EQV Expr                             { $$ = new BinaryOpAST($1, EQV, $3);                                }
                    | Expr '^' Expr                             { $$ = new BinaryOpAST($1, '^', $3);                                }
                    | GCD Expr ',' Expr ')'                     { $$ = new BinaryOpAST($2, GCD, $4);                                }
                    | LCM Expr ',' Expr ')'                     { $$ = new BinaryOpAST($2, LCM, $4);                                }
                    | '-' Expr %prec UMINUS                     { $$ = new UnaryOpAST('-', $2);                                     }
                    | '~' Expr                                  { $$ = new UnaryOpAST('~', $2);                                     }
                    | Expr '!'                                  { $$ = new UnaryOpAST('!', $1);                                     }
                    | '|' Expr '|'                              { $$ = new UnaryOpAST(ABS, $2);                                     }
                    | SQRT Expr ')'                             { $$ = new UnaryOpAST(SQRT, $2);                                    }
                    | SGN Expr ')'                              { $$ = new UnaryOpAST(SGN, $2);                                     }
                    | FIBO Expr ')'                             { $$ = new UnaryOpAST(FIBO, $2);                                    }
                    | PRIMORIAL Expr ')'                        { $$ = new UnaryOpAST(PRIMORIAL, $2);                               }
                    | Expr '#'                                  { $$ = new UnaryOpAST(PRIMORIAL, $1);                               }
                    | RATIONAL Expr ')'                         { $$ = new UnaryOpAST(RATIONAL, $2);                                }
                    | RATIONAL Expr ',' Expr ')'                { $$ = new BinaryOpAST($2, RATIONAL, $4);                           }
                    | INT_T Expr ')'                            { $$ = new UnaryOpAST(INT_T, $2);                                   }
                    | FLT_T Expr ')'                            { $$ = new UnaryOpAST(FLT_T, $2);                                   }
                    | NUM	Expr ')'                            { $$ = new UnaryOpAST(NUM, $2);                                     }
                    | DEN Expr ')'                              { $$ = new UnaryOpAST(DEN, $2);                                     }
                    | SETPREC Expr ')'                          { $$ = new UnaryOpAST(SETPREC, $2);                                 }
                    | GETPREC ')'                               { $$ = new UnaryOpAST(GETPREC, new IntAST("0"));                    }
                    | SETPRECD Expr ')'                         { $$ = new UnaryOpAST(SETPRECD, $2);                                }
                    | SETOUTPREC Expr ')'                       { $$ = new UnaryOpAST(SETOUTPREC, $2);                              }
                    | SOPD Expr ')'                             { $$ = new UnaryOpAST(SOPD, $2);                                    }
                    | ISPRIME Expr ',' Expr ')'                 { $$ = new BinaryOpAST($2, ISPRIME, $4);                            }
                    | ISPRIME Expr ')'                          { $$ = new UnaryOpAST(ISPRIME, $2);                                 }
                    | REF_COUNT Expr ')'                        { $$ = new UnaryOpAST(REF_COUNT, $2);                               }
                    | ADDRESS_OF Expr ')'                       { $$ = new UnaryOpAST(ADDRESS_OF, $2);                              }
                    | NEXTPRIME Expr ')'                        { $$ = new UnaryOpAST(NEXTPRIME, $2);                               }
                    | IS_KEY Expr ',' Expr ')'                  { $$ = new BinaryOpAST($2, IS_KEY, $4);                             }
                    ;

Print               : Printbegin ')'                            { $$ = $1;                                                          }
                    | PRINT ')'                                 { $$ = new PrintAST();                                              }
                    ;
Printbegin          : PRINT TopExpr                             { $$ = new PrintAST(); $$->add_argument($2);                        }
                    | Printbegin ',' Expr                       { $$ = $1; $$->add_argument($3);                                    }
                    | Printbegin ',' SEP '=' Expr               { $$ = $1; $$->add_seperator($5);                                   }
                    | Printbegin ',' END '=' Expr               { $$ = $1; $$->add_end($5);                                         }
                    ;

TopExpr             : Expr                                      { $$ = $1;                                                          }
                    | Assignment                                { $$ = $1;                                                          }
                    | SubscriptAssignment                       { $$ = $1;                                                          }
                    | If                                        { $$ = $1;                                                          }
                    ;

Expr                 : '(' Op ')'                               { $$ = $2;                                                          }
                     | '(' If ')'                               { $$ = $2;                                                          }
                     | Call                                     { $$ = $1;                                                          }
                     | List                                     { $$ = $1;                                                          }
                     | Dict                                     { $$ = $1;                                                          }
                     | Subscript                                { $$ = $1;                                                          }
                     | Op                                       { $$ = $1;                                                          }
                     | INT                                      { $$ = $1;                                                          }
                     | FLT                                      { $$ = $1;                                                          }
                     | VAR                                      { $$ = $1;                                                          }
                     | STR                                      { $$ = $1;                                                          }
                     ;
%%

int main() {	
	bool restart = true;
	printf("> ");
	while (restart) {
		yyparse();
	}
	return 0;
}


