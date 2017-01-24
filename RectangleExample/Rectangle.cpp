// Rectangle.cpp

#include "Rectangle.h"
using namespace std;

// Function: Initialize (construct) the rectangle object
// Precondition: height and weight are integers
// Postcondition: Rectangle is initialized with height and width
Rectangle::Rectangle(int height, int width)
{
  height_=height;
  width_=width;
}

// Function: gets the height
// Precondition: Rectangle has been initialized
// Postcondition: returns the height of rectangle
int Rectangle::getHeight() const
{
  return height_;
}

// Function: gets the width
// Precondition: Rectangle has been initialized
// Postcondition: returns the width of rectangle
int Rectangle::getWidth() const
{
  return width_;
}

// Function: sets the height
// Precondition: Rectangle has been initialized
// Postcondition: updates height of rectangle
void Rectangle::setHeight(int height)
{
  height_=height;
}

// Function: sets the width
// Precondition: Rectangle has been initialized
// Postcondition: updates the width of rectangle
void Rectangle::setWidth (int width)
{
  width_=width;
}

// Function: gets the area
// Precondition: Rectangle has been initialized
// Postcondition: returns the area of rectangle
int Rectangle::area() const
{
  return height_ * width_;
}

// Function: gets the perimeter
// Precondition: Rectangle has been initialized
// Postcondition: returns the perimeter of rectangle
int Rectangle::perimeter() const
{
  return 2*(height_ + width_);
}

// Function: 
