/* Name: Farhan Zaki
   Date: 03/14/2015
   HW6: Creating a class for Complex numbers.
*/

//Complex.cpp

#include <stdlib.h>
#include <iostream>
#include "Complex.h"
#include<stdio.h>

using namespace std;

//Default Constructor
Complex::Complex(){

a=0;
b=0;
}
//Constructor.
Complex::Complex(float r,float i){

	a=r;
	b=i;

}
//Copy Constructor
Complex::Complex(const Complex &source)
{
	a=source.a;
	b=source.b;
}
// Assignment Operator
void Complex::operator=(const Complex &source)
{
	a=source.a;
	b=source.b;
}
//Addition Operator between two complex numbers
Complex Complex::operator+(const Complex &other)
{
	float r = a+other.a;
	float i=b+other.b;
	return Complex(r,i);
}
//Addition Operator between a Complex number and a float.
Complex Complex::operator+(float x)
{
	float r= a+x;
	float i=b;
	return Complex(r,i);
}
//Subtractin operator between two Complex numbers
Complex Complex::operator-(const Complex &other)
{
	float r= a-other.a;
	float i=b-other.b;
	return Complex(r,i);
}
//Subtraction operator between a complex number and a float
Complex Complex::operator-(float x)
{
	float r=a-x;
	float i=b;
	return Complex(r,i);
}
//Multiplication Operator between two complex numbers
Complex Complex::operator*(const Complex &other)
{
	
	float r=(a*other.a)+(-1*(b*other.b));
	float i=(a*other.b + b*other.a);
	return Complex(r,i);

}
//Multiplication operator bewteen a compelex number and a float
Complex Complex::operator*(float x)
{
	float r=a*x;
	float i=b*x;
	return Complex(r,i);
}
// Division Operator between a Complex number and float.
Complex Complex::operator/(float x)
{
	
	float r=a/x;
	float i=b/x;

	return Complex(r,i);
}
//Division Operator betwee two complex numbers.
Complex Complex::operator/(const Complex &other)
{
	float r=((a*other.a)+(b*other.b))/ ((other.a*other.a)+(other.b*other.b));
	float i=(-(a*other.b)+(b*other.a)) / ((other.a*other.a)+(other.b*other.b));

	return Complex(r,i);
 

}
//Conjugate Operator
Complex Complex::operator~()
{

	return Complex(a,-b);
}
//Exponential Operator.
Complex Complex::operator^(int y)
{	
	float r=a;
	float i=b;
	float  tr,ti;
	if(y==0)
	  return Complex(1,0);
else if(y==1)
	return Complex(r,i);
else if(y>1){

	while(y>1){
	y--;
	tr=a*r-b*i;
	ti=r*b+i*a;
	r=tr;
	i=ti;
	}
	}
else if (y==-1){
	int t1=r;
	r=r/(r*r+i*i);
	i=-i/(t1*t1+i*i);
	}
else if (y<-1){

	while(y<-1){
	y++;
	tr=a*r-b*i;
	ti=r*b+i*a;
	r=tr;
	i=ti;
	}
	int t2=r;
	r=r/(r*r+i*i);
	i=-i/(t2*t2+i*i);
	}
	

return Complex(r,i);
}
	
	
	
// Formatting the complex number as a string.
string Complex::str()
{
	char temp[25];
	
	if(a==0 && b>0)
	  sprintf(temp,"%.2fi",b);
	else if(b==0)
	  sprintf(temp,"%.2f",a);	
	else if(b>0)
	{
	if(b==1)
	  sprintf(temp,"%.2f+i",a);
	else
	  sprintf(temp,"%.2f+%.2fi",a,b);
	}
	else
	{
	  if(b==-1)
		sprintf(temp,"%.2f-i",a);
	else
		sprintf(temp,"%.2f%.2fi",a,b);
	}
	

	return string(temp);

}
// defining the cout<< operator of the ostream class.
ostream& operator<<(ostream &os,Complex &c)
{
	os<<c.str();
	return os;

}





