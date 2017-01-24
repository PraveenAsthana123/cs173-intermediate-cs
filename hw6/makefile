all: Complex.o test_complex.o 
	g++ Complex.o test_complex.o -o test_complex

Complex.o:Complex.cpp Complex.h 
	g++ -c Complex.cpp

test_complex.o: test_complex.cpp 
	g++ -c test_complex.cpp

clean: rm test_complex *.o
