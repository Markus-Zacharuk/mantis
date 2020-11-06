/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 1 "parser.y"

#include "Header.h"

std::map<std::string, std::unique_ptr<FunctionAST>> functions;
shared_future_map empty_arg_evals;
shared_mts_obj_map variables;
shared_mts_obj_map empty_variables;
std::map<std::string, ExprAST *> empty_arg_vals;

int counter = 0;
int recurse_counter = 1;

#line 71 "parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EQL = 3,                        /* EQL  */
  YYSYMBOL_UNEQL = 4,                      /* UNEQL  */
  YYSYMBOL_BEQL = 5,                       /* BEQL  */
  YYSYMBOL_SEQL = 6,                       /* SEQL  */
  YYSYMBOL_LIMP = 7,                       /* LIMP  */
  YYSYMBOL_RIMP = 8,                       /* RIMP  */
  YYSYMBOL_EQV = 9,                        /* EQV  */
  YYSYMBOL_GRAPH = 10,                     /* GRAPH  */
  YYSYMBOL_POW = 11,                       /* POW  */
  YYSYMBOL_SQRT = 12,                      /* SQRT  */
  YYSYMBOL_SGN = 13,                       /* SGN  */
  YYSYMBOL_GCD = 14,                       /* GCD  */
  YYSYMBOL_LCM = 15,                       /* LCM  */
  YYSYMBOL_FIBO = 16,                      /* FIBO  */
  YYSYMBOL_PRIMORIAL = 17,                 /* PRIMORIAL  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_ELIF = 20,                      /* ELIF  */
  YYSYMBOL_ABS = 21,                       /* ABS  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_RET = 23,                       /* RET  */
  YYSYMBOL_SETPREC = 24,                   /* SETPREC  */
  YYSYMBOL_GETPREC = 25,                   /* GETPREC  */
  YYSYMBOL_SETPRECD = 26,                  /* SETPRECD  */
  YYSYMBOL_GETPRECD = 27,                  /* GETPRECD  */
  YYSYMBOL_SETOUTPREC = 28,                /* SETOUTPREC  */
  YYSYMBOL_SOPD = 29,                      /* SOPD  */
  YYSYMBOL_RATIONAL = 30,                  /* RATIONAL  */
  YYSYMBOL_NUM = 31,                       /* NUM  */
  YYSYMBOL_DEN = 32,                       /* DEN  */
  YYSYMBOL_INT_T = 33,                     /* INT_T  */
  YYSYMBOL_FLT_T = 34,                     /* FLT_T  */
  YYSYMBOL_ISPRIME = 35,                   /* ISPRIME  */
  YYSYMBOL_NEXTPRIME = 36,                 /* NEXTPRIME  */
  YYSYMBOL_PRINT = 37,                     /* PRINT  */
  YYSYMBOL_SEP = 38,                       /* SEP  */
  YYSYMBOL_END = 39,                       /* END  */
  YYSYMBOL_REF_COUNT = 40,                 /* REF_COUNT  */
  YYSYMBOL_ADDRESS_OF = 41,                /* ADDRESS_OF  */
  YYSYMBOL_IS_KEY = 42,                    /* IS_KEY  */
  YYSYMBOL_INT = 43,                       /* INT  */
  YYSYMBOL_FLT = 44,                       /* FLT  */
  YYSYMBOL_VAR = 45,                       /* VAR  */
  YYSYMBOL_FUN = 46,                       /* FUN  */
  YYSYMBOL_STR = 47,                       /* STR  */
  YYSYMBOL_48_ = 48,                       /* '^'  */
  YYSYMBOL_49_ = 49,                       /* '|'  */
  YYSYMBOL_50_ = 50,                       /* '&'  */
  YYSYMBOL_51_ = 51,                       /* '<'  */
  YYSYMBOL_52_ = 52,                       /* '>'  */
  YYSYMBOL_53_ = 53,                       /* '+'  */
  YYSYMBOL_54_ = 54,                       /* '-'  */
  YYSYMBOL_55_ = 55,                       /* '*'  */
  YYSYMBOL_56_ = 56,                       /* '/'  */
  YYSYMBOL_57_ = 57,                       /* '%'  */
  YYSYMBOL_58_ = 58,                       /* '!'  */
  YYSYMBOL_59_ = 59,                       /* '#'  */
  YYSYMBOL_60_ = 60,                       /* '~'  */
  YYSYMBOL_UMINUS = 61,                    /* UMINUS  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* ')'  */
  YYSYMBOL_64_ = 64,                       /* ';'  */
  YYSYMBOL_65_ = 65,                       /* '['  */
  YYSYMBOL_66_ = 66,                       /* ']'  */
  YYSYMBOL_67_ = 67,                       /* ','  */
  YYSYMBOL_68_ = 68,                       /* '{'  */
  YYSYMBOL_69_ = 69,                       /* '}'  */
  YYSYMBOL_70_ = 70,                       /* ':'  */
  YYSYMBOL_71_ = 71,                       /* '='  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_Source = 73,                    /* Source  */
  YYSYMBOL_List = 74,                      /* List  */
  YYSYMBOL_Listbegin = 75,                 /* Listbegin  */
  YYSYMBOL_Dict = 76,                      /* Dict  */
  YYSYMBOL_Dictbegin = 77,                 /* Dictbegin  */
  YYSYMBOL_Subscript = 78,                 /* Subscript  */
  YYSYMBOL_Subscriptmiddle = 79,           /* Subscriptmiddle  */
  YYSYMBOL_Subscriptbegin = 80,            /* Subscriptbegin  */
  YYSYMBOL_SubscriptExpr = 81,             /* SubscriptExpr  */
  YYSYMBOL_Return = 82,                    /* Return  */
  YYSYMBOL_For = 83,                       /* For  */
  YYSYMBOL_Forend = 84,                    /* Forend  */
  YYSYMBOL_Forendbegin = 85,               /* Forendbegin  */
  YYSYMBOL_Forcond = 86,                   /* Forcond  */
  YYSYMBOL_Forinit = 87,                   /* Forinit  */
  YYSYMBOL_Forinitbegin = 88,              /* Forinitbegin  */
  YYSYMBOL_Block = 89,                     /* Block  */
  YYSYMBOL_Blockmiddle = 90,               /* Blockmiddle  */
  YYSYMBOL_Blockbegin = 91,                /* Blockbegin  */
  YYSYMBOL_BlockExpr = 92,                 /* BlockExpr  */
  YYSYMBOL_SubscriptAssignment = 93,       /* SubscriptAssignment  */
  YYSYMBOL_Assignment = 94,                /* Assignment  */
  YYSYMBOL_Function = 95,                  /* Function  */
  YYSYMBOL_Functionproto = 96,             /* Functionproto  */
  YYSYMBOL_FunctionArgs = 97,              /* FunctionArgs  */
  YYSYMBOL_FunctionName = 98,              /* FunctionName  */
  YYSYMBOL_Call = 99,                      /* Call  */
  YYSYMBOL_Callbegin = 100,                /* Callbegin  */
  YYSYMBOL_If = 101,                       /* If  */
  YYSYMBOL_Ifbegin = 102,                  /* Ifbegin  */
  YYSYMBOL_IfExpr = 103,                   /* IfExpr  */
  YYSYMBOL_Op = 104,                       /* Op  */
  YYSYMBOL_Print = 105,                    /* Print  */
  YYSYMBOL_Printbegin = 106,               /* Printbegin  */
  YYSYMBOL_TopExpr = 107,                  /* TopExpr  */
  YYSYMBOL_Expr = 108                      /* Expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif (!defined __cplusplus                     \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0)  \
            || 4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
            || (defined __apple_build_version__ \
                ? 6000000 <= __apple_build_version__ \
                : 3 < __clang_major__ + (5 <= __clang_minor__))))
   /* _Noreturn works as-is.  */
