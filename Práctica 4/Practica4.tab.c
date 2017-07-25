
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Practica4.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "tabla_simbolos.h"
	#define YYERROR_VERBOSE
	
	int yydebug = 1;
	void yyerror(char*msg);
	
	int linea_actual = 1;
	TipoDato tipo_leido;
	int n_dimensiones = 0;
	int n_parametros = 0;
	int tipo_exp = 0;
	int funcion_existe = 0;
	int yystate = 0;
	
	typedef struct {
		int pos;
		int contParam;
	} PilaParams;
	PilaParams pilaParams[100];
	int topePilaParams = -1;


/* Line 189 of yacc.c  */
#line 100 "Practica4.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PYC = 258,
     ORLOGICO = 259,
     ANDLOGICO = 260,
     XORLOGICO = 261,
     OPIGUALDAD = 262,
     OPRELACION = 263,
     OPMULTIPLICATIVOS = 264,
     NEG = 265,
     INCREMENTO = 266,
     DECREMENTO = 267,
     SUMRES = 268,
     PARDCH = 269,
     PARIZQ = 270,
     CORDCH = 271,
     CORIZQ = 272,
     LLAVEDCH = 273,
     LLAVEIZQ = 274,
     ASIGN = 275,
     COMA = 276,
     NENTERO = 277,
     NDOBLE = 278,
     BOOL = 279,
     CARACTER = 280,
     INICIODCL = 281,
     FINDCL = 282,
     CABECERA = 283,
     TIPO = 284,
     SI = 285,
     SINO = 286,
     MIENTRAS = 287,
     HACER = 288,
     HASTA = 289,
     DEVOLVER = 290,
     ENTRADA = 291,
     SALIDA = 292,
     NOMBREVAR = 293,
     CADENAASCII = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 181 "Practica4.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    11,    18,    21,    22,
      25,    29,    30,    33,    35,    36,    41,    43,    47,    49,
      50,    57,    60,    61,    63,    65,    67,    69,    71,    73,
      75,    77,    79,    81,    83,    88,    94,   102,   108,   116,
     120,   124,   126,   128,   130,   132,   136,   140,   144,   148,
     152,   156,   160,   164,   168,   172,   175,   178,   181,   184,
     186,   188,   190,   192,   193,   196,   197,   201,   203,   204,
     210,   212,   217,   225,   230,   238,   240,   242,   244,   246,
     248,   250,   252,   254,   256,   260,   264,   266,   270,   272,
     276,   280,   282,   286,   288,   292,   296,   298,   302,   304,
     308,   312,   314,   318,   320,   324,   326,   327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    43,    -1,    28,    -1,     1,    -1,
      -1,    19,    44,    47,    45,    54,    18,    -1,    45,    46,
      -1,    -1,    52,    43,    -1,    26,    48,    27,    -1,    -1,
      48,    49,    -1,    49,    -1,    -1,    29,    50,    51,     3,
      -1,     1,    -1,    51,    21,    73,    -1,    73,    -1,    -1,
      29,    38,    15,    53,    89,    14,    -1,    54,    55,    -1,
      -1,    43,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    65,    -1,    66,    -1,     1,    -1,    38,
      -1,    74,    -1,    56,    20,    67,     3,    -1,    30,    15,
      67,    14,    55,    -1,    30,    15,    67,    14,    55,    31,
      55,    -1,    32,    15,    67,    14,    55,    -1,    33,    55,
      34,    15,    67,    14,     3,    -1,    36,    51,     3,    -1,
      62,    21,    63,    -1,    63,    -1,    67,    -1,    64,    -1,
      39,    -1,    37,    62,     3,    -1,    35,    67,     3,    -1,
      15,    67,    14,    -1,    67,     4,    67,    -1,    67,     5,
      67,    -1,    67,     6,    67,    -1,    67,     7,    67,    -1,
      67,     8,    67,    -1,    67,     9,    67,    -1,    67,    13,
      67,    -1,    13,    67,    -1,    10,    67,    -1,    11,    67,
      -1,    12,    67,    -1,    56,    -1,    76,    -1,    71,    -1,
       1,    -1,    -1,    69,    70,    -1,    -1,    70,    21,    67,
      -1,    67,    -1,    -1,    38,    72,    15,    68,    14,    -1,
      38,    -1,    38,    17,    22,    16,    -1,    38,    17,    22,
      16,    17,    22,    16,    -1,    38,    17,    67,    16,    -1,
      38,    17,    67,    16,    17,    67,    16,    -1,    22,    -1,
      23,    -1,    25,    -1,    24,    -1,    75,    -1,    77,    -1,
      80,    -1,    83,    -1,    86,    -1,    17,    78,    16,    -1,
      79,     3,    78,    -1,    79,    -1,    22,    21,    79,    -1,
      22,    -1,    17,    81,    16,    -1,    82,     3,    81,    -1,
      82,    -1,    23,    21,    82,    -1,    23,    -1,    17,    84,
      16,    -1,    85,     3,    84,    -1,    85,    -1,    24,    21,
      85,    -1,    24,    -1,    17,    87,    16,    -1,    88,     3,
      87,    -1,    88,    -1,    25,    21,    88,    -1,    25,    -1,
      89,    21,    90,    -1,    90,    -1,    -1,    29,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    85,    86,    88,    88,    94,    95,    97,
      99,   102,   104,   105,   108,   107,   112,   114,   123,   132,
     131,   145,   146,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   158,   159,   161,   175,   181,   188,   195,   202,
     204,   205,   207,   208,   210,   212,   214,   216,   218,   225,
     232,   239,   246,   253,   260,   267,   269,   271,   273,   275,
     282,   284,   286,   289,   289,   294,   297,   305,   316,   315,
     347,   349,   351,   354,   355,   357,   358,   359,   360,   362,
     363,   364,   365,   366,   368,   370,   371,   373,   374,   375,
     377,   378,   380,   381,   383,   385,   386,   388,   389,   391,
     393,   394,   396,   397,   399,   400,   401,   403
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PYC", "ORLOGICO", "ANDLOGICO",
  "XORLOGICO", "OPIGUALDAD", "OPRELACION", "OPMULTIPLICATIVOS", "NEG",
  "INCREMENTO", "DECREMENTO", "SUMRES", "PARDCH", "PARIZQ", "CORDCH",
  "CORIZQ", "LLAVEDCH", "LLAVEIZQ", "ASIGN", "COMA", "NENTERO", "NDOBLE",
  "BOOL", "CARACTER", "INICIODCL", "FINDCL", "CABECERA", "TIPO", "SI",
  "SINO", "MIENTRAS", "HACER", "HASTA", "DEVOLVER", "ENTRADA", "SALIDA",
  "NOMBREVAR", "CADENAASCII", "$accept", "Programa", "cabecera_programa",
  "bloque", "$@1", "Declar_de_subprogs", "Declar_subprog",
  "Declar_de_variables_locales", "Variables_locales",
  "Cuerpo_declar_variables", "$@2", "lista_variables", "Cabecera_subprog",
  "$@3", "Sentencias", "sentencia", "id", "sentencia_asignacion",
  "sentencia_si", "sentencia_mientras", "sentencia_hacer_hasta",
  "sentencia_entrada", "lista_expresiones_o_cadena", "exp_o_cadena",
  "cadena", "sentencia_salida", "sentencia_devolver", "expresion",
  "lista_exp_vacia", "$@4", "lista_expresiones", "llamada_funcion", "$@5",
  "identificador", "id_array", "constante", "constante_array",
  "array_entero", "asignacion_array_entero", "lista_num_entero",
  "array_real", "asignacion_array_real", "lista_num_real", "array_bool",
  "asignacion_array_bool", "lista_bool", "array_caracter",
  "asignacion_array_caracter", "lista_caracter", "argumentos", "arg", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    44,    43,    45,    45,    46,
      47,    47,    48,    48,    50,    49,    49,    51,    51,    53,
      52,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    58,    58,    59,    60,    61,
      62,    62,    63,    63,    64,    65,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    69,    68,    68,    70,    70,    72,    71,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    77,    78,    78,    79,    79,    80,
      81,    81,    82,    82,    83,    84,    84,    85,    85,    86,
      87,    87,    88,    88,    89,    89,    89,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     6,     2,     0,     2,
       3,     0,     2,     1,     0,     4,     1,     3,     1,     0,
       6,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     7,     5,     7,     3,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     0,     2,     0,     3,     1,     0,     5,
       1,     4,     7,     4,     7,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     3,     0,     0,     1,     5,     2,    11,     0,
       8,    16,    14,     0,    13,    22,     0,    10,    12,     0,
       7,     0,     0,    70,     0,    18,     0,     9,    31,     6,
       0,     0,     0,     0,     0,     0,    32,    23,    21,     0,
      24,    25,    26,    27,    28,    29,    30,    33,     0,    15,
       0,    19,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,    75,    76,    78,    77,    32,    59,     0,    61,
      79,    60,    80,    81,    82,    83,     0,    44,     0,    41,
      43,    42,     0,     0,     0,    17,   106,     0,     0,     0,
      56,    57,    58,    55,     0,    88,    93,    98,   103,     0,
      86,     0,    91,     0,    96,     0,   101,     0,    46,     0,
       0,     0,     0,     0,     0,     0,    39,    45,     0,     0,
       0,    71,     0,     0,   105,     0,     0,     0,    47,     0,
       0,     0,     0,    84,     0,    89,     0,    94,     0,    99,
       0,    63,    48,    49,    50,    51,    52,    53,    54,    40,
      73,    34,     0,   107,    20,     0,    35,    37,     0,    87,
      92,    97,   102,    85,    90,    95,   100,     0,     0,     0,
       0,   104,     0,     0,    69,    67,    64,     0,    72,    36,
      38,     0,    74,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    37,     8,    15,    20,    10,    13,    14,
      16,    24,    21,    86,    22,    38,    67,    40,    41,    42,
      43,    44,    78,    79,    80,    45,    46,    81,   167,   168,
     176,    69,   107,    25,    47,    70,    71,    72,    99,   100,
      73,   101,   102,    74,   103,   104,    75,   105,   106,   123,
     124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
      13,   -49,   -49,     4,    -2,   -49,   -49,   -49,    35,    11,
     -49,   -49,   -49,    10,   -49,    25,    37,   -49,   -49,    38,
     -49,    -2,    34,    46,     2,   -49,    50,   -49,   -49,   -49,
      73,    78,    54,    97,    37,    21,    77,   -49,   -49,    79,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,    80,   -49,
      37,   -49,    97,    97,    72,   -49,    97,    97,    97,    97,
      97,    93,   -49,   -49,   -49,   -49,     1,   -49,   161,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,    26,   -49,    27,   -49,
     -49,   226,    97,    97,    95,   -49,    84,   171,   182,   108,
     -49,   -49,   -49,   111,   193,   104,   105,   106,   107,   123,
     137,   126,   141,   129,   143,   131,   145,   142,   -49,    97,
      97,    97,    97,    97,    97,    97,   -49,   -49,    21,   125,
     205,   144,    37,    28,   -49,    54,    54,    97,   -49,   136,
     139,   135,   146,   -49,   136,   -49,   139,   -49,   135,   -49,
     146,   158,   235,     0,    49,    92,     6,   111,   111,   -49,
     156,   -49,   159,   -49,   -49,    84,   151,   -49,   215,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   169,    97,    97,
     176,   -49,    54,   190,   -49,   226,   173,   147,   -49,   -49,
     -49,    97,   -49,   226
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -49,    64,   -49,   -49,   -49,   -49,   -49,   191,
     -49,   181,   -49,   -49,   -49,   -29,   -22,   -49,   -49,   -49,
     -49,   -49,   -49,    85,   -49,   -49,   -49,   -32,   -49,   -49,
     -49,   -49,   -49,   -48,   -49,   -49,   -49,   -49,    71,    87,
     -49,    81,    96,   -49,    89,    94,   -49,    98,   113,   -49,
      82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -69
