%{
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

Programa : Cabecera_programa
	{
		// Abrir ficheros
		abrir_ficheros();
		// Escribir la cabecera del fichero (#include dec_dat, dec_fun, stdio)
		escribir_cabecera();
		// Escribir la cabecera del main
//		escribir_main();
	} 
		   bloque 
	{
		// Cerrar ficheros
		cerrar_ficheros();
	} ;

Cabecera_programa : PROG IDENT
				  | error ;

bloque : BEG 
	{ 
		TS_InsertaMarca();
		
		if (declarando_main == 0) { 
			// Abrir llave
			abrir_llave();
		}
	}
         Declar_de_variables_locales
    {
    	if (declarando_main) {
    		escribir_main();
    		abrir_llave();
    		
    		declarando_main = 0;
    	}
    }
         Declar_de_subprogs 
         Sentencias
         END 
	{ 
		$$.tipo = $6.tipo; // PUEDE QUE HAYA QUE PONER 6
		$$.lexema = $6.lexema; // Pude que haya que poner strdup (y 6)
		TS_VaciarEntradas(); 
		// Cerrar llave
		cerrar_llave();
	} ;                   
                          
Declar_de_subprogs : Declar_de_subprogs Declar_subprog { escribir_NL(); }
                   | ;
                               
Declar_subprog : Cabecera_subprog bloque
	{
//		printf("Funcion: %s, Tipo: %d\n", $1.lexema, $1.tipo);
//		if ($1.tipo != $2.tipo) {
//			printf("[Linea %d]: semantic error, Se esperaba una valor de "
//				   "retorno de tipo %s, no de tipo %s\n",
//				   linea_actual, MostrarTipo($1.tipo), MostrarTipo($2.tipo));
//		}
		if (en_fun > 0) en_fun = en_fun-1;
		TS_VaciarEntradas();
	};

Cabecera_subprog : FUNCTION IDENT PARI 
	{
		en_fun++;
		if (es_repetida($2.lexema) == 0) {insertarIDENT(funcion,$2.lexema); TS_InsertaMarca();}
		// Ellos en el if meten una marca. Nosotros borramos esa parte
		declarando_parametros = 1;
	}  
				   Cuerpo_declar_variables	 
	{
		CuentaParametros();
		declarando_parametros = 0;
	} 
				   PARD DOSPU tipo_dato
	{

		escribir_cabecera_funcion($9.tipo, $2.lexema);
		llaveCerrada[en_fun] = 1;
		asignarTipoFuncion($9.tipo);
		$$.tipo = $9.tipo;
	}
				   PYC ;

Declar_de_variables_locales : VAR
                              Cuerpo_declar_variables
                              ENDVAR		   
                            | ;

Cuerpo_declar_variables : Cuerpo_declar_variables 
						  lista_identificadores 
						  DOSPU 
						  tipo_dato 
						  PYC 
	{
		escribir_variables(TipoEscrito($4.tipo));
		
		if (declarando_main) {
//			fprintf(ficheroFunc,"extern \"C\"{\n");
			escribir_variables_extern(TipoEscrito($4.tipo));
//			fprintf(ficheroFunc,"}");
		}
		
		if(($3.tipo==4)||($3.tipo==5)||($3.tipo==6)||($3.tipo==7)){
			inicializaListasCascada($3.tipo);
		}
		asignarTipoCascada($4.tipo);
	}
						  | error
	{
		asignarTipoCascada(desconocido);
	}
						  | ;
                               
lista_identificadores : lista_identificadores COMA IDENT 
	{
		if (declarando_parametros == 0 && es_repetida($3.lexema) == 0) {	
			insertarIDENT(variable, $3.lexema);
		}
		else if (declarando_parametros == 1 &&
				 BuscarParametroRepetido($3.lexema) == 0) {
			insertarIDENT(parametro_formal, $3.lexema);
		}
	}
		          	  | IDENT 
	{
		if (declarando_parametros == 0 && es_repetida($1.lexema) == 0) {	
			insertarIDENT(variable, $1.lexema);
		}
		else if (declarando_parametros == 1 &&
				 BuscarParametroRepetido($1.lexema) == 0) {
			insertarIDENT(parametro_formal, $1.lexema);
		}
	};                          
                             
tipo_dato : TIPOBASICO
          | tipo_dato_B ;
                               
tipo_dato_B : LISTOF TIPOBASICO 
	{
		if ($2.tipo == entero) { $$.tipo = lista_entero; }
		if ($2.tipo == real) { $$.tipo = lista_real; }
		if ($2.tipo == booleano) { $$.tipo = lista_booleano; }
		if ($2.tipo == caracter) { $$.tipo = lista_caracter; }
	} ;
                  
Sentencias: Sentencias Sentencia
	{
		$$.lexema = $2.lexema;
		$$.tipo = $2.tipo;
	}
		  |  ;
                               
Sentencia: bloque
         | sentencia_if
         | sentencia_while
         | sentencia_for
         | sentencias_PYC PYC
	{
//		escribir_PYC();
	}
         | error;
       
sentencia_if: alternativa_simple ;
        
alternativa_simple: IF expresion  
	{
		if ($2.tipo!=booleano) {
			printf("[Linea %d]: semantic error, Se esperaba una expresion de "
				   "tipo boolean, no de tipo %s\n",
				   linea_actual, MostrarTipo($2.tipo));
		}
		escribe_if($2.lexema);
	} 
				   THEN Sentencia 
	{
//		escribe_elemento(";");
	}
	  			   alternativa_doble 
	{
		delete_descriptor();
		$$.tipo = desconocido;
	} ;
			
alternativa_doble: ELSE 
	{
		escribe_else(); 
	}
 				Sentencia
 	{
//		escribe_elemento(";");
		sprintf(temp,"%s:;\n",tablaControl[ind].EtiquetaSalida);
		escribe_elemento(temp);
	} 
				   | 
	{
		sprintf(temp,"%s:;\n",tablaControl[ind].EtiquetaElse);
		escribe_elemento(temp);
	} ;


sentencia_while: WHILE
	{
		genera_etiqueta(dW.EtiquetaEntrada);
		genera_etiqueta(dW.EtiquetaSalida);
		add_descriptor(dW);
		escribe_elemento(dW.EtiquetaEntrada); 
		escribe_elemento(":;");
	} 
				 expresion 
	{
		if ($3.tipo!=booleano) {
			printf("[Linea %d]: semantic error, Se esperaba una expresion de "
				   "tipo boolean, no de tipo %s\n",
				   linea_actual, MostrarTipo($3.tipo));
		}
		escribe_while($3.lexema);
	}
				DO Sentencia
	{
		escribir_PYC;
		fin_while();
		$$.tipo = desconocido;
	} ;

sentencia_for: FOR 
	{
		asignacion_for = 1;
	}
			   sentencia_asignacion
	{
		asignacion_for = 0;
		genera_etiqueta(dW.EtiquetaEntrada);
		genera_etiqueta(dW.EtiquetaSalida);
		add_descriptor(dW);
		escribe_elemento(dW.EtiquetaEntrada); 
		escribe_elemento(":;");
	}
			   TO expresion 	
	{

		if ($6.tipo!=entero) {
			printf("[Linea %d]: semantic error, Se esperaba una expresión de "
				   "tipo entero, no de tipo %s\n",
				   linea_actual, MostrarTipo($6.tipo));
		}
		
		escribe_for($3.lexema, $6.lexema);
	}		
				DO Sentencia
	{
		escribir_PYC;
		fin_for($3.lexema);
		$$.tipo = desconocido;
	}
				  ;


sentencias_PYC: sentencia_return
			  | sentencia_avance_retroceso
			  | sentencia_asignacion
			  | sentencia_cursor_comienzo
			  | sentencia_entrada
			  | sentencia_salida ;

sentencia_return: RETURN expresion 
	{
		sprintf (temp, "return %s;\n", $2.lexema);
		escribe_elemento(temp);
	} ;

sentencia_asignacion: IDENT ASIG expresion
	{
		if (existe($1.lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, $1.lexema);
		}
		else {
			$1.tipo=get_tipo($1.lexema);
			if ($1.tipo!=$3.tipo) {
				printf("[Linea %d]: semantic error, Asignacion de tipos "
					   "incompatibles, no se puede asignar un %s a un %s\n",
					   linea_actual, MostrarTipo($3.tipo),
					   MostrarTipo($1.tipo));
			}
			else if (asignacion_for == 1 && $1.tipo != entero) {
				printf("[Linea %d]: semantic error, En sentencia for se debe "
					   "usar un índice entero, no un %s\n",
					   linea_actual, MostrarTipo($1.tipo));
					   
				
			}
			
			if(existeFunc($3.lexema) > -1)
				sprintf(buf, "%s", pilaParams[topePilaParams+1].llamadaString);
			else
				sprintf(buf, "%s", $3.lexema);
			
			escribe_asignacion($1.lexema, buf);
			escribir_PYC();
			escribir_NL();
			$$.tipo = $1.tipo;
			$$.lexema = $1.lexema;
		}
	} ;

sentencia_avance_retroceso : IDENT RETAV 
	{
		$1.tipo=get_tipo($1.lexema);
		if (es_lista($1.tipo) == 0) {
			printf("[Linea %d]: semantic error, Solo se puede operar con "
				   "cursores sobre listas\n", linea_actual);
		}
		else {	
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema); 
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $2.lexema); 
		
			escribe_operacion_cursor(pilaExpr[topePilaExpr].buffer1, 
									 pilaExpr[topePilaExpr].buffer2, TipoEscrito($1.tipo));
									 
			escribir_PYC();
			escribir_NL();
		 }
		
	};

