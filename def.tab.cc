/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "def.yy" /* yacc.c:339  */

#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#define INFILE_ERROR 1
#define OUTFILE_ERROR 2
using namespace std;
extern "C" int yylex();
extern "C" int yyerror(const char *msg, ...);
void writeToFIle(char * text);
void writeToFIlei(int text);
void triples(char * text);
void writeToFIlef(float text);
vector<string> outCode;
class Element
{
	public:
		int type; // 1 zmienna , 2 int ,3 float
		string val;
		string fVal;

		Element()
		{
		}
		Element(int ty,string na)
		{
			type = ty;
			val = na;
			fVal = "0" ;
		}
		Element(int ty,string na, string fv)
		{
			type = ty;
			val = na;
			fVal = fv;
		}
};
void addSymbol(Element el);
stack<Element> myStack;
vector<Element> symbols;
vector<string> symbolsValues;
string result;
stack<string> labels;
stack<string> logOperators;
vector<string> toPrint;
void changeVariableValue(string variableName, int type);
void read(string variableName);
void printing();
void ifJump(string logOperator);
void stringPrintingData(int nl);
void addStringForPrint(string tmp);
void startIf();
static int labelNumber = 1 ;
static int printStringNum = 1;
static int counter = 1;
static int floatCounter = 1;
void endIF();
void startWhile();
void makeIntArray(string name,int lenght);
void makeFloatArray(string name,int lenght);
void changeArray(string name, int index);
void midWhile();
void addFloat(string id);
void addInt(string id);
void elseIf();
void elseIfend();

#line 138 "def.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "def.tab.hh".  */
#ifndef YY_YY_DEF_TAB_HH_INCLUDED
# define YY_YY_DEF_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    LC = 259,
    LR = 260,
    INT = 261,
    FLOAT = 262,
    STRING = 263,
    IF = 264,
    WHILE = 265,
    KOM = 266,
    PR = 267,
    RD = 268,
    EQ = 269,
    NEQ = 270,
    LEQ = 271,
    MEQ = 272,
    ELSE = 273,
    PRN = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 73 "def.yy" /* yacc.c:355  */

	char *text;
	int	ival;
	float fval;

#line 204 "def.tab.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DEF_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "def.tab.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
      26,    27,    31,    29,     2,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
      34,    23,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    84,    84,    85,    88,    89,    90,    91,    92,    93,
      97,    98,    99,   103,   106,   109,   113,   117,   120,   124,
     125,   126,   127,   128,   131,   134,   135,   138,   139,   140,
     143,   144,   145,   148,   149,   150,   153,   154,   155,   156,
     157,   158,   161,   162,   163,   164,   165,   168
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "LC", "LR", "INT", "FLOAT",
  "STRING", "IF", "WHILE", "KOM", "PR", "RD", "EQ", "NEQ", "LEQ", "MEQ",
  "ELSE", "PRN", "';'", "'['", "']'", "'='", "'{'", "'}'", "'('", "')'",
  "'\"'", "'+'", "'-'", "'*'", "'/'", "'>'", "'<'", "$accept", "wiel",
  "linia", "tab_wyr", "if_else_wyr_end", "if_wyr", "if_else_wyr",
  "if_pocz", "while_wyr", "while_pocz", "funkcja", "str", "word", "wyrp",
  "wyr", "skladnik", "operatorLog", "czynnik", "wyrWNawiasach", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      59,    91,    93,    61,   123,   125,    40,    41,    34,    43,
      45,    42,    47,    62,    60
};
# endif

