PROGRAM prueba
BEGIN
	VAR
		ve : INTEGER;
		vf : REAL;
		vc : CHAR;
		vl : BOOLEAN;
		
		pe : LIST OF INTEGER;
		pe2 : LIST OF INTEGER;
		pf, pf2 : LIST OF REAL;
		pc, pc2 : LIST OF CHAR;
		pl : LIST OF BOOLEAN;
	ENDVAR
	
	FUNCTION FuncionA (a1 : INTEGER; a2 : REAL ; a3 : CHAR;) : INTEGER;
	BEGIN
		VAR
			x1,x2 : REAL;
		ENDVAR

		FUNCTION FuncionB (b1 : CHAR; b2 : BOOLEAN;) : CHAR;
		BEGIN
			VAR
				xf,x2 : REAL;
			ENDVAR

			FUNCTION FuncionC (c1 : BOOLEAN; c2 : INTEGER;) : REAL;
			BEGIN
				VAR
					x1 : REAL;
					b5 : BOOLEAN;
				ENDVAR

				x1 := 1.3;

				ve := 3;
				vf := FuncionC(vl,FuncionA(2*4,vf,'a'));

				b5 := TRUE AND FALSE;

				IF(c2>10) THEN
					c2 := c2-1;
				ELSE
					x1 := 3.1;

				RETURN x1;
			END

	
			xf := FuncionC(TRUE, 10);
			x2 := xf*(FuncionC(FALSE,1) - FuncionC(TRUE,23))/10.0;

			WHILE((x2*FuncionC(FALSE,1)-xf) < 10.0) DO
				x2 := x2*xf;
				
			FOR c2 := 0 TO 10 DO
				x1 := x1 + 1.0;
		END

		FUNCTION FuncionD (d1 : REAL;) : REAL;
		BEGIN
			VAR
				dato : CHAR;
				valor: INTEGER;
			ENDVAR

			FUNCTION FuncionE (e1,e2 : CHAR;) : CHAR;
			BEGIN
				PRINT "Introduzca dos caracteres: ";
				SCAN e1;
				SCAN e2;
				

				IF(e1 = 'a') THEN
					RETURN e1;
				ELSE
					IF(e1 = 'b') THEN
						RETURN e2;
					ELSE
						RETURN ' ';
			END
		
			SCAN valor;
			
			IF((d1 > 0.0)) THEN
			BEGIN
				VAR
					dato: INTEGER;
				ENDVAR

				dato := 2;
				dato := valor*20/dato;
			END
			ELSE
			BEGIN
				valor := valor * 100;
				d1 := d1 / 1000.0;
	
			END

			RETURN d1;
		END
		
		pe := [10, 4, 3];
		pf := [10.0, 10.0];
		pc := ['#'];
		
		pe := (pe ++ ve @ (pe@2))*ve;
		pe2 := pe ** pe;
		PRINT pe@0;
		pe>>;
		$pe;
		
		pe := ve + pe;

		IF((#pe) = 10) THEN
			PRINT "La lista contiene un 10\n"; 
		ELSE
			PRINT "La lista no contiene un 10\n";
		
	END
	
END
