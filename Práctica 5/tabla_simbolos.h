#ifndef tabla_simbolos_h
#define tabla_simbolos_h

int linea_actual;

/* Variable para definir la estructura de la TS */

typedef enum {
	marca,			/* Marca de principio de bloque */
	funcion,		/* Función */
	variable,		/* Variable local */
	parametro_formal	/* Parámetro formal de una función situado */
} TipoEntrada;			/* en una entrada anterior de la tabla */

typedef enum {
	entero,
	real,
	caracter,
	booleano,
	lista_entero,
	lista_real,
	lista_booleano,
	lista_caracter,
	vacio,
	desconocido,
	no_asignado
} TipoDato;

typedef struct {
	char *nombre;
	TipoEntrada tipo_entrada;
	TipoDato tipo_dato;
	int n_parametros;
	int parametros[100];
	int pila;
} entradaTS;

typedef struct {
	int atrib ; 		/* Atributo del símbolo (si tiene) */
	char *lexema ; 		/* Nombre del lexema */
	TipoDato tipo ; 	/* Tipo del símbolo */
	int nargumentos;
} atributos ;

#define YYSTYPE atributos	/* Cada símbolo tiene una estructura de tipo atributos */
#define MAX_TS 500

unsigned int TOPE = -1 ; 	/* Tope de la pila inicializado a 0 o -1 */
entradaTS TS[MAX_TS] ;		/* Pila de la tabla de símbolos */

/* Lista de funciones y procedimientos para el manejo de la TS */

char* MostrarTipo(TipoDato tipo){
	if(tipo==0) return("entero");
	if(tipo==1) return("real");
	if(tipo==2) return("caracter");
	if(tipo==3) return("booleano");
	if(tipo==4) return("lista entero");
	if(tipo==5) return("lista real");
	if(tipo==6) return("lista booleano");
	if(tipo==7) return("lista caracter");
	if(tipo==8) return("vacio");
	if(tipo==9) return("desconocido");
	if(tipo==10) return("no asignado");	
}

char* TipoEscrito(TipoDato tipo){
	if(tipo==0) return("int");
	if(tipo==1) return("float");
	if(tipo==2) return("char");
	if(tipo==3) return("int");
	if(tipo==4) return("lista_entero");
	if(tipo==5) return("lista_real");
	if(tipo==6) return("lista_booleano");
	if(tipo==7) return("lista_caracter");
	return "NO_ENCONTRADO";
}


/* Imprime el contenido de la pila */
void imprimeTS () {
	int i;
	int letra;

	for (i=0 ; i<= TOPE ; i++) {
		if (TS[i].tipo_entrada==marca){
			printf ("\n<<< MARCA >>>");
		}
		if (TS[i].tipo_entrada==funcion){
			printf ("\nFuncion: %s, Tipo: %d, Num. Parametros: %d", TS[i].nombre, TS[i].tipo_dato, TS[i].n_parametros);
		}
		if (TS[i].tipo_entrada == variable){
			printf ("\nVariable: %s, Tipo: %d , espila: %d", TS[i].nombre, TS[i].tipo_dato,TS[i].pila);
		}	
		if (TS[i].tipo_entrada==parametro_formal){
			printf ("\nParametro: %s, Tipo: %d", TS[i].nombre, TS[i].tipo_dato);
		}
	}
	getchar();
	
	printf("\n-\n");
}

/* Para listas de variables */
void espila(){
	TS[TOPE].pila = 1;
}

void asignarTipo (TipoDato tipo) {
	TS[TOPE].tipo_dato = tipo;
	if((tipo==entero)&&(TS[TOPE].pila==1)){
		TS[TOPE].tipo_dato = lista_entero;
	}
	if((tipo==real)&&(TS[TOPE].pila==1)){
		TS[TOPE].tipo_dato = lista_real;
	}
	if((tipo==booleano)&&(TS[TOPE].pila==1)){
		TS[TOPE].tipo_dato = lista_booleano;
	}
	if((tipo==caracter)&&(TS[TOPE].pila==1)){
		TS[TOPE].tipo_dato = lista_caracter;
	}		
}