# elif 2 < __GNUC__ + (8 <= __GNUC_MINOR__) || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2787

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  298
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,    57,    50,     2,
      62,    63,    55,    53,    67,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    64,
      51,    71,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    49,    69,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    75,    76,    77,    80,    81,    83,    84,
      87,    88,    90,    91,    94,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   106,   107,   108,   109,   110,   111,
     112,   113,   115,   116,   117,   118,   121,   124,   127,   128,
     131,   132,   136,   139,   140,   143,   144,   147,   148,   150,
     151,   153,   155,   156,   157,   158,   161,   165,   166,   169,
     170,   171,   174,   175,   177,   178,   180,   181,   184,   185,
     187,   188,   191,   192,   194,   195,   197,   198,   199,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   250,   251,   253,   254,   255,
     256,   259,   260,   261,   262,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275
};
#endif

#define YYPACT_NINF (-202)
#define YYTABLE_NINF (-36)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1366,   -35,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
     -24,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  1891,  2404,  2404,  2404,  -202,  -202,     2,   -37,  -202,
    2404,  2404,  2404,  2005,  2062,  1775,    58,    21,    14,  -202,
     -23,     4,    87,  -202,    41,  -202,  -202,  -202,    37,    11,
      -9,    53,    20,  -202,    52,  -202,    93,    79,    99,  2527,
    2119,    78,    59,    86,   695,   756,   581,   615,   772,   788,
      44,   849,  -202,   865,   881,   942,   516,   958,   974,  1035,
    1051,   550,  1067,     5,    -5,  -202,  -202,  1128,  1144,   638,
    -202,  2404,  2176,  2404,  2539,   150,   156,   115,   116,  2527,
    -202,  2527,  -202,   265,  -202,  -202,  2404,  2404,  -202,  2404,
    -202,  1423,  1482,  2233,  -202,   136,  -202,  -202,  -202,  2404,
     113,  2404,  -202,  -202,  1948,  -202,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,  2404,
    2404,  2404,  2404,  2404,  -202,  -202,   122,  2290,  -202,  -202,
    2404,  2404,  -202,  -202,  2347,  -202,  -202,  -202,  -202,  -202,
    2404,  -202,  -202,  -202,  -202,  -202,  2404,  -202,  -202,  -202,
    2404,  2527,  -202,  2527,  2527,  2461,  -202,  -202,  2404,  2527,
     288,  2527,  1541,   322,  1600,   345,  1833,  -202,  1659,  1717,
     125,   672,  -202,  2527,  2347,   379,   119,   120,  2527,  2705,
    2714,  2551,  2563,   166,  2631,   253,    54,  2620,  2641,  2650,
    2721,  2728,   154,   190,    57,   182,   358,   130,  1160,  1221,
    2119,  -202,  -202,  -202,  2527,  1237,  1253,  1314,  2527,  2404,
    2404,   402,  2404,  2404,   436,  2404,    -8,  -202,   133,  -202,
     118,    56,    -3,  2119,    80,  -202,   134,   135,  -202,  -202,
    -202,  -202,  -202,  2347,  2404,  2404,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  2527,  2527,  2404,   459,  2527,  2404,   493,
     129,   131,  -202,  -202,  -202,  -202,  -202,  -202,   121,  -202,
    -202,   139,  -202,   121,  -202,  -202,  -202,  2527,  2527,  2527,
    2404,  2527,  2404,  -202,  -202,  -202,  2527,  2527
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,     0,   145,
       0,     0,     0,     0,     0,     0,     0,   138,     0,   139,
       0,   140,     0,    15,     0,   133,   132,     5,     0,     0,
       0,   137,     0,   134,    72,   141,     0,     0,     0,   131,
       0,   144,     0,   140,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,     0,   126,   127,     0,     0,     0,
      66,     0,     0,     0,     0,    99,   100,     0,   141,     0,
       6,     9,    10,     0,     1,     7,     0,     0,    11,     0,
      14,     0,     0,     0,    62,     0,    64,    63,    69,     0,
       0,     0,     4,   125,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   107,     0,     0,   103,   104,
       0,     0,   105,   106,     0,   114,   116,   117,   118,   108,
       0,   112,   113,   110,   111,   120,     0,   123,   121,   122,
       0,    57,    68,    70,    58,   102,   136,   135,     0,     8,
       0,    56,     0,    16,     0,    24,    51,    61,     0,     0,
       0,     0,    65,    71,     0,     0,     0,     0,   128,    87,
      88,    90,    89,    93,    94,    95,    84,    96,    92,    91,
      85,    86,    79,    80,    81,    82,    83,     0,     0,     0,
       0,    77,    78,    74,    76,     0,     0,     0,    13,     0,
      19,    17,    18,    27,    25,    26,     0,    48,     0,    53,
       0,     0,     0,     0,     0,    50,     0,     0,    47,    49,
      60,    59,    73,     0,     0,     0,     2,    97,    98,    36,
     109,   119,   124,    12,    21,     0,    20,    29,     0,    28,
       0,     0,    43,    45,    54,    51,    37,    38,     0,    39,
      40,     0,    44,     0,    55,    52,    75,   129,   130,    22,
       0,    30,     0,    41,    42,    46,    23,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,  -202,  -202,  -202,  -202,    19,  -202,  -202,  -202,
     -14,  -202,  -202,  -202,  -202,  -202,  -202,   -90,  -202,  -202,
      15,  -202,  -201,  -202,  -202,  -202,  -202,  -202,  -202,   -25,
    -202,  -168,   172,   206,  -202,    24,    -2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    36,    37,    38,    39,    40,    63,    42,    43,    44,
     221,   239,   240,   241,   242,   243,   244,   222,   188,   189,
     245,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,   223,    55,   246,    57,   247,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    65,    66,    67,    68,    69,    70,    71,    97,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    41,
      87,    88,    89,   187,    58,    92,   252,    60,    94,    95,
      96,    99,   101,   103,    93,   273,   116,   270,   271,    72,
      41,   280,   270,   271,   107,    86,   108,   126,   127,   128,
     129,   130,   131,   132,   117,   133,   272,   147,   104,   128,
     129,   279,   128,   129,    90,   133,    93,   -32,   133,   -34,
     -32,   120,   121,    91,   114,   109,    91,   293,   115,    41,
     105,   106,   295,   118,   146,   286,   -33,   119,   190,   171,
     173,   174,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   179,   180,   112,   181,   113,   183,
     185,   191,   144,   145,   154,   144,   145,   193,   -35,   195,
     277,   147,   198,   278,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   123,   -32,   282,   173,   124,   283,   218,   219,
     276,   -34,   224,   110,   111,   128,   129,   122,   225,   128,
     129,   128,   129,   125,   226,   133,   270,   271,   227,   126,
     127,   128,   129,   208,   238,   238,   228,   133,   176,   177,
     231,   192,   234,   194,   103,   217,   275,   128,   129,   250,
     254,   255,   224,   133,   256,   128,   129,   274,   284,   285,
      91,   133,    93,   294,   249,    98,    56,    41,    41,   141,
     142,   143,   144,   145,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,   263,   264,     0,
     266,   267,     0,   269,     0,     0,     0,     0,     0,    41,
     144,   145,     0,     0,   259,   141,   142,   143,   144,   145,
       0,   224,   287,   288,     0,     0,   126,   127,   128,   129,
     130,   131,    41,   289,   133,     0,   291,   281,   126,   127,
     128,   129,   130,   131,   132,     0,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   296,     0,
     297,   126,   127,   128,   129,   130,   131,   132,     0,   133,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   126,   127,   128,   129,   130,
     131,   132,     0,   133,     0,   178,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   126,   127,
     128,   129,   130,   131,   132,     0,   133,     0,   229,     0,
       0,     0,     0,   128,   129,     0,     0,     0,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   126,   127,   128,   129,   130,   131,   132,     0,
     133,     0,   232,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   126,   127,   128,   129,   130,
     131,   132,     0,   133,     0,   235,   144,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   126,
     127,   128,   129,   130,   131,   132,     0,   133,     0,   253,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   126,   127,   128,   129,   130,   131,   132,     0,
     133,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   126,   127,   128,   129,
     130,   131,   132,     0,   133,     0,   268,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   126,
     127,   128,   129,   130,   131,   132,     0,   133,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   126,   127,   128,   129,   130,   131,   132,
       0,   133,     0,   292,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,     0,   159,
       0,     0,     0,   160,   126,   127,   128,   129,   130,   131,
     132,     0,   133,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,     0,   165,     0,     0,     0,   166,   126,   127,
     128,   129,   130,   131,   132,     0,   133,     0,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   126,   127,   128,   129,   130,   131,   132,   150,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   126,   127,   128,   129,   130,
     131,   132,   151,   133,     0,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   126,   127,
     128,   129,   130,   131,   132,   170,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,     0,   251,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,     0,   148,   126,
     127,   128,   129,   130,   131,   132,     0,   133,     0,     0,
       0,     0,     0,     0,     0,   126,   127,   128,   129,   130,
     131,   132,     0,   133,     0,     0,     0,     0,     0,     0,
       0,   126,   127,   128,   129,   130,   131,   132,     0,   133,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,     0,   149,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,   152,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
       0,   153,   126,   127,   128,   129,   130,   131,   132,     0,
     133,     0,     0,     0,     0,     0,     0,     0,   126,   127,
     128,   129,   130,   131,   132,     0,   133,     0,     0,     0,
       0,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,     0,   133,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,     0,   155,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,     0,   156,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   157,   126,   127,   128,   129,   130,
     131,   132,     0,   133,     0,     0,     0,     0,     0,     0,
       0,   126,   127,   128,   129,   130,   131,   132,     0,   133,
       0,     0,     0,     0,     0,     0,     0,   126,   127,   128,
     129,   130,   131,   132,     0,   133,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,   158,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
       0,   161,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,   162,   126,   127,
     128,   129,   130,   131,   132,     0,   133,     0,     0,     0,
       0,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     126,   127,   128,   129,   130,   131,   132,     0,   133,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,     0,   163,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   164,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,     0,
     167,   126,   127,   128,   129,   130,   131,   132,     0,   133,
       0,     0,     0,     0,     0,     0,     0,   126,   127,   128,
     129,   130,   131,   132,     0,   133,     0,     0,     0,     0,
       0,     0,     0,   126,   127,   128,   129,   130,   131,   132,
       0,   133,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
       0,   168,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,   169,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,     0,   257,   126,   127,   128,   129,   130,   131,
     132,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     126,   127,   128,   129,   130,   131,   132,     0,   133,     0,
       0,     0,     0,     0,     0,     0,   126,   127,   128,   129,
     130,   131,   132,     0,   133,     0,     0,     0,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   258,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,     0,
     260,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,     0,   261,   126,   127,   128,
     129,   130,   131,   132,     0,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     1,   262,     2,     3,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,    32,     0,    33,     0,
       0,    34,     0,     0,    35,     2,     3,     4,     5,     6,
       7,     0,     0,     0,     0,     0,     0,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,    22,    23,    24,    25,    26,    61,    62,
      29,     0,    30,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,    32,     0,    33,     0,     0,    34,     0,
       0,    35,     0,   182,     2,     3,     4,     5,     6,     7,
       0,     0,     0,     0,     0,     0,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,    22,    23,    24,    25,    26,    61,    62,    29,
       0,    30,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,    32,     0,    33,     0,     0,    34,     0,     0,
      35,     0,   184,     2,     3,     4,     5,     6,     7,     0,
       0,     0,     0,     0,     0,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,    22,    23,    24,    25,    26,    61,    62,    29,     0,
      30,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,    32,     0,    33,     0,     0,    34,     0,     0,    35,
       0,   230,     2,     3,     4,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
      22,    23,    24,    25,    26,    61,    62,    29,     0,    30,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
      32,     0,    33,     0,     0,    34,     0,     0,    35,     0,
     233,     2,     3,     4,     5,     6,     7,     8,     0,     0,
       0,   236,   220,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    22,
      23,    24,    25,    26,    83,    84,    29,     0,    30,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,    32,
       0,    33,     0,     0,    34,     0,     0,    35,   237,     2,
       3,     4,     5,     6,     7,     8,     0,     0,     0,   236,
     220,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,    22,    23,    24,
      25,    26,    83,    84,    29,     0,    30,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,    32,     0,    33,
       0,     0,    34,     0,     0,    35,   248,     2,     3,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     0,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,    22,    23,    24,    25,    26,
      61,    62,    29,     0,    30,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,   102,     2,     3,     4,     5,     6,
       7,     0,     0,     0,     0,     0,     0,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,    22,    23,    24,    25,    26,    61,    62,
      29,     0,    30,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,    32,     0,    33,     0,     0,    34,     0,
       0,    35,   102,     2,     3,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,    22,    23,    24,    25,    26,    83,    84,    29,     0,
      30,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,    32,     0,    33,    85,     0,    34,     0,     0,    35,
       2,     3,     4,     5,     6,     7,     0,     0,     0,     0,
       0,     0,     9,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,   196,   197,    22,    23,
      24,    25,    26,    61,    62,    29,     0,    30,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,    32,     0,
      33,     0,     0,    34,     0,     0,    35,     2,     3,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     9,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,    22,    23,    24,    25,    26,
      61,    62,    29,     0,    30,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,    32,     0,    33,     0,     0,
      34,     0,     0,    35,     2,     3,     4,     5,     6,     7,
       0,     0,     0,     0,     0,     0,     9,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,    22,    23,    24,    25,    26,    61,    62,    29,
       0,    30,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,    32,     0,    33,     0,     0,    34,   100,     0,
      35,     2,     3,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,    22,
      23,    24,    25,    26,    83,    84,    29,     0,    30,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,    32,
       0,    33,     0,     0,    34,     0,     0,    35,     2,     3,
       4,     5,     6,     7,     0,     0,     0,     0,     0,     0,
       9,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,    22,    23,    24,    25,
      26,    61,    62,    29,     0,    30,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,    32,     0,    33,   172,
       0,    34,     0,     0,    35,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     9,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,    22,    23,    24,    25,    26,    61,    62,
      29,     0,    30,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,    32,     0,    33,     0,     0,    34,     0,
       0,   186,     2,     3,     4,     5,     6,     7,     0,     0,
       0,     0,     0,     0,     9,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
      22,    23,    24,    25,    26,    61,    62,    29,     0,    30,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
      32,     0,    33,   172,     0,    34,     0,     0,    35,     2,
       3,     4,     5,     6,     7,     0,     0,     0,     0,     0,
     220,     9,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,    22,    23,    24,
      25,    26,    61,    62,    29,     0,    30,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,    32,     0,    33,
       0,     0,    34,     0,     0,   186,     2,     3,     4,     5,
       6,     7,     0,     0,     0,     0,     0,     0,     9,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,     0,    22,    23,    24,    25,    26,    61,
      62,    29,     0,    30,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,    32,     0,    33,     0,     0,    34,
       0,     0,    35,     2,     3,     4,     5,     6,     7,     0,
       0,     0,     0,     0,     0,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,    22,    23,    24,    25,    26,    61,    62,    29,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,    32,     0,    33,     0,     0,    34,     0,     0,    35,
     126,   127,   128,   129,   130,   131,   132,     0,   133,     0,
       0,     0,   126,   127,   128,   129,   130,   131,   132,     0,
     133,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,     0,   133,     0,     0,     0,   126,   127,   128,   129,
     130,   131,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   134,   175,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   126,   127,   128,   129,   130,   131,   132,
       0,   133,     0,     0,   126,   127,   128,   129,     0,     0,
       0,     0,   133,     0,   126,   127,   128,   129,     0,     0,
       0,     0,   133,   126,   127,   128,   129,     0,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     128,   129,     0,     0,     0,     0,   133,     0,     0,   128,
     129,     0,     0,     0,     0,   133,   128,   129,     0,     0,
       0,     0,   133,   128,   129,     0,     0,     0,     0,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   139,   140,   141,   142,   143,   144,
     145,   139,   140,   141,   142,   143,   144,   145
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,     5,     6,     7,     8,     9,    33,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      22,    23,    24,   113,     0,    62,   194,    62,    30,    31,
      32,    33,    34,    35,    71,   236,    45,    45,    46,    63,
      21,   242,    45,    46,    67,    21,    69,     3,     4,     5,
       6,     7,     8,     9,    63,    11,    64,    62,     0,     5,
       6,    64,     5,     6,    62,    11,    71,    65,    11,    65,
      65,    19,    20,    71,    63,    71,    71,   278,    67,    60,
      66,    67,   283,    63,    60,   253,    65,    67,   113,    91,
      92,    93,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   106,   107,    65,   109,    71,   111,
     112,   113,    58,    59,    70,    58,    59,   119,    65,   121,
      64,    62,   124,    67,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    63,    65,    64,   147,    67,    67,   150,   151,
     240,    65,   154,    66,    67,     5,     6,    64,   160,     5,
       6,     5,     6,    64,   166,    11,    45,    46,   170,     3,
       4,     5,     6,   175,   188,   189,   178,    11,    63,    63,
     182,    45,   184,    70,   186,    63,    68,     5,     6,    64,
      71,    71,   194,    11,    64,     5,     6,    64,    64,    64,
      71,    11,    71,    64,   189,    33,     0,   188,   189,    55,
      56,    57,    58,    59,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,   229,   230,    -1,
     232,   233,    -1,   235,    -1,    -1,    -1,    -1,    -1,   220,
      58,    59,    -1,    -1,   220,    55,    56,    57,    58,    59,
      -1,   253,   254,   255,    -1,    -1,     3,     4,     5,     6,
       7,     8,   243,   265,    11,    -1,   268,   243,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   290,    -1,
     292,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    70,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    70,    -1,
      -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    -1,    11,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    70,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    70,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    70,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    70,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    70,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    67,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    67,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     3,     4,     5,     6,     7,     8,     9,    67,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     3,     4,     5,     6,     7,
       8,     9,    67,    11,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     3,     4,
       5,     6,     7,     8,     9,    67,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    63,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    63,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    63,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    63,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    63,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    63,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    63,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    63,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    63,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    63,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    63,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    63,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      63,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    63,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    63,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    63,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    63,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      63,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    63,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    10,    63,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,
      -1,    65,    -1,    -1,    68,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    -1,    70,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    62,    -1,    -1,    65,    -1,    -1,
      68,    -1,    70,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    62,    -1,    -1,    65,    -1,    -1,    68,
      -1,    70,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    62,    -1,    -1,    65,    -1,    -1,    68,    -1,
      70,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    -1,    -1,    65,    -1,    -1,    68,    69,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    65,    -1,    -1,    68,    69,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,
      65,    -1,    -1,    68,    69,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    69,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    62,    63,    -1,    65,    -1,    -1,    68,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      62,    -1,    -1,    65,    -1,    -1,    68,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,
      65,    -1,    -1,    68,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    -1,
      68,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    -1,    -1,    65,    -1,    -1,    68,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    63,
      -1,    65,    -1,    -1,    68,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    62,    63,    -1,    65,    -1,    -1,    68,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    65,    -1,    -1,    68,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    65,
      -1,    -1,    68,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    62,    -1,    -1,    65,    -1,    -1,    68,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    11,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    11,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       5,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,     5,
       6,    -1,    -1,    -1,    -1,    11,     5,     6,    -1,    -1,
      -1,    -1,    11,     5,     6,    -1,    -1,    -1,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    53,    54,    55,    56,    57,    58,
      59,    53,    54,    55,    56,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    12,    13,    14,    15,    16,    17,    18,    24,
      25,    26,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    40,    41,    42,    43,    44,    45,    46,    47,
      49,    54,    60,    62,    65,    68,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   104,   105,   106,   107,   108,
      62,    45,    46,    78,   108,   108,   108,   108,   108,   108,
     108,   108,    63,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,    45,    46,    63,   107,   108,   108,   108,
      62,    71,    62,    71,   108,   108,   108,   101,   104,   108,
      66,   108,    69,   108,     0,    66,    67,    67,    69,    71,
      66,    67,    65,    71,    63,    67,    45,    63,    63,    67,
      19,    20,    64,    63,    67,    64,     3,     4,     5,     6,
       7,     8,     9,    11,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   107,    62,    63,    63,
      67,    67,    63,    63,    70,    63,    63,    63,    63,    63,
      67,    63,    63,    63,    63,    63,    67,    63,    63,    63,
      67,   108,    63,   108,   108,    49,    63,    63,    70,   108,
     108,   108,    70,   108,    70,   108,    68,    89,    90,    91,
     101,   108,    45,   108,    70,   108,    38,    39,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,    63,   108,   108,
      23,    82,    89,   103,   108,   108,   108,   108,   108,    70,
      70,   108,    70,    70,   108,    70,    22,    69,    82,    83,
      84,    85,    86,    87,    88,    92,   105,   107,    69,    92,
      64,    64,   103,    70,    71,    71,    64,    63,    63,   107,
      63,    63,    63,   108,   108,    70,   108,   108,    70,   108,
      45,    46,    64,    94,    64,    68,    89,    64,    67,    64,
      94,   107,    64,    67,    64,    64,   103,   108,   108,   108,
      70,   108,    70,    94,    64,    94,   108,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    82,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    92,    92,    92,    92,    93,    94,    94,    95,
      95,    95,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   106,   106,   106,
     106,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     1,     2,     2,     3,     2,
       2,     2,     5,     4,     2,     1,     3,     4,     4,     4,
       5,     5,     6,     7,     3,     4,     4,     4,     5,     5,
       6,     7,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     3,     3,     2,     2,     2,     3,     2,     2,     2,
       2,     1,     2,     1,     2,     2,     3,     3,     3,     4,
       4,     3,     2,     2,     2,     3,     2,     2,     3,     2,
       3,     3,     1,     4,     4,     5,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     5,     2,
       2,     2,     3,     3,     3,     3,     3,     2,     3,     5,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     5,
       3,     3,     3,     3,     5,     2,     2,     2,     3,     5,
       5,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_uint8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     185,     0,   215,   217,     0,     0,     0,     0,     0,     0,
       0,     1,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    11,     0,     0,   207,
     209,    13,    15,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   221,     0,
       0,     0,     0,     0,     0,   211,   213,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    19,    21,    23,    25,
      27,     0,     0,     0,     0,     0,     0,    29,    31,    33,
       0,    35,    37,    39,    41,    43,    45,    47,    49,    51,
       0,     0,     0,    53,    55,    57,    59,    61,    63,    65,
      67,     0,    69,     0,     0,     0,     0,    71,     0,     0,
       0,     0,     0,    73,     0,    75,     0,     0,    77,     0,
       0,    79,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    93,    95,    97,    99,   101,
     103,     0,   105,     0,     0,     0,   131,   133,   135,   137,
     139,   141,   143,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     109,   111,   113,   115,   117,   119,   121,   123,   125,   127,
     129,   147,   149,   151,   153,   155,   157,   159,   161,   163,
     165,   167,   169,     0,     0,   187,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   177,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   193,     0,     0,
       0,     0,     0,     0,     0,   195,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    85,     0,     0,     0,     0,     0,     0,     0,    87,
      89,     0,     0,     0,     0,     0,   199,   201,     0,     0,
       0,     0,     0,   203,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    72,     0,    72,     0,    67,     0,    67,     0,    99,
       0,    99,     0,   100,     0,   100,     0,    51,     0,    51,
       0,    51,     0,    51,     0,    51,     0,    51,     0,    51,
       0,    51,     0,    51,     0,    51,     0,    51,     0,    51,
       0,    51,     0,    51,     0,    51,     0,    51,     0,    51,
       0,    51,     0,    51,     0,    51,     0,    51,     0,    51,
       0,    51,     0,    51,     0,    51,     0,    51,     0,    51,
       0,    51,     0,    51,     0,    51,     0,    51,     0,    51,
       0,    51,     0,    87,     0,    87,     0,    88,     0,    88,
       0,    90,     0,    90,     0,    90,     0,    90,     0,    90,
       0,    90,     0,    90,     0,    90,     0,    90,     0,    90,
       0,    90,     0,    90,     0,    90,     0,    90,     0,    90,
       0,    90,     0,    90,     0,    90,     0,    90,     0,    90,
       0,    89,     0,    89,     0,    89,     0,    89,     0,    89,
       0,    89,     0,    89,     0,    89,     0,    89,     0,    89,
       0,    89,     0,    89,     0,    89,     0,    89,     0,    89,
       0,    89,     0,    89,     0,    89,     0,    89,     0,    89,
       0,    93,     0,    93,     0,    94,     0,    94,     0,    95,
       0,    95,     0,    84,     0,    84,     0,    96,     0,    96,
       0,    92,     0,    92,     0,    91,     0,    91,     0,    85,
       0,    85,     0,    86,     0,    86,     0,    79,     0,    79,
       0,    80,     0,    80,     0,    81,     0,    81,     0,    82,
       0,    82,     0,    83,     0,    83,     0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EQL", "UNEQL", "BEQL",
  "SEQL", "LIMP", "RIMP", "EQV", "GRAPH", "POW", "SQRT", "SGN", "GCD",
  "LCM", "FIBO", "PRIMORIAL", "IF", "ELSE", "ELIF", "ABS", "FOR", "RET",
  "SETPREC", "GETPREC", "SETPRECD", "GETPRECD", "SETOUTPREC", "SOPD",
  "RATIONAL", "NUM", "DEN", "INT_T", "FLT_T", "ISPRIME", "NEXTPRIME",
  "PRINT", "SEP", "END", "REF_COUNT", "ADDRESS_OF", "IS_KEY", "INT", "FLT",
  "VAR", "FUN", "STR", "'^'", "'|'", "'&'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'#'", "'~'", "UMINUS", "'('", "')'", "';'",
  "'['", "']'", "','", "'{'", "'}'", "':'", "'='", "$accept", "Source",
  "List", "Listbegin", "Dict", "Dictbegin", "Subscript", "Subscriptmiddle",
  "Subscriptbegin", "SubscriptExpr", "Return", "For", "Forend",
  "Forendbegin", "Forcond", "Forinit", "Forinitbegin", "Block",
  "Blockmiddle", "Blockbegin", "BlockExpr", "SubscriptAssignment",
  "Assignment", "Function", "Functionproto", "FunctionArgs",
  "FunctionName", "Call", "Callbegin", "If", "Ifbegin", "IfExpr", "Op",
  "Print", "Printbegin", "TopExpr", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)

