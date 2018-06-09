    Program ex11;   
        const a = 1;
              b = 2;
              c = 1.0;
        var      
        		//a, b, c: real; //报错重定义 
            x, y, i:integer;
            z:char;
            outer:integer; 
            k:boolean;
            rec: record						//record定义测试
            		Month: INTeger;
            		Day: integer;
            		Year: Integer;
            end;
            ar:array [1..24] of integer; 	//array定义测试
            tem:1...10;										//子界类型测试
        Function max(x: integer;y:integer) : integer;		//function定义测试
		        Begin
		           x := outer;
		           y := 1;
		           max := 1;
		        End;  
        Begin 
        	z := 'a';       
        	x := abs(1);	//内置函数      
        	x := max(1,1);	//用户自定义函数
        	rec.Month := 1;	//测试record
        	ar[0] := 1;			//数组测试        	
        	x := 1;
        	a := 1;
        	if(x*x = a) k:=odd(11);	//if测试
        	
        	For i := 1 to 100 do		//for循环测试
        	Begin
        	    y := (y+i) * 2;
        	End;
        	
        	while  i < 100  do		//while循环测试
        	Begin                
        	   y := y+i;
        	End;
        	repeat							//repeat测试
        	    Begin
        	        x := x+1;
        	    End
        	until x > 1; 
        	{11    //注释测试
        	111}
        	case  x  of        //case测试
        	    1:  y:=0;      
        	    2:  y:=1;
        	end;  
        End.