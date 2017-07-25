%{
    //#include "tabla.h"
    
    //int linea_actual = 1;
    static int atrib;
%}

letra         [a-zA-Z]
digito        [0-9]
alphanum      [a-zA-Z_0-9]
otros         .

%option noyywrap

%%

[ \t] ;
\n {++linea_actual;}

":=" { yylval.lexema = strdup (yytext) ; return ASIG;}
":"  { yylval.lexema = strdup (yytext) ; return DOSPU;}

"++"  { yylval.lexema = strdup (yytext) ; return OPTER1;}
"@"   { yylval.lexema = strdup (yytext) ; return OPTER2;}

"--"  { yylval.atrib = 0  ; yylval.lexema = strdup(yytext); return OPLISTA;}
"**"  { yylval.atrib = 1  ; yylval.lexema = strdup(yytext); return OPLISTA;}
"%"   { yylval.atrib = 2  ; yylval.lexema = strdup(yytext); return OPLISTA;}

">>" { yylval.atrib = 0 ; yylval.lexema = strdup(yytext); return RETAV;}
"<<" { yylval.atrib = 1 ; yylval.lexema = strdup(yytext); return RETAV;}

"OR"  { yylval.lexema = strdup (yytext) ; return OPOR;}
"AND" { yylval.lexema = strdup (yytext) ; return OPAND;}

"+" { yylval.atrib = 0 ; yylval.lexema = strdup(yytext); return MASMENOS;}
"-" { yylval.atrib = 1 ; yylval.lexema = strdup(yytext); return MASMENOS;}

"*"   { yylval.atrib = 0  ; yylval.lexema = strdup(yytext); return MULDIV;}
"/"   { yylval.atrib = 1  ; yylval.lexema = strdup(yytext); return MULDIV;}

"="   { yylval.atrib = 0  ; yylval.lexema = strdup(yytext); return OPIGUALDAD;}
"<>"  { yylval.atrib = 1  ; yylval.lexema = strdup(yytext); return OPIGUALDAD;}

">"   { yylval.atrib = 0  ; yylval.lexema = strdup(yytext); return OPRELACION;}
"<"   { yylval.atrib = 1  ; yylval.lexema = strdup(yytext); return OPRELACION;}
">="  { yylval.atrib = 2  ; yylval.lexema = strdup(yytext); return OPRELACION;}
"<="  { yylval.atrib = 3  ; yylval.lexema = strdup(yytext); return OPRELACION;}

"?"  { yylval.atrib = 0 ; yylval.lexema = strdup(yytext); return OPUNA;}
"#"  { yylval.atrib = 1 ; yylval.lexema = strdup(yytext); return OPUNA;}

"$"	 { yylval.lexema = strdup(yytext); return DOLAR;}

\'[^\"]\'       	   { yylval.tipo = caracter; yylval.tipo = caracter; yylval.lexema = strdup(yytext); return CONST;}
{digito}+              { yylval.tipo = entero; yylval.atrib = entero; yylval.lexema = strdup(yytext); return CONST;}
{digito}+"."{digito}+  { yylval.tipo = real; yylval.atrib = real; yylval.lexema = strdup(yytext); return CONST;}
"TRUE"                 { yylval.tipo = booleano; yylval.atrib = booleano; yylval.lexema = strdup(yytext); return CONST;}
"FALSE"                { yylval.tipo = booleano; yylval.atrib = booleano; yylval.lexema = strdup(yytext); return CONST;}

\"[^\"]*\" { yylval.lexema = strdup(yytext) ; return CAD;}

"(" { yylval.lexema = strdup (yytext) ; return PARI;}
")" { yylval.lexema = strdup (yytext) ; return PARD;}
"[" { yylval.lexema = strdup (yytext) ; return CORI;}
"]" { yylval.lexema = strdup (yytext) ; return CORD;}
"," { yylval.lexema = strdup (yytext) ; return COMA;}
";" { yylval.lexema = strdup (yytext) ; return PYC;}
"PRINT" { yylval.lexema = strdup (yytext) ; return PRINT;}
"SCAN" { yylval.lexema = strdup (yytext) ; return SCAN;}
"IF" { yylval.lexema = strdup (yytext) ; return IF;}
"THEN" { yylval.lexema = strdup (yytext) ; return THEN;}
"ELSE" { yylval.lexema = strdup (yytext) ; return ELSE;}
"WHILE" { yylval.lexema = strdup (yytext) ; return WHILE;}
"DO" { yylval.lexema = strdup (yytext) ; return DO;}
"FOR" { yylval.lexema = strdup (yytext) ; return FOR;}
"TO" { yylval.lexema = strdup (yytext) ; return TO;}

"INTEGER" { yylval.atrib = entero ; yylval.tipo = entero; yylval.lexema = strdup(yytext); return TIPOBASICO;}
"REAL"    { yylval.atrib = real ; yylval.tipo = real; yylval.lexema = strdup(yytext); return TIPOBASICO;}
"CHAR"    { yylval.atrib = caracter ; yylval.tipo = caracter; yylval.lexema = strdup(yytext); return TIPOBASICO;}
"BOOLEAN" { yylval.atrib = booleano ; yylval.tipo = booleano; yylval.lexema = strdup(yytext); return TIPOBASICO;}

"LIST OF" { yylval.lexema = strdup (yytext) ; return LISTOF;}
"BEGIN" { yylval.lexema = strdup (yytext) ; return BEG;}
"END" { yylval.lexema = strdup (yytext) ; return END;}
"VAR" { yylval.lexema = strdup (yytext) ; return VAR;}
"ENDVAR" { yylval.lexema = strdup (yytext) ; return ENDVAR;}
"PROGRAM" { yylval.lexema = strdup (yytext) ; return PROG;}
"FUNCTION" { yylval.lexema = strdup (yytext) ; return FUNCTION;}
"RETURN" { yylval.lexema = strdup (yytext) ; return RETURN;}

{letra}{alphanum}* { yylval.lexema = strdup(yytext); return IDENT;}

{otros} {printf("\n[Linea %i] Error léxico: token desconocido: \"%s\"\n", linea_actual+1, yytext);}


%%


