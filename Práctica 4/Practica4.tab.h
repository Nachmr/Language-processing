
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


