%{
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
%}

%error-verbose

%token PYC
%token ORLOGICO
%token ANDLOGICO
%token XORLOGICO
%token OPIGUALDAD
%token OPRELACION
%token OPMULTIPLICATIVOS
%token NEG
%token INCREMENTO
%token DECREMENTO
%token SUMRES
%token PARDCH
%token PARIZQ
%token CORDCH
%token CORIZQ
%token LLAVEDCH
%token LLAVEIZQ
%token ASIGN
%token COMA
%token NENTERO
%token NDOBLE
%token BOOL
%token CARACTER
%token INICIODCL
%token FINDCL
%token CABECERA
%token TIPO
%token SI
%token SINO
%token MIENTRAS
%token HACER
%token HASTA
%token DEVOLVER
%token ENTRADA
%token SALIDA
%token NOMBREVAR
%token CADENAASCII


%left ORLOGICO
%left ANDLOGICO
%left XORLOGICO
%left OPIGUALDAD
%left OPRELACION
%left OPMULTIPLICATIVOS
%right SUMRES
%right NEG
%left INCREMENTO
%left DECREMENTO

%start Programa

%%

Programa: cabecera_programa bloque;

cabecera_programa: CABECERA
                 | error; 

bloque: LLAVEIZQ {TS_InsertaMarca();}
		Declar_de_variables_locales 
		Declar_de_subprogs 
		Sentencias 
		LLAVEDCH {TS_VaciarEntradas();};

Declar_de_subprogs: Declar_de_subprogs Declar_subprog
					|;

Declar_subprog: Cabecera_subprog bloque;

Declar_de_variables_locales: INICIODCL 
							 Variables_locales 
							 FINDCL
							|;

Variables_locales: Variables_locales Cuerpo_declar_variables 
                 | Cuerpo_declar_variables;
				 
Cuerpo_declar_variables: TIPO
						{tipo_leido = $1.atrib;
							//printf("\nTipo leido: %d\n", $1.atrib);
						}
						lista_variables PYC
                       | error;

lista_variables: lista_variables COMA identificador
		{
			if(!es_repetida($3.lexema)) {	
				insertarIDENT(variable, $3.lexema, tipo_leido, n_dimensiones);
			}else{
				//printf("[Linea %d]: semantic error, El identificador %s ya ha sido declarado.\n",linea_actual,$3.lexema);
			}
		}	

        | identificador
		{
			if(!es_repetida($1.lexema)) {	
				insertarIDENT(variable, $1.lexema, tipo_leido, n_dimensiones);
				//printf("\n Acabo de insertar %s\n", $1.lexema);
			}
		};
			   
Cabecera_subprog: TIPO NOMBREVAR PARIZQ
			{
				if(!es_repetida($2.lexema)) {
					insertarIDENT(funcion,$2.lexema,$1.tipo, n_parametros);
				}
			}
			argumentos
			PARDCH
			{
				asignarNumeroParametros($2.lexema, n_parametros);
				n_parametros = 0;
			}
			;

Sentencias: Sentencias sentencia
          |;
		  
sentencia: bloque
         | sentencia_asignacion
         | sentencia_si
         | sentencia_mientras
         | sentencia_hacer_hasta
         | sentencia_entrada
         | sentencia_salida
         | sentencia_devolver
		 | error;
		 
id: NOMBREVAR
  | id_array;
		 
sentencia_asignacion: id ASIGN expresion PYC
		{
			if(existe($1.lexema)==0){
				printf("[Linea %d]: semantic error, Identificador %s no declarado\n",linea_actual,$1.lexema);
			}
			else{
				$1.tipo=get_tipo($1.lexema);
				if($1.tipo!=$3.tipo){
					printf("[Linea %d]: semantic error, Asignacion de tipos incompatibles, no se puede asignar un %s a un %s\n",linea_actual, MostrarTipo($3.tipo),MostrarTipo($1.tipo));
				}
			}
		} ;