#endif /* !YYDEBUG */



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
  case 2: /* Source: GRAPH '(' TopExpr ')' ';'  */
#line 74 "parser.y"
                                                                                          { save_graph((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr)); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr); YYACCEPT;               }
#line 2056 "parser.tab.cpp"
    break;

  case 3: /* Source: TopExpr ';'  */
#line 75 "parser.y"
                                                                                                                  { print_eval((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr); YYACCEPT;               }
#line 2062 "parser.tab.cpp"
    break;

  case 4: /* Source: Print ';'  */
#line 76 "parser.y"
                                                                                                                  { print_eval((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Print)); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Print); YYACCEPT;               }
#line 2068 "parser.tab.cpp"
    break;

  case 5: /* Source: Function  */
#line 77 "parser.y"
                                                                                                                  { functions[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Function)->name] = std::unique_ptr<FunctionAST>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Function)); YYACCEPT; }
#line 2074 "parser.tab.cpp"
    break;

  case 6: /* List: '[' ']'  */
#line 80 "parser.y"
                                                                                                          { ((*yyvalp).List) = new ListAST();                                }
#line 2080 "parser.tab.cpp"
    break;

  case 7: /* List: Listbegin ']'  */
#line 81 "parser.y"
                                                                                                          { ((*yyvalp).List) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.List);                                           }
