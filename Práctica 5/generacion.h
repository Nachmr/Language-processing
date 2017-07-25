#ifndef generacion_h
#define generacion_h

#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///****Comentarios*****///

//Imprimir tabulación adecuada usando main_llave
//Parametro n de funcion copia
//Crear funcion imprimir PYC, LN
//Si hay tiempo cambiar ifelses anidados de escribe_bla_lista
//Revisar funciones de pilas -> listas . p.e escribe lista vacia
//Genera generaExpUnaria con operadores pila

int llaveCerrada[100];

typedef struct {
	int pos;
	int contParam;
	char llamadaString[200];
} PilaParams;

PilaParams pilaParams[100];

int topePilaParams = -1;

char buf [200];

typedef struct {
	char buffer1[200];
	char buffer2[200];
} PilaExpr;

PilaExpr pilaExpr[100];

int topePilaExpr = -1;

char * nombre_fichero = "codigoSalida.c";

FILE *fichero1;
FILE *ficheroFunc;
FILE *actual;

char  tmp[200];
char  tmp1[200];
char tmp2[200];

char *tipo_actual;

unsigned int etiqueta_base =0;
unsigned int tmporal_base =0;
unsigned int almacena_tmp=0;

int main_llave=0;
int en_fun=0;

typedef struct{
	char EtiquetaEntrada[15];
	char EtiquetaSalida[15];
	char EtiquetaElse[15];
	char NombreVarControl[15];
}DescriptorControl;

typedef struct{
	int num;
}Temporales;

DescriptorControl tablaControl[200];
int ind=-1;
Temporales temporales[500];
int indtmp=-1;





void add_descriptor(DescriptorControl d){
	ind++;
	tablaControl[ind]=d;
}

void delete_descriptor(){
	ind--;
}

DescriptorControl get_descriptor(){
	DescriptorControl d=tablaControl[ind];
	return d;
}


void abrir_ficheros(){
	fichero1 = fopen(nombre_fichero,"w+");
	ficheroFunc = fopen("dec_fun","w+");
//	fprintf(ficheroFunc,"#include \"dec_dat\"\n");
	fprintf(ficheroFunc,"#include <stdio.h>\n\n");
}

void cerrar_ficheros(){
	fclose(fichero1);
	fclose(ficheroFunc);
}


void escribir_cabecera(){
//	fprintf(fichero1,"#include \"dec_dat\"\n");
	fprintf(fichero1,"#include \"dec_fun\"\n");
	fprintf(fichero1,"#include <stdio.h>\n\n");
//	fprintf(fichero1,"int main()");
}

void escribir_main(){
	fprintf(fichero1,"int main()");
}

void abrir_llave(){
	if(en_fun==0)
		fprintf(fichero1,"{\n");
	else
		fprintf(ficheroFunc,"{\n");
	main_llave++;	
}

void cerrar_llave(){
	main_llave--;

	if(en_fun > -1 && llaveCerrada[en_fun]) {
		llaveCerrada[en_fun] = 0;
	}
	if(en_fun==0){
		if(main_llave==0)
			fprintf(fichero1,"return 0;\n}\n");
		else
			fprintf(fichero1,"\n}\n");
	}
	else
		fprintf(ficheroFunc,"\n}\n");
}

void escribir_una_variable(char *nombre){

	if(en_fun==0){
			fprintf(fichero1,"%s %s;\n",tipo_actual,nombre);
	}else{
		fprintf(ficheroFunc,"%s %s;\n",tipo_actual,nombre);
	}
}

void escribir_una_variable_extern(char *nombre) {
	fprintf(ficheroFunc,"extern %s %s;\n",tipo_actual,nombre);
}

void actualiza_tipo(char* tipo){
	tipo_actual = tipo;
}

void escribe_elemento(char *el){
	if(en_fun==0){
		fprintf(fichero1,"%s",el);
	}else{
		fprintf(ficheroFunc,"%s",el);
	}
}

void escribir_PYC(){
	if(en_fun==0){
		fprintf(fichero1,";");
	}else{
		fprintf(ficheroFunc,";");
	}
}

void escribir_NL(){
	if(en_fun==0){
		fprintf(fichero1,"\n");
	}else{
		fprintf(ficheroFunc,"\n");
	}
}

void copiaToBufLexemaOLlamada(char* buf, char* lexema) {
	if(existeFunc(lexema) > -1)
		sprintf(buf, "%s", pilaParams[topePilaParams+1].llamadaString);
	else
		sprintf(buf, "%s", lexema);
}

void copiaTotmp(char *m){
	strcpy(tmp,m);
}

void copiaTo(char *m1, char* m2,int n){
	//Parametro "n" no se usa 
	strcpy(m2,m1);
}

