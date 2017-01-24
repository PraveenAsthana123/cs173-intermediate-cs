// test_rational.cpp
// Unit tests for Rational class (incomplete)

#include <cassert>
#include "rational.h"

void testConstructorOneInt()
{
	Rational r(-3);
	assert(r.str() == "-3/1");
}
		
void testConstructorTwoInt()
{
	Rational r(6, 8);
	assert(r.str() == "3/4");
}

void testCopyConstructor()
{
    Rational r(2, 3);
    Rational r2(r);
    assert(r2.str() == "2/3");
}

void testAssignment()
{
    Rational r(3, 7);
    Rational r2;
    r2 = r;
    assert(r2.str() == "3/7");
}
		
void testMul()
{
	Rational r1(2, 3);
	Rational r2(3, 4);
	Rational r3(r1 * r2);
	assert(r3.str() == "1/2");
	
	Rational r4;
	Rational r5(r1 * r4);
	assert(r5.str() == "0/1");
}

void testDiv()
{
	Rational r1(1, 2);
	Rational r2(3, 4);
	Rational r3(r1 / r2);
	assert(r3.str() == "2/3");
}

void testLess()
{
	Rational r1(1, 2);
	Rational r2(3, 4);
	assert(r1 < r2);
}
		
int main()
{
	testConstructorOneInt();
	testConstructorTwoInt();
	testCopyConstructor();
	testAssignment();
	testMul();
	testDiv();
	testLess();
	
	return 0;
}
