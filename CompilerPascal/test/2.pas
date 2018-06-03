Program ex11;
    const con = 1;
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
                max := x
            else max := y;           
        End;  
    Begin
        x := x div y;
        con := 2;
        y := 1;
    End.