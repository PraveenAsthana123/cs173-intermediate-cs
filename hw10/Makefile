all: Test

Test: Test.o
	g++ -o Test Test.o

Test.o: Test.cpp List.h List.cpp
	g++ -c Test.cpp