sentencia_cursor_comienzo : DOLAR IDENT 
	{
		$2.tipo=get_tipo($2.lexema);
		if (es_lista($2.tipo) == 0) {
			printf("[Linea %d]: semantic error, Solo se puede operar con "
				   "cursores sobre listas.\n", linea_actual);
		}	
		else {
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema); 
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $2.lexema); 
		
		
			printf ("%s\n", $1.lexema);
			escribe_operacion_cursor(pilaExpr[topePilaExpr].buffer2, 
									 pilaExpr[topePilaExpr].buffer1, TipoEscrito($2.tipo));
									 
			escribir_PYC();
			escribir_NL();
		
		}
	};
                                      
sentencia_entrada: SCAN lista_variables 
	{
		if (existe($2.lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, $2.lexema);
		}
		else {
			$2.tipo=get_tipo($2.lexema);
		}
		if (es_lista($2.tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede leer en una "
				   "lista.\n", linea_actual);
		}
		$$.tipo = desconocido;
	};

sentencia_salida: PRINT lista_expresiones_o_cadena
	{
		$$.tipo = desconocido;
	};
                               
expresion: PARI expresion PARD 
	{
		$$.tipo=$2.tipo;
		$$.lexema = $2.lexema;
	}
		 | MASMENOS expresion %prec OPUNA 
 	{
 		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $2.lexema);
		sprintf(pilaExpr[topePilaExpr].buffer1, 
				"%s%s;\n", $1.lexema, pilaExpr[topePilaExpr].buffer2);
 	
		$2.tipo = get_tipoValido($2.lexema, $2.tipo);
		if (es_lista($2.tipo) && $2.tipo != lista_entero && 
			$2.tipo != lista_real) {
			printf("[Linea %d]: semantic error, El operador %s es incompatible "
				   "con tipo %s, se esperaba lista de enteros o reales.\n",
				   linea_actual, $1.lexema, MostrarTipo($2.tipo));
		}
		else if (($2.tipo!=entero) && ($2.tipo!=real)) {
			printf("[Linea %d]: semantic error, El operador %s es incompatible "
				   "con tipo %s, se esperaba entero o real.\n",
				   linea_actual, $1.lexema, MostrarTipo($2.tipo));
		}
		else {$$.tipo=$2.tipo;}
		strcpy($$.lexema, pilaExpr[topePilaExpr].buffer1);
		topePilaExpr--;
	}
         		| OPUNA expresion   
	{
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $2.lexema);
	
		$2.tipo = get_tipoValido($2.lexema, $2.tipo);
		if (es_lista($2.tipo) == 0) {
			printf("[Linea %d]: semantic error, El operador %s debe aplicarse "
				   "sobre listas.\n",
				   linea_actual, $1.lexema, MostrarTipo($2.tipo));
		}
		else {
			if ($1.atrib == 0) { 
				$$.tipo = tipoEnLista($2.tipo); 
				generaExpUnaria(pilaExpr[topePilaExpr].buffer2,"?",TipoEscrito($2.tipo));
				strcpy($$.lexema, tmp);
				
			}
			else if ($1.atrib == 1) { 
				$$.tipo = entero; 
				generaExpUnaria(pilaExpr[topePilaExpr].buffer2,"#",TipoEscrito($2.tipo));
				strcpy($$.lexema, tmp);
			}
		}
	}
				 | expresion MASMENOS
	{
		topePilaExpr++; 
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema);
	}
				 
				  expresion
 	{
		$1.tipo = get_tipoValido($1.lexema, $1.tipo);
		$4.tipo = get_tipoValido($4.lexema, $4.tipo);
		
		//Valor y valor
		if (es_lista($1.tipo) == 0 && es_lista($4.tipo) == 0) {
			if ($1.tipo != $4.tipo) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual ,MostrarTipo($1.tipo),
					   MostrarTipo($4.tipo));
			}
			else {
				$$.tipo=$1.tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
										 $4.lexema);
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
								 pilaExpr[topePilaExpr].buffer2, $2.lexema,
								 TipoEscrito($1.tipo), TipoEscrito($4.tipo),0);
				escribe_elemento(";\n");
				strcpy($$.lexema, tmp);
				expresion_correcta =1;
			}
		}
		
		//Valor y lista (solo el *)
		if (es_lista($1.tipo) == 0 && es_lista($4.tipo) == 1) {
			if ($1.tipo!=tipoEnLista($4.tipo)) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo($1.tipo),
					   MostrarTipo($4.tipo));
			}
			$$.tipo=$3.tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $4.lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
							 pilaExpr[topePilaExpr].buffer2, $2.lexema,
							 TipoEscrito($1.tipo), TipoEscrito($4.tipo), "il");
			escribe_elemento(";\n");
			strcpy($$.lexema, tmp);
		}
		
		//Dos listas
		if (es_lista($1.tipo) == 1 && es_lista($4.tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede hacer suma de "
				   "listas.\n", linea_actual);
				   
			$$.tipo=$1.tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $4.lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
							 pilaExpr[topePilaExpr].buffer2, $2.lexema,
							 TipoEscrito($1.tipo), TipoEscrito($4.tipo), "ll");
			escribe_elemento(";\n");
			strcpy($$.lexema, tmp);
			expresion_correcta =1;
		}
		
		//Lista y valor
		if (es_lista($1.tipo) == 1 && es_lista($4.tipo) == 0) {
			if (tipoEnLista($1.tipo) !=$4.tipo) {
				printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo($1.tipo),
					   MostrarTipo($4.tipo));
			}
			
			$$.tipo=$1.tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $4.lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
							 pilaExpr[topePilaExpr].buffer2, $2.lexema,
							 TipoEscrito($1.tipo), TipoEscrito($4.tipo), "li");							
			escribe_elemento(";\n");
			strcpy($$.lexema, tmp);
		}
		
		topePilaExpr--;
	}
				 | expresion MULDIV
	 { 
	 	topePilaExpr++; 
	 	copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema); 
	 }
				  expresion
	{
		$1.tipo = get_tipoValido($1.lexema, $1.tipo);
		$4.tipo = get_tipoValido($4.lexema, $4.tipo);
		
		//Valor y valor
		if (es_lista($1.tipo) == 0 && es_lista($4.tipo) == 0) {
			if ($1.tipo != $4.tipo) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo($1.tipo),
					   MostrarTipo($4.tipo));
			}
			
			else{
				$$.tipo=$1.tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
										 $4.lexema);
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1,
								 pilaExpr[topePilaExpr].buffer2, $2.lexema,
								 TipoEscrito($1.tipo), TipoEscrito($4.tipo), 0);
				escribe_elemento(";\n");
				strcpy($$.lexema, tmp);
				expresion_correcta =1;
			}
		}
		
		//Valor y lista
		if (es_lista($1.tipo) == 0 && es_lista($4.tipo) == 1) {
			if ($1.tipo!=tipoEnLista($4.tipo)) {
				printf("[Linea %d]: semantic error,Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo($1.tipo),
					   MostrarTipo($4.tipo));
			}
			
			else{
				if($1.tipo!=entero && $1.tipo!=real){
					printf("[Linea %d]: semantic error, No se puede aplicar el "
						   "operador %s a %s%s%s.\n", linea_actual, $2.lexema,
						   MostrarTipo($1.tipo), $2.lexema,
						   MostrarTipo($4.tipo));
				}
				$$.tipo=$3.tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2,
										 $4.lexema);
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1, 
								 pilaExpr[topePilaExpr].buffer2, $2.lexema,
								 TipoEscrito($1.tipo),
								 TipoEscrito($4.tipo), "il");
				escribe_elemento(";\n");
				strcpy($$.lexema, tmp);
			}
		}
		
		//Dos listas
		if (es_lista($1.tipo) == 1 && es_lista($4.tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede hacer suma de "
				   "listas.\n", linea_actual);

			$$.tipo=$1.tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $4.lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,TipoEscrito($1.tipo), TipoEscrito($4.tipo),"ll");
			escribe_elemento(";\n");
			strcpy($$.lexema, tmp);
		}
		
		//Lista y valor
		if (es_lista($1.tipo) == 1 && es_lista($4.tipo) == 0) {
			if (tipoEnLista($1.tipo) !=$4.tipo) {
				printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
					   "incompatible con %s.\n",
					   linea_actual, MostrarTipo($1.tipo),
					   MostrarTipo($4.tipo));
			}
			
			$$.tipo=$1.tipo;
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $4.lexema);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,TipoEscrito($1.tipo), TipoEscrito($4.tipo),"li");							
			escribe_elemento(";\n");
			strcpy($$.lexema, tmp);
		}
		
		topePilaExpr--;
	}
				 | expresion OPOR expresion
	{
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $3.lexema);
		
		expresion_correcta = 1;
		if (es_lista(get_tipoValido($1.lexema, $1.tipo)) == 1 || 
			es_lista(get_tipoValido($3.lexema, $3.tipo)) == 1) {
			printf("[Linea %d]: semantic error, No se pueden hacer operaciones "
				   "logicas entre listas.\n", linea_actual,
				   MostrarTipo(get_tipoValido($1.lexema, $1.tipo)),
				   MostrarTipo(get_tipoValido($3.lexema, $3.tipo)));
				   
			expresion_correcta = 0;
		}
				   
		else if (($1.tipo) != ($3.tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n", linea_actual,
				   MostrarTipo(get_tipoValido($1.lexema, $1.tipo)),
				   MostrarTipo(get_tipoValido($3.lexema, $3.tipo)));
				   
			expresion_correcta = 0;
		}
		else {
			if ($3.tipo!=booleano) {
				printf("[Linea %d]: semantic error, Solo se admiten operaciones"
					   " logicas sobre tipo boolean, no de tipo %s\n",
					   linea_actual,MostrarTipo($3.tipo)); 
			expresion_correcta = 0;
		
			}
		}
		
		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,"int", TipoEscrito($3.tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,$$.lexema,11);
		}
		
		expresion_correcta = 1;
		$$.tipo=booleano;
		topePilaExpr--;
	}
				 | expresion OPAND expresion
	{
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $3.lexema);
	
		if (es_lista(get_tipoValido($1.lexema, $1.tipo)) == 1 || 
			es_lista(get_tipoValido($3.lexema, $3.tipo)) == 1) {
			printf("[Linea %d]: semantic error, No se pueden hacer operaciones "
				   "logicas entre listas.\n", linea_actual,
				   MostrarTipo(get_tipoValido($1.lexema, $1.tipo)),
				   MostrarTipo(get_tipoValido($3.lexema, $3.tipo)));
			
			expresion_correcta = 0;		   
		}
		else if (($1.tipo) != ($3.tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n", linea_actual,
				   MostrarTipo(get_tipoValido($1.lexema, $1.tipo)),
				   MostrarTipo(get_tipoValido($3.lexema, $3.tipo)));
			expresion_correcta = 0;	
		}
		else {
			if ($3.tipo!=booleano) {
				printf("[Linea %d]: semantic error, Solo se admiten operaciones"
					   " logicas sobre tipo boolean, no de tipo %s\n",
					   linea_actual, MostrarTipo($3.tipo)); 
				expresion_correcta = 0;	
			}
		}

		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,"int", TipoEscrito($3.tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,$$.lexema,11);
		}
		
		expresion_correcta = 1;
		$$.tipo=booleano;
		topePilaExpr--;
	}
				 | expresion OPIGUALDAD expresion
	{
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $3.lexema);
		
		if (es_lista(get_tipoValido($1.lexema, $1.tipo)) == 1 ||
			es_lista(get_tipoValido($3.lexema, $3.tipo)) == 1) {
			printf("[Linea %d]: semantic error, No se pueden hacer operaciones"
				   " logicas entre listas.\n", linea_actual,
				   MostrarTipo(get_tipoValido($1.lexema, $1.tipo)),
				   MostrarTipo(get_tipoValido($3.lexema, $3.tipo)));
			
			expresion_correcta = 0;
		}
		else if (($1.tipo) != ($3.tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n", linea_actual,
				   MostrarTipo(get_tipoValido($1.lexema, $1.tipo)),
				   MostrarTipo(get_tipoValido($3.lexema, $3.tipo)));
			
			expresion_correcta = 0;
		}
		
		
		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,"int", TipoEscrito($3.tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,$$.lexema,11);
		}
		
		expresion_correcta = 1;
		$$.tipo=booleano;
		topePilaExpr--;
	}
				 | expresion OPRELACION expresion
	{
		topePilaExpr++;
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema);
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $3.lexema);
	
		$1.tipo = get_tipoValido($1.lexema, $1.tipo);
		$3.tipo = get_tipoValido($3.lexema, $3.tipo);
		if ((($1.tipo!=entero) && ($1.tipo!=real)) || 
			(($3.tipo!=entero) && ($3.tipo!=real))) {
			printf("[Linea %d]: semantic error, El operador %s se esta "
				   "utilizando como: %s%s%s, se esperaba int%sint o "
				   "real%sreal.\n",
				   linea_actual, $2.lexema, MostrarTipo($1.tipo), $2.lexema, 
				   MostrarTipo($3.tipo), $2.lexema, $2.lexema);
		
			expresion_correcta = 0;
		}
		else if (($1.tipo) != ($3.tipo)) {
			printf("[Linea %d]: semantic error, Tipos incompatibles: %s "
				   "incompatible con %s.\n",
				   linea_actual, MostrarTipo($1.tipo), MostrarTipo($3.tipo));
			expresion_correcta = 0;
		}
		
		if (expresion_correcta == 1) {
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,"int", TipoEscrito($3.tipo),0);
			escribe_elemento("; ");
			copiaTo(tmp,$$.lexema,11);
		}
		
		expresion_correcta = 1;
		$$.tipo=booleano;

		topePilaExpr--;
	}
				 | expresion OPLISTA expresion
				 
	{
		copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema); 
	
	 	$1.tipo = get_tipoValido($1.lexema, $1.tipo);
		$3.tipo = get_tipoValido($3.lexema, $3.tipo);
		
		if ($2.atrib == 1) {
			if (es_lista($1.tipo) == 0 || es_lista($3.tipo) == 0) {
				printf("[Linea %d]: semantic error, El operador %s se debe "
					   "utilizar con dos listas.\n", linea_actual, $2.lexema);
			}
			else {
				if (tipoEnLista($1.tipo) != tipoEnLista($3.tipo)) {
					printf ("[Linea %d]: semantic error, Ambas listas deben ser"
						    " del mismo tipo.\n", linea_actual, $2.lexema);
				}
				else {
					$$.tipo = $1.tipo;
					copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
									 $3.lexema);
					
					generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,TipoEscrito($1.tipo), TipoEscrito($3.tipo),"ll");
					escribir_PYC();
			
					strcpy ($$.lexema, tmp);
					
					
				}
					
			}
		}
		else if ($2.atrib == 0 || $2.atrib == 2) {
			if (es_lista($1.tipo) == 0 || $3.tipo != entero) {
				printf("[Linea %d]: semantic error, El operador %s se debe "
					   "utilizar con una lista y un índice.\n",
					   linea_actual, $2.lexema);
			}
			else {
				$$.tipo = $1.tipo;
				copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
									 $3.lexema);
									 
				generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,TipoEscrito($1.tipo), TipoEscrito($3.tipo),"li");
				escribir_PYC();
		
				strcpy ($$.lexema, tmp);
			}
			
		}
		else {
			if (es_lista($1.tipo) == 0 || $3.tipo != entero) {
				printf("[Linea %d]: semantic error, El operador %s se debe "
					   "utilizar con una lista y un entero.\n",
					   linea_actual, $2.lexema);
			}
		}
	}
				 | expresion OPTER2 expresion 
	{
	 	copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema); 
		$1.tipo = get_tipoValido($1.lexema, $1.tipo);
		$3.tipo = get_tipoValido($3.lexema, $3.tipo);
		
		if (es_lista($1.tipo) == 0 || $3.tipo != entero) {
			printf("[Linea %d]: semantic error, El operador %s se debe utilizar"
				   " con una lista y un entero.\n", linea_actual, $2.lexema);
		}
		else {
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, 
									 $3.lexema);
		
			$$.tipo = tipoEnLista($1.tipo);
			generaExpBinaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2,$2.lexema,TipoEscrito($1.tipo), TipoEscrito($3.tipo),"li");
			escribir_PYC();
			
			strcpy ($$.lexema, tmp);
		}	 
	}
				 | expresion OPTER1 expresion OPTER2 expresion
	{
		if (es_lista($1.tipo) == 0 || $3.tipo != entero || $5.tipo != entero) {
			printf("[Linea %d]: semantic error, El operador %s se debe utilizar"
				   " con una lista y dos enteros.\n", linea_actual, $2.lexema);
		}		
		else {
		 	copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer1, $1.lexema); 
			$1.tipo = get_tipoValido($1.lexema, $1.tipo);
			$3.tipo = get_tipoValido($3.lexema, $3.tipo);

			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer2, $3.lexema);
									 
			copiaToBufLexemaOLlamada(pilaExpr[topePilaExpr].buffer3, $5.lexema);
		
			$$.tipo = $1.tipo;
			generaExpTernaria(pilaExpr[topePilaExpr].buffer1,pilaExpr[topePilaExpr].buffer2, pilaExpr[topePilaExpr].buffer3, $2.lexema,TipoEscrito($1.tipo), TipoEscrito($3.tipo));
			escribir_PYC();
			
			strcpy ($$.lexema, tmp);
		}
		 
	}
				 | IDENT
	{
		if (existe($1.lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, $1.lexema);}
		else if (existeFunc($1.lexema) > -1) {
			printf("[Linea %d]: semantic error, no se le están pasando parámetros a la función '%s' \n",linea_actual,$1.lexema);
		}		
		else {
			$$.tipo=get_tipo($1.lexema);
			$$.lexema = $1.lexema;
		}
	}
				 | CONST 
	{
		
		
		if (strcmp($1.lexema,"TRUE") == 0) {
			strcpy($1.lexema, "1");
		}
		else if (strcmp($1.lexema,"FALSE") == 0) {
			strcpy($1.lexema, "0");
		}
		$$.tipo=$1.tipo;
		$$.lexema=$1.lexema;
		
	}
				 | agregado {$$.tipo=tipoLista($1.tipo);};
				 | funcion
	{
		$$.lexema = $1.lexema;
		$$.tipo = $1.tipo;
	}
				 | error ;	  
                                              
