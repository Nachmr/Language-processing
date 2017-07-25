/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "generador.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "tabla_simbolos.h"
    #include "generacion.h"
    #define YYERROR_VERBOSE

	int yydebug = 1;    
    void yyerror(const char *msg);
    
    int linea_actual = 1;
    int declarando_parametros = 0;
    int asignacion_for = 0;
    int yystate = 0;
    int funcion_existe = 0;
    int expresion_correcta = 1;
    char temp [200];
    DescriptorControl dW;	
    int declarando_main = 1;


/* Line 268 of yacc.c  */
#line 94 "y.tab.c"

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
     MASMENOS = 258,
     OPUNA = 259,
     CONST = 260,
     IDENT = 261,
     CAD = 262,
     PARI = 263,
     PARD = 264,
     COMA = 265,
     PYC = 266,
     PRINT = 267,
     SCAN = 268,
     IF = 269,
     THEN = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     FOR = 274,
     TO = 275,
     TIPOBASICO = 276,
     LISTOF = 277,
     BEG = 278,
     END = 279,
     VAR = 280,
     ENDVAR = 281,
     PROG = 282,
     FUNCTION = 283,
     RETURN = 284,
     ASIG = 285,
     CORD = 286,
     CORI = 287,
     DOSPU = 288,
     OPTER1 = 289,
     OPTER2 = 290,
     DOLAR = 291,
     RETAV = 292,
     OPOR = 293,
     OPAND = 294,
     MULDIV = 295,
     OPIGUALDAD = 296,
     OPRELACION = 297,
     OPLISTA = 298
   };
