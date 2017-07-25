PROGRAM Prueba4
BEGIN
	VAR
		a, b, c, d, n, i 	: INTEGER;
		cadena 		: CHAR;
		b1, b2 		: BOOLEAN;
	ENDVAR
	
	FUNCTION FuncionA (x,w : INTEGER;) : INTEGER;
	BEGIN
		VAR 
			A1 : INTEGER;
		ENDVAR
		FUNCTION FuncionB () : INTEGER;
		BEGIN
			
			PRINT "Dentro de B\n";
			PRINT "En B conocemos A1: ", A1, "\n";
			RETURN 4;
		END
		PRINT x,"\n";
		PRINT w,"\n";
		A1 := 3;
		
		a := FuncionB();
	
		PRINT "El resultado de B es: ", a, "\n";

		RETURN x;
	END

	c := FuncionA(a+4*b,b);
	PRINT "a sale de A con el valor: ", a, "\n";
	a := 0;
	b := 0;
	c := 0;
	d := 0;
	
	PRINT "Introduce un numero: ";
	SCAN n;
	
	FOR i:=0 TO n DO
	BEGIN
		PRINT "Hola mundo ", i;
		PRINT "\n";
	END

	PRINT "Dime tu inicial: ";
	SCAN cadena;

	PRINT "\n";
	PRINT "Hola ", cadena, "!";

	b1 := TRUE;
	b2 := FALSE;

	IF (b1 <> b2) THEN
		PRINT "Son distintos\n";
	ELSE
		PRINT "Son iguales\n";


	
END