#line 2086 "parser.tab.cpp"
    break;

  case 8: /* Listbegin: Listbegin ',' Expr  */
#line 83 "parser.y"
                                                                                                  { ((*yyvalp).List) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.List); ((*yyvalp).List)->add_element((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                      }
#line 2092 "parser.tab.cpp"
    break;

  case 9: /* Listbegin: '[' Expr  */
#line 84 "parser.y"
                                                                                                                  { ((*yyvalp).List) = new ListAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                              }
#line 2098 "parser.tab.cpp"
    break;

  case 10: /* Dict: '{' '}'  */
#line 87 "parser.y"
                                                                                                          { ((*yyvalp).Dict) = new DictAST();                                }
#line 2104 "parser.tab.cpp"
    break;

  case 11: /* Dict: Dictbegin '}'  */
#line 88 "parser.y"
                                                                                                          { ((*yyvalp).Dict) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Dict);                                           }
#line 2110 "parser.tab.cpp"
    break;

  case 12: /* Dictbegin: Dictbegin ',' Expr ':' Expr  */
#line 90 "parser.y"
                                                                                      { ((*yyvalp).Dict) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Dict); ((*yyvalp).Dict)->add_entry((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                    }
#line 2116 "parser.tab.cpp"
    break;

  case 13: /* Dictbegin: '{' Expr ':' Expr  */
#line 91 "parser.y"
                                                                                                          { ((*yyvalp).Dict) = new DictAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                          }
#line 2122 "parser.tab.cpp"
    break;

  case 14: /* Subscript: Subscriptmiddle ']'  */
#line 94 "parser.y"
                                                                                                   { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Subscript);                                          }