lista_variables: lista_variables COMA IDENT
	{
		if (existe($3.lexema) == 0) {
			printf("[Linea %d]: semantic error, Identificador %s no "
				   "declarado\n", linea_actual, $3.lexema);
		}
		else {
			$3.tipo=get_tipo($3.lexema);
			escribe_leer($3.tipo, $3.lexema);
		}
	}
   			   | IDENT  
    {
 		$1.tipo = get_tipo($1.lexema);
    	$$.lexema=$1.lexema;
    	$$.tipo = $1.tipo;
    	escribe_leer($1.tipo, $1.lexema);
    } ;
          
lista_expresiones_o_cadena: lista_expresiones_o_cadena COMA exp_cad
						  | exp_cad;

exp_cad: expresion 
	{
		if (es_lista($1.tipo) == 1) {
			printf("[Linea %d]: semantic error, No se puede imprimir una "
				   "lista\n", linea_actual);
		}
		else {
			if (existeFunc($1.lexema) > -1) {
				$1.lexema = pilaParams[topePilaParams+1].llamadaString;
			}
		}
		escribe_imprimir($1.tipo, $1.lexema); // ¿Las listas no se deben imprimir?
	}
   	   | CAD 
   	   
   	{
   		escribe_imprimir(-1, $1.lexema);
   	};   				            

