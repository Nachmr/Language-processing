%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "msj.err"
    #define YYERROR_VERBOSE


	int yydebug = 1;    
    void yyerror(const char *msg);
    
    int linea_actual = 1;
    int yystate = 0;
%}

%error-verbose

%token MASMENOS
%token OPUNA
%token CONST
%token IDENT
%token CAD
%token PARI
%token PARD
%token COMA
%token PYC
%token PRINT
%token SCAN
%token IF
%token THEN
%token ELSE
%token WHILE
%token DO
%token FOR
%token TO
%token TIPOBASICO
%token LISTOF
%token BEG
%token END
%token VAR
%token ENDVAR
%token PROG
%token FUNCTION
%token RETURN
%token ASIG
%token CORD
%token CORI
%token DOSPU
%token OPTER1
%token OPTER2
%token DOLAR
%token RETAV
%token OPOR
%token OPAND
%token MULDIV
%token OPIGUALDAD
%token OPRELACION
%token OPLISTA


%right OPTER2
%left OPOR
%left OPAND
%left OPIGUALDAD
%left OPRELACION
%right OPLISTA
%left MASMENOS
%left MULDIV
%left OPTER1
%right OPUNA

%start Programa

%%

Programa : Cabecera_programa bloque ;

Cabecera_programa : PROG IDENT
				  | error ;

bloque : BEG 
         Declar_de_variables_locales
         Declar_de_subprogs 
         Sentencias
         END ;                   
                          
Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   | ;
                               
Declar_subprog : Cabecera_subprog bloque;

Cabecera_subprog : FUNCTION IDENT PARI Cuerpo_declar_variables PARD DOSPU tipo_dato PYC ;

Declar_de_variables_locales : VAR
                              Cuerpo_declar_variables
                              ENDVAR		   
                            | ;

Cuerpo_declar_variables : Cuerpo_declar_variables lista_identificadores DOSPU tipo_dato PYC
				     	| error
                        | ;
                               
lista_identificadores : lista_identificadores COMA IDENT
                      | IDENT ;                             
                             
tipo_dato : TIPOBASICO
          | tipo_dato_B ;
                               
tipo_dato_B : LISTOF TIPOBASICO ;
                  
Sentencias: Sentencias Sentencia
		  |  ;
                               
Sentencia: bloque
         | sentencia_if
         | sentencia_while
         | sentencia_for
         | sentencias_PYC PYC
         | error;
       
sentencia_if: alternativa_simple 
            | alternativa_doble ;
        
alternativa_simple: IF expresion THEN Sentencia ;

alternativa_doble: IF expresion THEN Sentencia ELSE Sentencia ;

sentencia_while: WHILE expresion DO Sentencia ;

sentencia_for: FOR sentencia_asignacion TO expresion DO Sentencia ;

sentencias_PYC: sentencia_return
			  | sentencia_avance_retroceso
			  | sentencia_asignacion
			  | sentencia_cursor_comienzo
			  | sentencia_entrada
			  | sentencia_salida ;

sentencia_return: RETURN expresion ;

sentencia_asignacion: IDENT ASIG expresion ;

sentencia_avance_retroceso : IDENT RETAV ;

sentencia_cursor_comienzo : DOLAR IDENT ;
                                      
sentencia_entrada: SCAN lista_variables ;

sentencia_salida: PRINT lista_expresiones_o_cadena ;
                               
expresion: PARI expresion PARD
		 | MASMENOS expresion %prec OPUNA
         | OPUNA expresion
         | expresion MASMENOS expresion
         | expresion MULDIV expresion
         | expresion OPOR expresion
         | expresion OPAND expresion
         | expresion OPIGUALDAD expresion
         | expresion OPRELACION expresion
         | expresion OPLISTA expresion
         | expresion OPTER2 expresion
         | expresion OPTER1 expresion OPTER2 expresion
         | IDENT
         | CONST
         | agregado
         | funcion
	     | error ;	  
                                              
lista_variables: lista_variables COMA IDENT
   			   | IDENT ;
          
lista_expresiones_o_cadena: lista_expresiones_o_cadena COMA exp_cad
						  | exp_cad ;

exp_cad: expresion
   	   | CAD ;
       
lista_expresiones: lista_expresiones COMA expresion
   				 | expresion ;
   				            

agregado : CORI lista_constantes CORD ;

lista_constantes: lista_constantes COMA CONST 
   				| CONST ;

funcion: IDENT PARI lista_expresiones PARD ;

%%

#include "lex.yy.c"

void yyerror(const char *msg) {
    fprintf(stderr,"[En linea %d]: %s\n",linea_actual, msg);
}
