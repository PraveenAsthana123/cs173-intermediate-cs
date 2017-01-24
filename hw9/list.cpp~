/*==============================
James Le
April 17, 2015
CS 173, Spring 2015, Ashwin Lall
Homework Project 9
list.cpp
===============================*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "list.h"

/*====================================
Default Constructor
Pre: None
Post: Creates an empty list (no item)
====================================*/
List::List()
{
  head = tail = NULL; // Sets head and tail to NULL
  currentFwd = currentRev = NULL; // Sets forward and backward iterator to NULL
  size = 0; // initializes size of the list as 0
}

/*===============================================================
Copy Constructor
Pre: source is a doubly linked list
Post: Creates a new List that is an exact copy of an existing List
================================================================*/
List::List(const List& source)
{
  copy(source); // Calls the copy function (written below)
}

/*============================================
Copy function to copy source list to this list
============================================*/
void List::copy(const List& source)
{
  Node *snode, *node; // pointers
  snode = source.head; // makes snode the head of the source list
  if (snode != NULL) // checks if source is not an empty list
    {
      node = head = new Node(snode->item); // creates a new node with the value of snode and makes it the head
      snode = snode->next; // updates the "next" pointer of the current snode to the next node
    }
  while (snode != NULL)
    {
      node->next = new Node(snode->item); // creates a new node with the value of snode and have the "next" pointer of the current node pointed to it
      node = node->next; // updates the "next" pointer of the current node to the next node
      snode = snode->next; // updates the "next" pointer of the current snode to the next node
    }
  size = source.size; // copy the size
}

/*===========================================================
Destructor
Pre: None
Post: Cleans up the memory for an existing List to be deleted
===========================================================*/
List::~List()
{
  dealloc(); // Calls the deallocate function (written below)
}

/*========================================
Deallocate function to deallocate the list
========================================*/
void List::dealloc()
{
  Node *node, *dnode; // pointers
  node = head; // make node the current head
  while (node != NULL) // checks if not an empty
    {
	  dnode = node; // makes dnode the current node (head)
	  node = node->next; // makes the next node the new head
	  delete dnode; // deletes the old head (dnode)
	  node->prev = NULL; // sets the "prev" pointer of the current node (head) to NULL
    }
}

/*==========================================================
Assignment Operator
Pre: source is a doubly linked list
Post: Makes a copy of an existing List for the assigned List
===========================================================*/
List& List::operator=(const List& source)
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
void List::append(const ItemType& x)
{
  Node *newNode; // pointer for a newly created node with value x
  newNode = new Node(x); // creates the new node with value x

  if (head == NULL) // checks for an empty list
    head = tail = newNode;
  else {
    tail->next = newNode; // updates tail's "next" pointer to new node
    newNode->prev = tail; // updates new node's "prev" pointer to tail
    tail = newNode; // makes new node the tail of list
  }  
  size++; // increases size
}

/*==================================================================================
Insert function
Pre: index is an integer, x is of type Itemtype
Post: Inserts item x at location i in the List. The existing items are moved towards
the end of the List to make room for the new item.
==================================================================================*/
void List::insert(int index, const ItemType& x)
{
  Node *newNode; // pointer for a newly created node with value x
  newNode = new Node(x); // creates the new node with value x

  if ((index < 0 || index > size)) // check if index is out of range
    throw IndexError();

  if (index == 0) { // insert x into the first position
    newNode->next = head; // sets new node's "next" pointer to head
    head->prev = newNode; // sets head's "prev" pointer to new node
    head = newNode; // makes new node the head of the list
    size++; // increases size
  }

  else if (index == size - 1) // inserts x into the last position
    append(const ItemType& x); // calls the append function

  else {
    Node *before = newNode->prev; // creates a 'before' node and sets new node's "prev" pointer to before
    Node *after = newNode->next; // creates an 'after' node and sets new node's "next" pointer to after
    before->next = newNode; // updates before's "next" pointer to new node
    after->prev = newNode; // updates after's "prev" pointer to new node
    size++; // increases size
  }
}

/*=====================================================
Pop function
Pre: index is an integer
Post: Removes and returns item at index i from the list.
======================================================*/
ItemType List::pop(int index)
{
  if ((index < -size) || (index >= size)) // checks if index is out of range
    throw IndexError();

  if (index < 0) // if index is negative, converts it to positive
    index = index + size;

  return _delete(index); // removes and returns the node at index i by calling Delete function
}

