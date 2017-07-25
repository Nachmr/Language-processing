%{
#include<stdio.h>
%}

%option main

comillas	[\"]
blanco		[ ]

%option noyywrap

%%
{comillas}syntax{blanco}error{comillas}	{printf("msjerror[yystate]");}
.					{printf("%c",*yytext);}
\n					{printf("\n");}
%%