void genera_etiqueta(char * m){
	char aux[15]= "etiqueta";
	char aux2[5];
	sprintf(aux2,"%d",etiqueta_base);
	
	strcat(aux,aux2);

	etiqueta_base++;
	copiaTo(aux,m,15);
}

void copiaTotmp1(char *m){
	strcpy(tmp1,m);
}

void copiaTotmp2(char *m){
	strcpy(tmp2,m);
}

void genera_temporal(){
	char aux[11]= "tmp";
	char aux2[5];
	sprintf(aux2,"%d",tmporal_base);
	
	strcat(aux,aux2);

	tmporal_base++;
	copiaTotmp(aux);
}

void escribir_variables(char *tipo){
	actualiza_tipo(tipo);
	int i;
	
	for (i=TOPE; TS[i].tipo_entrada==variable && TS[i].tipo_dato == no_asignado; i--){
		
		escribir_una_variable(TS[i].nombre);
	}
	if(en_fun==0)
		fprintf(fichero1,"\n");
	else
		fprintf(ficheroFunc,"\n");
}

escribir_variables_extern(char *tipo) {
	actualiza_tipo(tipo);
	int i;
	
	for (i=TOPE; TS[i].tipo_entrada==variable && TS[i].tipo_dato == no_asignado; i--){
		
		escribir_una_variable_extern(TS[i].nombre);
	}
	
	fprintf(ficheroFunc,"\n");
}



char * fromOpToChar(char* op){
	char * aux;
	aux = malloc(100);
	if(strcmp("*", op)==0)
		strcpy(aux,"producto");
	if(strcmp("+", op)==0)
		strcpy(aux,"suma");
	if(strcmp("-", op)==0)
		strcpy(aux,"resta");
	if(strcmp("/", op)==0)
		strcpy(aux,"division");	
	return aux;
}

void generaExpBinaria(char *elem1, char*elem2, char*op, char*tip, char*tip2, char *tipos){
	copiaTotmp1(elem1);
	copiaTotmp2(elem2);
	genera_temporal();
	
	char buf[200];
	
	if(strcmp(op,"AND") == 0)
		strcpy(op,"&&");
	else if (strcmp(op,"OR") == 0)
		strcpy(op,"||");
	else if (strcmp(op,"=") == 0)
		strcpy(op,"==");
	else if (strcmp(op,"<>") == 0)
		strcpy(op,"!=");
	
	
	if(en_fun==0){
		fprintf(fichero1,"%s %s;\n",tip,tmp);
		fprintf(fichero1,"%s = %s %s ",tmp, tmp1, op);	
		fprintf(fichero1,"%s",tmp2);
	}
	else{
		fprintf(ficheroFunc,"%s %s;\n",tip,tmp);
		fprintf(ficheroFunc,"%s = %s %s ",tmp, tmp1, op);	
		fprintf(ficheroFunc,"%s",tmp2);
	}
}

void escribe_asignacion(char *elem1, char*elem2){
	copiaTotmp1(elem1);
	copiaTotmp2(elem2);
	
	if(en_fun==0){
		fprintf(fichero1,"\n%s = ",tmp1);

		fprintf(fichero1,"%s",elem2);
	}
	else{
		fprintf(ficheroFunc,"\n%s = ",tmp1);

		fprintf(ficheroFunc,"%s",elem2);
	}
}

void escribe_if(char *elem1){
	DescriptorControl d;
	
	genera_etiqueta(d.EtiquetaSalida);
	genera_etiqueta(d.EtiquetaElse);
	
	add_descriptor(d);
	copiaTotmp1(elem1);
	if(en_fun==0){
		fprintf(fichero1,"if(!%s)goto %s;\n\n",tmp1,d.EtiquetaElse);
	}
	else{
		fprintf(ficheroFunc,"if(!%s)goto %s;\n\n",tmp1,d.EtiquetaElse);
	}
}

void escribe_else(){
	DescriptorControl d=get_descriptor();
	if(en_fun==0){
		fprintf(fichero1,"goto %s;\n",d.EtiquetaSalida);
		fprintf(fichero1,"%s:;\n\n",d.EtiquetaElse);
	}
	else{
		fprintf(ficheroFunc,"goto %s;\n",d.EtiquetaSalida);
		fprintf(ficheroFunc,"%s:;\n\n",d.EtiquetaElse);
	}
}

void escribe_while(char *elem1){
	DescriptorControl d=get_descriptor();
	copiaTotmp1(elem1);
	if(en_fun==0)
		fprintf(fichero1,"\nif(!%s)goto %s;\n",tmp1,d.EtiquetaSalida);
	else
		fprintf(ficheroFunc,"\nif(!%s)goto %s;\n",tmp1,d.EtiquetaSalida);
}

