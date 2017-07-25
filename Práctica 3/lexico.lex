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

":=" {return ASIG;}
":"  {return DOSPU;}

"++"  {return OPTER1;}
"@"   {return OPTER2;}

"--"  {atrib = 0  ; return OPLISTA;}
"**"  {atrib = 1  ; return OPLISTA;}
"%"   {atrib = 2  ; return OPLISTA;}

">>" {atrib = 0 ; return RETAV;}
"<<" {atrib = 1 ; return RETAV;}

"OR"  {return OPOR;}
"AND" {return OPAND;}

"+" {atrib = 0 ; return MASMENOS;}
"-" {atrib = 1 ; return MASMENOS;}

"*"   {atrib = 0  ; return MULDIV;}
"/"   {atrib = 1  ; return MULDIV;}

"="   {atrib = 0  ; return OPIGUALDAD;}
"<>"  {atrib = 1  ; return OPIGUALDAD;}

">"   {atrib = 0  ; return OPRELACION;}
"<"   {atrib = 1  ; return OPRELACION;}
">="  {atrib = 2  ; return OPRELACION;}
"<="  {atrib = 3  ; return OPRELACION;}

"?"  {atrib = 0 ; return OPUNA;}
"#"  {atrib = 1 ; return OPUNA;}

"$"	 {return DOLAR;}

\'[^\"]\'       	   {atrib = 0 ; return CONST;}
{digito}+"."{digito}+  {atrib = 2 ; return CONST;}
{digito}+              {atrib = 1 ; return CONST;}
"TRUE"                 {atrib = 3 ; return CONST;}
"FALSE"                {atrib = 4 ; return CONST;}

\"[^\"]*\" {return CAD;}

"(" {return PARI;}
")" {return PARD;}
"[" {return CORI;}
"]" {return CORD;}
"," {return COMA;}
";" {return PYC;}
"PRINT" {return PRINT;}
"SCAN" {return SCAN;}
"IF" {return IF;}
"THEN" {return THEN;}
"ELSE" {return ELSE;}
"WHILE" {return WHILE;}
"DO" {return DO;}
"FOR" {return FOR;}
"TO" {return TO;}

"INTEGER" {atrib = 0 ; return TIPOBASICO;}
"REAL"    {atrib = 1 ; return TIPOBASICO;}
"CHAR"    {atrib = 2 ; return TIPOBASICO;}
"BOOLEAN" {atrib = 3 ; return TIPOBASICO;}

"LIST OF" {return LISTOF;}
"BEGIN" {return BEG;}
"END" {return END;}
"VAR" {return VAR;}
"ENDVAR" {return ENDVAR;}
"PROGRAM" {return PROG;}
"FUNCTION" {return FUNCTION;}
"RETURN" {return RETURN;}

{letra}{alphanum}* {return IDENT;}

{otros} {printf("\n[Linea %i] Error léxico: token desconocido: \"%s\"\n", linea_actual+1, yytext);}


%%