#define YYPACT_NINF -22

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-22)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      90,    -9,    12,    15,   -15,    -5,    -2,     0,    13,    79,
     -22,    22,   -22,   -22,    25,    33,   -22,    39,    46,    49,
      77,     5,    60,    80,    64,    86,     5,     5,    -1,   -22,
      98,    20,   -22,   -22,   -22,    90,    90,    90,   -22,   -22,
      88,    87,   -22,   -22,     5,   -22,    75,   -22,   -22,     5,
      89,     5,    91,    61,    61,   109,    92,    93,    94,   -22,
      95,    10,    31,    55,   100,   110,     5,     5,     5,     5,
     -22,   112,   -22,   113,   -22,   -22,   -22,   -22,   -22,   -22,
       5,     5,   -22,     4,   -22,   -22,   -22,   -22,   -22,    99,
     -22,     5,    96,   -22,   -22,   -22,   -22,   -22,   -22,    97,
     101,   -22,   -22,   -22,   -22,   -22,   -22,   -22
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     7,     6,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     1,     2,     9,     0,     0,     0,     5,     4,
       0,    42,    43,    44,     0,    29,    32,    35,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     0,    36,    37,    39,    38,    40,    41,
       0,     0,    25,     0,    22,    47,    23,    20,    13,    14,
      17,     0,     0,    30,    31,    33,    34,    10,    11,     0,
       0,    26,    24,    15,    12,    46,    16,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,    36,    -8,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   102,   -22,   -22,   -21,   -22,    71,   -17,   120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    56,    83,    19,    57,    46,    80,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    33,    41,    42,    43,    53,    54,   101,    41,    42,
      43,    26,    20,     1,    21,    22,     2,     3,    24,     4,
       5,    27,     6,     7,    28,    44,    30,    55,    70,     8,
      72,    44,   102,    23,     1,    88,    25,     2,     3,    31,
       4,     5,    34,     6,     7,    93,    94,    59,    55,    35,
       8,    95,    96,    33,    33,    33,    89,    36,     1,    99,
     100,     2,     3,    37,     4,     5,    38,     6,     7,    39,
     104,    61,    62,    63,     8,    74,    75,    76,    77,    32,
      90,    40,     1,    49,    50,     2,     3,    51,     4,     5,
      52,     6,     7,     1,    78,    79,     2,     3,     8,     4,
       5,    58,     6,     7,    66,    67,    68,    69,    65,     8,
      64,    71,    82,    73,    92,    97,    98,   103,   105,    84,
      85,    86,    87,    91,   106,    81,    29,     0,   107,     0,
       0,     0,     0,    60
};

