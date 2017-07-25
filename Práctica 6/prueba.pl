PROGRAM Listas1
BEGIN
	VAR
		l1, l2, l3 : LIST OF BOOLEAN;
		e1, e2 : BOOLEAN;
		
	ENDVAR
	
	l3 := [TRUE, TRUE, FALSE, TRUE];
	PRINT ?l3, "\n";
	l3>>;
	PRINT ?l3, "\n";
	l3>>;
	PRINT ?l3, "\n";
	l3<<;
	PRINT ?l3, "\n";
	$l3;
	PRINT ?l3, "\n";

END
			
