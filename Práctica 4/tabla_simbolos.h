int linea_actual;
typedef int bool;
#define true 1
#define false 0

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
	array_entero,
	array_real,
	array_booleano,
	array_caracter,
	desconocido
} TipoDato;

static char* TipoDatoString[] = {	
	"entero",
	"real",
	"caracter",
	"booleano",
	"array_entero",
	"array_real",
	"array_booleano",
	"array_caracter",
	"desconocido"
};


typedef struct {
	TipoEntrada tipo_entrada;
	char *nombre;
	TipoDato tipo_dato;
	unsigned int parametros;
	int tipo_parametros[100];
	unsigned int dimensiones;
	bool es_array;
	int TamDimen1;
	int TamDimen2;
} entradaTS;

typedef struct {
	int atrib ; 		/* Atributo del símbolo (si tiene) */
	char *lexema ; 		/* Nombre del lexema */
	TipoDato tipo ; 	/* Tipo del símbolo */
} atributos ;

#define YYSTYPE atributos	/* Cada símbolo tiene una estructura de tipo atributos */
#define MAX_TS 500

unsigned int TOPE = -1 ; 	/* Tope de la pila inicializado a 0 */
entradaTS TS[MAX_TS] ;		/* Pila de la tabla de símbolos */

/* Lista de funciones y procedimientos para el manejo de la TS */

char* MostrarTipo(TipoDato tipo){
	if(tipo==0) return("entero");
	if(tipo==1) return("real");
	if(tipo==2) return("caracter");
	if(tipo==3) return("booleano");
	if(tipo==4) return("array entero");
	if(tipo==5) return("array real");
	if(tipo==6) return("array booleano");
	if(tipo==7) return("array caracter");
	if(tipo==8) return("desconocido");
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
			printf ("\nFuncion: %s, Tipo: %s, Num. Parametros: %d", TS[i].nombre, TipoDatoString[TS[i].tipo_dato], TS[i].parametros);
		}
		if (TS[i].tipo_entrada == variable){
			printf ("\nVariable: %s, Tipo: %s , dimensiones: %d", TS[i].nombre, TipoDatoString[TS[i].tipo_dato],TS[i].dimensiones);
		}	
		if (TS[i].tipo_entrada==parametro_formal){
			printf ("\nParametro: %s, Tipo: %s", TS[i].nombre, TipoDatoString[TS[i].tipo_dato]);
		}
	}
	getchar();
	
	printf("\n-\n");
}

/* Para listas de variables */
int soy_array(){
	TS[TOPE].es_array = true;
	return 1;
}

void asignarTipo (TipoDato tipo) {
	TS[TOPE].tipo_dato = tipo;
	if((tipo==entero)&&(TS[TOPE].es_array)){
		TS[TOPE].tipo_dato = array_entero;
	}
	if((tipo==real)&&(TS[TOPE].es_array)){
		TS[TOPE].tipo_dato = array_real;
	}
	if((tipo==booleano)&&(TS[TOPE].es_array)){
		TS[TOPE].tipo_dato = array_booleano;
	}
	if((tipo==caracter)&&(TS[TOPE].es_array)){
		TS[TOPE].tipo_dato = array_caracter;
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

void insertarIDENT(TipoEntrada tipo, char* lexema, TipoDato tipo_leido, int n_dimensiones){
	//printf("\n He leido lexema:%s de tipo %s", lexema, TipoDatoString[tipo_leido]);
	TOPE++;
	TS[TOPE].tipo_entrada = tipo;
	TS[TOPE].nombre = strdup(lexema);
	TS[TOPE].tipo_dato = tipo_leido;
	if(n_dimensiones==0){
		TS[TOPE].es_array = false;
		TS[TOPE].dimensiones = 0;
	}else{
		TS[TOPE].es_array = true;
		TS[TOPE].dimensiones = n_dimensiones;
	}
	if(tipo == funcion)
		TS[TOPE].parametros = 0;

	//imprimeTS();
}

/* Insertar una marca en la TS y añadir parametros como variables */
void TS_InsertaMarca(){
	int i;
	TOPE++;

	TS[TOPE].tipo_entrada = marca;

	for (i=TOPE-1 ; i>=0 && TS[i].tipo_entrada != marca && TS[i].tipo_entrada != funcion ; i--){
		if (TS[i].tipo_entrada == parametro_formal) {
			/* Hemos encontrado un parametro, incluirlo como variable */
			insertarIDENT(variable, TS[i].nombre, TS[i].tipo_dato, 0);
			if(TS[i].es_array){
				soy_array();
			}
		}
	}
	//imprimeTS();
}

/* Elimina entradas de la tabla de simbolos hasta que se encuentra una marca de comienzo de bloque o se queda la tabla de simbolos vacia */
void TS_VaciarEntradas() {
	for (;TOPE>=0 && TS[TOPE].tipo_entrada!=marca ; TOPE--);
	if (TOPE != 0)
		TOPE--;
	//imprimeTS();
}

int es_array(TipoDato v){
	if((v==array_booleano) || (v==array_entero) || (v==array_real) || (v==array_caracter))
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
			printf ("[Linea %d]: semantic error, El identificador %s ya ha sido declarado.\n", linea_actual, lexema);
			return 1;
		}
	}
	return 0;
}

/* Devuelve 1 si existe definida una variable con el nombre especificado 0 en caso contrario */
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
void CuentaParametros (TipoDato tipo) {
	int i;
	int nParametros = 0;
	int parametros[100];

	for (i=TOPE ; TS[i].tipo_entrada != funcion ; i--){
		if (TS[i].tipo_entrada == parametro_formal) {
			parametros[nParametros] = TS[i].tipo_dato;
			nParametros++;
		}
	}

	TS[i].tipo_dato = tipo;
	TS[i].parametros = nParametros;
	//imprimeTS ();
}

/* Asigna el tipo especificado a todas las entradas consecutivas que sean variables de tipo no_asignado 
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
}*/

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
	long int temp;
	for (temp=TOPE ; temp>0 ; temp--){
		//printf("%i\n",TS[temp].tipoentrada);
		if ((TS[temp].tipo_entrada == funcion) && !strcmp(TS[temp].nombre, lexema))
			return temp;
	}
	
	return -1;
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

	if(es_array(v)){	
		if(v==array_booleano)
			return booleano;
		if(v==array_entero)
			return entero;
		if(v==array_real)
			return real;
		if(v==array_caracter)
			return caracter;
	}
	else
		return v;

}

/*Devuelve el tipo de la lista*/
TipoDato tipoLista(TipoDato v){
	if(es_array(v)==0){
		if(v==booleano)
			return array_booleano;
		if(v==entero)
			return array_entero;
		if(v==real)
			return array_real;
		if(v==caracter)
			return array_caracter;
	}
	else
		return v;
}


/* Asigna el numero y tipo de parametros que tiene una funcion: */
void asignarNumeroParametros(char *lexema, int n_parametros){
	int i, j;
	for (i=TOPE ; TS[i].tipo_entrada!=funcion; i--){};
	//Asignamos el numero de parametros:
	TS[i].parametros = n_parametros;
	int n = 0;
	for(j=i ; j!=TOPE ; j++){
		TS[i].tipo_parametros[n] = TS[j].tipo_dato;
		n++;
	}
}



/* Fin de funciones y procedimientos para el manejo de la TS */
