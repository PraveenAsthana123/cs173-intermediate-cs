/*======================================
// James Le
// May 4, 2015
// CS 173, Spring 2015, Ashwin Lall
// Homework 11 (list.cpp)
// Implementation of list template class
======================================*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "list.h"

/*===================================
Default Constructor
Pre: None
Post: Creates an empty list (no item)
===================================*/
template <class ItemType>
List<ItemType>::List()
{
  head = tail = NULL; // Set head and tail to NULL
  currentFwd = currentRev = NULL; // Set forward and backward iterator to NULL
  size = 0; // initialize size of the list as 0
}

/*===============================================================
Copy Constructor
Pre: source is a doubly linked list
Post: Creates a new List that is an exact copy of an existing List
================================================================*/
template <class ItemType>
List<ItemType>::List(const List<ItemType>& source)
{
  copy(source); // call the copy method (written below)
}

/*===============================================
Copy method to copy source list to this list
===============================================*/
template <class ItemType>
void List<ItemType>::copy(const List<ItemType>& source)
{
  size = source.size; // copy the size
  if (source.head == NULL)  // if original list is empty
    {
      // sets all pointers to NULL
      head = tail = NULL;
      currentFwd = currentRev = NULL;
    }
  else
    {
      Node<ItemType> *temp1, *temp2, *temp3; // if source is not empty, run through the list
      temp1 = source.head;
      temp2 = new Node<ItemType> (temp1->item);
      head = temp2;
      temp1 = temp1->next;

      while (temp1 != NULL) // Set values to new nodes
	{
	  temp3 = temp2;
	  temp2->next = new Node<ItemType> (temp1->item);
	  temp2 = temp2->next;
	  temp2->prev = temp3;
	  temp1 = temp1->next;
	}
      tail = temp2; // Set tail and two current pointers
      currentFwd = source.currentFwd; 
      currentRev = source.currentRev;
    }
}

/*===========================================================
Destructor
Pre: None
Post: Cleans up the memory for an existing List to be deleted
===========================================================*/
template <class ItemType>
List<ItemType>::~List()
{
  dealloc(); // call the deallocate method (written below)
}

/*========================================
Deallocate method to deallocate the list
========================================*/
template <class ItemType>
void List<ItemType>::dealloc()
{
  Node<ItemType> *temp = head;
  while (temp != NULL) // consecutively delete each node in the list
    {
      Node<ItemType> *temp2 = temp->next;
      delete temp;
      temp = temp2;
    }
}

/*==========================================================
Assignment Operator
Pre: source is a doubly linked list
Post: Makes a copy of an existing List for the assigned List
==========================================================*/
template <class ItemType>
List<ItemType> & List<ItemType>::operator=(const List<ItemType>& source)
{
  dealloc();
  copy(source);

  return *this;
}

/*===============================================
Append function
Pre: x is of type ItemType
Post: Adds item x to the end of the existing List
===============================================*/
template <class ItemType>
void List<ItemType>::append(const ItemType& x)
{
  if (head == NULL) // if the list is empty
    {
      Node<ItemType> *newN = new Node<ItemType> (x); // create a new node and add value
      head = tail = newN;
    }
  else // if not make sure nodes position are correct
    {
      Node<ItemType> *newN = new Node<ItemType> (x);
      newN->next = NULL;
      newN->prev = tail;
      Node<ItemType> *temp = tail;
      temp->next = newN;
      tail = newN;
    }
  size++;
}

/*==========================================================================
Insert function
Pre: index is an integer, x is of type ItemType
Post: Inserts item x at location i in the List. The existing items are moved
towards the end of the List to make room for the new item.
==========================================================================*/
template <class ItemType>
void List<ItemType>::insert(int index, const ItemType& x)
{
  if ((index < -size) || (index > size)) // print error if index is invalid
    throw IndexError();

  if (index < 0) // if index is negative, converts it to positive
    index = index + size;

  Node<ItemType> *newN = new Node<ItemType> (x);
  if (index == 0) // if insert into the first position
    {
      if (size != 0) // set the previous and next pointer
	{
	  newN->next = head;
	  head->prev = newN;
	  newN->prev = NULL;
	  head = newN;
	}
      if (size == 0) // if list is empty, then set next and previous pointer to NULL
	{
	  head = newN;
	  newN->next = NULL;
	  newN->prev = NULL;
	}
    }
  else if (index <= size - 1) // if index is in the middle
    {
      Node<ItemType> *temp = head;
      for (int i = 0; i < index - 1; i++)
	{
	  temp = temp->next;
	}
      newN->prev = temp;
      newN->next = temp->next;
      Node<ItemType> *use = temp->next;
      temp->next = newN;
      use->prev = newN;
    }
  else if (index == size) // if insert into the last position
    {
      newN->next = NULL;
      newN->prev = tail;
      tail->next = newN;
      tail = newN;	
    }
  size++;
}