#line 2128 "parser.tab.cpp"
    break;

  case 15: /* Subscriptmiddle: Subscriptbegin  */
#line 96 "parser.y"
                                                                                           { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Subscript);                                          }
#line 2134 "parser.tab.cpp"
    break;

  case 16: /* Subscriptmiddle: Subscriptmiddle ',' Expr  */
#line 97 "parser.y"
                                                                                                   { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                   }
#line 2140 "parser.tab.cpp"
    break;

  case 17: /* Subscriptmiddle: Subscriptmiddle ',' ':' Expr  */
#line 98 "parser.y"
                                                                                           { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript(new NoneAST(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));    }
#line 2146 "parser.tab.cpp"
    break;

  case 18: /* Subscriptmiddle: Subscriptmiddle ',' Expr ':'  */
#line 99 "parser.y"
                                                                                           { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr), new NoneAST());    }
#line 2152 "parser.tab.cpp"
    break;

  case 19: /* Subscriptmiddle: Subscriptmiddle ',' ':' ':'  */
#line 100 "parser.y"
                                                                                                   { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript(new NoneAST(), new NoneAST()); }
#line 2158 "parser.tab.cpp"
    break;

  case 20: /* Subscriptmiddle: Subscriptmiddle ',' Expr ':' Expr  */
#line 101 "parser.y"
                                                                                           { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));               }
#line 2164 "parser.tab.cpp"
    break;

  case 21: /* Subscriptmiddle: Subscriptmiddle ',' ':' ':' Expr  */
