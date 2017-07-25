%{

#include "Practica4.tab.h"

static int atrib;

%}

%option noyywrap

letra			[A-Za-z]
digito			[0-9]
entero			{digito}+
flotante		({digito}+)"."({digito}+)
alfanum			{letra}|{digito}|"_"|"-"
caracter		\'[^\']\'
cadenaASCII		\"[^\"]*\"
bool			"verdadero"|"falso"
nombrevar		{letra}({alfanum})*
otros			.

%%

[ \t] ;
\n {++linea_actual;}
";"						{yylval.lexema = strdup (yytext); return PYC ;}
"*"						{yylval.atrib = 0; yylval.lexema = strdup (yytext); return OPMULTIPLICATIVOS ;}
"/"						{yylval.atrib = 1; yylval.lexema = strdup (yytext); return OPMULTIPLICATIVOS ;}
"&&"					{yylval.lexema = strdup (yytext); return ANDLOGICO ;}
"||"					{yylval.lexema = strdup (yytext); return ORLOGICO ;}
"xor"					{yylval.lexema = strdup (yytext); return XORLOGICO ;}
"=="					{yylval.lexema = strdup (yytext); return OPIGUALDAD ;}
">"						{yylval.atrib = 0; yylval.lexema = strdup (yytext); return OPRELACION ;}
"<"						{yylval.atrib = 1; yylval.lexema = strdup (yytext); return OPRELACION ;}
">="					{yylval.atrib = 2; yylval.lexema = strdup (yytext); return OPRELACION ;}
"<="					{yylval.atrib = 3; yylval.lexema = strdup (yytext); return OPRELACION ;}
"!="					{yylval.lexema = strdup (yytext); return OPRELACION ;}
"+"						{yylval.lexema = strdup (yytext); return SUMRES ;}
"-"						{yylval.lexema = strdup (yytext); return SUMRES ;}
"++"					{yylval.atrib = 0; yylval.lexema = strdup (yytext); return INCREMENTO ;}
"--"					{yylval.atrib = 1; yylval.lexema = strdup (yytext); return DECREMENTO ;}
"!"						{yylval.lexema = strdup (yytext); return NEG ;}
")"						{yylval.lexema = strdup (yytext); return PARDCH ;}
"("						{yylval.lexema = strdup (yytext); return PARIZQ ;}
"]"						{yylval.lexema = strdup (yytext); return CORDCH ;}					
"["						{yylval.lexema = strdup (yytext); return CORIZQ ;}
"}"						{yylval.lexema = strdup (yytext); return LLAVEDCH ;}
"{"						{yylval.lexema = strdup (yytext); return LLAVEIZQ ;}
"="						{yylval.lexema = strdup (yytext); return ASIGN ;}
","						{yylval.lexema = strdup (yytext); return COMA ;}
"inicio_declaracion"    {yylval.lexema = strdup (yytext); return INICIODCL ;}
"fin_declaracion"		{yylval.lexema = strdup (yytext); return FINDCL ;}
"programa"				{yylval.lexema = strdup (yytext); return CABECERA ;}
{bool}					{yylval.tipo = booleano; yylval.atrib = booleano; yylval.lexema = strdup (yytext); return BOOL ;}
{entero}				{yylval.tipo = entero;   yylval.atrib = entero;   yylval.lexema = strdup (yytext); return NENTERO ;}
{flotante}				{yylval.tipo = real;     yylval.atrib = real;     yylval.lexema = strdup (yytext); return NDOBLE ;}
{cadenaASCII}			{yylval.tipo = array_caracter; yylval.atrib = array_caracter; yylval.lexema = strdup (yytext); return CADENAASCII ;}
{caracter}				{yylval.tipo = caracter; yylval.atrib = caracter; yylval.lexema = strdup (yytext); return CARACTER ;}
"ent"					{yylval.atrib = 0; yylval.tipo = entero; yylval.lexema = strdup (yytext); return TIPO ;}
"real"					{yylval.atrib = 1; yylval.tipo = real; yylval.lexema = strdup (yytext); return TIPO ;}
"car"					{yylval.atrib = 2; yylval.tipo = caracter; yylval.lexema = strdup (yytext); return TIPO ;}
"bool"					{yylval.atrib = 3; yylval.tipo = booleano; yylval.lexema = strdup (yytext); return TIPO ;}
"si"					{yylval.lexema = strdup (yytext); return SI ;}
"sino"					{yylval.lexema = strdup (yytext); return SINO ;}
"mientras"				{yylval.lexema = strdup (yytext); return MIENTRAS ;}
"hacer"					{yylval.lexema = strdup (yytext); return HACER ;}
"hasta"					{yylval.lexema = strdup (yytext); return HASTA ;}
"devolver"				{yylval.lexema = strdup (yytext); return DEVOLVER ;}
"entrada"				{yylval.lexema = strdup (yytext); return ENTRADA ;}
"salida"				{yylval.lexema = strdup (yytext); return SALIDA ;}
{nombrevar}				{yylval.lexema = strdup (yytext); return NOMBREVAR ;}
{otros}					{return;}

%%