sentencia_si: SI PARIZQ expresion PARDCH sentencia
			{
				if($3.tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo($3.tipo));
				}
			}
            | SI PARIZQ expresion PARDCH sentencia SINO sentencia
			{
				if($3.tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo($3.tipo));
				}
			};
			
sentencia_mientras: MIENTRAS PARIZQ expresion PARDCH sentencia
			{
				if($3.tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo($3.tipo));
				}
			};

sentencia_hacer_hasta: HACER sentencia HASTA PARIZQ expresion PARDCH PYC
			{
				if($5.tipo!=booleano){
					printf("[Linea %d]: semantic error, Se esperaba una expresion de tipo booleana, no de tipo %s\n",linea_actual,MostrarTipo($5.tipo));
				}
			};

sentencia_entrada: ENTRADA lista_variables PYC;

lista_expresiones_o_cadena: lista_expresiones_o_cadena COMA exp_o_cadena
                          | exp_o_cadena;
						  
exp_o_cadena: expresion
            | cadena;
			
cadena: CADENAASCII;

sentencia_salida: SALIDA lista_expresiones_o_cadena PYC;

sentencia_devolver: DEVOLVER expresion PYC;

expresion: PARIZQ expresion PARDCH
			{$$.tipo = $2.tipo;}
         | expresion ORLOGICO expresion
			{
				if( ($1.tipo != booleano) || ($3.tipo != booleano) ){
					printf("[Linea %d]: semantic error, los operadores no son booleanos.\n",linea_actual);}
				else{
				$$.tipo = booleano;}
			}
		 | expresion ANDLOGICO expresion
			{
				if( ($1.tipo != booleano) || ($3.tipo != booleano) ){
					printf("[Linea %d]: semantic error, los operadores no son booleanos.\n",linea_actual);}
				else{
				$$.tipo = booleano;}
			}
		 | expresion XORLOGICO expresion
			{
				if( ($1.tipo != booleano) || ($3.tipo != booleano) ){
					printf("[Linea %d]: semantic error, los operadores no son booleanos.\n",linea_actual);}
				else{
				$$.tipo = booleano;}
			}
		 | expresion OPIGUALDAD expresion
			{
				if($1.tipo != $3.tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				$$.tipo = booleano;}
			}
		 | expresion OPRELACION expresion
			{
				if($1.tipo != $3.tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				$$.tipo = booleano;}
			}
		 | expresion OPMULTIPLICATIVOS expresion
			{
				if($1.tipo != $3.tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				$$.tipo = $1.tipo;}
			}
	     | expresion SUMRES expresion
			{
				if($1.tipo != $3.tipo){
					printf("[Linea %d]: semantic error, los operadores no son del mismo tipo.\n",linea_actual);}
				else{
				$$.tipo = $1.tipo;}
			}
         | SUMRES expresion
			{$$.tipo = $2.tipo;}
		 | NEG expresion
			{$$.tipo = $2.tipo;}
		 | INCREMENTO expresion
		 	{$$.tipo = $2.tipo;}
		 | DECREMENTO expresion
		 	{$$.tipo = $2.tipo;}
         | id
			{
			if(existe($1.lexema)==0){
				printf("[Linea %d]: semantic error, Identificador %s no declarado\n",linea_actual,$1.lexema);}
			else{
				$$.tipo=get_tipo($1.lexema);}
			}
         | constante_array
			{$$.tipo = $1.tipo;}
		 | llamada_funcion
			{$$.tipo = $1.tipo;}
		 | error;

lista_exp_vacia: 
	{
		pilaParams[topePilaParams].contParam = 0;
	}
				 lista_expresiones
	
			    | ;

		 
lista_expresiones: lista_expresiones COMA expresion 
	{
	if(funcion_existe != 0) {
		if(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam] != $3.tipo)
			printf("[Linea %d]: semantic error, Se esperaba parametro de tipo %s en lugar de %s.\n",
					linea_actual, MostrarTipo(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam]), MostrarTipo($3.tipo));
		pilaParams[topePilaParams].contParam++;
	}}
				| expresion
   	{
	if(funcion_existe != 0) {
		if(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam] != $1.tipo)
			printf("[Linea %d]: semantic error, Se esperaba parametro de tipo %s en lugar de %s.\n",
					linea_actual, MostrarTipo(TS[pilaParams[topePilaParams].pos].tipo_parametros[pilaParams[topePilaParams].contParam]), MostrarTipo($1.tipo));
		pilaParams[topePilaParams].contParam++;
	}};


