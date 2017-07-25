/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


