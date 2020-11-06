/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EQL = 258,                     /* EQL  */
    UNEQL = 259,                   /* UNEQL  */
    BEQL = 260,                    /* BEQL  */
    SEQL = 261,                    /* SEQL  */
    LIMP = 262,                    /* LIMP  */
    RIMP = 263,                    /* RIMP  */
    EQV = 264,                     /* EQV  */
    GRAPH = 265,                   /* GRAPH  */
    POW = 266,                     /* POW  */
    SQRT = 267,                    /* SQRT  */
    SGN = 268,                     /* SGN  */
    GCD = 269,                     /* GCD  */
    LCM = 270,                     /* LCM  */
    FIBO = 271,                    /* FIBO  */
    PRIMORIAL = 272,               /* PRIMORIAL  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    ELIF = 275,                    /* ELIF  */
    ABS = 276,                     /* ABS  */
    FOR = 277,                     /* FOR  */
    RET = 278,                     /* RET  */
    SETPREC = 279,                 /* SETPREC  */
    GETPREC = 280,                 /* GETPREC  */
    SETPRECD = 281,                /* SETPRECD  */
    GETPRECD = 282,                /* GETPRECD  */
    SETOUTPREC = 283,              /* SETOUTPREC  */
    SOPD = 284,                    /* SOPD  */
    RATIONAL = 285,                /* RATIONAL  */
    NUM = 286,                     /* NUM  */
    DEN = 287,                     /* DEN  */
    INT_T = 288,                   /* INT_T  */
    FLT_T = 289,                   /* FLT_T  */
    ISPRIME = 290,                 /* ISPRIME  */
    NEXTPRIME = 291,               /* NEXTPRIME  */
    PRINT = 292,                   /* PRINT  */
    SEP = 293,                     /* SEP  */
    END = 294,                     /* END  */
    REF_COUNT = 295,               /* REF_COUNT  */
    ADDRESS_OF = 296,              /* ADDRESS_OF  */
    IS_KEY = 297,                  /* IS_KEY  */
    INT = 298,                     /* INT  */
    FLT = 299,                     /* FLT  */
    VAR = 300,                     /* VAR  */
    FUN = 301,                     /* FUN  */
    STR = 302,                     /* STR  */
    UMINUS = 303                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

	ExprAST * Expr;
	ReturnAST* Return;
	ForAST * For;
	VarAST * Var;
	BlockAST * Block;
	AssignmentAST * Assignment;
	IntAST * Int;
	FltAST * Flt;
	BinaryOpAST * Binary;
	UnaryOpAST *  Unary;
	FunctionAST * Function;
	CallAST * Call;
	IfAST * If;
	ListAST * List;
	DictAST * Dict;
	SubscriptAST * Subscript;
	SubscriptAssignmentAST * SubscriptAssignment;
	StringAST * String;
	PrintAST * Print;

#line 129 "parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
