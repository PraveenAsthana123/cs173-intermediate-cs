all: test_set

test_set: test_set.o
	g++ -o test_set test_set.o

test_set.o: set.cpp set.h test_set.cpp
	g++ -c test_set.cpp

clean:
	rm *.o test_set