agregado: CORI lista_constantes CORD
	{
		$$.tipo=$2.tipo;
		strcpy($$.lexema, tmp);
		if (es_lista($2.tipo) == 1) {
			printf("[Linea %d]: semantic error, No se pueden usar listas de "
				   "listas.\n", linea_actual);
		}
	};

lista_constantes: lista_constantes COMA CONST
	{
		if ($$.tipo != $3.tipo) {
			printf("[Linea %d]: semantic error, Las constantes introducidas "
					"son de diferentes tipos\n", linea_actual);
		$$.tipo=$3.tipo;
		}
		else {
			if (strcmp($3.lexema,"TRUE") == 0) {
				strcpy($3.lexema, "1");
			}
			else if (strcmp($3.lexema,"FALSE") == 0) {
				strcpy($3.lexema, "0");
			}
			$$.tipo=$3.tipo;
			$$.lexema=$3.lexema;
		
			char aux[200];
			sprintf(aux, "%s = insertar_%s(&%s, %s, longitud_%s(&%s));\n", tmp, MostrarTipo($3.tipo),tmp, $3.lexema, MostrarTipo($3.tipo), tmp);
			escribe_elemento(aux);
		}
	}
   				| CONST
   	{
   		if ($$.tipo != $1.tipo) {
   			printf("[Linea %d]: semantic error, Las constantes introducidas "
   				   "son de diferentes tipo\n", linea_actual);
			$$.tipo=$1.tipo; 
		}
		else {
			if (strcmp($1.lexema,"TRUE") == 0) {
				strcpy($1.lexema, "1");
			}
			else if (strcmp($1.lexema,"FALSE") == 0) {
				strcpy($1.lexema, "0");
			}
			$$.tipo=$1.tipo;
			$$.lexema=$1.lexema;
		
			genera_temporal();
			char aux[200];
			sprintf(aux, "lista_%s %s;\ninicializa_%s(&%s);\n"
					"%s = insertar_%s(&%s, %s, longitud_%s(&%s));\n", 
					MostrarTipo($1.tipo), tmp, MostrarTipo($1.tipo),
					tmp, tmp, MostrarTipo($1.tipo),tmp, $1.lexema,
					MostrarTipo($1.tipo), tmp);
			escribe_elemento(aux);
		}
			
	} ;

