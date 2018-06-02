Program ex11;  
    var m, n:real;
        x, y, i, sum:integer;
        a:array [1..24] of integer;  
    Begin
        if y < 0 then 
            Begin
                x := 1;
            End
        else x := 2;


        For i := 1 to 100 do
        Begin
            y := (y+i)*2 div 3;
        End;

        while  i < 100  do
        Begin                
           y := y+i;
        End;


        repeat
            Begin
                x := x+1;
            End
        until x > 1; 

        case  x  of        
            1:  y:=0;      
            2:  y:=1;
        end;  

    End.