llamada_funcion: NOMBREVAR 
	{
		topePilaParams++;
		pilaParams[topePilaParams].pos = existeFunc($1.lexema);
		
		if (pilaParams[topePilaParams].pos >= 0) {
			funcion_existe = 1;
		}
		else {
			funcion_existe = 0;
		}
	}
				PARIZQ lista_exp_vacia PARDCH
	{

		if(funcion_existe != 0) {
			if(pilaParams[topePilaParams].contParam != TS[pilaParams[topePilaParams].pos].parametros) {
				printf("[Linea %d]: semantic error, La funcion %s esperaba %d argumentos y ha recibido %d.\n",
							linea_actual,TS[pilaParams[topePilaParams].pos].nombre,TS[pilaParams[topePilaParams].pos].parametros, pilaParams[topePilaParams].contParam);
			}
			$$.tipo = TS[pilaParams[topePilaParams].pos].tipo_dato;
		}
		else {
			printf("[Linea %d]: semantic error, La funcion %s no ha sido declarada.\n",
							linea_actual, $1.lexema);
							
			$$.tipo = desconocido;
		}
		topePilaParams--;
		$$.tipo = get_tipo($1.lexema);
	};

identificador: NOMBREVAR
				{n_dimensiones = 0;}
             | NOMBREVAR CORIZQ NENTERO CORDCH
				{n_dimensiones = 1;}
             | NOMBREVAR CORIZQ NENTERO CORDCH CORIZQ NENTERO CORDCH
				{n_dimensiones = 2;};
  
id_array: NOMBREVAR CORIZQ expresion CORDCH {$$.tipo = $1.tipo;}
        | NOMBREVAR CORIZQ expresion CORDCH CORIZQ expresion CORDCH {$$.tipo = $1.tipo;};

constante: NENTERO
	     | NDOBLE
         | CARACTER
	     | BOOL;
		 
constante_array: constante
               | array_entero
			   | array_real
			   | array_bool
			   | array_caracter;
			   
array_entero: CORIZQ asignacion_array_entero CORDCH;

asignacion_array_entero: lista_num_entero PYC asignacion_array_entero
                       | lista_num_entero;
					   
lista_num_entero: NENTERO COMA lista_num_entero
                | NENTERO;
array_real: CORIZQ asignacion_array_real CORDCH;

asignacion_array_real: lista_num_real PYC asignacion_array_real
                     | lista_num_real;
					 
lista_num_real: NDOBLE COMA lista_num_real
              | NDOBLE;
			  
array_bool: CORIZQ asignacion_array_bool CORDCH;

asignacion_array_bool: lista_bool PYC asignacion_array_bool
					 | lista_bool;
					 
lista_bool: BOOL COMA lista_bool
          | BOOL;
		  
array_caracter: CORIZQ asignacion_array_caracter CORDCH;

asignacion_array_caracter: lista_caracter PYC asignacion_array_caracter
                         | lista_caracter;
						 
lista_caracter: CARACTER COMA lista_caracter
              | CARACTER;

argumentos: argumentos COMA arg
          | arg
          |;
		  
arg: TIPO identificador
	{
		if(!es_repetida($2.lexema)) {	
			insertarIDENT(parametro_formal, $2.lexema, $1.tipo, n_dimensiones);
		}else{
			printf("[Linea %d]: semantic error, El parametro formal %s ya ha sido declarado.\n",linea_actual,$2.lexema);
		}
		$$.tipo = $1.tipo;
		n_parametros = n_parametros + 1;
	};

%%

#include "lex.yy.c"

void yyerror(char *msg){
	fprintf(stderr, "[Linea %d]: %s\n", linea_actual, msg);
}