/* Asigna el tipo de una función */
/* Busca hacia atrás y cuando la encuentre lo mete */
void asignarTipoFuncion (TipoDato tipo) {

	int i;

	for (i=TOPE; TS[i].tipo_entrada != funcion ; i--)
		;
	
	TS[i].tipo_dato = tipo;
	//imprimeTS();
}

void insertarIDENT(TipoEntrada tipo, char* lexema){
	TOPE++;
	TS[TOPE].tipo_entrada = tipo;
	TS[TOPE].nombre = strdup(lexema);
	TS[TOPE].tipo_dato = no_asignado;
	TS[TOPE].pila = 0;
	if(tipo == funcion)
		TS[TOPE].n_parametros = 0;
//	imprimeTS();
}

/* Insertar una marca en la TS y añadir parametros como variables */
void TS_InsertaMarca(){
	int i;
	TOPE++;

	TS[TOPE].tipo_entrada = marca;

	for (i=TOPE-1 ; i>=0 && TS[i].tipo_entrada != marca && TS[i].tipo_entrada != funcion ; i--){
		if (TS[i].tipo_entrada == parametro_formal) {
			/* Hemos encontrado un parametro, incluirlo como variable */
			insertarIDENT(variable, TS[i].nombre);
			asignarTipo(TS[i].tipo_dato);
			if(TS[i].pila==1){
				espila();
			}
		}
	}
//	imprimeTS();
}

/* Elimina entradas de la tabla de simbolos hasta que se encuentra una marca de comienzo de bloque o se queda la tabla de simbolos vacia */
void TS_VaciarEntradas() {
	for (;TOPE>=0 && TS[TOPE].tipo_entrada!=marca ; TOPE--);
	if (TOPE != 0)
		TOPE--;
//	imprimeTS();
}

int es_lista(TipoDato v){
	if((v==lista_booleano) || (v==lista_entero) || (v==lista_real) || (v==lista_caracter))
		return 1;
	else
		return 0;
}

/* Comprueba si existe un identificador en la pila igual al que se le pasa por parámetro */
int es_repetida(char * lexema){
	int i;
	int igual = 0;
	
	for (i=TOPE ; TS[i].tipo_entrada != marca ; i--){
		igual = strcmp(TS[i].nombre, strdup(lexema));
		if (!igual && TS[i].tipo_entrada != parametro_formal) {
			printf ("[Linea %d]: semantic error, Identificador %s ya esta declarado\n", linea_actual, lexema);
			return 1;
		}
	}
	return 0;
}

/* Devuelve 1 si existe definida una variable con el nombre especificad o 0 en caso contrario */
int existe (char *lexema) {
	long int temp;

	for (temp=TOPE ; temp>0 ; temp--){
		//printf("%i\n",TS[temp].tipoentrada);
		if ((TS[temp].tipo_entrada == variable || TS[temp].tipo_entrada == parametro_formal  || TS[temp].tipo_entrada == funcion) && !strcmp(TS[temp].nombre, lexema))
			return 1;
	}
	return 0;
}

/* Asigna el tipo vacio al funcion y  cuenta cuantos parametros tiene */
void CuentaParametros () {
	int i;
	int nParametros = 0;
	int parametros[100];

	for (i=TOPE ; TS[i].tipo_entrada != funcion ; i--){
		if (TS[i].tipo_entrada == parametro_formal) {
			parametros[nParametros] = TS[i].tipo_dato;
			nParametros++;
		}
	}

	TS[i].tipo_dato = vacio;
	TS[i].n_parametros = nParametros;
	int j;
	for(j=0 ; j<nParametros ; j++)
		TS[i].parametros[nParametros-j-1] = parametros[j];
	//imprimeTS ();
}

