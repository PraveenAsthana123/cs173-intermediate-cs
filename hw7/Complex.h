/* Name: Farhan Zaki
   Date: 03/14/2015
   HW6: Creating a class for Complex numbers.
*/

//Complex.h

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;

class Complex
{
	//Private Variables
	private:

	float a; // Stores the real part of the complex number
	float b; // Stores the imaginary part of the Complex number

	public:

	//Constructs a new Complex Object
	//Pre: None:
	//Post: Creates the Complex object with default values for a and b.
	Complex();

	// Copy constructor for Complex object.
	// Pre:  source is a Complex
	// Post: Creates a Complex object with same a and b as source
	Complex(const Complex &source);
	
	int getReal() const { return a;};
	int getImag() const { return b;};
	
	Complex(float a,float b);

	//Assignment operator
	//Pre: this and source are rational objects
	//Post: Assigns the a,b of source to this.
	void operator=(const Complex &source);

	//+ operator
	//Pre: this and source are rational objects
	//Post: Returns the comlex sum of this and source
	Complex operator+(const Complex &other);


	//+ operator
	//Pre: A float x and Complex this.
	//Post: Returns the comlex sum this and x.
	Complex operator+(float x);

	//- operator
	//Pre: this and source are rational objects
	//Post: Returns the comlex difference of this and source
	Complex operator-(const Complex &other);

	//- operator
	//Pre: A float x and Complex this.
	//Post: Returns the comlex difference this and x.
	Complex operator-(float x);
	
	// Division operator
	//Pre: this and source are rational objects
	//Post: Returns the comlex division of this and source
	Complex operator/(const Complex &other);

	// Division operator
	//Pre: A float x and Complex this.
	//Post: Returns the comlex division this and x.
	Complex operator/(float x);
	
	//* operator
	//Pre: this and source are rational objects
	//Post: Returns the comlex multiplication of this and source
	Complex operator*(const Complex &other);

	//* operator
	//Pre: A float x and Complex this.
	//Post: Returns the multiplication sum this and x.
	Complex operator*(float x);
	
	//Conjugate Operator.
	//Pre: None
	//Post: returns the conjugate of the complex number.
	Complex operator~();

	//^ operator
	//Pre: A float x and Complex this.
	//Post: Returns the comlex number raised to y.
	Complex operator^(int y);
	
	string str();
	
	
};

ostream& operator<<(ostream &os, Complex &c);

#endif
	

