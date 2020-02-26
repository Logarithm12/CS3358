a4t: sequenceTest.o
	g++ sequenceTest.o -o a4t
sequenceTest.o: sequenceTest.cpp sequence.template sequence.h
	g++ -Wall -ansi -pedantic -std=c++11 -c sequenceTest.cpp

test:
	./a4t auto < a4test.in > a4test.out
clean:
	@rm -rf sequence.o sequenceTest.o
cleanall:
	@rm -rf sequence.o sequenceTest.o a4t

