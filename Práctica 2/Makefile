lexico: lex.yy.o
	gcc -o lexico lex.yy.o

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: lexico.lex
	flex -8 -l -i lexico.lex

clean:
	rm -f lexico lex.yy.o lex.yy.c