static const yytype_int8 yycheck[] =
{
      21,     9,     3,     4,     5,    26,    27,     3,     3,     4,
       5,    26,    21,     3,    23,     3,     6,     7,     3,     9,
      10,    26,    12,    13,    26,    26,    26,    28,    49,    19,
      51,    26,    28,    21,     3,    25,    21,     6,     7,    26,
       9,    10,    20,    12,    13,    66,    67,    27,    28,    24,
      19,    68,    69,    61,    62,    63,    25,    24,     3,    80,
      81,     6,     7,    24,     9,    10,    20,    12,    13,    20,
      91,    35,    36,    37,    19,    14,    15,    16,    17,     0,
      25,     4,     3,    23,     4,     6,     7,    23,     9,    10,
       4,    12,    13,     3,    33,    34,     6,     7,    19,     9,
      10,     3,    12,    13,    29,    30,    31,    32,    21,    19,
      22,    22,     3,    22,     4,     3,     3,    18,    22,    27,
      27,    27,    27,    23,    27,    54,     6,    -1,    27,    -1,
      -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     9,    10,    12,    13,    19,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    48,
      21,    23,     3,    21,     3,    21,    26,    26,    26,    53,
      26,    26,     0,    37,    20,    24,    24,    24,    20,    20,
       4,     3,     4,     5,    26,    49,    50,    52,    53,    23,
       4,    23,     4,    49,    49,    28,    46,    49,     3,    27,
      46,    36,    36,    36,    22,    21,    29,    30,    31,    32,
      49,    22,    49,    22,    14,    15,    16,    17,    33,    34,
      51,    51,     3,    47,    27,    27,    27,    27,    25,    25,
      25,    23,     4,    49,    49,    52,    52,     3,     3,    49,
      49,     3,    28,    18,    49,    22,    27,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      38,    38,    38,    39,    40,    41,    42,    43,    44,    45,
      45,    45,    45,    45,    46,    47,    47,    48,    48,    48,
      49,    49,    49,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     1,     2,
       5,     5,     6,     4,     4,     5,     6,     4,     6,     2,
       4,     3,     4,     4,     3,     1,     2,     4,     4,     3,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 84 "def.yy" /* yacc.c:1646  */
    {printf(" wielolinia \n");}
#line 1366 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "def.yy" /* yacc.c:1646  */
    {printf(" linia \n");}
#line 1372 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "def.yy" /* yacc.c:1646  */
    {printf(" linia przypisujaca \n");}
#line 1378 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 89 "def.yy" /* yacc.c:1646  */
    {printf(" linia z funkcja \n");}
#line 1384 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "def.yy" /* yacc.c:1646  */
    {}
#line 1390 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "def.yy" /* yacc.c:1646  */
    {}
#line 1396 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "def.yy" /* yacc.c:1646  */
    {}
#line 1402 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "def.yy" /* yacc.c:1646  */
    {}
#line 1408 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 97 "def.yy" /* yacc.c:1646  */
    {makeIntArray((yyvsp[0].text),(yyvsp[-2].ival));}
#line 1414 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 98 "def.yy" /* yacc.c:1646  */
    {makeFloatArray((yyvsp[0].text),(yyvsp[-2].ival));}
#line 1420 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 99 "def.yy" /* yacc.c:1646  */
    {changeArray((yyvsp[-5].text), (yyvsp[-3].ival));}
#line 1426 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "def.yy" /* yacc.c:1646  */
    { endIF(); }
#line 1432 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "def.yy" /* yacc.c:1646  */
    { endIF(); }
#line 1438 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 109 "def.yy" /* yacc.c:1646  */
    { elseIf(); }
#line 1444 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 113 "def.yy" /* yacc.c:1646  */
    { startIf(); }
#line 1450 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "def.yy" /* yacc.c:1646  */
    { midWhile(); }
#line 1456 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 120 "def.yy" /* yacc.c:1646  */
    { startWhile(); }
#line 1462 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 124 "def.yy" /* yacc.c:1646  */
    {printf(" wyswietlenie \n"); printing();}
#line 1468 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 125 "def.yy" /* yacc.c:1646  */
    {printf(" wyswietlenie \n"); stringPrintingData(2);}
#line 1474 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "def.yy" /* yacc.c:1646  */
    {printf(" wyswietlenie \n"); stringPrintingData(3);}
#line 1480 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "def.yy" /* yacc.c:1646  */
    {printf(" wyswietlenie str \n"); stringPrintingData(1);}
#line 1486 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 128 "def.yy" /* yacc.c:1646  */
    {printf(" czytanie \n"); read((yyvsp[-1].text));}
#line 1492 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 131 "def.yy" /* yacc.c:1646  */
    {}
#line 1498 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "def.yy" /* yacc.c:1646  */
    {addStringForPrint((yyvsp[0].text));}
#line 1504 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 135 "def.yy" /* yacc.c:1646  */
    {addStringForPrint((yyvsp[0].text));}
#line 1510 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 138 "def.yy" /* yacc.c:1646  */
    {printf(" nowa zmienna int \n"); addInt((yyvsp[-2].text)); }
#line 1516 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 139 "def.yy" /* yacc.c:1646  */
    {printf(" nowa zmienna float \n");addFloat((yyvsp[-2].text));  }
#line 1522 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 140 "def.yy" /* yacc.c:1646  */
    {printf(" przypisanie \n"); changeVariableValue((yyvsp[-2].text),3); }
#line 1528 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 143 "def.yy" /* yacc.c:1646  */
    {printf("+\n");triples("+");}
#line 1534 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 144 "def.yy" /* yacc.c:1646  */
    {printf("-\n");triples("-");}
#line 1540 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 145 "def.yy" /* yacc.c:1646  */
    {printf("wyr\n");}
#line 1546 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 148 "def.yy" /* yacc.c:1646  */
    {printf("*\n");triples("*");}
#line 1552 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 149 "def.yy" /* yacc.c:1646  */
    {printf("/\n");triples("/");}
#line 1558 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 150 "def.yy" /* yacc.c:1646  */
    {printf("skladnik\n");}
#line 1564 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 153 "def.yy" /* yacc.c:1646  */
    { logOperators.push("==");}
#line 1570 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 154 "def.yy" /* yacc.c:1646  */
    {logOperators.push("!=");}
#line 1576 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 155 "def.yy" /* yacc.c:1646  */
    {logOperators.push(">=");}
#line 1582 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 156 "def.yy" /* yacc.c:1646  */
    {logOperators.push("<=");}
#line 1588 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 157 "def.yy" /* yacc.c:1646  */
    {logOperators.push(">");}
#line 1594 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 158 "def.yy" /* yacc.c:1646  */
    {logOperators.push("<");}
#line 1600 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 161 "def.yy" /* yacc.c:1646  */
    {printf("zmienna (%s)\n",(yyvsp[0].text));myStack.push(Element(1,string((yyvsp[0].text))));}
#line 1606 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 162 "def.yy" /* yacc.c:1646  */
    {printf("b:liczba całkowita(%d)\n",(yyvsp[0].ival)); myStack.push(Element(2,to_string((yyvsp[0].ival))));}
#line 1612 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 163 "def.yy" /* yacc.c:1646  */
    {printf("b:liczba rzeczywista (%f)\n",(yyvsp[0].fval)); myStack.push(Element(3,to_string((yyvsp[0].fval)),to_string((yyvsp[0].fval))));}
#line 1618 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 164 "def.yy" /* yacc.c:1646  */
    {printf("wyrazenie w nawiasach\n");}
#line 1624 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 165 "def.yy" /* yacc.c:1646  */
    {stringstream tmp ;tmp<<(yyvsp[-3].text)<<"_"<<to_string((yyvsp[-1].ival)) ;myStack.push(Element(1,tmp.str()));}
#line 1630 "def.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 168 "def.yy" /* yacc.c:1646  */
    {}
#line 1636 "def.tab.cc" /* yacc.c:1646  */
    break;


#line 1640 "def.tab.cc" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 170 "def.yy" /* yacc.c:1906  */

void addSymbol(Element el)
{
	symbols.push_back(el);
	//symbolsValues.push_back(myStack.top().val);
	//myStack.pop();
}
void addStringForPrint(string tmp)
{
	toPrint.push_back(tmp);
}
void addFloat (string id)
{
	if (myStack.top().type == 2) 
		yyerror("you can`t put int into float \n");
	else if (myStack.top().type == 1)
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if(myStack.top().val == symbols[i].val)
			{
				type2 = symbols[i].type;
				break;
			}
		}
		if(type2 == 2)
			yyerror("you can`t put int into float \n");
	}
	symbols.push_back(Element(3,id,myStack.top().fVal));
	myStack.pop();
}
void addInt(string id)
{
	if (myStack.top().type == 3) 
		yyerror("you can`t put float into int \n");
	else if (myStack.top().type == 1)
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if(myStack.top().val == symbols[i].val)
			{
				type2 = symbols[i].type;
				break;
			}
		}
		if(type2 == 3)
			yyerror("you can`t put float into int \n");
	}
	addSymbol(Element(2,id)); 
	changeVariableValue(id,1);
}
void makeIntArray(string name,int lenght)
{
	for (int i = 0 ; i < lenght ; i++)
	{
		stringstream  tmp;
		tmp << name << "_" << i;
		addSymbol(Element(2,tmp.str())); 
	}
}
void makeFloatArray(string name,int lenght)
{
	for (int i = 0 ; i < lenght ; i++)
	{
		stringstream  tmp;
		tmp << name << "_" << i;
		addSymbol(Element(3,tmp.str())); 
	}
}
void changeArray(string name, int index)
{
	stringstream  tmp;
	tmp << name << "_" << index;
	changeVariableValue(tmp.str(),3);
}
void startIf()
{	
	if (myStack.top().type == 2)
		outCode.push_back("li $t1 , "+myStack.top().val);
	else
		outCode.push_back("lw $t1 , "+myStack.top().val);	
	myStack.pop();

	if (myStack.top().type == 2)
		outCode.push_back("li $t0 , "+myStack.top().val);
	else
		outCode.push_back("lw $t0 , "+myStack.top().val);
	myStack.pop();

	string logOperator = logOperators.top();
	logOperators.pop();

	ifJump(logOperator);

	labels.push("label"+to_string(labelNumber));
	labelNumber++;
}
void startWhile()
{	
	outCode.push_back("label"+to_string(labelNumber)+":");
	labelNumber++;
	if (myStack.top().type == 2)
		outCode.push_back("li $t1 , "+myStack.top().val);
	else
		outCode.push_back("lw $t1 , "+myStack.top().val);
	myStack.pop();
	if (myStack.top().type == 2)
		outCode.push_back("li $t0 , "+myStack.top().val);
	else
		outCode.push_back("lw $t0 , "+myStack.top().val);
	myStack.pop();

	string logOperator = logOperators.top();
	logOperators.pop();

	ifJump(logOperator);

	labels.push("label"+to_string(labelNumber));
	labelNumber++;
}
void ifJump(string logOperator)
{
	if(logOperator == "==")
	{
		outCode.push_back("bne $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == "!=")
	{
		outCode.push_back("beq $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == "<")
	{
		outCode.push_back("bge $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == "<=")
	{
		outCode.push_back("bgt $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == ">")
	{
		outCode.push_back("ble $t0, $t1 ,label"+to_string(labelNumber));
	}else if(logOperator == ">=")
	{
		outCode.push_back("blt $t0, $t1 ,label"+to_string(labelNumber));
	}
}
void endIF()
{
	outCode.push_back(labels.top() + ":");
	labels.pop();
}
void elseIf()
{	
	stringstream  tmp;
	tmp <<  "b	" << "label" << labelNumber+1;
	outCode.push_back(tmp.str());
	outCode.push_back(labels.top() + ":");
	labels.pop();
	labelNumber++;
	labels.push("label"+to_string(labelNumber));
}
void midWhile()
{
	outCode.push_back("b label"+to_string(labelNumber-2));
	outCode.push_back(labels.top() + ":");
	labels.pop();
}
void stringPrintingText()
{
	outCode.push_back("li $v0 , 4");
	outCode.push_back("la $a0 , str"+to_string(printStringNum));
	outCode.push_back("syscall");
	printStringNum = printStringNum + 1 ;
}
void stringPrintingData(int nl)
{
	stringstream  tmp;
	tmp <<  "str" << printStringNum << ": .asciiz	";

	tmp << "\"";

	if(nl != 3)
	{
		for (int i = 0 ; i < toPrint.size(); i++)
		{
			tmp << toPrint[i] << " ";
		}
	}
	if(nl == 2 || nl == 3)
		{tmp << "\\n";}

	tmp << "\"";

	toPrint.clear();
	symbols.push_back(Element(4,tmp.str()));

	stringPrintingText();
}
void printing()
{
	int type = myStack.top().type;  // 1 zmienna , 2 int ,3 float

	if(type == 2)
	{
		outCode.push_back("li $v0 , 1");
		outCode.push_back("li $a0 , "+myStack.top().val);
	}else if (type == 3) 
	{
		symbols.push_back(Element(3,"tmp"+to_string(floatCounter),myStack.top().fVal));
		outCode.push_back("li $v0 , 2");
		outCode.push_back("l.s $f12 , tmp"+to_string(floatCounter));
	}else if (type == 1) 
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if( myStack.top().val == symbols[i].val)
			{
				type2 = symbols[i].type;
			}
		}
		if(type2 == 2)
		{
			outCode.push_back("li $v0 , 1");
			outCode.push_back("lw $a0 , "+myStack.top().val);
		}else if (type2 == 3) 
		{
			outCode.push_back("li $v0 , 2");
			outCode.push_back("l.s $f12 , "+ myStack.top().val);
		}
	}

	//zmienna int
	//outCode.push_back("li $v0 , 1");
	//outCode.push_back("lw $a0 , "+myStack.top().val);

	outCode.push_back("syscall");
}
void triples(char * text)
{
	//outfile.open("yyout", std::ios_base::app);

	Element sec = myStack.top();
	myStack.pop();
	Element first = myStack.top();
	myStack.pop();
	int type1 = 0 ;
	int type2 = 0 ;

	result = first.val + text + sec.val;
	//symbols.push_back(Element(2,"result"+to_string(counter)));
	myStack.push(Element(1,"result"+to_string(counter)));
	//symbolsValues.push_back("0");

	outCode.push_back("# " + result );

	if(sec.type == 1 || first.type == 1)
	{
		if (first.type == 1)
		{
			for (int i = 0 ; i < symbols.size() ;i++ )
			{
				if(first.val == symbols[i].val)
				{
					type1 = symbols[i].type;
					break;
				}
			}
		}else
		{
			type1 = first.type;
		}
		if (sec.type == 1)
		{
			for (int i = 0 ; i < symbols.size() ;i++ )
			{
				if(first.val == symbols[i].val)
				{
					type2 = symbols[i].type;
					break;
				}
			}
		}else
		{
			type2 = sec.type;
		}
		if(type1 != type2)
		{
			yyerror("expression has both float and int, unacceptable 1 !!! \n");
		}
	}
	else if (sec.type != first.type )
	{
		yyerror("expression has both float and int, unacceptable 2 !!! \n");
	}

	if(first.type == 1)
	{
		outCode.push_back("lw $t0, " + first.val);
	}else if (first.type == 2)
	{
		outCode.push_back("li $t0, " + first.val);
	}else if (first.type == 3)
	{
		symbols.push_back(Element(3,"tmp"+to_string(floatCounter),first.fVal));
		stringstream  tmp;
		tmp <<  "l.s $f0 , " << "tmp";
		outCode.push_back(tmp.str()+to_string(floatCounter));
		floatCounter++;
	}

	if(sec.type == 1)
	{
		outCode.push_back("lw $t1, " + sec.val);
	}else if (sec.type == 2)
	{
		outCode.push_back("li $t1, " + sec.val);
	}else if (sec.type == 3)
	{
		symbols.push_back(Element(3,"tmp"+to_string(floatCounter),sec.fVal));
		stringstream  tmp;
		tmp <<  "l.s $f1 , " << "tmp";
		outCode.push_back(tmp.str()+to_string(floatCounter));
		floatCounter++;
	}

	if (first.type != 1)
		type1 = first.type ;
	if (sec.type != 1)
		type2 = sec.type ;

	if(type1 == 3 || type2 == 3)
	{
		symbols.push_back(Element(3,"result"+to_string(counter)));
		if(text =="-")
		{	
			outCode.push_back("sub.s $f0 , $f0 , $f1");
		}else if(text == "+")
		{	
			outCode.push_back("add.s $f0 , $f0 , $f1");
		}else if(text == "*")
		{	
			outCode.push_back("mul.s $f0 , $f0 , $f1");
		}else if(text == "/")
		{	
			outCode.push_back("div.s $f0 , $f0 , $f1");
		}
		outCode.push_back("s.s $f0  , result"+to_string(counter) + "\n");
	}else
	{
		symbols.push_back(Element(2,"result"+to_string(counter)));
		if(text =="-")
		{	
			outCode.push_back("sub $t0 , $t0 , $t1");
		}else if(text == "+")
		{	
			outCode.push_back("add $t0 , $t0 , $t1");
		}else if(text == "*")
		{	
			outCode.push_back("mul $t0 , $t0 , $t1");
		}else if(text == "/")
		{	
			outCode.push_back("div $t0 , $t0 , $t1");
		}
		outCode.push_back("sw $t0 , result"+to_string(counter) + "\n");
	}

	ofstream outfile;
	counter++;

	outfile.open("file.txt", std::ios_base::app);
	outfile << result << endl; 
}
void symbolsToFile()
{	
	ofstream outfile;
	ofstream symbolsFile;

	symbolsFile.open("symbols.txt", std::ios_base::app);
	outfile.open("yyout.asm", std::ios_base::app);

	outfile << ".data" << endl;

	for (int i = 0 ; i < symbols.size();i++)
	{
		symbolsFile << symbols[i].type << " " << symbols[i].val << endl;
		if(symbols[i].type == 4 )
			outfile << symbols[i].val << endl;
		else if (symbols[i].type == 3)
			outfile << symbols[i].val << ": .float	" << symbols[i].fVal << endl;
		else
			outfile << symbols[i].val << ":	.word	" << "0" << endl;
	} 
}
void changeVariableValue(string variableName, int type)
{	
	// 1 - int | 2 - float | 3- nieznana
	outCode.push_back("#"+variableName+"="+myStack.top().val);
	if(type == 1)
	{	
		if (myStack.top().type == 2)
			outCode.push_back("li $t0 , "+myStack.top().val);
		else
			outCode.push_back("lw $t0 , "+myStack.top().val);
		outCode.push_back("sw $t0, "+variableName);
	}else if (type == 2) 
	{
		if (myStack.top().type == 3 || myStack.top().type == 2)
			outCode.push_back("l.s $f0 , "+myStack.top().val);
		else
			outCode.push_back("s.s $f0 , "+myStack.top().val);
	}else if (type == 3)
	{
		int type2 = 0;
		for (int i = 0 ; i < symbols.size() ;i++ )
		{
			if(variableName == symbols[i].val)
			{
				type2 = symbols[i].type;
			}
		}
		if (type2 == 3)
		{
			if(myStack.top().type == 2)
			{
				yyerror("you can`t put int into float \n");
			}else if (myStack.top().type == 1)
			{
				for (int i = 0 ; i < symbols.size() ;i++ )
				{
					if(myStack.top().val == symbols[i].val)
					{
						type2 = symbols[i].type;
					}
				}
				if(type2 == 2)
					yyerror("you can`t put int into float \n");
			}
			symbols.push_back(Element(3,"tmp"+to_string(floatCounter),myStack.top().fVal));
			stringstream  tmp;
			tmp <<  "l.s $f0 , " << "tmp";
			outCode.push_back(tmp.str()+to_string(floatCounter));
			outCode.push_back("s.s $f0 , "+variableName);
			floatCounter++;
			
		}else
		{
			if(myStack.top().type == 3)
			{
				yyerror("you can`t put float into int \n");
			}else if (myStack.top().type == 1)
			{
				for (int i = 0 ; i < symbols.size() ;i++ )
				{
					if(myStack.top().val == symbols[i].val)
					{
						type2 = symbols[i].type;
					}
				}
				if(type2 == 3)
					yyerror("you can`t put float into int \n");
				else
					outCode.push_back("lw $t0 , "+myStack.top().val);
			}
			if (myStack.top().type == 2)
				outCode.push_back("li $t0 , "+myStack.top().val);
				
			outCode.push_back("sw $t0, "+variableName);
		}
	}	
	myStack.pop();	
	
}
void read(string variableName)
{
	

	outCode.push_back("li $v0 , 5");
	outCode.push_back("syscall");
	outCode.push_back("sw $v0, "+variableName);
}
void saveOutput()
{	
	ofstream outfile;

	outfile.open("yyout.asm", std::ios_base::app);

	outfile << ".text" << endl;

	for (int i = 0 ; i < outCode.size();i++)
	{
		outfile << outCode[i] << endl;
	} 
}
void writeToFIle(char * text)
{
	FILE *f = fopen("file.txt", "a");	
	fprintf(f, " %s", text);
	fclose(f);
}
void writeToFIlei(int text)
{
	FILE *f = fopen("file.txt", "a");	
	fprintf(f, " %d", text);
	fclose(f);
}
void writeToFIlef(float text)
{
	FILE *f = fopen("file.txt", "a");	
	fprintf(f, " %f", text);
	fclose(f);
}
void clearFiles()
{
	result ="";
	FILE *f = fopen("file.txt", "w");	
	fprintf(f, "");
	fclose(f);

	FILE *fi = fopen("symbols.txt", "w");
	fprintf(fi, "");
	fclose(fi);

	FILE *fil = fopen("yyout.asm", "w");
	fprintf(fil, "");
	fclose(fil);
}
int main(int argc, char *argv[])
{
	clearFiles();

	yyparse();

	symbolsToFile();
	saveOutput();
	
	return 0;
}
