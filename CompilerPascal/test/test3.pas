Program ex11;  
    var layer0:integer;
        x, y:integer;
    Procedure link(x,y: integer);
        Var layer1 : integer;
        function linktest(x:integer):integer;
            var layer2: integer;
            Begin
                layer2 := layer0;
                layer2 := layer1;
            End;
        Begin     
            layer1 := layer0;     
        End;   
    Function max(x, y : integer) : integer;
        Begin
            if x > y then 
                x := x
            else x := y;           
        End;  
    Begin 
        x := max(x, y);
        link(x, y);
    End.