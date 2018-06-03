Program ex11;  
    var c:char;
        m, n:real;
        x, y, i, sum:integer;
        a:array [1..24] of integer;  
    Procedure swap (x,y: integer);
        Var t : integer;
            m : char;
        function linktest(x:integer):char;
            var mc: char;
            Begin
                mc := c;
            End;
        Begin     
            m := c;                         
            t := x;       
            x := y;
            y := t;       
        End;   
    Function max(x, y : integer) : integer;
        Begin
            if x > y then 
                x := x
            else x := y;           
        End;  
    Begin
        x := max(x, y);
        swap(x, y);
        if y < 0 then 
            Begin
                x := 1;
            End
        else x := 2;


        For i := 1 to 100 do
        Begin
            y := (y+i) * 2;
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