#line 102 "parser.y"
                                                                                           { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript(new NoneAST(), new NoneAST(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); }
#line 2170 "parser.tab.cpp"
    break;

  case 22: /* Subscriptmiddle: Subscriptmiddle ',' ':' Expr ':' Expr  */
#line 103 "parser.y"
                                                                                   { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript(new NoneAST(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); }
#line 2176 "parser.tab.cpp"
    break;

  case 23: /* Subscriptmiddle: Subscriptmiddle ',' Expr ':' Expr ':' Expr  */
#line 104 "parser.y"
                                                                                   { ((*yyvalp).Subscript) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.Subscript); ((*yyvalp).Subscript)->add_subscript((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));           }
#line 2182 "parser.tab.cpp"
    break;

  case 24: /* Subscriptbegin: SubscriptExpr '[' Expr  */
#line 106 "parser.y"
                                                                                        { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                   }
#line 2188 "parser.tab.cpp"
    break;

  case 25: /* Subscriptbegin: SubscriptExpr '[' ':' Expr  */
#line 107 "parser.y"
                                                                                                        { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), new NoneAST(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));    }
#line 2194 "parser.tab.cpp"
    break;

  case 26: /* Subscriptbegin: SubscriptExpr '[' Expr ':'  */
#line 108 "parser.y"
                                                                                                        { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr), new NoneAST());    }
#line 2200 "parser.tab.cpp"
    break;

  case 27: /* Subscriptbegin: SubscriptExpr '[' ':' ':'  */
#line 109 "parser.y"
                                                                                                        { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), new NoneAST(), new NoneAST()); }
#line 2206 "parser.tab.cpp"
    break;

  case 28: /* Subscriptbegin: SubscriptExpr '[' Expr ':' Expr  */
#line 110 "parser.y"
                                                                                                { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));               }
#line 2212 "parser.tab.cpp"
    break;

  case 29: /* Subscriptbegin: SubscriptExpr '[' ':' ':' Expr  */
#line 111 "parser.y"
                                                                                                { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Expr), new NoneAST(), new NoneAST(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); }
#line 2218 "parser.tab.cpp"
    break;

  case 30: /* Subscriptbegin: SubscriptExpr '[' ':' Expr ':' Expr  */
#line 112 "parser.y"
                                                                                                { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.Expr), new NoneAST(), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); }
#line 2224 "parser.tab.cpp"
    break;

  case 31: /* Subscriptbegin: SubscriptExpr '[' Expr ':' Expr ':' Expr  */
#line 113 "parser.y"
                                                                                        { ((*yyvalp).Subscript) = new SubscriptAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));           }
#line 2230 "parser.tab.cpp"
    break;

  case 32: /* SubscriptExpr: VAR  */
#line 115 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Var);                                         }
#line 2236 "parser.tab.cpp"
    break;

  case 33: /* SubscriptExpr: List  */
#line 116 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.List);                                         }
#line 2242 "parser.tab.cpp"
    break;

  case 34: /* SubscriptExpr: Subscript  */
#line 117 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Subscript);                                         }
#line 2248 "parser.tab.cpp"
    break;

  case 35: /* SubscriptExpr: Call  */
#line 118 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Call);                                         }
#line 2254 "parser.tab.cpp"
    break;

  case 36: /* Return: RET TopExpr  */
#line 121 "parser.y"
                                                                                                                { ((*yyvalp).Return) = new ReturnAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                          }
#line 2260 "parser.tab.cpp"
    break;

  case 37: /* For: Forend Block  */
#line 124 "parser.y"
                                                                                                                { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.For); ((*yyvalp).For)->add_body((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Block));                       }
#line 2266 "parser.tab.cpp"
    break;

  case 38: /* Forend: Forendbegin ';'  */
#line 127 "parser.y"
                                                                                                        { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.For);                                         }
#line 2272 "parser.tab.cpp"
    break;

  case 39: /* Forend: Forcond ';'  */
#line 128 "parser.y"
                                                                                                                        { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.For);                                         }
#line 2278 "parser.tab.cpp"
    break;

  case 40: /* Forendbegin: Forcond Assignment  */
#line 131 "parser.y"
                                                                                                        { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.For); ((*yyvalp).For)->add_end((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Assignment));                        }
#line 2284 "parser.tab.cpp"
    break;

  case 41: /* Forendbegin: Forendbegin ',' Assignment  */
#line 132 "parser.y"
                                                                                                        { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.For); ((*yyvalp).For)->add_end((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Assignment));                        }
#line 2290 "parser.tab.cpp"
    break;

  case 42: /* Forcond: Forinit TopExpr ';'  */
#line 136 "parser.y"
                                                                                                        { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.For); ((*yyvalp).For)->add_cond((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr));                       }
#line 2296 "parser.tab.cpp"
    break;

  case 43: /* Forinit: FOR ';'  */
#line 139 "parser.y"
                                                                                                                { ((*yyvalp).For) = new ForAST();                               }
#line 2302 "parser.tab.cpp"
    break;

  case 44: /* Forinit: Forinitbegin ';'  */
#line 140 "parser.y"
                                                                                                                { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.For);                                         }
#line 2308 "parser.tab.cpp"
    break;

  case 45: /* Forinitbegin: FOR Assignment  */
#line 143 "parser.y"
                                                                                                { ((*yyvalp).For) = new ForAST(); ((*yyvalp).For)->add_init((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Assignment));             }
#line 2314 "parser.tab.cpp"
    break;

  case 46: /* Forinitbegin: Forinitbegin ',' Assignment  */
#line 144 "parser.y"
                                                                                                        { ((*yyvalp).For) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.For); ((*yyvalp).For)->add_init((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Assignment));                       }
#line 2320 "parser.tab.cpp"
    break;

  case 47: /* Block: Blockbegin '}'  */
#line 147 "parser.y"
                                                                                                        { ((*yyvalp).Block) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Block);                                         }
#line 2326 "parser.tab.cpp"
    break;

  case 48: /* Block: Blockmiddle '}'  */
#line 148 "parser.y"
                                                                                                                { ((*yyvalp).Block) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Block);                                         }
#line 2332 "parser.tab.cpp"
    break;

  case 49: /* Blockmiddle: Blockbegin BlockExpr  */
#line 150 "parser.y"
                                                                                                { ((*yyvalp).Block) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Block); ((*yyvalp).Block)->add_statement((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                  }
#line 2338 "parser.tab.cpp"
    break;

  case 50: /* Blockmiddle: Blockmiddle BlockExpr  */
#line 151 "parser.y"
                                                                                                        { ((*yyvalp).Block) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Block); ((*yyvalp).Block)->add_statement((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                  }
#line 2344 "parser.tab.cpp"
    break;

  case 51: /* Blockbegin: '{'  */
#line 153 "parser.y"
                                                                                                                { ((*yyvalp).Block) = new BlockAST();                             }
#line 2350 "parser.tab.cpp"
    break;

  case 52: /* BlockExpr: TopExpr ';'  */
#line 155 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr);                                         }
#line 2356 "parser.tab.cpp"
    break;

  case 53: /* BlockExpr: For  */
#line 156 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.For);                                         }
#line 2362 "parser.tab.cpp"
    break;

  case 54: /* BlockExpr: Return ';'  */
#line 157 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Return);                                         }
#line 2368 "parser.tab.cpp"
    break;

  case 55: /* BlockExpr: Print ';'  */
#line 158 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Print);                                         }
#line 2374 "parser.tab.cpp"
    break;

  case 56: /* SubscriptAssignment: Subscript '=' Expr  */
#line 161 "parser.y"
                                                                        { ((*yyvalp).SubscriptAssignment) = new SubscriptAssignmentAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Subscript)); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Subscript); }
#line 2380 "parser.tab.cpp"
    break;

  case 57: /* Assignment: VAR '=' Expr  */
#line 165 "parser.y"
                                                                                                        { ((*yyvalp).Assignment) = new AssignmentAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var)->name, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var); }
#line 2386 "parser.tab.cpp"
    break;

  case 58: /* Assignment: FUN '=' Expr  */
