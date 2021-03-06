// Rectangle.cpp

#include <iostream>
using namespace std;
#include "Rectangle.h"

int main()
{
    // constructors
    Rectangle r1(3, 4);  // create a rectangle of height 3 and width 4
    Rectangle r2(1, 2);  // create a rectangle of height 1 and width 2

    // accessors
    cout << "r1 has dimensions " <<  r1.getHeight() << " X " << r1.getWidth() << endl;
  
    // modififer
    r2.setHeight(5);
    r2.setWidth(6);
    cout << "r2 now has dimensions " <<  r2.getHeight() << " X " << r2.getWidth() << endl;

    // other methods
    cout << "The area of r1 is " << r1.area() << endl;
    cout << "The perimeter of r2 is " << r2.perimeter() << endl;
    
    r1.draw(); // this should print the rectangle as a grid of *s
    /* e.g., for r1 this should print the following:
    ****
    ****
    ****
    */
    
    return 0;
}
