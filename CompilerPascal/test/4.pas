    Program ex11;   
        const a = 1;
              b = 2;
              c = 1.0;
        var      
        		//a, b, c: real; //�����ض��� 
            x, y, i:integer;
            z:char;
            outer:integer; 
            k:boolean;
            rec: record						//record�������
            		Month: INTeger;
            		Day: integer;
            		Year: Integer;
            end;
            ar:array [1..24] of integer; 	//array�������
            tem:1...10;										//�ӽ����Ͳ���
        Function max(x: integer;y:integer) : integer;		//function�������
		        Begin
		           x := outer;
		           y := 1;
		           max := 1;
		        End;  
        Begin 
        	z := 'a';       
        	x := abs(1);	//���ú���      
        	x := max(1,1);	//�û��Զ��庯��
        	rec.Month := 1;	//����record
        	ar[0] := 1;			//�������        	
        	x := 1;
        	a := 1;
        	if(x*x = a) k:=odd(11);	//if����
        	
        	For i := 1 to 100 do		//forѭ������
        	Begin
        	    y := (y+i) * 2;
        	End;
        	
        	while  i < 100  do		//whileѭ������
        	Begin                
        	   y := y+i;
        	End;
        	repeat							//repeat����
        	    Begin
        	        x := x+1;
        	    End
        	until x > 1; 
        	{11    //ע�Ͳ���
        	111}
        	case  x  of        //case����
        	    1:  y:=0;      
        	    2:  y:=1;
        	end;  
        End.