static const yytype_int16 yytable[] =
{
      39,    68,    85,    54,     5,    49,   111,   112,   113,   114,
      39,    11,    11,   115,     1,   114,   -68,     6,    82,   115,
      87,    88,    55,    50,    90,    91,    92,    93,    94,   116,
     117,    56,    57,    58,    59,    28,    60,    17,    61,    12,
      12,     2,   154,    62,    63,    64,    65,    50,   118,   155,
     119,   120,    29,     6,    19,    28,   112,   113,   114,    66,
      77,     9,   115,    48,    30,    51,    31,    32,     7,    33,
      34,    35,    36,     6,   153,    23,    26,   142,   143,   144,
     145,   146,   147,   148,    30,    27,    31,    32,    52,    33,
      34,    35,    36,    53,    82,   158,   156,   157,    55,    83,
     113,   114,    84,    39,    39,   115,    89,    56,    57,    58,
      59,   121,    60,   122,    61,    95,    96,    97,    98,    62,
      63,    64,    65,   127,   115,   129,   130,   131,   132,   109,
     110,   111,   112,   113,   114,    66,   175,   177,   115,   133,
     134,   150,   135,   179,   136,   137,   138,   139,   140,   183,
      39,   109,   110,   111,   112,   113,   114,   141,    95,    97,
     115,   152,    96,   182,   108,   109,   110,   111,   112,   113,
     114,    98,   -65,   169,   115,   109,   110,   111,   112,   113,
     114,   170,   172,   174,   115,   125,   109,   110,   111,   112,
     113,   114,   178,   180,   181,   115,   126,   109,   110,   111,
     112,   113,   114,   149,    18,   163,   115,   128,   151,   109,
     110,   111,   112,   113,   114,    76,   159,   164,   115,   109,
     110,   111,   112,   113,   114,   161,   160,   165,   115,   173,
     109,   110,   111,   112,   113,   114,     0,   171,   166,   115,
     110,   111,   112,   113,   114,   162,     0,     0,   115
};