void fin_while(){
	DescriptorControl d=get_descriptor();
	if(en_fun==0){
		fprintf(fichero1,"goto %s;\n",d.EtiquetaEntrada);
		fprintf(fichero1,"%s:;\n\n",d.EtiquetaSalida);
	}
	else{
		fprintf(ficheroFunc,"goto %s;\n",d.EtiquetaEntrada);
		fprintf(ficheroFunc,"%s:;\n\n",d.EtiquetaSalida);
	}
	delete_descriptor();
}

void escribe_for(char *elem1, char *elem2){
	DescriptorControl d=get_descriptor();
	copiaTotmp1(elem1);
	copiaTotmp2(elem2);

	if(en_fun==0)
		fprintf(fichero1,"\nif(!(%s < %s))goto %s;\n\n",tmp1, tmp2, d.EtiquetaSalida);
	else
		fprintf(ficheroFunc,"\nif(!(%s < %s))goto %s;\n\n",tmp1,tmp2,d.EtiquetaSalida);
}

void fin_for(char *elem1){
	copiaTotmp1(elem1);

	DescriptorControl d=get_descriptor();
	if(en_fun==0){
		fprintf(fichero1,"%s++;", tmp1);
		fprintf(fichero1,"goto %s;\n",d.EtiquetaEntrada);
		fprintf(fichero1,"%s:;\n\n",d.EtiquetaSalida);
	}
	else{
		fprintf(ficheroFunc,"%s++;", tmp1);
		fprintf(ficheroFunc,"goto %s;\n",d.EtiquetaEntrada);
		fprintf(ficheroFunc,"%s:;\n\n",d.EtiquetaSalida);
	}
	delete_descriptor();
}

void escribe_argumentos(){
	int args = TOPE-indiceFunc();
	int i=0;
	int primero = 1;
	for(i=indiceFunc()+2;i<=TOPE;i++){
		if(primero==1){
			fprintf(ficheroFunc,"%s",TipoEscrito(TS[i].tipo_dato)); 
			primero=0;
		}
		else{
			fprintf(ficheroFunc,", %s",TipoEscrito(TS[i].tipo_dato)); 	
		}
		fprintf(ficheroFunc," %s",TS[i].nombre); 
	}
	fprintf(ficheroFunc,")"); 
}


void escribir_cabecera_funcion(TipoDato tipo, char *iden){

	fprintf(ficheroFunc,"\n%s %s(",TipoEscrito(tipo),iden); 
	escribe_argumentos();
}

void escribe_imprimir(TipoDato tip, char *elem){
	if((tip==0)||(tip==3)){ 
		if(en_fun==0)
			fprintf(fichero1,"printf(\"%%d\",%s);\n",elem);
		else
			fprintf(ficheroFunc,"printf(\"%%d\",%s);\n",elem);
	}else if(tip==1){
			if(en_fun==0)
				fprintf(fichero1,"printf(\"%%f\",%s);\n",elem);
			else
				fprintf(ficheroFunc,"printf(\"%%f\",%s);\n",elem);
	} else if(tip==2){
		if(en_fun==0)
			fprintf(fichero1,"printf(\"%%c\",%s);\n",elem);
		else
			fprintf(ficheroFunc,"printf(\"%%c\",%s);\n",elem);
	} else {
		if(en_fun==0)
			fprintf(fichero1,"printf(\"%%s\",%s);\n",elem);
		else
			fprintf(ficheroFunc,"printf(\"%%s\",%s);\n",elem);
	}
}

void escribe_leer(TipoDato tip, char *elem){
	if((tip==0)||(tip==3)){
		if(en_fun==0){
			fprintf(fichero1,"scanf(\"%%i\",&%s);\n",elem);
		}
		else{
			fprintf(ficheroFunc,"scanf(\"%%i\",&%s);\n",elem);
		}
	}
	if(tip==1){//reales
		if(en_fun==0){
			fprintf(fichero1,"scanf(\"%%f\",&%s);\n",elem);
		}
		else{
			fprintf(ficheroFunc,"scanf(\"%%f\",&%s);\n",elem);
		}
	}
	if(tip==2){//caracteres
		if(en_fun==0){
			fprintf(fichero1,"scanf(\"%%c\",&%s);\n",elem);
		}
		else{
			fprintf(ficheroFunc,"scanf(\"%%c\",&%s);\n",elem);
		}		
	}
}

void libera_temporales(){
	tmporal_base=0;
}

void inserta_marcatmp(){
	indtmp++;
	
	temporales[indtmp].num = tmporal_base;
	libera_temporales();
}

void elimina_marcatmp(){
	indtmp--;
	tmporal_base=	temporales[indtmp].num;
}

int get_tmp(){	
	return temporales[indtmp].num;
}

#endif
