PROGRAM fibonacci
BEGIN
	VAR
		iteraciones : INTEGER;
		sucesion : LIST OF INTEGER;
		i : INTEGER;
	ENDVAR
	
	FUNCTION SucesionFibonacci (n_iteraciones : INTEGER;) : LIST OF INTEGER;
	BEGIN
		VAR
			i : INTEGER;
			suc : LIST OF INTEGER;
		ENDVAR
		
		FUNCTION IteracionFibonacci (n1, n2 : INTEGER;) : INTEGER;
		BEGIN
			VAR
				a : INTEGER;
			ENDVAR
			a := n1 + n2;
			RETURN a;
		END
		
		suc := [1, 1];
		
		i := 1;
		WHILE i <= n_iteraciones DO
		BEGIN
			VAR
				resultado : INTEGER;
			ENDVAR
			
			resultado := IteracionFibonacci (suc @ (#suc - 1), suc @ (#suc - 2));
			
			suc := suc ++ resultado @ (#suc);
			i := i + 1;
		END
		RETURN suc;
	END
	
	PRINT "Introduce el numero de iteraciones: ";
	SCAN iteraciones;
	
	sucesion := SucesionFibonacci (iteraciones);
	
	PRINT #sucesion, "\n";
	
	FOR i := 0 TO #sucesion DO
		PRINT sucesion @ i, " ";
	
END