/*======================================================
Pop function
Pre: index is an integer
Post: Removes and returns value at index i from the list.
======================================================*/
template<class ItemType>
ItemType List<ItemType>::pop(int index)
{
  if((index < -1) || (index >= size )) // print error if index is invalid
	  throw IndexError();
	
  if (size == 1)  //poping when there is only one element in the list
    {
	  ItemType x = head -> item;
	  delete head;
	  head = tail = NULL;
	  size--;
	  return x;
    }

  else if((index==-1) || (index == size -1))	//poping the last element in the list
    {
	  ItemType x=tail ->item;
	  tail=tail->prev;
	  delete tail ->next;
	  tail ->next = NULL;
	  size--;
	  return x;
    }
	
  else if (index == 0)	//Poping the first element in the list
    {
	  ItemType x = head -> item;
	  head = head -> next;
	  delete head ->prev;
	  head -> prev = NULL;
	  size--;
	  return x;
    }

  else	//poping an item in the middle
    {		
	  Node<ItemType> *node, *before, *after;
	  node = _find(index);
	  ItemType x = node -> item;
	  before = node -> prev;
	  after = node -> next;
	  before -> next = after;
	  after -> prev = before;
	  delete node;
	  size--;
	  return x;
    }
}

/*==============================================
Indexing Operator
Pre: index is an integer
Post: Access (by reference) the item at index i.
==============================================*/
template <class ItemType>
ItemType& List<ItemType>::operator[](int index)
{
  if((index < -size) || (index >= size)) // print error if index is invalid
    throw IndexError();

  if (index < 0) // if index is negative, converts it to positive
    index = index + size;

  Node<ItemType> *temp = head;
  for (int i = 0; i < size; i++) // Run to the node position
    {
      if (i == index)
	{
	  return temp->item;
	}
      temp = temp->next;
    }
  return temp->item;
}

/*===========================================================
Find method to return a pointer to the node in position index
===========================================================*/
template <class ItemType>
Node<ItemType>* List<ItemType>::_find(int index)
{
  Node<ItemType> *temp = head;
  if ((index < -size) || (index >= size)) // print error if index is invalid
    throw IndexError();

  if (index < 0) // if index is negative, converts it to positive
    index = index + size;

  for (int i = 0; i < index; i++) // run through the list to the index and return the pointer to that index
    {
      temp = temp->next;
    }
  return temp;
}

/*====================================================================
Index of item
Pre: x is of type ItemType
Post: Returns the index of the first occurrence of item x in the List,
return -1 if x is not in the List.
====================================================================*/
template <class ItemType>
int List<ItemType>::index(const ItemType &x)
{
  int count = 0;

  Node<ItemType> *temp = head;
  for (int i = 0; i < size; i++) // iterate through the list
    {
      if (temp->item == x)
	{
	  return count; // return index if value == number
	}
      count++;
      temp = temp->next;
    }
  return -1; // if there is no number in the list
}

/*========================================================
Reset Forward
Pre: None
Post: Resets the forward iterator to the front of the list.
========================================================*/
template <class ItemType>
void List<ItemType>::resetForward(void)
{
  currentFwd = head;
}

/*========================================================
Reset Reverse
Pre: None
Post: Resets the backward iterator to the end of the list.
========================================================*/
template <class ItemType>
void List<ItemType>::resetReverse(void)
{
  currentRev = tail;
}

/*==================================================================================
Next Item
Pre: None
Post: Returns the value of the next item in the list using the forward iterator location. 
The forward iterator is then moved to the next item.
==================================================================================*/
template <class ItemType>
ItemType List<ItemType>::next()
{
  if (currentFwd == NULL) // print out error if current Forward is invalid
    {
      throw StopIteration();
    }
  Node<ItemType> *temp = currentFwd;
  currentFwd = currentFwd->next;

  return temp->item;
}

/*==================================================================================
Previous Item
Pre: None
Post: Returns the value of the next item in the list using the backward iterator location. 
The backward iterator is then moved to the next (previous) item.
==================================================================================*/
template <class ItemType>
ItemType List<ItemType>::prev()
{
  if (currentRev == NULL) // print our error if current Reverse is invalid
    {
      throw StopIteration();
    }
  Node<ItemType> *temp = currentRev;
  currentRev = currentRev->prev;

  return temp->item;
}

/*====================================
String Representation
Pre: None
Post: Converts the List into a string.
====================================*/
template <class ItemType>
string List<ItemType>::str()
{
  Node<ItemType> *node = head;
  ItemType element;
  ostringstream oss;
  oss << "[";
  if (node != NULL) {
    element = node->item;
    node = node->next;
    oss << element;
  }
  for (int i = 1; i < size; i++) {
    element = node->item;
    node = node->next;
    oss << ", " << element;
  }
  oss << "]";
  string str = oss.str();
  return str;
}
