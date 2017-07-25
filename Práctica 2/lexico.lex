%{
    //#include "tabla.h"
    
    int linea_actual = 0;
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

"+" {atrib = 0 ; return MASMENOS;}
"-" {atrib = 1 ; return MASMENOS;}

"*"   {atrib = 0  ; return OPBIN;}
"/"   {atrib = 1  ; return OPBIN;}
"--"  {atrib = 2  ; return OPBIN;}
"**"  {atrib = 3  ; return OPBIN;}
"%"   {atrib = 4  ; return OPBIN;}
"="   {atrib = 6  ; return OPBIN;}
"AND" {atrib = 7  ; return OPBIN;}
"OR"  {atrib = 8  ; return OPBIN;}
"<>"  {atrib = 9  ; return OPBIN;}
">"   {atrib = 10 ; return OPBIN;}
"<"   {atrib = 11 ; return OPBIN;}
">="  {atrib = 12 ; return OPBIN;}
"<="  {atrib = 13 ; return OPBIN;}

"?"  {atrib = 0 ; return OPUNA;}
">>" {atrib = 1 ; return OPUNA;}
"<<" {atrib = 2 ; return OPUNA;}
"$"  {atrib = 3 ; return OPUNA;}
"#"  {atrib = 4 ; return OPUNA;}

\'"{alphanum}"\'       {atrib = 0 ; return CONST;}
{digito}+"."{digito}+  {atrib = 2 ; return CONST;}
{digito}+              {atrib = 1 ; return CONST;}
"TRUE"                 {atrib = 3 ; return CONST;}
"FALSE"                {atrib = 4 ; return CONST;}

\""(alphanum)*"\" {return CAD;}

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

{otros} {printf("\n[Linea %i] Error: token desconocido: \"%s\"\n", linea_actual+1, yytext);}


%%

int main (int argc, char *argv[]) {
    int val;
    
    if (argc != 2) {
        printf("\nNumero de argumentos incorrecto");
        exit(1);
    }
    else {
        yyin = fopen (argv[1], "rt");
        
        if (yyin == NULL) {
            printf("\nNo se ha podido abrir el fichero");
            exit(1);
        }
    }
    
    do {
    	atrib = -1;
        val = yylex();
        
        if (atrib == -1) {
        	printf("%s: %d\n", yytext, val);
        }
        else {
        	printf("%s: %d con atributo: %d\n", yytext, val, atrib);
        }
    }
    while (val != 0);
    
    exit (1);
}
