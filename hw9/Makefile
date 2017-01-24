all: list.o test_list.o
	g++ list.o test_list.o -o test_list

list.o:list.cpp list.h
	g++ -c list.cpp

test_list.o: test_list.cpp
	g++ -c test_list.cpp

clean: rm test_list *.o
