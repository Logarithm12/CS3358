a2: IntSet.o Assign02.o
	g++ IntSet.o Assign02.o -o a2
IntSet.o: IntSet.cpp IntSet.h
	g++ -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter -Wfloat-equal -pedantic -ansi -std=c++14 -c IntSet.cpp
Assign02.o: Assign02.cpp IntSet.h
	g++ -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast -Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter -Wfloat-equal -pedantic -ansi -std=c++14 -c Assign02.cpp
cleanall:
	@rm a2 *.o
test:
	./a2 auto < a2test.in > a2test.out
