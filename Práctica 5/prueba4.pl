PROGRAM Prueba4
BEGIN
	VAR
		a, b, c, d, n, i 	: INTEGER;
		cadena 		: CHAR;
		b1, b2 		: BOOLEAN;
	ENDVAR
	
	FUNCTION FuncionA (x,w : INTEGER;) : INTEGER;
	BEGIN
		FUNCTION FuncionB () : INTEGER;
		BEGIN
			RETURN 4;
		END
		PRINT x,"\n";
		PRINT w,"\n";

		RETURN x;
	END
	
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


	a := FuncionA(a+4*b,b);
END
