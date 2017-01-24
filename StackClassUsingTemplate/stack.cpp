// stack.cpp
// Implementation of stack template class

/*============================================
MakeEmpty()
Function: Sets stack to an empty state.
Precondition: None.
Postcondition: Stack is initialized and empty.
============================================*/
template <class ItemType>
Stack <ItemType>::Stack()
{
  top = -1;
}

/*=============================================================
bool IsEmpty()
Function: Determines whether the stack is empty.
Precondition: Stack has been initialized.
Postcondition: Returns true if stack is empty, false otherwise.
=============================================================*/
template <class ItemType>
bool Stack<ItemType>::IsEmpty() const
{
  return (top == -1);
}

/*============================================================
bool IsFull()
Function: Determines whether the stack is full.
Precondition: Stack has been initialized.
Postcondition: Returns true if stack is full, false otherwise.
============================================================*/
template <class ItemType>
bool Stack<ItemType>::IsFull() const
{
  return (top == MAX_ITEMS - 1);
}

/*========================================================================
void Push(ItemType item)
Function: Adds item to the top of the stack.
Precondition: Stack has been initialized.
Postcondition: Exception FullStack thrown for full stack; else item pushed.
========================================================================*/
template <class ItemType>
void Stack<ItemType>::Push(ItemType item)
{
  if (IsFull())
    throw FullStack();
  top++;
  items[top] = item;
}

/*==========================================================================
ItemType Pop()
Function: Removes and returns the item from the top of the stack.
Precondition: Stack has been initialized.
Postcondition: Exception EmptyStack is thrown if empty; else top element pop.
===========================================================================*/
template <class ItemType>
ItemType Stack<ItemType>::Pop()
{
  if (IsEmpty())
    throw EmptyStack();
  top--;
  return items[top + 1];
}

/*======================================================================
ItemType Top()
Function: Returns the item from the top of the stack.
Precondition: Stack has been initialized.
Postcondition: Exception EmptyStack is thrown if empty; else return top.
======================================================================*/
template <class ItemType>
ItemType Stack<ItemType>::Top() const
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}
