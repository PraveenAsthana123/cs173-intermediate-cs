// rational.h

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
 private:
	int num, den;
	
 public:
	
	// Constructs a new Rational object.
	// Pre:  num and den are integers
	// Post: Creates the Rational object with value num / den
	Rational(int n = 0, int d = 1);
	
	// Copy constructor for Rational object.
	// Pre:  source is a Rational
	// Post: Creates a Rational object with same num / den as source
	Rational(const Rational &source);
	
	// Returns the numerator of the object.
	// Pre:  None
	// Post: Returns the numerator of this
	int getNum() const { return num; };
	
	// Returns the denominator of the object.
	// Pre:  None
	// Post: Returns the denominator of this
	int getDenom() const { return den; };
		
	// assignment operator
	// Pre:  this and source are Rational objects
	// Post: assigns num / den of source to this
	void operator=(const Rational &source);	
	
	// + operator	
	// Pre:  this and other are Rational objects
	// Post: Returns the Rational sum this + other
	Rational operator+(const Rational& other);
	
	// - operator
	// Pre:  this and other are Rational objects
	// Post: Returns the Rational difference this - other
	Rational operator-(const Rational& other);
	
	//	* operator
	// Pre:  this and other are Rational objects
	// Post: Returns the Rational product this * other
	Rational operator*(const Rational& other);
	
	// / operator
	// Pre:  this and other are Rational objects
	// Post: Returns the Rational quotient this / other
	Rational operator/(const Rational& other);
	
	// < operator
	// Pre:  this and other are Rational objects
	// Post: Returns this < other
	bool operator<(const Rational& other);
	
	// > operator
	// Pre:  this and other are Rational objects
	// Post: Returns this > other
	bool operator>(const Rational& other);
	
	// <= operator
	// Pre:  this and other are Rational objects
	// Post: Returns this <= other
	bool operator<=(const Rational& other);
	
	// >= operator
	// Pre:  this and other are Rational objects
	// Post: Returns this >= other
	bool operator>=(const Rational& other);
	
	// == operator
	// Pre:  this and other are Rational objects
	// Post: Returns this == other
	bool operator==(const Rational& other);
	
	// != operator
	// Pre:  this and other are Rational objects
	// Post: Returns this != other
	bool operator!=(const Rational& other);
	
	// Convert rational to a string representation.
	// Pre:  None
	// Post: Returns a string representation of the Rational object
	string str();
};

ostream& operator<<(ostream &os, Rational &r);

#endif