#endif
/* Tokens.  */
#define MASMENOS 258
#define OPUNA 259
#define CONST 260
#define IDENT 261
#define CAD 262
#define PARI 263
#define PARD 264
#define COMA 265
#define PYC 266
#define PRINT 267
#define SCAN 268
#define IF 269
#define THEN 270
#define ELSE 271
#define WHILE 272
#define DO 273
#define FOR 274
#define TO 275
#define TIPOBASICO 276
#define LISTOF 277
#define BEG 278
#define END 279
#define VAR 280
#define ENDVAR 281
#define PROG 282
#define FUNCTION 283
#define RETURN 284
#define ASIG 285
#define CORD 286
#define CORI 287
#define DOSPU 288
#define OPTER1 289
#define OPTER2 290
#define DOLAR 291
#define RETAV 292
#define OPOR 293
#define OPAND 294
#define MULDIV 295
#define OPIGUALDAD 296
#define OPRELACION 297
#define OPLISTA 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 222 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,    11,    13,    14,    15,    23,
      26,    27,    30,    31,    32,    33,    45,    49,    50,    56,
      58,    59,    63,    65,    67,    69,    72,    75,    76,    78,
      80,    82,    84,    87,    89,    91,    92,    93,   101,   102,
     106,   107,   108,   109,   116,   117,   118,   119,   129,   131,
     133,   135,   137,   139,   141,   144,   148,   151,   154,   157,
     160,   164,   167,   170,   171,   176,   177,   182,   186,   190,
     194,   198,   202,   206,   212,   214,   216,   218,   220,   222,
     226,   228,   232,   234,   236,   238,   242,   246,   248,   249,
     255,   256,   259,   260,   264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,    47,    46,    48,    -1,    27,     6,
      -1,     1,    -1,    -1,    -1,    23,    49,    57,    50,    51,
      62,    24,    -1,    51,    52,    -1,    -1,    53,    48,    -1,
      -1,    -1,    -1,    28,     6,     8,    54,    58,    55,     9,
      33,    60,    56,    11,    -1,    25,    58,    26,    -1,    -1,
      58,    59,    33,    60,    11,    -1,     1,    -1,    -1,    59,
      10,     6,    -1,     6,    -1,    21,    -1,    61,    -1,    22,
      21,    -1,    62,    63,    -1,    -1,    48,    -1,    64,    -1,
      70,    -1,    73,    -1,    77,    11,    -1,     1,    -1,    65,
      -1,    -1,    -1,    14,    84,    66,    15,    63,    67,    68,
      -1,    -1,    16,    69,    63,    -1,    -1,    -1,    -1,    17,
      71,    84,    72,    18,    63,    -1,    -1,    -1,    -1,    19,
      74,    79,    75,    20,    84,    76,    18,    63,    -1,    78,
      -1,    80,    -1,    79,    -1,    81,    -1,    82,    -1,    83,
      -1,    29,    84,    -1,     6,    30,    84,    -1,     6,    37,
      -1,    36,     6,    -1,    13,    87,    -1,    12,    88,    -1,
       8,    84,     9,    -1,     3,    84,    -1,     4,    84,    -1,
      -1,    84,     3,    85,    84,    -1,    -1,    84,    40,    86,
      84,    -1,    84,    38,    84,    -1,    84,    39,    84,    -1,
      84,    41,    84,    -1,    84,    42,    84,    -1,    84,    43,
      84,    -1,    84,    35,    84,    -1,    84,    34,    84,    35,
      84,    -1,     6,    -1,     5,    -1,    90,    -1,    92,    -1,
       1,    -1,    87,    10,     6,    -1,     6,    -1,    88,    10,
      89,    -1,    89,    -1,    84,    -1,     7,    -1,    32,    91,
      31,    -1,    91,    10,     5,    -1,     5,    -1,    -1,     6,
      93,     8,    94,     9,    -1,    -1,    95,    96,    -1,    -1,
      96,    10,    84,    -1,    84,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    82,    97,    98,   101,   110,   100,   129,
     130,   132,   145,   152,   157,   144,   166,   169,   171,   190,
     194,   196,   206,   217,   218,   220,   228,   233,   235,   236,
     237,   238,   239,   243,   245,   248,   257,   247,   267,   266,
     277,   284,   292,   283,   308,   312,   321,   307,   340,   341,
     342,   343,   344,   345,   347,   353,   388,   408,   430,   446,
     451,   456,   479,   505,   504,   589,   588,   678,   723,   764,
     799,   835,   894,   915,   938,   951,   965,   966,   971,   973,
     984,   992,   993,   995,  1008,  1014,  1024,  1046,  1076,  1075,
    1116,  1116,  1122,  1126,  1146
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MASMENOS", "OPUNA", "CONST", "IDENT",
  "CAD", "PARI", "PARD", "COMA", "PYC", "PRINT", "SCAN", "IF", "THEN",
  "ELSE", "WHILE", "DO", "FOR", "TO", "TIPOBASICO", "LISTOF", "BEG", "END",
  "VAR", "ENDVAR", "PROG", "FUNCTION", "RETURN", "ASIG", "CORD", "CORI",
  "DOSPU", "OPTER1", "OPTER2", "DOLAR", "RETAV", "OPOR", "OPAND", "MULDIV",
  "OPIGUALDAD", "OPRELACION", "OPLISTA", "$accept", "Programa", "$@1",
  "Cabecera_programa", "bloque", "$@2", "$@3", "Declar_de_subprogs",
  "Declar_subprog", "Cabecera_subprog", "$@4", "$@5", "@6",
  "Declar_de_variables_locales", "Cuerpo_declar_variables",
  "lista_identificadores", "tipo_dato", "tipo_dato_B", "Sentencias",
  "Sentencia", "sentencia_if", "alternativa_simple", "$@7", "$@8",
  "alternativa_doble", "$@9", "sentencia_while", "$@10", "$@11",
  "sentencia_for", "$@12", "$@13", "$@14", "sentencias_PYC",
  "sentencia_return", "sentencia_asignacion", "sentencia_avance_retroceso",
  "sentencia_cursor_comienzo", "sentencia_entrada", "sentencia_salida",
  "expresion", "@15", "@16", "lista_variables",
  "lista_expresiones_o_cadena", "exp_cad", "agregado", "lista_constantes",
  "funcion", "@17", "lista_exp_vacia", "$@18", "lista_expresiones", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    47,    49,    50,    48,    51,
      51,    52,    54,    55,    56,    53,    57,    57,    58,    58,
      58,    59,    59,    60,    60,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    64,    66,    67,    65,    69,    68,
      68,    71,    72,    70,    74,    75,    76,    73,    77,    77,
      77,    77,    77,    77,    78,    79,    80,    81,    82,    83,
      84,    84,    84,    85,    84,    86,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    87,
      87,    88,    88,    89,    89,    90,    91,    91,    93,    92,
      95,    94,    94,    96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     0,     0,     7,     2,
       0,     2,     0,     0,     0,    11,     3,     0,     5,     1,
       0,     3,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     1,     2,     1,     1,     0,     0,     7,     0,     3,
       0,     0,     0,     6,     0,     0,     0,     9,     1,     1,
       1,     1,     1,     1,     2,     3,     2,     2,     2,     2,
       3,     2,     2,     0,     4,     0,     4,     3,     3,     3,
       3,     3,     3,     5,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     3,     3,     1,     0,     5,
       0,     2,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     2,     4,     1,     0,     6,     3,
      17,     0,     7,    19,     0,    10,    22,    16,     0,    27,
       0,     0,     0,     9,     0,     0,    21,    23,     0,     0,
      24,     0,    11,    33,     0,     0,     0,     0,    41,    44,
       8,     0,     0,    28,    26,    29,    34,    30,    31,     0,
      48,    50,    49,    51,    52,    53,    25,    18,    12,     0,
      56,    78,     0,     0,    75,    74,    84,     0,     0,    83,
      59,    82,    76,    77,    80,    58,    35,     0,     0,    54,
      57,    32,     0,    55,    61,    62,     0,     0,    87,     0,
      63,     0,     0,     0,     0,    65,     0,     0,     0,     0,
       0,     0,    42,     0,    45,    13,    90,    60,     0,    85,
       0,     0,    72,    67,    68,     0,    69,    70,    71,    81,
      79,     0,     0,     0,     0,     0,     0,    86,    64,     0,
      66,    36,     0,     0,     0,    89,    94,    91,    73,    40,
      43,    46,     0,     0,    38,    37,     0,    14,    93,     0,
       0,     0,    39,    47,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     7,     4,    43,    10,    15,    19,    23,    24,
      82,   124,   151,    12,    14,    18,    29,    30,    25,    44,
      45,    46,   101,   139,   145,   149,    47,    77,   122,    48,
      78,   123,   146,    49,    50,    51,    52,    53,    54,    55,
      69,   110,   115,    75,    70,    71,    72,    89,    73,    86,
     125,   126,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
       0,   -98,     8,    29,   -98,   -98,   -98,    16,   -98,   -98,
      24,     2,   -98,   -98,     7,   -98,   -98,   -98,    -1,    22,
      59,    54,    66,   -98,    16,   131,   -98,   -98,    56,    70,
     -98,    74,   -98,   -98,    21,   172,    91,    15,   -98,   -98,
     -98,    15,    92,   -98,   -98,   -98,   -98,   -98,   -98,    82,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,    15,
     -98,   -98,    15,    15,   -98,    86,   -98,    15,    94,    28,
      97,   -98,   -98,   -98,   -98,    98,    28,    15,   103,    28,
     -98,   -98,     1,    28,   -98,   -98,   102,     3,   -98,     5,
     -98,    15,    15,    15,    15,   -98,    15,    15,    15,   172,
     109,   101,    28,    89,   -98,   111,   114,   -98,   113,   -98,
      15,    45,    28,    61,    71,    15,    87,    88,    88,   -98,
     -98,   145,   106,   100,   116,   117,    15,   -98,   -29,    15,
      99,   -98,   145,    15,   105,   -98,    28,   124,    28,   119,
     -98,    28,    54,    15,   -98,   -98,   118,   -98,    28,   145,
     145,   128,   -98,   -98,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,   -98,    10,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,    58,   -98,    11,   -98,   -98,   -97,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,    63,   -98,   -98,   -98,   -98,
     -37,   -98,   -98,   -98,   -98,    43,   -98,   -98,   -98,   -98,
     -98,   -98,   -98
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      76,     1,    13,    13,    79,    91,    90,   -20,   -20,    20,
     -20,    95,   107,    16,     5,   108,    61,     9,    62,    63,
      64,    65,    83,    67,   131,    84,    85,     2,   -20,     6,
      87,    90,    21,    17,    32,   140,   109,    91,    92,     8,
     102,    93,    94,    95,    96,    97,    98,    68,    90,    11,
      22,    59,   152,   153,   111,   112,   113,   114,    60,   116,
     117,   118,    91,    92,    90,    26,    93,    94,    95,    96,
      97,    98,    31,   128,    90,    27,    28,    56,   130,    91,
     129,    57,    58,    93,    94,    95,    96,    97,    98,   136,
      90,    90,   138,    81,   -88,    91,   141,    74,    80,    88,
      94,    95,    96,    97,    98,    91,   148,    99,   100,   103,
     106,    95,    96,    97,    98,   120,   121,    16,   127,    59,
     133,    91,    91,   -92,   132,   134,   135,    95,    95,    97,
      98,    98,    33,    91,   143,   144,   150,    34,   142,   154,
     105,   104,   119,    35,    36,    37,    33,     0,    38,     0,
      39,    34,     0,   147,     8,    40,     0,    35,    36,    37,
      41,     0,    38,     0,    39,     0,     0,    42,     8,     0,
       0,     0,     0,    61,    41,    62,    63,    64,    65,    66,
      67,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-98))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      37,     1,     1,     1,    41,    34,     3,     6,     6,    10,
       9,    40,     9,     6,     6,    10,     1,     7,     3,     4,
       5,     6,    59,     8,   121,    62,    63,    27,    26,     0,
      67,     3,    33,    26,    24,   132,    31,    34,    35,    23,
      77,    38,    39,    40,    41,    42,    43,    32,     3,    25,
      28,    30,   149,   150,    91,    92,    93,    94,    37,    96,
      97,    98,    34,    35,     3,     6,    38,    39,    40,    41,
      42,    43,     6,   110,     3,    21,    22,    21,   115,    34,
      35,    11,     8,    38,    39,    40,    41,    42,    43,   126,
       3,     3,   129,    11,     8,    34,   133,     6,     6,     5,
      39,    40,    41,    42,    43,    34,   143,    10,    10,     6,
       8,    40,    41,    42,    43,     6,    15,     6,     5,    30,
      20,    34,    34,     9,    18,     9,     9,    40,    40,    42,
      43,    43,     1,    34,    10,    16,    18,     6,    33,    11,
      82,    78,    99,    12,    13,    14,     1,    -1,    17,    -1,
      19,     6,    -1,   142,    23,    24,    -1,    12,    13,    14,
      29,    -1,    17,    -1,    19,    -1,    -1,    36,    23,    -1,
      -1,    -1,    -1,     1,    29,     3,     4,     5,     6,     7,
       8,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    45,    47,     6,     0,    46,    23,    48,
      49,    25,    57,     1,    58,    50,     6,    26,    59,    51,
      10,    33,    28,    52,    53,    62,     6,    21,    22,    60,
      61,     6,    48,     1,     6,    12,    13,    14,    17,    19,
      24,    29,    36,    48,    63,    64,    65,    70,    73,    77,
      78,    79,    80,    81,    82,    83,    21,    11,     8,    30,
      37,     1,     3,     4,     5,     6,     7,     8,    32,    84,
      88,    89,    90,    92,     6,    87,    84,    71,    74,    84,
       6,    11,    54,    84,    84,    84,    93,    84,     5,    91,
       3,    34,    35,    38,    39,    40,    41,    42,    43,    10,
      10,    66,    84,     6,    79,    58,     8,     9,    10,    31,
      85,    84,    84,    84,    84,    86,    84,    84,    84,    89,
       6,    15,    72,    75,    55,    94,    95,     5,    84,    35,
      84,    63,    18,    20,     9,     9,    84,    96,    84,    67,
      63,    84,    33,    10,    16,    68,    76,    60,    84,    69,
      18,    56,    63,    63,    11
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
        case 2:

