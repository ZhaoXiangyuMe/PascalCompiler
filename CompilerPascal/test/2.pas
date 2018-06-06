Program ex11;
    // this is const part 
    const con = 1.0;
    var x, y, i:integer;
    Begin
    	x := 1;
        For i := 1 to 100 do
        Begin
            y := (y+i) * 2;
            // this another test 
            y := 1.0;
            con := 1;
        End;
    End.
    
