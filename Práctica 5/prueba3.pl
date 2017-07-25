PROGRAM descomposicion2
BEGIN
	VAR
		n, curr, ultim, cuenta, primero : INTEGER;
	ENDVAR
	
	n := 2;
	ultim := 0;
	cuenta := 0;
	primero := 1;
	
	PRINT "Introduce numero : ";
	SCAN n;
	PRINT n, " == ";
	curr := 2;
	
	WHILE curr <= n DO
	BEGIN
		VAR
			d : INTEGER;
		ENDVAR
		
		d := n/curr;
		
		IF d * curr = n THEN
		BEGIN
			IF curr <> ultim THEN
			BEGIN
				ultim := curr ;
				cuenta := 1 ;
			END
			ELSE
				cuenta := cuenta + 1;
				
			n := n/curr;
		END
		ELSE
		BEGIN
			IF cuenta > 0 THEN
			BEGIN
				IF primero = 0 THEN
					PRINT " *";
				
				primero := 0;
				PRINT " ", curr;
				
				IF cuenta > 1 THEN
					PRINT "^", cuenta;
			END
			
			curr := curr + 1;
			cuenta := 0;
		END

	END
	
	IF cuenta > 0 THEN
	BEGIN
		IF primero = 0 THEN
			PRINT " *";
		
		primero := 0;
		PRINT " ", curr;
		
		IF cuenta > 1 THEN
			PRINT "^", cuenta;
	END
	
	PRINT "\n";
	
END
