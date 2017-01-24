/*===========================================================
Stack Implementation (Homework 5)
James Le
03/06/2015
CS 173, Spring 2015
============================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
private:
  int size;
  int *a;
  int top;

public:

  Stack(void);
  ~Stack(void); 
  void push(int k);
  int pop(void);
  int topElement(void);
  int sizes(void);

};

Stack::Stack(void)
{
  size = 5;
  a = new int[size];
  top = -1;
}

Stack::~Stack(void)
{
  delete [] a;
}

/*==========================================================================
The push operation pushes one item on the top of the stack
===========================================================================*/
void Stack::push(int k)
{
  if(top == size - 1)
    {
      // cout << "oh" << endl;
      // Create a temporary array that has a capacity of 5 greater than the current array
      int *na = new int[size + 5];
      int i;
      for (i = 0; i < size; i++)
	{
	  // Copy the current values from existing array into temporary array
	  na[i] = a[i];
	}
      delete [] a; // Delete the current array
      a = na; // Set the array pointer to the new temporary array
      size = size + 5;
    }
  a[top + 1] = k;
  top++;
}

/*===========================================================================
The pop operation removes one item from the top of the stack and returns
that item
===========================================================================*/
int Stack::pop(void)
{
  if(top != -1)
    {
      top--;
      return a[top + 1];
    }
  else
    cout<<"You cannot pop from an empty array!"<<endl;
    exit(1);
    return -1;
}

/*===========================================================================
The top operation returns the top item on the stack (without removing it)
============================================================================*/
int Stack::topElement(void)
{
  return a[top];
}

/*===========================================================================
The size operation returns the number of elements in the stack
============================================================================*/
int Stack::sizes(void)
{
  return top + 1;
}

// Main function
main(void)
{
  Stack r1;
  char m = 'o';
  while(m != 'q')
    {
      // cout << "enter command" << endl;
      cin >> m;

      // call the push function
      if(m == 'p')
	{
	  int k;
	  cin >> k;
	  r1.push(k);
	}

      // call the pop function
      if(m == 'x')
	{
	  cout << r1.pop() << endl;
	}

      // return the top
      if(m == 't')
	{
	  cout << r1.topElement() << endl;
	}

      // return the size
      if(m == 's')
	{
	  cout << r1.sizes() << endl;
	}
    }
}