/* Line 1806 of yacc.c  */
#line 83 "generador.y"
    {
		// Abrir ficheros
		abrir_ficheros();
		// Escribir la cabecera del fichero (#include dec_dat, dec_fun, stdio)
		escribir_cabecera();
		// Escribir la cabecera del main
//		escribir_main();
	}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 92 "generador.y"
    {
		// Cerrar ficheros
		cerrar_ficheros();
	}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 101 "generador.y"
    { 
		TS_InsertaMarca();
		
		if (declarando_main == 0) { 
			// Abrir llave
			abrir_llave();
		}
	}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 110 "generador.y"
    {
    	if (declarando_main) {
    		escribir_main();
    		abrir_llave();
    		
    		declarando_main = 0;
    	}
    }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 121 "generador.y"
    { 
		(yyval).tipo = (yyvsp[(6) - (7)]).tipo; // PUEDE QUE HAYA QUE PONER 6
		(yyval).lexema = (yyvsp[(6) - (7)]).lexema; // Pude que haya que poner strdup (y 6)
		TS_VaciarEntradas(); 
		// Cerrar llave
		cerrar_llave();
	}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 129 "generador.y"
    { escribir_NL(); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 133 "generador.y"
    {
//		printf("Funcion: %s, Tipo: %d\n", $1.lexema, $1.tipo);
//		if ($1.tipo != $2.tipo) {
//			printf("[Linea %d]: semantic error, Se esperaba una valor de "
//				   "retorno de tipo %s, no de tipo %s\n",
//				   linea_actual, MostrarTipo($1.tipo), MostrarTipo($2.tipo));
//		}
		if (en_fun > 0) en_fun = en_fun-1;
		TS_VaciarEntradas();
	}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 145 "generador.y"
    {
		en_fun++;
		if (es_repetida((yyvsp[(2) - (3)]).lexema) == 0) {insertarIDENT(funcion,(yyvsp[(2) - (3)]).lexema); TS_InsertaMarca();}
		// Ellos en el if meten una marca. Nosotros borramos esa parte
		declarando_parametros = 1;
	}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 152 "generador.y"
    {
		CuentaParametros();
		declarando_parametros = 0;
	}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 157 "generador.y"
    {

		escribir_cabecera_funcion((yyvsp[(9) - (9)]).tipo, (yyvsp[(2) - (9)]).lexema);
		llaveCerrada[en_fun] = 1;
		asignarTipoFuncion((yyvsp[(9) - (9)]).tipo);
		(yyval).tipo = (yyvsp[(9) - (9)]).tipo;
	}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 176 "generador.y"
    {
		escribir_variables(TipoEscrito((yyvsp[(4) - (5)]).tipo));
		
		if (declarando_main) {
//			fprintf(ficheroFunc,"extern \"C\"{\n");
			escribir_variables_extern(TipoEscrito((yyvsp[(4) - (5)]).tipo));
//			fprintf(ficheroFunc,"}");
		}
		
		if(((yyvsp[(3) - (5)]).tipo==4)||((yyvsp[(3) - (5)]).tipo==5)||((yyvsp[(3) - (5)]).tipo==6)||((yyvsp[(3) - (5)]).tipo==7)){
			inicializaListasCascada((yyvsp[(3) - (5)]).tipo);
		}
		asignarTipoCascada((yyvsp[(4) - (5)]).tipo);
	}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 191 "generador.y"
    {
		asignarTipoCascada(desconocido);
	}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 197 "generador.y"
    {
		if (declarando_parametros == 0 && es_repetida((yyvsp[(3) - (3)]).lexema) == 0) {	
			insertarIDENT(variable, (yyvsp[(3) - (3)]).lexema);
		}
		else if (declarando_parametros == 1 &&
				 BuscarParametroRepetido((yyvsp[(3) - (3)]).lexema) == 0) {
			insertarIDENT(parametro_formal, (yyvsp[(3) - (3)]).lexema);
		}
	}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 207 "generador.y"
    {
		if (declarando_parametros == 0 && es_repetida((yyvsp[(1) - (1)]).lexema) == 0) {	
			insertarIDENT(variable, (yyvsp[(1) - (1)]).lexema);
		}
		else if (declarando_parametros == 1 &&
				 BuscarParametroRepetido((yyvsp[(1) - (1)]).lexema) == 0) {
			insertarIDENT(parametro_formal, (yyvsp[(1) - (1)]).lexema);
		}
	}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 221 "generador.y"
    {
		if ((yyvsp[(2) - (2)]).tipo == entero) { (yyval).tipo = lista_entero; }
		if ((yyvsp[(2) - (2)]).tipo == real) { (yyval).tipo = lista_real; }
		if ((yyvsp[(2) - (2)]).tipo == booleano) { (yyval).tipo = lista_booleano; }
		if ((yyvsp[(2) - (2)]).tipo == caracter) { (yyval).tipo = lista_caracter; }
	}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 229 "generador.y"
    {
		(yyval).lexema = (yyvsp[(2) - (2)]).lexema;
		(yyval).tipo = (yyvsp[(2) - (2)]).tipo;
	}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 240 "generador.y"
    {
//		escribir_PYC();
	}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 248 "generador.y"
    {
		if ((yyvsp[(2) - (2)]).tipo!=booleano) {
			printf("[Linea %d]: semantic error, Se esperaba una expresion de "
				   "tipo boolean, no de tipo %s\n",
				   linea_actual, MostrarTipo((yyvsp[(2) - (2)]).tipo));
		}
		escribe_if((yyvsp[(2) - (2)]).lexema);
	}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 257 "generador.y"
    {
//		escribe_elemento(";");
	}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 261 "generador.y"
    {
		delete_descriptor();
		(yyval).tipo = desconocido;
	}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 267 "generador.y"
    {
		escribe_else(); 
	}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 271 "generador.y"
    {
//		escribe_elemento(";");
		sprintf(temp,"%s:;\n",tablaControl[ind].EtiquetaSalida);
		escribe_elemento(temp);
	}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 277 "generador.y"
    {
		sprintf(temp,"%s:;\n",tablaControl[ind].EtiquetaElse);
		escribe_elemento(temp);
	}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 284 "generador.y"
    {
		genera_etiqueta(dW.EtiquetaEntrada);
		genera_etiqueta(dW.EtiquetaSalida);
		add_descriptor(dW);
		escribe_elemento(dW.EtiquetaEntrada); 
		escribe_elemento(":;");
	}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 292 "generador.y"
    {
		if ((yyvsp[(3) - (3)]).tipo!=booleano) {
			printf("[Linea %d]: semantic error, Se esperaba una expresion de "
				   "tipo boolean, no de tipo %s\n",
				   linea_actual, MostrarTipo((yyvsp[(3) - (3)]).tipo));
		}
		escribe_while((yyvsp[(3) - (3)]).lexema);
	}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 301 "generador.y"
    {
		escribir_PYC;
		fin_while();
		(yyval).tipo = desconocido;
	}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 308 "generador.y"
    {
		asignacion_for = 1;
	}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 312 "generador.y"
    {
		asignacion_for = 0;
		genera_etiqueta(dW.EtiquetaEntrada);
		genera_etiqueta(dW.EtiquetaSalida);
		add_descriptor(dW);
		escribe_elemento(dW.EtiquetaEntrada); 
		escribe_elemento(":;");
	}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 321 "generador.y"
    {

		if ((yyvsp[(6) - (6)]).tipo!=entero) {
			printf("[Linea %d]: semantic error, Se esperaba una expresión de "
				   "tipo entero, no de tipo %s\n",
				   linea_actual, MostrarTipo((yyvsp[(6) - (6)]).tipo));
		}
		
		escribe_for((yyvsp[(3) - (6)]).lexema, (yyvsp[(6) - (6)]).lexema);
	}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 332 "generador.y"
    {
		escribir_PYC;
		fin_for((yyvsp[(3) - (9)]).lexema);
		(yyval).tipo = desconocido;
	}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 348 "generador.y"
    {
		sprintf (temp, "return %s;\n", (yyvsp[(2) - (2)]).lexema);
		escribe_elemento(temp);
	}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 354 "generador.y"
    {
		if (existe((yyvsp[(1) - (3)]).lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, (yyvsp[(1) - (3)]).lexema);
		}
		else {
			(yyvsp[(1) - (3)]).tipo=get_tipo((yyvsp[(1) - (3)]).lexema);
			if ((yyvsp[(1) - (3)]).tipo!=(yyvsp[(3) - (3)]).tipo) {
				printf("[Linea %d]: semantic error, Asignacion de tipos "
					   "incompatibles, no se puede asignar un %s a un %s\n",
					   linea_actual, MostrarTipo((yyvsp[(3) - (3)]).tipo),
					   MostrarTipo((yyvsp[(1) - (3)]).tipo));
			}
			else if (asignacion_for == 1 && (yyvsp[(1) - (3)]).tipo != entero) {
				printf("[Linea %d]: semantic error, En sentencia for se debe "
					   "usar un índice entero, no un %s\n",
					   linea_actual, MostrarTipo((yyvsp[(1) - (3)]).tipo));
					   
				
			}
			
			if(existeFunc((yyvsp[(3) - (3)]).lexema) > -1)
				sprintf(buf, "%s", pilaParams[topePilaParams+1].llamadaString);
			else
				sprintf(buf, "%s", (yyvsp[(3) - (3)]).lexema);
			
			escribe_asignacion((yyvsp[(1) - (3)]).lexema, buf);
			escribir_PYC();
			escribir_NL();
			(yyval).tipo = (yyvsp[(1) - (3)]).tipo;
			(yyval).lexema = (yyvsp[(1) - (3)]).lexema;
		}
	}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 389 "generador.y"
    {
		(yyvsp[(1) - (2)]).tipo=get_tipo((yyvsp[(1) - (2)]).lexema);
		if (es_lista((yyvsp[(1) - (2)]).tipo) == 0) {
			printf("[Linea %d]: semantic error, Solo se puede operar con "
				   "cursores sobre listas\n", linea_actual);
		}
		else {	
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (2)]).lexema); 
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (2)]).lexema); 
		
			escribe_operacion_cursor(pilaExpr[topePilaExpr].buffer1, 
									 pilaExpr[topePilaExpr].buffer2, TipoEscrito((yyvsp[(1) - (2)]).tipo));
									 
			escribir_PYC();
			escribir_NL();
		 }
		
	}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 409 "generador.y"
    {
		(yyvsp[(2) - (2)]).tipo=get_tipo((yyvsp[(2) - (2)]).lexema);
		if (es_lista((yyvsp[(2) - (2)]).tipo) == 0) {
			printf("[Linea %d]: semantic error, Solo se puede operar con "
				   "cursores sobre listas.\n", linea_actual);
		}	
		else {
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (2)]).lexema); 
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (2)]).lexema); 
		
		
			printf ("%s\n", (yyvsp[(1) - (2)]).lexema);
			escribe_operacion_cursor(pilaExpr[topePilaExpr].buffer2, 
									 pilaExpr[topePilaExpr].buffer1, TipoEscrito((yyvsp[(2) - (2)]).tipo));
									 
			escribir_PYC();
			escribir_NL();
		
		}
	}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 431 "generador.y"
    {
		if (existe((yyvsp[(2) - (2)]).lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, (yyvsp[(2) - (2)]).lexema);
		}
		else {
			(yyvsp[(2) - (2)]).tipo=get_tipo((yyvsp[(2) - (2)]).lexema);
		}
		if (es_lista((yyvsp[(2) - (2)]).tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede leer en una "
				   "lista.\n", linea_actual);
		}
		(yyval).tipo = desconocido;
	}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 447 "generador.y"
    {
		(yyval).tipo = desconocido;
	}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 452 "generador.y"
    {
		(yyval).tipo=(yyvsp[(2) - (3)]).tipo;
		(yyval).lexema = (yyvsp[(2) - (3)]).lexema;
	}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 457 "generador.y"
    {
 		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (2)]).lexema);
		sprintf(pilaExpr[topePilaExpr].buffer1, 
				"%s%s;\n", (yyvsp[(1) - (2)]).lexema, pilaExpr[topePilaExpr].buffer2);
 	
		(yyvsp[(2) - (2)]).tipo = get_tipoValido((yyvsp[(2) - (2)]).lexema, (yyvsp[(2) - (2)]).tipo);
		if (es_lista((yyvsp[(2) - (2)]).tipo) && (yyvsp[(2) - (2)]).tipo != lista_entero && 
			(yyvsp[(2) - (2)]).tipo != lista_real) {
			printf("[Linea %d]: semantic error, El operador %s es incompatible "
				   "con tipo %s, se esperaba lista de enteros o reales.\n",
				   linea_actual, (yyvsp[(1) - (2)]).lexema, MostrarTipo((yyvsp[(2) - (2)]).tipo));
		}
		else if (((yyvsp[(2) - (2)]).tipo!=entero) && ((yyvsp[(2) - (2)]).tipo!=real)) {
			printf("[Linea %d]: semantic error, El operador %s es incompatible "
				   "con tipo %s, se esperaba entero o real.\n",
				   linea_actual, (yyvsp[(1) - (2)]).lexema, MostrarTipo((yyvsp[(2) - (2)]).tipo));
		}
		else {(yyval).tipo=(yyvsp[(2) - (2)]).tipo;}
		strcpy((yyval).lexema, pilaExpr[topePilaExpr].buffer1);
		topePilaExpr--;
	}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 480 "generador.y"
    {
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (2)]).lexema);
	
		(yyvsp[(2) - (2)]).tipo = get_tipoValido((yyvsp[(2) - (2)]).lexema, (yyvsp[(2) - (2)]).tipo);
		if (es_lista((yyvsp[(2) - (2)]).tipo) == 0) {
			printf("[Linea %d]: semantic error, El operador %s debe aplicarse "
				   "sobre listas.\n",
				   linea_actual, (yyvsp[(1) - (2)]).lexema, MostrarTipo((yyvsp[(2) - (2)]).tipo));
		}
		else {
			if ((yyvsp[(1) - (2)]).atrib == 0) { 
				(yyval).tipo = tipoEnLista((yyvsp[(2) - (2)]).tipo); 
				generaExpUnaria(pilaExpr[topePilaExpr].buffer2,"?",TipoEscrito((yyvsp[(2) - (2)]).tipo));
				strcpy((yyval).lexema, tmp);
				
			}
			else if ((yyvsp[(1) - (2)]).atrib == 1) { 
				(yyval).tipo = entero; 
				generaExpUnaria(pilaExpr[topePilaExpr].buffer2,"#",TipoEscrito((yyvsp[(2) - (2)]).tipo));
				strcpy((yyval).lexema, tmp);
			}
		}
	}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 505 "generador.y"
    {
		topePilaExpr++; 
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (2)]).lexema);
	}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 511 "generador.y"
    {
		(yyvsp[(1) - (4)]).tipo = get_tipoValido((yyvsp[(1) - (4)]).lexema, (yyvsp[(1) - (4)]).tipo);
		(yyvsp[(4) - (4)]).tipo = get_tipoValido((yyvsp[(4) - (4)]).lexema, (yyvsp[(4) - (4)]).tipo);
		
		//Valor y valor
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 0 && es_lista((yyvsp[(4) - (4)]).tipo) == 0) {
			if ((yyvsp[(1) - (4)]).tipo != (yyvsp[(4) - (4)]).tipo) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual ,MostrarTipo((yyvsp[(1) - (4)]).tipo),
					   MostrarTipo((yyvsp[(4) - (4)]).tipo));
			}
			else {
				(yyval).tipo=(yyvsp[(1) - (4)]).tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
										 (yyvsp[(4) - (4)]).lexema);
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
								 pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (4)]).lexema,
								 TipoEscrito((yyvsp[(1) - (4)]).tipo), TipoEscrito((yyvsp[(4) - (4)]).tipo),0);
				escribe_elemento(";\n");
				strcpy((yyval).lexema, tmp);
				expresion_correcta =1;
			}
		}
		
		//Valor y lista (solo el *)
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 0 && es_lista((yyvsp[(4) - (4)]).tipo) == 1) {
			if ((yyvsp[(1) - (4)]).tipo!=tipoEnLista((yyvsp[(4) - (4)]).tipo)) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo((yyvsp[(1) - (4)]).tipo),
					   MostrarTipo((yyvsp[(4) - (4)]).tipo));
			}
			(yyval).tipo=(yyvsp[(3) - (4)]).tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(4) - (4)]).lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
							 pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (4)]).lexema,
							 TipoEscrito((yyvsp[(1) - (4)]).tipo), TipoEscrito((yyvsp[(4) - (4)]).tipo), "il");
			escribe_elemento(";\n");
			strcpy((yyval).lexema, tmp);
		}
		
		//Dos listas
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 1 && es_lista((yyvsp[(4) - (4)]).tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede hacer suma de "
				   "listas.\n", linea_actual);
				   
			(yyval).tipo=(yyvsp[(1) - (4)]).tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(4) - (4)]).lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
							 pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (4)]).lexema,
							 TipoEscrito((yyvsp[(1) - (4)]).tipo), TipoEscrito((yyvsp[(4) - (4)]).tipo), "ll");
			escribe_elemento(";\n");
			strcpy((yyval).lexema, tmp);
			expresion_correcta =1;
		}
		
		//Lista y valor
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 1 && es_lista((yyvsp[(4) - (4)]).tipo) == 0) {
			if (tipoEnLista((yyvsp[(1) - (4)]).tipo) !=(yyvsp[(4) - (4)]).tipo) {
				printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo((yyvsp[(1) - (4)]).tipo),
					   MostrarTipo((yyvsp[(4) - (4)]).tipo));
			}
			
			(yyval).tipo=(yyvsp[(1) - (4)]).tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(4) - (4)]).lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
							 pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (4)]).lexema,
							 TipoEscrito((yyvsp[(1) - (4)]).tipo), TipoEscrito((yyvsp[(4) - (4)]).tipo), "li");							
			escribe_elemento(";\n");
			strcpy((yyval).lexema, tmp);
		}
		
		topePilaExpr--;
	}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 589 "generador.y"
    { 
	 	topePilaExpr++; 
	 	copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (2)]).lexema); 
	 }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 594 "generador.y"
    {
		(yyvsp[(1) - (4)]).tipo = get_tipoValido((yyvsp[(1) - (4)]).lexema, (yyvsp[(1) - (4)]).tipo);
		(yyvsp[(4) - (4)]).tipo = get_tipoValido((yyvsp[(4) - (4)]).lexema, (yyvsp[(4) - (4)]).tipo);
		
		//Valor y valor
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 0 && es_lista((yyvsp[(4) - (4)]).tipo) == 0) {
			if ((yyvsp[(1) - (4)]).tipo != (yyvsp[(4) - (4)]).tipo) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo((yyvsp[(1) - (4)]).tipo),
					   MostrarTipo((yyvsp[(4) - (4)]).tipo));
			}
			
			else{
				(yyval).tipo=(yyvsp[(1) - (4)]).tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
										 (yyvsp[(4) - (4)]).lexema);
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
								 pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (4)]).lexema,
								 TipoEscrito((yyvsp[(1) - (4)]).tipo), TipoEscrito((yyvsp[(4) - (4)]).tipo), 0);
				escribe_elemento(";\n");
				strcpy((yyval).lexema, tmp);
				expresion_correcta =1;
			}
		}
		
		//Valor y lista
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 0 && es_lista((yyvsp[(4) - (4)]).tipo) == 1) {
			if ((yyvsp[(1) - (4)]).tipo!=tipoEnLista((yyvsp[(4) - (4)]).tipo)) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo((yyvsp[(1) - (4)]).tipo),
					   MostrarTipo((yyvsp[(4) - (4)]).tipo));
			}
			
			else{
				if((yyvsp[(1) - (4)]).tipo!=entero && (yyvsp[(1) - (4)]).tipo!=real){
					printf("[Linea %d]: semantic error, No se puede aplicar el "
						   "operador %s a %s%s%s.\n", linea_actual, (yyvsp[(2) - (4)]).lexema,
						   MostrarTipo((yyvsp[(1) - (4)]).tipo), (yyvsp[(2) - (4)]).lexema,
						   MostrarTipo((yyvsp[(4) - (4)]).tipo));
				}
				(yyval).tipo=(yyvsp[(3) - (4)]).tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2,
										 (yyvsp[(4) - (4)]).lexema);
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1, 
								 pilaExpr[topePilaExpr].buffer2, (yyvsp[(2) - (4)]).lexema,
								 TipoEscrito((yyvsp[(1) - (4)]).tipo),
								 TipoEscrito((yyvsp[(4) - (4)]).tipo), "il");
				escribe_elemento(";\n");
				strcpy((yyval).lexema, tmp);
			}
		}
		
		//Dos listas
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 1 && es_lista((yyvsp[(4) - (4)]).tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede hacer suma de "
				   "listas.\n", linea_actual);

			(yyval).tipo=(yyvsp[(1) - (4)]).tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(4) - (4)]).lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (4)]).lexema,TipoEscrito((yyvsp[(1) - (4)]).tipo), TipoEscrito((yyvsp[(4) - (4)]).tipo),"ll");
			escribe_elemento(";\n");
			strcpy((yyval).lexema, tmp);
		}
		
		//Lista y valor
		if (es_lista((yyvsp[(1) - (4)]).tipo) == 1 && es_lista((yyvsp[(4) - (4)]).tipo) == 0) {
			if (tipoEnLista((yyvsp[(1) - (4)]).tipo) !=(yyvsp[(4) - (4)]).tipo) {
				printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo((yyvsp[(1) - (4)]).tipo),
					   MostrarTipo((yyvsp[(4) - (4)]).tipo));
			}
			
			(yyval).tipo=(yyvsp[(1) - (4)]).tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(4) - (4)]).lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (4)]).lexema,TipoEscrito((yyvsp[(1) - (4)]).tipo), TipoEscrito((yyvsp[(4) - (4)]).tipo),"li");							
			escribe_elemento(";\n");
			strcpy((yyval).lexema, tmp);
		}
		
		topePilaExpr--;
	}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 679 "generador.y"
    {
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (3)]).lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(3) - (3)]).lexema);
		
		expresion_correcta = 1;
		if (es_lista(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)) == 1 || 
			es_lista(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)) == 1) {
			printf("[Linea %d]: semantic error, No se pueden hacer operaciones "
				   "logicas entre listas.\n", linea_actual,
				   MostrarTipo(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)),
				   MostrarTipo(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)));
				   
			expresion_correcta = 0;
		}
				   
		else if (((yyvsp[(1) - (3)]).tipo) != ((yyvsp[(3) - (3)]).tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n", linea_actual,
				   MostrarTipo(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)),
				   MostrarTipo(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)));
				   
			expresion_correcta = 0;
		}
		else {
			if ((yyvsp[(3) - (3)]).tipo!=booleano) {
				printf("[Linea %d]: semantic error, Solo se admiten operaciones"
					   " logicas sobre tipo boolean, no de tipo %s\n",
					   linea_actual,MostrarTipo((yyvsp[(3) - (3)]).tipo)); 
			expresion_correcta = 0;
		
			}
		}
		
		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (3)]).lexema,"int", TipoEscrito((yyvsp[(3) - (3)]).tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,(yyval).lexema,11);
		}
		
		expresion_correcta = 1;
		(yyval).tipo=booleano;
		topePilaExpr--;
	}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 724 "generador.y"
    {
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (3)]).lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(3) - (3)]).lexema);
	
		if (es_lista(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)) == 1 || 
			es_lista(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)) == 1) {
			printf("[Linea %d]: semantic error, No se pueden hacer operaciones "
				   "logicas entre listas.\n", linea_actual,
				   MostrarTipo(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)),
				   MostrarTipo(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)));
			
			expresion_correcta = 0;		   
		}
		else if (((yyvsp[(1) - (3)]).tipo) != ((yyvsp[(3) - (3)]).tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n", linea_actual,
				   MostrarTipo(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)),
				   MostrarTipo(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)));
			expresion_correcta = 0;	
		}
		else {
			if ((yyvsp[(3) - (3)]).tipo!=booleano) {
				printf("[Linea %d]: semantic error, Solo se admiten operaciones"
					   " logicas sobre tipo boolean, no de tipo %s\n",
					   linea_actual, MostrarTipo((yyvsp[(3) - (3)]).tipo)); 
				expresion_correcta = 0;	
			}
		}

		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (3)]).lexema,"int", TipoEscrito((yyvsp[(3) - (3)]).tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,(yyval).lexema,11);
		}
		
		expresion_correcta = 1;
		(yyval).tipo=booleano;
		topePilaExpr--;
	}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 765 "generador.y"
    {
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (3)]).lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(3) - (3)]).lexema);
		
		if (es_lista(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)) == 1 ||
			es_lista(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)) == 1) {
			printf("[Linea %d]: semantic error, No se pueden hacer operaciones"
				   " logicas entre listas.\n", linea_actual,
				   MostrarTipo(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)),
				   MostrarTipo(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)));
			
			expresion_correcta = 0;
		}
		else if (((yyvsp[(1) - (3)]).tipo) != ((yyvsp[(3) - (3)]).tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n", linea_actual,
				   MostrarTipo(get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo)),
				   MostrarTipo(get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo)));
			
			expresion_correcta = 0;
		}
		
		
		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (3)]).lexema,"int", TipoEscrito((yyvsp[(3) - (3)]).tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,(yyval).lexema,11);
		}
		
		expresion_correcta = 1;
		(yyval).tipo=booleano;
		topePilaExpr--;
	}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 800 "generador.y"
    {
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (3)]).lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(3) - (3)]).lexema);
	
		(yyvsp[(1) - (3)]).tipo = get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo);
		(yyvsp[(3) - (3)]).tipo = get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo);
		if ((((yyvsp[(1) - (3)]).tipo!=entero) && ((yyvsp[(1) - (3)]).tipo!=real)) || 
			(((yyvsp[(3) - (3)]).tipo!=entero) && ((yyvsp[(3) - (3)]).tipo!=real))) {
			printf("[Linea %d]: semantic error, El operador %s se esta "
				   "utilizando como: %s%s%s, se esperaba int%sint o "
				   "real%sreal.\n",
				   linea_actual, (yyvsp[(2) - (3)]).lexema, MostrarTipo((yyvsp[(1) - (3)]).tipo), (yyvsp[(2) - (3)]).lexema, 
				   MostrarTipo((yyvsp[(3) - (3)]).tipo), (yyvsp[(2) - (3)]).lexema, (yyvsp[(2) - (3)]).lexema);
		
			expresion_correcta = 0;
		}
		else if (((yyvsp[(1) - (3)]).tipo) != ((yyvsp[(3) - (3)]).tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n",
				   linea_actual, MostrarTipo((yyvsp[(1) - (3)]).tipo), MostrarTipo((yyvsp[(3) - (3)]).tipo));
			expresion_correcta = 0;
		}
		
		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (3)]).lexema,"int", TipoEscrito((yyvsp[(3) - (3)]).tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,(yyval).lexema,11);
		}
		
		expresion_correcta = 1;
		(yyval).tipo=booleano;

		topePilaExpr--;
	}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 837 "generador.y"
    {
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (3)]).lexema); 
	
	 	(yyvsp[(1) - (3)]).tipo = get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo);
		(yyvsp[(3) - (3)]).tipo = get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo);
		
		if ((yyvsp[(2) - (3)]).atrib == 1) {
			if (es_lista((yyvsp[(1) - (3)]).tipo) == 0 || es_lista((yyvsp[(3) - (3)]).tipo) == 0) {
				printf("[Linea %d]: semantic error, El operador %s se debe "
					   "utilizar con dos listas.\n", linea_actual, (yyvsp[(2) - (3)]).lexema);
			}
			else {
				if (tipoEnLista((yyvsp[(1) - (3)]).tipo) != tipoEnLista((yyvsp[(3) - (3)]).tipo)) {
					printf ("[Linea %d]: semantic error, Ambas listas deben ser"
						    " del mismo tipo.\n", linea_actual, (yyvsp[(2) - (3)]).lexema);
				}
				else {
					(yyval).tipo = (yyvsp[(1) - (3)]).tipo;
					copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
									 (yyvsp[(3) - (3)]).lexema);
					
					generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (3)]).lexema,TipoEscrito((yyvsp[(1) - (3)]).tipo), TipoEscrito((yyvsp[(3) - (3)]).tipo),"ll");
					escribir_PYC();
			
					strcpy ((yyval).lexema, tmp);
					
					
				}
					
			}
		}
		else if ((yyvsp[(2) - (3)]).atrib == 0 || (yyvsp[(2) - (3)]).atrib == 2) {
			if (es_lista((yyvsp[(1) - (3)]).tipo) == 0 || (yyvsp[(3) - (3)]).tipo != entero) {
				printf("[Linea %d]: semantic error, El operador %s se debe "
					   "utilizar con una lista y un índice.\n",
					   linea_actual, (yyvsp[(2) - (3)]).lexema);
			}
			else {
				(yyval).tipo = (yyvsp[(1) - (3)]).tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
									 (yyvsp[(3) - (3)]).lexema);
									 
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (3)]).lexema,TipoEscrito((yyvsp[(1) - (3)]).tipo), TipoEscrito((yyvsp[(3) - (3)]).tipo),"li");
				escribir_PYC();
		
				strcpy ((yyval).lexema, tmp);
			}
			
		}
		else {
			if (es_lista((yyvsp[(1) - (3)]).tipo) == 0 || (yyvsp[(3) - (3)]).tipo != entero) {
				printf("[Linea %d]: semantic error, El operador %s se debe "
					   "utilizar con una lista y un entero.\n",
					   linea_actual, (yyvsp[(2) - (3)]).lexema);
			}
		}
	}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 895 "generador.y"
    {
	 	copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (3)]).lexema); 
		(yyvsp[(1) - (3)]).tipo = get_tipoValido((yyvsp[(1) - (3)]).lexema, (yyvsp[(1) - (3)]).tipo);
		(yyvsp[(3) - (3)]).tipo = get_tipoValido((yyvsp[(3) - (3)]).lexema, (yyvsp[(3) - (3)]).tipo);
		
		if (es_lista((yyvsp[(1) - (3)]).tipo) == 0 || (yyvsp[(3) - (3)]).tipo != entero) {
			printf("[Linea %d]: semantic error, El operador %s se debe utilizar"
				   " con una lista y un entero.\n", linea_actual, (yyvsp[(2) - (3)]).lexema);
		}
		else {
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
									 (yyvsp[(3) - (3)]).lexema);
		
			(yyval).tipo = tipoEnLista((yyvsp[(1) - (3)]).tipo);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,(yyvsp[(2) - (3)]).lexema,TipoEscrito((yyvsp[(1) - (3)]).tipo), TipoEscrito((yyvsp[(3) - (3)]).tipo),"li");
			escribir_PYC();
			
			strcpy ((yyval).lexema, tmp);
		}	 
	}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 916 "generador.y"
    {
		if (es_lista((yyvsp[(1) - (5)]).tipo) == 0 || (yyvsp[(3) - (5)]).tipo != entero || (yyvsp[(5) - (5)]).tipo != entero) {
			printf("[Linea %d]: semantic error, El operador %s se debe utilizar"
				   " con una lista y dos enteros.\n", linea_actual, (yyvsp[(2) - (5)]).lexema);
		}		
		else {
		 	copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, (yyvsp[(1) - (5)]).lexema); 
			(yyvsp[(1) - (5)]).tipo = get_tipoValido((yyvsp[(1) - (5)]).lexema, (yyvsp[(1) - (5)]).tipo);
			(yyvsp[(3) - (5)]).tipo = get_tipoValido((yyvsp[(3) - (5)]).lexema, (yyvsp[(3) - (5)]).tipo);

			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, (yyvsp[(3) - (5)]).lexema);
									 
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer3, (yyvsp[(5) - (5)]).lexema);
		
			(yyval).tipo = (yyvsp[(1) - (5)]).tipo;
			generaExpTernaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2, pilaExpr[topePilaExpr].buffer3, (yyvsp[(2) - (5)]).lexema,TipoEscrito((yyvsp[(1) - (5)]).tipo), TipoEscrito((yyvsp[(3) - (5)]).tipo));
			escribir_PYC();
			
			strcpy ((yyval).lexema, tmp);
		}
		 
	}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 939 "generador.y"
    {
		if (existe((yyvsp[(1) - (1)]).lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, (yyvsp[(1) - (1)]).lexema);}
		else if (existeFunc((yyvsp[(1) - (1)]).lexema) > -1) {
			printf("[Linea %d]: semantic error, no se le están pasando parámetros a la función '%s' \n",linea_actual,(yyvsp[(1) - (1)]).lexema);
		}		
		else {
			(yyval).tipo=get_tipo((yyvsp[(1) - (1)]).lexema);
			(yyval).lexema = (yyvsp[(1) - (1)]).lexema;
		}
	}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 952 "generador.y"
    {
		
		
		if (strcmp((yyvsp[(1) - (1)]).lexema,"TRUE") == 0) {
			strcpy((yyvsp[(1) - (1)]).lexema, "1");
		}
		else if (strcmp((yyvsp[(1) - (1)]).lexema,"FALSE") == 0) {
			strcpy((yyvsp[(1) - (1)]).lexema, "0");
		}
		(yyval).tipo=(yyvsp[(1) - (1)]).tipo;
		(yyval).lexema=(yyvsp[(1) - (1)]).lexema;
		
	}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 965 "generador.y"
    {(yyval).tipo=tipoLista((yyvsp[(1) - (1)]).tipo);}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 967 "generador.y"
    {
		(yyval).lexema = (yyvsp[(1) - (1)]).lexema;
		(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
	}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 974 "generador.y"
    {
		if (existe((yyvsp[(3) - (3)]).lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, (yyvsp[(3) - (3)]).lexema);
		}
		else {
			(yyvsp[(3) - (3)]).tipo=get_tipo((yyvsp[(3) - (3)]).lexema);
			escribe_leer((yyvsp[(3) - (3)]).tipo, (yyvsp[(3) - (3)]).lexema);
		}
	}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 985 "generador.y"
    {
 		(yyvsp[(1) - (1)]).tipo = get_tipo((yyvsp[(1) - (1)]).lexema);
    	(yyval).lexema=(yyvsp[(1) - (1)]).lexema;
    	(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
    	escribe_leer((yyvsp[(1) - (1)]).tipo, (yyvsp[(1) - (1)]).lexema);
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 996 "generador.y"
    {
		if (es_lista((yyvsp[(1) - (1)]).tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede imprimir una "
				   "lista\n", linea_actual);
		}
		else {
			if (existeFunc((yyvsp[(1) - (1)]).lexema) > -1) {
				(yyvsp[(1) - (1)]).lexema = pilaParams[topePilaParams+1].llamadaString;
			}
		}
		escribe_imprimir((yyvsp[(1) - (1)]).tipo, (yyvsp[(1) - (1)]).lexema); // ¿Las listas no se deben imprimir?
	}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1010 "generador.y"
    {
   		escribe_imprimir(-1, (yyvsp[(1) - (1)]).lexema);
   	}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1015 "generador.y"
    {
		(yyval).tipo=(yyvsp[(2) - (3)]).tipo;
		strcpy((yyval).lexema, tmp);
		if (es_lista((yyvsp[(2) - (3)]).tipo) == 1) {
			printf("[Linea %d]: semantic error, No se pueden usar listas de "
				   "listas.\n", linea_actual);
		}
	}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1025 "generador.y"
    {
		if ((yyval).tipo != (yyvsp[(3) - (3)]).tipo) {
			printf("[Linea %d]: semantic error, Las constantes introducidas "
					"son de diferentes tipos\n", linea_actual);
		(yyval).tipo=(yyvsp[(3) - (3)]).tipo;
		}
		else {
			if (strcmp((yyvsp[(3) - (3)]).lexema,"TRUE") == 0) {
				strcpy((yyvsp[(3) - (3)]).lexema, "1");
			}
			else if (strcmp((yyvsp[(3) - (3)]).lexema,"FALSE") == 0) {
				strcpy((yyvsp[(3) - (3)]).lexema, "0");
			}
			(yyval).tipo=(yyvsp[(3) - (3)]).tipo;
			(yyval).lexema=(yyvsp[(3) - (3)]).lexema;
		
			char aux[200];
			sprintf(aux, "%s = insertar_%s(&%s, %s, longitud_%s(&%s));\n", tmp, MostrarTipo((yyvsp[(3) - (3)]).tipo),tmp, (yyvsp[(3) - (3)]).lexema, MostrarTipo((yyvsp[(3) - (3)]).tipo), tmp);
			escribe_elemento(aux);
		}
	}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1047 "generador.y"
    {
   		if ((yyval).tipo != (yyvsp[(1) - (1)]).tipo) {
   			printf("[Linea %d]: semantic error, Las constantes introducidas "
   				   "son de diferentes tipo\n", linea_actual);
			(yyval).tipo=(yyvsp[(1) - (1)]).tipo; 
		}
		else {
			if (strcmp((yyvsp[(1) - (1)]).lexema,"TRUE") == 0) {
				strcpy((yyvsp[(1) - (1)]).lexema, "1");
			}
			else if (strcmp((yyvsp[(1) - (1)]).lexema,"FALSE") == 0) {
				strcpy((yyvsp[(1) - (1)]).lexema, "0");
			}
			(yyval).tipo=(yyvsp[(1) - (1)]).tipo;
			(yyval).lexema=(yyvsp[(1) - (1)]).lexema;
		
			genera_temporal();
			char aux[200];
			sprintf(aux, "lista_%s %s;\ninicializa_%s(&%s);\n"
					"%s = insertar_%s(&%s, %s, longitud_%s(&%s));\n", 
					MostrarTipo((yyvsp[(1) - (1)]).tipo), tmp, MostrarTipo((yyvsp[(1) - (1)]).tipo),
					tmp, tmp, MostrarTipo((yyvsp[(1) - (1)]).tipo),tmp, (yyvsp[(1) - (1)]).lexema,
					MostrarTipo((yyvsp[(1) - (1)]).tipo), tmp);
			escribe_elemento(aux);
		}
			
	}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1076 "generador.y"
    {
		(yyval).lexema = (yyvsp[(1) - (1)]).lexema;
		(yyval).tipo = (yyvsp[(1) - (1)]).tipo;
		topePilaParams++;
		pilaParams[topePilaParams].pos = existeFunc((yyvsp[(1) - (1)]).lexema);
		sprintf(pilaParams[topePilaParams].llamadaString, "%s(", (yyvsp[(1) - (1)]).lexema);
		
		if (pilaParams[topePilaParams].pos >= 0) {
			funcion_existe = 1;
		}
		else {
			funcion_existe = 0;
		}
	}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1091 "generador.y"
    {
		sprintf(buf, "%s)", pilaParams[topePilaParams].llamadaString);
		sprintf(pilaParams[topePilaParams].llamadaString, "%s", buf);
		
		if (pilaParams[topePilaParams].pos >= 0) {
			if (pilaParams[topePilaParams].contParam != 
				TS[pilaParams[topePilaParams].pos].n_parametros) {
				printf("[Linea %d]: semantic error, La funcion %s esperaba %d "
					   "argumentos y ha recibido %d.\n",
					   linea_actual,TS[pilaParams[topePilaParams].pos].nombre,
					   TS[pilaParams[topePilaParams].pos].n_parametros,
					   pilaParams[topePilaParams].contParam);
			}
			(yyval).tipo = TS[pilaParams[topePilaParams].pos].tipo_dato;
		}
		else {
			printf("[Linea %d]: semantic error, La funcion %s no ha sido "
				   "declarada.\n", linea_actual, (yyvsp[(1) - (5)]).lexema);
							
//			$$.tipo = desconocido;
		}
		topePilaParams--;
	}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1116 "generador.y"
    {
		pilaParams[topePilaParams].contParam = 0;
	}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1122 "generador.y"
    {
		pilaParams[topePilaParams].contParam = 0;
	}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1127 "generador.y"
    {	
		if (funcion_existe != 0) {
			if(existeFunc((yyvsp[(3) - (3)]).lexema) > -1)
				sprintf(buf, "%s, %s", pilaParams[topePilaParams].llamadaString, pilaParams[topePilaParams+1].llamadaString);
			else
				sprintf(buf, "%s, %s", pilaParams[topePilaParams].llamadaString, (yyvsp[(3) - (3)]).lexema);

			sprintf(pilaParams[topePilaParams].llamadaString, "%s", buf);
		
			int tipo_param = TS[pilaParams[topePilaParams].pos].parametros[
							 pilaParams[topePilaParams].contParam];
			if (tipo_param != (yyvsp[(3) - (3)]).tipo)
				printf("[Linea %d]: semantic error, Se esperaba parametro de "
					   "tipo %s en lugar de %s.\n", linea_actual, 
					   MostrarTipo(tipo_param), MostrarTipo((yyvsp[(3) - (3)]).tipo));
					   
			pilaParams[topePilaParams].contParam++;
		}
	}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1147 "generador.y"
    {
		if (funcion_existe != 0) {
			int tipo_param = TS[pilaParams[topePilaParams].pos].parametros[
							 pilaParams[topePilaParams].contParam];
			if (tipo_param != (yyvsp[(1) - (1)]).tipo)
				printf("[Linea %d]: semantic error, Se esperaba parametro de "
					   "tipo %s en lugar de %s.\n", linea_actual, 
					   MostrarTipo(tipo_param), MostrarTipo((yyvsp[(1) - (1)]).tipo));
			
			pilaParams[topePilaParams].contParam++; 
			if(existeFunc((yyvsp[(1) - (1)]).lexema) > -1)
				sprintf(buf, "%s%s", pilaParams[topePilaParams].llamadaString, pilaParams[topePilaParams+1].llamadaString);
			else
				sprintf(buf, "%s%s", pilaParams[topePilaParams].llamadaString, (yyvsp[(1) - (1)]).lexema);
			sprintf(pilaParams[topePilaParams].llamadaString, "%s", buf);
			
		}
	}
    break;



/* Line 1806 of yacc.c  */
#line 2958 "y.tab.c"
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 1166 "generador.y"


#include "lex.yy.c"

void yyerror(const char *msg) {
    fprintf(stderr,"[En linea %d]: %s\n",linea_actual, msg);
}

