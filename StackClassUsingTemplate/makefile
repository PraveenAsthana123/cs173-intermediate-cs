all: match

match: match.o
	g++ match.o -o match

match.o: stack.cpp stack.h match.cpp
	g++ -c match.cpp -o match.o

clean:
	rm *.o match
