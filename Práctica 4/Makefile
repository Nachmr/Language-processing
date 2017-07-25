.SUFFIXES:
Practica4: main.o y.tab.o
	gcc -o Practica4 main.o y.tab.o

y.tab.o: y.tab.c
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

y.tab.c: Practica4.y lex.yy.c tabla_simbolos.h
	bison -o y.tab.c Practica4.y

lex.yy.c: lenguaje.l
	flex lenguaje.l

limpia:
	rm -f Practica4 main.o y.tab.o y.tab.c lex.yy.c

todo:
	make limpia
	make Practica4
