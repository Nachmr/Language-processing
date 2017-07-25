#include "dec_dat"
#include "dec_fun"
#include <stdio.h>

int iteraciones_1;
int comienzo_1;

int iteraciones_2;
int comienzo_2;

lista_entero sucesion_2;
lista_entero sucesion_1;

lista_entero sucesion_producto;
lista_entero sucesion_suma;
lista_entero sucesion_cat;

int multiplicar;
int sumar;

int i;

int main(){

printf("%s","Introduce la posicion de comienzo de la lista 1: ");
scanf("%i",&comienzo_1);
printf("%s","Introduce el numero de iteraciones de la lista 1: ");
scanf("%i",&iteraciones_1);
printf("%s","Introduce la posicion de comienzo de la lista 2: ");
scanf("%i",&comienzo_2);
printf("%s","Introduce el numero de iteraciones de la lista 2: ");
scanf("%i",&iteraciones_2);

sucesion_1 = SucesionFibonacci(comienzo_1, iteraciones_1);

sucesion_2 = SucesionFibonacci(comienzo_2, iteraciones_2);
lista_entero tmp15;
inicializa_entero(&tmp15);
tmp15 = concatenar_ll_entero(&sucesion_1, &sucesion_2);
sucesion_cat = tmp15;
printf("%s","Sucesion 1: \n\t");

i = 0;
etiqueta4:;int tmp16;
tmp16 = longitud_entero(&sucesion_1);

if(!(i < tmp16))goto etiqueta5;

int tmp17;
tmp17 = elemento_pos_li_entero(&sucesion_1, i);printf("%d",tmp17);
printf("%s"," ");
i++;goto etiqueta4;
etiqueta5:;

printf("%s","\nSucesion 2: \n\t");

i = 0;
etiqueta6:;int tmp18;
tmp18 = longitud_entero(&sucesion_2);

if(!(i < tmp18))goto etiqueta7;

int tmp19;
tmp19 = elemento_pos_li_entero(&sucesion_2, i);printf("%d",tmp19);
printf("%s"," ");
i++;goto etiqueta6;
etiqueta7:;

printf("%s","\nSucesion Concatenada: \n\t");

i = 0;
etiqueta8:;int tmp20;
tmp20 = longitud_entero(&sucesion_cat);

if(!(i < tmp20))goto etiqueta9;

int tmp21;
tmp21 = elemento_pos_li_entero(&sucesion_cat, i);printf("%d",tmp21);
printf("%s"," ");
i++;goto etiqueta8;
etiqueta9:;

printf("%s","\nIntroduce un numero para sumar: ");
scanf("%i",&sumar);
lista_entero tmp22;
inicializa_entero(&tmp22);
tmp22 = suma_li_entero(&sucesion_cat, sumar);

sucesion_suma = tmp22;
printf("%s","La sucesion con la suma es: \n\t");

i = 0;
etiqueta10:;int tmp23;
tmp23 = longitud_entero(&sucesion_suma);

if(!(i < tmp23))goto etiqueta11;

int tmp24;
tmp24 = elemento_pos_li_entero(&sucesion_suma, i);printf("%d",tmp24);
printf("%s"," ");
i++;goto etiqueta10;
etiqueta11:;

printf("%s","\nIntroduce un numero para multiplicar: ");
scanf("%i",&multiplicar);
lista_entero tmp25;
inicializa_entero(&tmp25);
tmp25 = producto_li_entero(&sucesion_cat, multiplicar);

sucesion_producto = tmp25;
printf("%s","La sucesion con el producto es: \n\t");

i = 0;
etiqueta12:;int tmp26;
tmp26 = longitud_entero(&sucesion_producto);

if(!(i < tmp26))goto etiqueta13;

int tmp27;
tmp27 = elemento_pos_li_entero(&sucesion_producto, i);printf("%d",tmp27);
printf("%s"," ");
i++;goto etiqueta12;
etiqueta13:;

printf("%s","\n");
return 0;
}
