SHELL := /bin/bash

.SUFFIXES:

sintactico:y.tab.o main.o  
	gcc -o sintactico main.o y.tab.o
	
y.tab.o: msj.err y.tab2.c
	gcc -c y.tab.c -o y.tab.o 
	
main.o: main.c
	gcc -c main.c
	
y.tab.c y.output: sintactico.y lex.yy.c
	bison -ydvo y.tab.c sintactico.y
	
lex.yy.c: lexico.lex
	flex lexico.lex
	
y.tab2.c: y.tab.c mes2
	./mes2 < y.tab.c > y.tab2.c
	mv y.tab.c y.tab3.c
	mv y.tab2.c y.tab.c

msj.err: y.output mes
	$(shell ./mes < y.output > msj2.err)
	sed 's#.*char#char#g' msj2.err > msj.err

clean:
	rm -f sintactico main.o y.tab.o y.tab.c lex.yy.c msj.err msj2.err y.tab2.c y.output
	
todo:
	make clean
	make sintactico