#line 166 "parser.y"
                                                                                                                        { ((*yyvalp).Assignment) = new AssignmentAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var)->name, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var); }
#line 2392 "parser.tab.cpp"
    break;

  case 59: /* Function: Functionproto '=' Expr ';'  */
#line 169 "parser.y"
                                                                                                        { ((*yyvalp).Function) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Function); ((*yyvalp).Function)->add_body((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr));                       }
#line 2398 "parser.tab.cpp"
    break;

  case 60: /* Function: Functionproto '=' If ';'  */
#line 170 "parser.y"
                                                                                                        { ((*yyvalp).Function) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Function); ((*yyvalp).Function)->add_body((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.If));                       }
#line 2404 "parser.tab.cpp"
    break;

  case 61: /* Function: Functionproto '=' Block  */
#line 171 "parser.y"
                                                                                                                { ((*yyvalp).Function) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Function); ((*yyvalp).Function)->add_body((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Block));                       }
#line 2410 "parser.tab.cpp"
    break;

  case 62: /* Functionproto: FunctionArgs ')'  */
#line 174 "parser.y"
                                                                                                { ((*yyvalp).Function) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Function);                                         }
#line 2416 "parser.tab.cpp"
    break;

  case 63: /* Functionproto: FunctionName ')'  */
#line 175 "parser.y"
                                                                                                                { ((*yyvalp).Function) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Function);                                         }
#line 2422 "parser.tab.cpp"
    break;

  case 64: /* FunctionArgs: FunctionName VAR  */
#line 177 "parser.y"
                                                                                                { ((*yyvalp).Function) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Function); ((*yyvalp).Function)->add_arg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Var)->name);                  }
#line 2428 "parser.tab.cpp"
    break;

  case 65: /* FunctionArgs: FunctionArgs ',' VAR  */
#line 178 "parser.y"
                                                                                                                { ((*yyvalp).Function) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Function); ((*yyvalp).Function)->add_arg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Var)->name); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Var);       }
#line 2434 "parser.tab.cpp"
    break;

  case 66: /* FunctionName: VAR '('  */
#line 180 "parser.y"
                                                                                                                { ((*yyvalp).Function) = new FunctionAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Var)->name); functions[(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Var)->name] = std::make_unique<FunctionAST>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Var)->name); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Var); }
#line 2440 "parser.tab.cpp"
    break;

  case 67: /* FunctionName: FUN '('  */
#line 181 "parser.y"
                                                                                                                                { ((*yyvalp).Function) = new FunctionAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Var)->name); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Var);       }
#line 2446 "parser.tab.cpp"
    break;

  case 68: /* Call: FUN '(' ')'  */
#line 184 "parser.y"
                                                                                                                        { ((*yyvalp).Call) = new CallAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var)->name); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var);           }
#line 2452 "parser.tab.cpp"
    break;

  case 69: /* Call: Callbegin ')'  */
#line 185 "parser.y"
                                                                                                                        { ((*yyvalp).Call) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Call);                                         }
#line 2458 "parser.tab.cpp"
    break;

  case 70: /* Callbegin: FUN '(' Expr  */
#line 187 "parser.y"
                                                                                                                { ((*yyvalp).Call) = new CallAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var)->name); delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Var); ((*yyvalp).Call)->add_arg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); }
#line 2464 "parser.tab.cpp"
    break;

  case 71: /* Callbegin: Callbegin ',' Expr  */
#line 188 "parser.y"
                                                                                                                { ((*yyvalp).Call) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Call); ((*yyvalp).Call)->add_arg((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                        }
#line 2470 "parser.tab.cpp"
    break;

  case 72: /* If: Ifbegin  */
#line 191 "parser.y"
                                                                                                                                { ((*yyvalp).If) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.If);                                         }
#line 2476 "parser.tab.cpp"
    break;

  case 73: /* If: Ifbegin ELSE ':' IfExpr  */
#line 192 "parser.y"
                                                                                                        { ((*yyvalp).If) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.If); ((*yyvalp).If)->add_default((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                    }
#line 2482 "parser.tab.cpp"
    break;

  case 74: /* Ifbegin: IF Expr ':' IfExpr  */
#line 194 "parser.y"
                                                                                                        { ((*yyvalp).If) = new IfAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                          }
#line 2488 "parser.tab.cpp"
    break;

  case 75: /* Ifbegin: Ifbegin ELIF Expr ':' IfExpr  */
#line 195 "parser.y"
                                                                                                    { ((*yyvalp).If) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.If); ((*yyvalp).If)->add_if((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr));                     }
#line 2494 "parser.tab.cpp"
    break;

  case 76: /* IfExpr: Expr  */
#line 197 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr);                                         }
#line 2500 "parser.tab.cpp"
    break;

  case 77: /* IfExpr: Return  */
#line 198 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Return);                                         }
#line 2506 "parser.tab.cpp"
    break;

  case 78: /* IfExpr: Block  */
#line 199 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Block);                                         }
#line 2512 "parser.tab.cpp"
    break;

  case 79: /* Op: Expr '+' Expr  */
#line 202 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '+', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2518 "parser.tab.cpp"
    break;

  case 80: /* Op: Expr '-' Expr  */
#line 203 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '-', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2524 "parser.tab.cpp"
    break;

  case 81: /* Op: Expr '*' Expr  */
#line 204 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '*', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2530 "parser.tab.cpp"
    break;

  case 82: /* Op: Expr '/' Expr  */
#line 205 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '/', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2536 "parser.tab.cpp"
    break;

  case 83: /* Op: Expr '%' Expr  */
#line 206 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '%', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2542 "parser.tab.cpp"
    break;

  case 84: /* Op: Expr POW Expr  */
#line 207 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), POW, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2548 "parser.tab.cpp"
    break;

  case 85: /* Op: Expr '<' Expr  */
#line 208 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '<', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2554 "parser.tab.cpp"
    break;

  case 86: /* Op: Expr '>' Expr  */
#line 209 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '>', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2560 "parser.tab.cpp"
    break;

  case 87: /* Op: Expr EQL Expr  */
#line 210 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), EQL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2566 "parser.tab.cpp"
    break;

  case 88: /* Op: Expr UNEQL Expr  */
#line 211 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), UNEQL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2572 "parser.tab.cpp"
    break;

  case 89: /* Op: Expr SEQL Expr  */
#line 212 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), SEQL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2578 "parser.tab.cpp"
    break;

  case 90: /* Op: Expr BEQL Expr  */
#line 213 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), BEQL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2584 "parser.tab.cpp"
    break;

  case 91: /* Op: Expr '&' Expr  */
#line 214 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '&', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2590 "parser.tab.cpp"
    break;

  case 92: /* Op: Expr '|' Expr  */
#line 215 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '|', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2596 "parser.tab.cpp"
    break;

  case 93: /* Op: Expr LIMP Expr  */
#line 216 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), LIMP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2602 "parser.tab.cpp"
    break;

  case 94: /* Op: Expr RIMP Expr  */
#line 217 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), RIMP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2608 "parser.tab.cpp"
    break;

  case 95: /* Op: Expr EQV Expr  */
#line 218 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), EQV, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2614 "parser.tab.cpp"
    break;

  case 96: /* Op: Expr '^' Expr  */
#line 219 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Expr), '^', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2620 "parser.tab.cpp"
    break;

  case 97: /* Op: GCD Expr ',' Expr ')'  */
#line 220 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), GCD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2626 "parser.tab.cpp"
    break;

  case 98: /* Op: LCM Expr ',' Expr ')'  */
#line 221 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), LCM, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2632 "parser.tab.cpp"
    break;

  case 99: /* Op: '-' Expr  */
#line 222 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST('-', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2638 "parser.tab.cpp"
    break;

  case 100: /* Op: '~' Expr  */
#line 223 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST('~', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2644 "parser.tab.cpp"
    break;

  case 101: /* Op: Expr '!'  */
