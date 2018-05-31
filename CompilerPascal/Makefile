objects = main.o semant.o env.o types.o translate.o tree.o prabsyn.o temp.o frame.o symbol.o table.o absyn.o util.o errormsg.o y.tab.o lex.yy.o 
pascalc: $(objects)
	cc -o pascalc -g $(objects)


main.o: 
	cc -g -c main.c

semant.o: semant.c semant.h
	cc -g -c semant.c

env.o: env.c env.h
	cc -g -c env.c

types.o: types.c types.h
	cc -g -c types.c

translate.o: translate.c  translate.h
	cc -g -c translate.c 

tree.o: tree.c tree.h
	cc -g -c tree.c

temp.o:	temp.c temp.h
	cc -g -c temp.c

frame.o: mipsframe.c frame.h
	cc -o frame.o -g -c mipsframe.c

symbol.o: symbol.c symbol.h
	cc -g -c symbol.c

table.o: table.c table.h
	cc -g -c table.c

absyn.o: absyn.c absyn.h
	cc -g -c absyn.c

util.o: util.c util.h
	cc -g -c util.c

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c
y.tab.c: Pascal.y
	yacc -dv Pascal.y

lex.yy.o: lex.yy.c symbol.h absyn.h y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c
lex.yy.c: Pascal.l
	lex Pascal.l


prabsyn.o: prabsyn.c prabsyn.h
	cc -g -c prabsyn.c

clean: 
	rm -f *.o