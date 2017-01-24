// stack.h
// Note: The pop operation actually returns the top item here, unlike in the text

#ifndef STACK
#define STACK

const int MAX_ITEMS = 100;
class FullStack { }; // FullStack exception
class EmptyStack { }; // EmptyStack exception

template <class ItemType>
class Stack
{
 public:
  Stack();
  bool IsEmpty() const;
  bool IsFull() const;
  void Push(ItemType item);
  ItemType Pop();
  ItemType Top() const;
 private:
  int top;
  ItemType items[MAX_ITEMS];
};
#include "stack.cpp"
#endif
