    Program ex11;   
        const a = 1;
              b = 2;
              c = 1.0;      
        type 
            Temperatures = array [1..24] of Integer;
            Date = record
                Month: Byte;
                Day: Byte;
                Year: Integer;
            end;
        var a, b, c:real;
            x, y:integer;
        Procedure Swap (var x,y: integer);
            Var t  : integer;
            Begin                              
                x := 2;       
                y := 3;       
            End;
        Function max(x1,x2 : integer) : integer;
            Begin
                x1 := 2;       
                x2 := 3; 
            End;
        Begin
            Temperatures[2] := 2;
            Date.Month := 1;

            Swap(a,b);
            c := max(1,2);

            if x and (y < 0) then 
                Begin
                    x := 1;
                End
            else inc(y);

            For a := 1 to 100 do
            Begin
                S := S+a;
            End;

            while  d mod b = 0  do
            Begin                
                inc(d,a);
                S := 1;
            End;

            repeat
                Begin
                    x := 1;
                End
            until x > 1;

            case  nn  of        
                1:  dm:=a;      
                2:  dm:=b;
                y:  dm:=c;
            end;

            x := 1;
        End.