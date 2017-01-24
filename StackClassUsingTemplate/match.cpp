// match.cpp
// This program uses a stack to decide whether a parenthesized expression is well formed (i.e., the parentheses match).

#include "stack.h"
#include <iostream>

using namespace std;

bool IsOpen(char symbol)
{
  return ((symbol == '(') || (symbol == '{') || (symbol == '['));
}

bool IsClosed(char symbol)
{
  return ((symbol == ')') || (symbol == '}') || (symbol == ']'));
}

bool Matches(char symbol, char openSymbol)
{
  return (((openSymbol == '(') && (symbol == ')')) ||
	  ((openSymbol == '{') && (symbol == '}')) ||
	  ((openSymbol == '[') && (symbol == ']')));
}

int main()
{
  char symbol;
  Stack<char> stack; // Declare stack to be a Stack of characters.
  Stack<int> intStack; // Added to demonstrate that you can use two types in the same program.
  bool balanced = true;
  char openSymbol;

  cout << "Expression: ";
  cin.get(symbol);
  while ((symbol != '\n') && balanced)
    {
      if (IsOpen(symbol))
	{
	  try
	    {
	      stack.Push(symbol);
	    }
	  catch (FullStack exception)
	    {
	      cerr << "Stack is full." << endl;
	      return 1;
	    }
	}
      else if (IsClosed(symbol))
	{
	  if (stack.IsEmpty())
	    balanced = false;
	  else
	    {
	      try
		{
		  openSymbol = stack.Pop();
		}
	      catch (EmptyStack exception)
		{
		  cerr << "Stack is empty." << endl;
		  return 1;
		}
	      balanced = Matches(symbol, openSymbol);
	    }
	}
      cin.get(symbol);
    }
  if (balanced && stack.IsEmpty())
    cout << "Expression is well formed." << endl;
  else
    cout << "Expression is not well formed." << endl;
  return 0;
}
