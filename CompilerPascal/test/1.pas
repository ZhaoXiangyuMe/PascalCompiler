Program ex11;
    var outer:integer; 
        rec: record
            Month: Byte;
            Day: Byte;
            Year: Integer;
        end;
    Function max(x: integer;y:integer) : integer;
        Begin
           x := outer;
           y := 1;
        End;  
    Begin
       outer := 0;
    End.