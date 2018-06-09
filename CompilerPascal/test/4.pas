    Program ex11;   
        const a = 1;
              b = 2;
              c = 1.0;
        var      
        		//a, b, c: real; //报错重定义 
            x, y:integer;
            z:char;
            outer:integer; 
            rec: record
            		Month: INTeger;
            		Day: integer;
            		Year: Integer;
            end;
        Function max(x: integer;y:integer) : integer;
		        Begin
		           x := outer;
		           y := 1;
		        End;  
        Begin 
        	x := 1;
        	a := 1;
        	z := 'a';       
        	x := abs(1);	//内置函数      
        	max(1,1);
        End.