#line 224 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST('!', (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2650 "parser.tab.cpp"
    break;

  case 102: /* Op: '|' Expr '|'  */
#line 225 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(ABS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2656 "parser.tab.cpp"
    break;

  case 103: /* Op: SQRT Expr ')'  */
#line 226 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(SQRT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2662 "parser.tab.cpp"
    break;

  case 104: /* Op: SGN Expr ')'  */
#line 227 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(SGN, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2668 "parser.tab.cpp"
    break;

  case 105: /* Op: FIBO Expr ')'  */
#line 228 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(FIBO, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr));	 			   }
#line 2674 "parser.tab.cpp"
    break;

  case 106: /* Op: PRIMORIAL Expr ')'  */
#line 229 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(PRIMORIAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2680 "parser.tab.cpp"
    break;

  case 107: /* Op: Expr '#'  */
#line 230 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(PRIMORIAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2686 "parser.tab.cpp"
    break;

  case 108: /* Op: RATIONAL Expr ')'  */
#line 231 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(RATIONAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2692 "parser.tab.cpp"
    break;

  case 109: /* Op: RATIONAL Expr ',' Expr ')'  */
#line 232 "parser.y"
                                                                                                    { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), RATIONAL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 		   }
#line 2698 "parser.tab.cpp"
    break;

  case 110: /* Op: INT_T Expr ')'  */
#line 233 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(INT_T, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2704 "parser.tab.cpp"
    break;

  case 111: /* Op: FLT_T Expr ')'  */
#line 234 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(FLT_T, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2710 "parser.tab.cpp"
    break;

  case 112: /* Op: NUM Expr ')'  */
#line 235 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(NUM, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2716 "parser.tab.cpp"
    break;

  case 113: /* Op: DEN Expr ')'  */
#line 236 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(DEN, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2722 "parser.tab.cpp"
    break;

  case 114: /* Op: SETPREC Expr ')'  */
#line 237 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(SETPREC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2728 "parser.tab.cpp"
    break;

  case 115: /* Op: GETPREC ')'  */
#line 238 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(GETPREC, new IntAST("0"));   }
#line 2734 "parser.tab.cpp"
    break;

  case 116: /* Op: SETPRECD Expr ')'  */
#line 239 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(SETPRECD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2740 "parser.tab.cpp"
    break;

  case 117: /* Op: SETOUTPREC Expr ')'  */
#line 240 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(SETOUTPREC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2746 "parser.tab.cpp"
    break;

  case 118: /* Op: SOPD Expr ')'  */
#line 241 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(SOPD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2752 "parser.tab.cpp"
    break;

  case 119: /* Op: ISPRIME Expr ',' Expr ')'  */
#line 242 "parser.y"
                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), ISPRIME, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 		   }
#line 2758 "parser.tab.cpp"
    break;

  case 120: /* Op: ISPRIME Expr ')'  */
#line 243 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(ISPRIME, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2764 "parser.tab.cpp"
    break;

  case 121: /* Op: REF_COUNT Expr ')'  */
#line 244 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(REF_COUNT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2770 "parser.tab.cpp"
    break;

  case 122: /* Op: ADDRESS_OF Expr ')'  */
#line 245 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = new UnaryOpAST(ADDRESS_OF, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2776 "parser.tab.cpp"
    break;

  case 123: /* Op: NEXTPRIME Expr ')'  */
#line 246 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = new UnaryOpAST(NEXTPRIME, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 			   }
#line 2782 "parser.tab.cpp"
    break;

  case 124: /* Op: IS_KEY Expr ',' Expr ')'  */
#line 247 "parser.y"
                                                                                                        { ((*yyvalp).Expr) = new BinaryOpAST((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.Expr), IS_KEY, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr)); 		   }
#line 2788 "parser.tab.cpp"
    break;

  case 125: /* Print: Printbegin ')'  */
#line 250 "parser.y"
                                                                                                                { ((*yyvalp).Print) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Print); 										   }
#line 2794 "parser.tab.cpp"
    break;

  case 126: /* Print: PRINT ')'  */
#line 251 "parser.y"
                                                                                                                        { ((*yyvalp).Print) = new PrintAST(); 							   }
#line 2800 "parser.tab.cpp"
    break;

  case 127: /* Printbegin: PRINT TopExpr  */
#line 253 "parser.y"
                                                                                                { ((*yyvalp).Print) = new PrintAST(); ((*yyvalp).Print)->add_argument((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 	   }
#line 2806 "parser.tab.cpp"
    break;

  case 128: /* Printbegin: Printbegin ',' Expr  */
#line 254 "parser.y"
                                                                                                            { ((*yyvalp).Print) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.Print); ((*yyvalp).Print)->add_argument((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2812 "parser.tab.cpp"
    break;

  case 129: /* Printbegin: Printbegin ',' SEP '=' Expr  */
#line 255 "parser.y"
                                                                                                { ((*yyvalp).Print) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Print); ((*yyvalp).Print)->add_seperator((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 				   }
#line 2818 "parser.tab.cpp"
    break;

  case 130: /* Printbegin: Printbegin ',' END '=' Expr  */
#line 256 "parser.y"
                                                                                                { ((*yyvalp).Print) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.Print); ((*yyvalp).Print)->add_end((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr)); 					   }
#line 2824 "parser.tab.cpp"
    break;

  case 131: /* TopExpr: Expr  */
#line 259 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr);                                         }
#line 2830 "parser.tab.cpp"
    break;

  case 132: /* TopExpr: Assignment  */
#line 260 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Assignment); 										   }
#line 2836 "parser.tab.cpp"
    break;

  case 133: /* TopExpr: SubscriptAssignment  */
#line 261 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.SubscriptAssignment); 										   }
#line 2842 "parser.tab.cpp"
    break;

  case 134: /* TopExpr: If  */
#line 262 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.If); 										   }
#line 2848 "parser.tab.cpp"
    break;

  case 135: /* Expr: '(' Op ')'  */
#line 265 "parser.y"
                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.Expr); 										   }
#line 2854 "parser.tab.cpp"
    break;

  case 136: /* Expr: '(' If ')'  */
#line 266 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.If); 										   }
#line 2860 "parser.tab.cpp"
    break;

  case 137: /* Expr: Call  */
#line 267 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Call);                                         }
#line 2866 "parser.tab.cpp"
    break;

  case 138: /* Expr: List  */
#line 268 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.List); 										   }
#line 2872 "parser.tab.cpp"
    break;

  case 139: /* Expr: Dict  */
#line 269 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Dict); 										   }
#line 2878 "parser.tab.cpp"
    break;

  case 140: /* Expr: Subscript  */
#line 270 "parser.y"
                                                                                                                        { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Subscript); 										   }
#line 2884 "parser.tab.cpp"
    break;

  case 141: /* Expr: Op  */
#line 271 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Expr); 										   }
#line 2890 "parser.tab.cpp"
    break;

  case 142: /* Expr: INT  */
#line 272 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Int); 										   }
#line 2896 "parser.tab.cpp"
    break;

  case 143: /* Expr: FLT  */
#line 273 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Flt); 										   }
#line 2902 "parser.tab.cpp"
    break;

  case 144: /* Expr: VAR  */
#line 274 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.Var); 										   }
#line 2908 "parser.tab.cpp"
    break;

  case 145: /* Expr: STR  */
#line 275 "parser.y"
                                                                                                                                { ((*yyvalp).Expr) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.String); 										   }
#line 2914 "parser.tab.cpp"
    break;


#line 2918 "parser.tab.cpp"

      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yysval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}






static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  yyerror (YY_("syntax error"));
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yyst);
  YY_FPRINTF ((stderr, "\n"));
}

static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs




#line 277 "parser.y"


int main() {	
	bool restart = true;
	printf("> ");
	while (restart) {
		yyparse();
	}
	return 0;
}