static const yytype_int16 yycheck[] =
{
      22,    33,    50,    32,     0,     3,     6,     7,     8,     9,
      32,     1,     1,    13,     1,     9,    15,    19,    17,    13,
      52,    53,     1,    21,    56,    57,    58,    59,    60,     3,
       3,    10,    11,    12,    13,     1,    15,    27,    17,    29,
      29,    28,    14,    22,    23,    24,    25,    21,    21,    21,
      82,    83,    18,    19,    29,     1,     7,     8,     9,    38,
      39,    26,    13,    17,    30,    15,    32,    33,     4,    35,
      36,    37,    38,    19,   122,    38,    38,   109,   110,   111,
     112,   113,   114,   115,    30,    21,    32,    33,    15,    35,
      36,    37,    38,    15,    17,   127,   125,   126,     1,    20,
       8,     9,    22,   125,   126,    13,    34,    10,    11,    12,
      13,    16,    15,    29,    17,    22,    23,    24,    25,    22,
      23,    24,    25,    15,    13,    21,    21,    21,    21,     4,
       5,     6,     7,     8,     9,    38,   168,   169,    13,    16,
       3,    16,    16,   172,     3,    16,     3,    16,     3,   181,
     172,     4,     5,     6,     7,     8,     9,    15,    22,    24,
      13,    17,    23,    16,     3,     4,     5,     6,     7,     8,
       9,    25,    14,    17,    13,     4,     5,     6,     7,     8,
       9,    22,    31,    14,    13,    14,     4,     5,     6,     7,
       8,     9,    16,     3,    21,    13,    14,     4,     5,     6,
       7,     8,     9,   118,    13,   134,    13,    14,     3,     4,
       5,     6,     7,     8,     9,    34,   129,   136,    13,     4,
       5,     6,     7,     8,     9,   131,   130,   138,    13,    14,
       4,     5,     6,     7,     8,     9,    -1,   155,   140,    13,
       5,     6,     7,     8,     9,   132,    -1,    -1,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    28,    41,    42,     0,    19,    43,    44,    26,
      47,     1,    29,    48,    49,    45,    50,    27,    49,    29,
      46,    52,    54,    38,    51,    73,    38,    43,     1,    18,
      30,    32,    33,    35,    36,    37,    38,    43,    55,    56,
      57,    58,    59,    60,    61,    65,    66,    74,    17,     3,
      21,    15,    15,    15,    55,     1,    10,    11,    12,    13,
      15,    17,    22,    23,    24,    25,    38,    56,    67,    71,
      75,    76,    77,    80,    83,    86,    51,    39,    62,    63,
      64,    67,    17,    20,    22,    73,    53,    67,    67,    34,
      67,    67,    67,    67,    67,    22,    23,    24,    25,    78,
      79,    81,    82,    84,    85,    87,    88,    72,     3,     4,
       5,     6,     7,     8,     9,    13,     3,     3,    21,    67,
      67,    16,    29,    89,    90,    14,    14,    15,    14,    21,
      21,    21,    21,    16,     3,    16,     3,    16,     3,    16,
       3,    15,    67,    67,    67,    67,    67,    67,    67,    63,
      16,     3,    17,    73,    14,    21,    55,    55,    67,    79,
      82,    85,    88,    78,    81,    84,    87,    68,    69,    17,
      22,    90,    31,    14,    14,    67,    70,    67,    16,    55,
       3,    21,    16,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

/* Line 1455 of yacc.c  */
#line 88 "Practica4.y"
    {TS_InsertaMarca();;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 92 "Practica4.y"
    {TS_VaciarEntradas();;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 108 "Practica4.y"
    {tipo_leido = (yyvsp[(1) - (1)]).atrib;
							//printf("\nTipo leido: %d\n", $1.atrib);
						;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 115 "Practica4.y"
    {
			if(!es_repetida((yyvsp[(3) - (3)]).lexema)) {	
				insertarIDENT(variable, (yyvsp[(3) - (3)]).lexema, tipo_leido, n_dimensiones);
			}else{
				//printf("[Linea %d]: semantic error, El identificador %s ya ha sido declarado.\n",linea_actual,$3.lexema);
			}
		;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 124 "Practica4.y"
    {
			if(!es_repetida((yyvsp[(1) - (1)]).lexema)) {	
				insertarIDENT(variable, (yyvsp[(1) - (1)]).lexema, tipo_leido, n_dimensiones);
				//printf("\n Acabo de insertar %s\n", $1.lexema);
			}
		;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 132 "Practica4.y"
    {
				if(!es_repetida((yyvsp[(2) - (3)]).lexema)) {
					insertarIDENT(funcion,(yyvsp[(2) - (3)]).lexema,(yyvsp[(1) - (3)]).tipo, n_parametros);
				}
			;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 139 "Practica4.y"
    {
				asignarNumeroParametros((yyvsp[(2) - (6)]).lexema, n_parametros);
				n_parametros = 0;
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 162 "Practica4.y"
    {
			if(existe((yyvsp[(1) - (4)]).lexema)==0){
				printf("[Linea %d]: semantic error, Identificador %s no declarado\n",linea_actual,(yyvsp[(1) - (4)]).lexema);
			}
			else{
				(yyvsp[(1) - (4)]).tipo=get_tipo((yyvsp[(1) - (4)]).lexema);
				if((yyvsp[(1) - (4)]).tipo!=(yyvsp[(3) - (4)]).tipo){
					printf("[Linea %d]: semantic error, Asignacion de tipos incompatibles, no se puede asignar un %s a un %s\n",linea_actual, MostrarTipo((yyvsp[(3) - (4)]).tipo),MostrarTipo((yyvsp[(1) - (4)]).tipo));
				}
			}
		;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 176 "Practica4.y"
    {
				if((yyvsp[(3) - (5)]).tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo((yyvsp[(3) - (5)]).tipo));
				}
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 182 "Practica4.y"
    {
				if((yyvsp[(3) - (7)]).tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo((yyvsp[(3) - (7)]).tipo));
				}
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 189 "Practica4.y"
    {
				if((yyvsp[(3) - (5)]).tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo((yyvsp[(3) - (5)]).tipo));
				}
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 196 "Practica4.y"
    {
				if((yyvsp[(5) - (7)]).tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo((yyvsp[(5) - (7)]).tipo));
				}
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 217 "Practica4.y"
    {(yyval).tipo = (yyvsp[(2) - (3)]).tipo;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 219 "Practica4.y"
    {
				if( ((yyvsp[(1) - (3)]).tipo != booleano) || ((yyvsp[(3) - (3)]).tipo != booleano) ){
					printf("[Linea %d]: semantic error, los operadores no son booleanos.\n",linea_actual);}
				else{
				(yyval).tipo = booleano;}
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 226 "Practica4.y"
    {
				if( ((yyvsp[(1) - (3)]).tipo != booleano) || ((yyvsp[(3) - (3)]).tipo != booleano) ){
					printf("[Linea %d]: semantic error, los operadores no son booleanos.\n",linea_actual);}
				else{
				(yyval).tipo = booleano;}
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 233 "Practica4.y"
    {
				if( ((yyvsp[(1) - (3)]).tipo != booleano) || ((yyvsp[(3) - (3)]).tipo != booleano) ){
					printf("[Linea %d]: semantic error, los operadores no son booleanos.\n",linea_actual);}
				else{
				(yyval).tipo = booleano;}
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 240 "Practica4.y"
    {
				if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				(yyval).tipo = booleano;}
			;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 247 "Practica4.y"
    {
				if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				(yyval).tipo = booleano;}
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 254 "Practica4.y"
    {
				if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				(yyval).tipo = (yyvsp[(1) - (3)]).tipo;}
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 261 "Practica4.y"
    {
				if((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				(yyval).tipo = (yyvsp[(1) - (3)]).tipo;}
			;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 268 "Practica4.y"
    {(yyval).tipo = (yyvsp[(2) - (2)]).tipo;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 270 "Practica4.y"
    {(yyval).tipo = (yyvsp[(2) - (2)]).tipo;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 272 "Practica4.y"
    {(yyval).tipo = (yyvsp[(2) - (2)]).tipo;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 274 "Practica4.y"
    {(yyval).tipo = (yyvsp[(2) - (2)]).tipo;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 276 "Practica4.y"
    {
			if(existe((yyvsp[(1) - (1)]).lexema)==0){
				printf("[Linea %d]: semantic error, Identificador %s no declarado\n",linea_actual,(yyvsp[(1) - (1)]).lexema);}
			else{
				(yyval).tipo=get_tipo((yyvsp[(1) - (1)]).lexema);}
			;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 283 "Practica4.y"
    {(yyval).tipo = (yyvsp[(1) - (1)]).tipo;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 285 "Practica4.y"
    {(yyval).tipo = (yyvsp[(1) - (1)]).tipo;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 289 "Practica4.y"
    {
		pilaParams[topePilaParams].contParam = 0;
	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 298 "Practica4.y"
    {
	if(funcion_existe != 0) {
		if(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam] != (yyvsp[(3) - (3)]).tipo)
			printf("[Linea %d]: semantic error, Se esperaba parametro de tipo %s en lugar de %s.\n",
					linea_actual, MostrarTipo(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam]), MostrarTipo((yyvsp[(3) - (3)]).tipo));
		pilaParams[topePilaParams].contParam++;
	};}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 306 "Practica4.y"
    {
	if(funcion_existe != 0) {
		if(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam] != (yyvsp[(1) - (1)]).tipo)
			printf("[Linea %d]: semantic error, Se esperaba parametro de tipo %s en lugar de %s.\n",
					linea_actual, MostrarTipo(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam]), MostrarTipo((yyvsp[(1) - (1)]).tipo));
		pilaParams[topePilaParams].contParam++;
	};}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 316 "Practica4.y"
    {
		topePilaParams++;
		pilaParams[topePilaParams].pos = existeFunc((yyvsp[(1) - (1)]).lexema);
		
		if (pilaParams[topePilaParams].pos >= 0) {
			funcion_existe = 1;
		}
		else {
			funcion_existe = 0;
		}
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 328 "Practica4.y"
    {

		if(funcion_existe != 0) {
			if(pilaParams[topePilaParams].contParam != TS[pilaParams[topePilaParams].pos].parametros) {
				printf("[Linea %d]: semantic error, La funcion %s esperaba %d argumentos y ha recibido %d.\n",
							linea_actual,TS[pilaParams[topePilaParams].pos].nombre,TS[pilaParams[topePilaParams].pos].parametros, pilaParams[topePilaParams].contParam);
			}
			(yyval).tipo = TS[pilaParams[topePilaParams].pos].tipo_dato;
		}
		else {
			printf("[Linea %d]: semantic error, La funcion %s no ha sido declarada.\n",
							linea_actual, (yyvsp[(1) - (5)]).lexema);
							
			(yyval).tipo = desconocido;
		}
		topePilaParams--;
		(yyval).tipo = get_tipo((yyvsp[(1) - (5)]).lexema);
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 348 "Practica4.y"
    {n_dimensiones = 0;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 350 "Practica4.y"
    {n_dimensiones = 1;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 352 "Practica4.y"
    {n_dimensiones = 2;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 354 "Practica4.y"
    {(yyval).tipo = (yyvsp[(1) - (4)]).tipo;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 355 "Practica4.y"
    {(yyval).tipo = (yyvsp[(1) - (7)]).tipo;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 404 "Practica4.y"
    {
		if(!es_repetida((yyvsp[(2) - (2)]).lexema)) {	
			insertarIDENT(parametro_formal, (yyvsp[(2) - (2)]).lexema, (yyvsp[(1) - (2)]).tipo, n_dimensiones);
		}else{
			printf("[Linea %d]: semantic error, El parametro formal %s ya ha sido declarado.\n",linea_actual,(yyvsp[(2) - (2)]).lexema);
		}
		(yyval).tipo = (yyvsp[(1) - (2)]).tipo;
		n_parametros = n_parametros + 1;
	;}
    break;



/* Line 1455 of yacc.c  */
#line 1968 "Practica4.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 414 "Practica4.y"


#include "lex.yy.c"

void yyerror(char *msg){
	fprintf(stderr, "[Linea %d]: %s\n", linea_actual, msg);
}