/*========================================
Delete function to delete node in position
========================================*/
Node* List::_delete(int index)
{
  if ((index < 0) || (index >= size)) // checks if index is out of range
    throw IndexError();

  Node *dnode; // pointer for the node to be deleted
  ItemType item; // type of item

  if (size == 1) // checks if there is one thing in the list
    {
    item = dnode->item;
    delete dnode;
    head = tail = NULL;
    }
  else if (index == 0) // delete the first node (head)
    {
      head = head->next; // makes the next node the new head
      delete head->prev; // delete the old head
      head->prev = NULL; // sets the 'prev' pointer of the current head to NULL
    }
  else if (index == size - 1) // delete the last node (tail)
    {
      tail = tail->prev; // makes the second to last node the new tail
      delete tail->next; // delete the old tail
      tail->next = NULL; // sets the 'next' pointer of the current tail to NULL
    }
  else
    {
      Node *before = dnode->prev; // creates a 'before' node and sets dnode's "prev" pointer to 'before'
      Node *after = dnode->next; // creates an 'after' node and sets dnode's "next" pointer to 'after'
      before->next = after; // the "next" pointer of 'before' is pointed to 'after'
      after->prev = before; // the "prev" pointer of 'after' is pointed to 'before'
      item = dnode->item;
      delete dnode;
    }
  size--; // decreases size
  return item;
}

/*==============================================
Indexing Operator
Pre: index is an integer
Post: Access (by reference) the item at index i.
==============================================*/
ItemType& List::operator[](int index)
{
  if ((index < -size) || (index >= size)) // checks if index is out of range
    throw IndexError();

  if (index < 0) // if index is negative, converts it to positive
    index = index + size;

  Node *node = _find(index); // makes a pointer to the node at index i by calling Find function
  return node->item; // returns the node at index i
}

/*=============================================================
Find function to return a pointer to the node in position index
=============================================================*/
Node* List::_find(int index)
{
  if ((index < -size) || (index >= size)) // checks if index is out of range
    throw IndexError();

  if (index < 0) // if index is negative, converts it to positive
    index = index + size;

  Node *pnode; // pointer
  Node *node = head; // set the 1st node as head
  for (int i = 0; i < index; i++) // iterate through the list
    {
      pnode = node; // makes pnode the current node
      node = node->next; // updates the "next" pointer of current node to the next node
      node->prev = pnode; // updates the "prev" pointer of current node to pnode (also the old node)
    }
  return node;
}

/*==================================================================================
Index of item
Pre: x is of type ItemType
Post: Returns the index of the first occurrence of item x in the List, returns -1 if 
x is not in the List.
==================================================================================*/
int List::index(const ItemType &x)
{
  currentFwd = head; // makes the current forward pointer the head
  int index = -1;
  for (int i = 0; i < size; i++) // iterate through the list
    {
    index = i;
    return index;
    }
  currentFwd = currentFwd->next; // increment current pointer so that it points to the
                                 // next node in the list
  return index;
}

/*========================================================
Reset Forward
Pre: None
Post: Resets the forward iterator to the front of the list.
========================================================*/
void List::resetForward()
{
  currentFwd = head;
}

/*========================================================
Reset Reverse
Pre: None
Post: Resets the backward iterator to the end of the list.
========================================================*/
void List::resetReverse()
{
  currentRev = tail;
}

/*==================================================================================
Next Item
Pre: None
Post: Returns the value of the next item in the list using the forward iterator location. 
The forward iterator is then moved to the next item.
==================================================================================*/
ItemType List::next()
{
  try // Print out error if go over the tail
    {
      if (currentFwd == NULL)
	{
	  throw StopIteration();
	}
      else
	{
	  Node *temp = currentFwd;
	  currentFwd = currentFwd->next;
	  return temp->item;
	}
    }
  catch (const StopIteration &i)
    {
      cout << i.Reason();
    }
  return -1;
}

/*==================================================================================
Previous Item
Pre: None
Post: Returns the value of the next item in the list using the backward iterator location. 
The backward iterator is then moved to the next (previous) item.
==================================================================================*/
ItemType List::prev()
{
  try // Print out error if go below the head
    {
      if (currentRev == NULL)
	{
	  throw StopIteration();
	}
      else
	{
	  Node *temp = currentRev;
	  currentRev = currentRev->prev;
	  return temp->item;
	}
    }
  catch (const StopIteration &i)
    {
      cout << i.Reason();
    }
  return -1;
}

/*====================================
String Representation
Pre: None
Post: Converts the List into a string.
====================================*/
string List::str()
{
  string str = "";
  Node *temp = head;
  char Result;
  str += "[";
  while (temp != NULL)
    {
      if (temp->next != NULL)
	{
	  ostringstream convert;
	  convert << (temp->item);
	  str += Result;
	  str += ",";
	}
      else
	{
	  ostringstream convert;
	  convert << (temp->item);
	  str += Result;
	}
      temp = temp->next;
    }
  str += "]";
  return str;
}

/*============================
Print out the function
============================*/
std::ostream& operator<< (ostream& os, const List& l)
{
  Node *temp = l.head;
  cout << "[";
  while (temp->next != NULL)
    {
      os << temp->item << ",";
      temp = temp->next;
    }
  os << temp->item;
  cout << "]";

  return os;
}