/* Asigna el tipo especificado a todas las entradas consecutivas que sean variables de tipo no_asignado */
void asignarTipoCascada(TipoDato tipo) {
	int i;
	for (i=TOPE ; (TS[i].tipo_entrada==parametro_formal || TS[i].tipo_entrada==variable) && TS[i].tipo_dato == no_asignado ; i--){
		TS[i].tipo_dato = tipo;
		if((tipo==entero)&&(TS[i].pila==1)){
			TS[i].tipo_dato = lista_entero;
		}
		if((tipo==real)&&(TS[i].pila==1)){
			TS[i].tipo_dato = lista_real;
		}
		if((tipo==booleano)&&(TS[i].pila==1)){
			TS[i].tipo_dato = lista_booleano;
		}
		if((tipo==caracter)&&(TS[i].pila==1)){
			TS[i].tipo_dato = lista_caracter;
		}
		if(tipo == desconocido)
			TOPE--;
	}
//	imprimeTS();		
}

/* Comprobar si ya existe otro parametro con el mismo lexema en el mismo funcion*/
int BuscarParametroRepetido(char *lexema){
	int i;
	int igual= 0;
	
	for (i=TOPE ; TS[i].tipo_entrada != funcion && TS[i].tipo_entrada != marca ; i--){
		igual = strcmp(TS[i].nombre, strdup(lexema));
		if (!igual) {
			printf ("[Linea %d]: semantic error, Parametro %s esta duplicado\n", linea_actual, strdup(lexema));
			return 1;
		}
	}
	return 0;
}

/* Comprueba que existe un nombre de procedimiento declarado igual al que se le pasa */
int existeFunc(char *lexema) {
	int i;
	int pos = -1;
	for (i=TOPE+1 ; i>=0 && TS[TOPE].tipo_entrada!=marca ; i--){
		if(TS[i].tipo_entrada == funcion && !strcmp(TS[i].nombre, strdup(lexema))) {
			pos = i;
		}
	}
	return pos;
}

/*Devuelve el tipo de dato del parametro de la funcion comparandolo con el que se pasa a la funcion*/
TipoDato tipoParametro(int num, char* lexema){
	int i;
	int igual=0;

	for (i=TOPE ; i>=0 ; i--){
		if (TS[i].tipo_entrada == funcion && !strcmp(TS[i].nombre, lexema)){
			return (TS[i+num].tipo_dato);
		}
	}
}

/* Devuelve el tipo si existe definida una variable con el nombre especificado*/
TipoDato get_tipo (char *lexema) {
	long int temp;
	//imprimeTS();
	for (temp=TOPE ; temp>=0 ; temp--){
		if((TS[temp].tipo_entrada == variable || TS[temp].tipo_entrada == funcion) && !strcmp(TS[temp].nombre, lexema))
			return TS[temp].tipo_dato;
	}
}

TipoDato get_tipoValido (char *lexema, TipoDato td) {
	int tipoTmp1, tipoTmp2;

	if(existe(lexema)) //Es Identificador
		tipoTmp1 = get_tipo(lexema);
	else //Es constante
		tipoTmp1 = td;
}

/*Devuelve el tipo de la lista*/
TipoDato tipoEnLista(TipoDato v){

	if(es_lista(v)){	
		if(v==lista_booleano)
			return booleano;
		if(v==lista_entero)
			return entero;
		if(v==lista_real)
			return real;
		if(v==lista_caracter)
			return caracter;
	}
	else
		return v;

}

/*Devuelve el tipo de la lista*/
TipoDato tipoLista(TipoDato v){
	if(es_lista(v)==0){
		if(v==booleano)
			return lista_booleano;
		if(v==entero)
			return lista_entero;
		if(v==real)
			return lista_real;
		if(v==caracter)
			return lista_caracter;
	}
	else
		return v;
}

int indiceFunc(){
	int i;
	int igual=0;
	for (i=TOPE; i>=0; i--)
		if (TS[i].tipo_entrada == funcion){
			return (i);
		}
}

/* Fin de funciones y procedimientos para el manejo de la TS */

#endif
