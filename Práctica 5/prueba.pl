PROGRAM descomposicion1
BEGIN
	VAR
		n, curr : INTEGER;
		
	ENDVAR
	
	PRINT "Introduce numero ---->: ";
	SCAN n;
	PRINT n, " == ";
	curr := 2;
	WHILE curr <= n DO
		BEGIN
			VAR
				d : INTEGER;
			ENDVAR
			
			d := n/ curr;
			IF d*curr = n THEN
				BEGIN
					PRINT "* ", curr, " ";
					n := n / curr;
				END
			ELSE
				curr := curr + 1;
				
		END
	PRINT "\n";
END
			
