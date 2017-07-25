PROGRAM fibonacci
BEGIN
	VAR
		comienzo_1, iteraciones_1 : INTEGER;
		comienzo_2, iteraciones_2 : INTEGER;
		sucesion_1, sucesion_2 : LIST OF INTEGER;
		sucesion_cat, sucesion_suma, sucesion_producto : LIST OF INTEGER;
		sumar, multiplicar : INTEGER;
		i : INTEGER;
	ENDVAR
	
	FUNCTION SucesionFibonacci (comienzo, n_iteraciones : INTEGER;) : LIST OF INTEGER;
	BEGIN
		VAR
			i,va : INTEGER;
			suc : LIST OF INTEGER;
		ENDVAR
		
		FUNCTION IteracionFibonacci (n1, n2 : INTEGER;) : INTEGER;
		BEGIN
			VAR
				a,vb : INTEGER;
			ENDVAR
			va := 20;
			PRINT "Valor va" , va;
			a := n1 + n2;
			RETURN a;
		END
		
		suc := [1, 1];
		
		
		PRINT comienzo, "\n";
		FOR i := 1 TO comienzo DO
		BEGIN
			VAR
				resultado : INTEGER;
			ENDVAR
			
			resultado := IteracionFibonacci (suc @ 1, suc @ 0);

			suc := suc ++ (suc @ 0) @ 1;
			suc := suc ++ resultado @ 0;
		END

		FOR i := 1 TO n_iteraciones DO
		BEGIN
			VAR
				resultado : INTEGER;
			ENDVAR
			
			resultado := IteracionFibonacci (suc @ (#suc - 1), suc @ (#suc - 2));
			
			suc := suc ++ resultado @ (#suc);
		END
		RETURN suc;
	END
	
	PRINT "Introduce la posicion de comienzo de la lista 1: ";
	SCAN comienzo_1;
	PRINT "Introduce el numero de iteraciones de la lista 1: ";
	SCAN iteraciones_1;
	
	PRINT "Introduce la posicion de comienzo de la lista 2: ";
	SCAN comienzo_2;
	PRINT "Introduce el numero de iteraciones de la lista 2: ";
	SCAN iteraciones_2;
	
	sucesion_1 := SucesionFibonacci (comienzo_1, iteraciones_1);
	
	sucesion_2 := SucesionFibonacci (comienzo_2, iteraciones_2);
	
	sucesion_cat := sucesion_1 ** sucesion_2;
	
	PRINT "Sucesion 1: \n\t";
	FOR i := 0 TO #sucesion_1 DO
		PRINT sucesion_1 @ i, " ";
		
	PRINT "\nSucesion 2: \n\t";
	FOR i := 0 TO #sucesion_2 DO
		PRINT sucesion_2 @ i, " ";
		
	PRINT "\nSucesion Concatenada: \n\t";
	FOR i := 0 TO #sucesion_cat DO
		PRINT sucesion_cat @ i, " ";
		
		
	PRINT "\nIntroduce un numero para sumar: ";
	SCAN sumar;
	
	sucesion_suma := sucesion_cat + sumar;
	
	PRINT "La sucesion con la suma es: \n\t";
	FOR i := 0 TO #sucesion_suma DO
		PRINT sucesion_suma @ i, " ";
		
	PRINT "\nIntroduce un numero para multiplicar: ";
	SCAN multiplicar;
	
	sucesion_producto :=  sucesion_cat * multiplicar;
	
	PRINT "La sucesion con el producto es: \n\t";
	FOR i := 0 TO #sucesion_producto DO
		PRINT sucesion_producto @ i, " ";
		
	PRINT "\n";
	
END
