// Makefile

all: Rectangle.o RectangleExample.o
	g++ Rectangle.o RectangleExample.o -o RectangleExample

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp

RectangleExample.o: RectangleExample.cpp
	g++ -c RectangleExample.cpp

clean:
	rm RectangleExample *.o