funcion: IDENT
	{
		$$.lexema = $1.lexema;
		$$.tipo = $1.tipo;
		topePilaParams++;
		pilaParams[topePilaParams].pos = existeFunc($1.lexema);
		sprintf(pilaParams[topePilaParams].llamadaString, "%s(", $1.lexema);
		
		if (pilaParams[topePilaParams].pos >= 0) {
			funcion_existe = 1;
		}
		else {
			funcion_existe = 0;
		}
	}
		 PARI lista_exp_vacia PARD 
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
			$$.tipo = TS[pilaParams[topePilaParams].pos].tipo_dato;
		}
		else {
			printf("[Linea %d]: semantic error, La funcion %s no ha sido "
				   "declarada.\n", linea_actual, $1.lexema);
							
//			$$.tipo = desconocido;
		}
		topePilaParams--;
	};

lista_exp_vacia : 
	{
		pilaParams[topePilaParams].contParam = 0;
	}
				 lista_expresiones
	
			    | 
	{
		pilaParams[topePilaParams].contParam = 0;
	} ;

lista_expresiones: lista_expresiones COMA expresion
	{	
		if (funcion_existe != 0) {
			if(existeFunc($3.lexema) > -1)
				sprintf(buf, "%s, %s", pilaParams[topePilaParams].llamadaString, pilaParams[topePilaParams+1].llamadaString);
			else
				sprintf(buf, "%s, %s", pilaParams[topePilaParams].llamadaString, $3.lexema);

			sprintf(pilaParams[topePilaParams].llamadaString, "%s", buf);
		
			int tipo_param = TS[pilaParams[topePilaParams].pos].parametros[
							 pilaParams[topePilaParams].contParam];
			if (tipo_param != $3.tipo)
				printf("[Linea %d]: semantic error, Se esperaba parametro de "
					   "tipo %s en lugar de %s.\n", linea_actual, 
					   MostrarTipo(tipo_param), MostrarTipo($3.tipo));
					   
			pilaParams[topePilaParams].contParam++;
		}
	} // AQUÍ HABÍA UN ';'
				 | expresion 
	{
		if (funcion_existe != 0) {
			int tipo_param = TS[pilaParams[topePilaParams].pos].parametros[
							 pilaParams[topePilaParams].contParam];
			if (tipo_param != $1.tipo)
				printf("[Linea %d]: semantic error, Se esperaba parametro de "
					   "tipo %s en lugar de %s.\n", linea_actual, 
					   MostrarTipo(tipo_param), MostrarTipo($1.tipo));
			
			pilaParams[topePilaParams].contParam++; 
			if(existeFunc($1.lexema) > -1)
				sprintf(buf, "%s%s", pilaParams[topePilaParams].llamadaString, pilaParams[topePilaParams+1].llamadaString);
			else
				sprintf(buf, "%s%s", pilaParams[topePilaParams].llamadaString, $1.lexema);
			sprintf(pilaParams[topePilaParams].llamadaString, "%s", buf);
			
		}
	};

%%

#include "lex.yy.c"

void yyerror(const char *msg) {
    fprintf(stderr,"[En linea %d]: %s\n",linea_actual, msg);
}
