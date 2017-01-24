//==============================================================================
// list.h
// CS 173, Spring 2015
// This file contains the class definition for a List ADT class.
//
//==============================================================================
// List ADT
//
// The List class implements a sequence of stored items all of the same datatype.
// There are methods to add and remove items from the List, to query the List for
// an item, to index into the list at a specific location, and to iterate through
// the list.
//
// Default Constructor: creates an empty List (no items)
// Copy Constructor:    creates a new List that is an exact copy of an existing List.
// Destructor:          cleans up the memory for an existing List to be deleted.
// Assignment Operator: makes a copy of an existing List for the assigned List.
//
// length():            returns the number of items in the List.
// append(ItemType &x): adds item x to the end of the existing List.  Note that
//                      duplicate items are permitted.
// insert(i,x):         inserts item x at location i in the List.  The existing
//                      items are moved towards the end of the List to make room
//                      for the new item.  Valid values for i are 0 to length().
//                      If length() is the index, this will add the new item to the
//                      end of the list (such as in append).
// pop(i):              removes and returns item at index i from the list.  Valid
//                      values for i are 0 to length()-1.  The argument is optional
//                      will default to removing the last item in the list if i is not given.
// operator[i]:         access (by reference) the item at index i.  Valid values
//                      for i are 0 to length()-1.  The access by reference allows
//                      the user to change the value at this index.
// index(x):            returns the index of the first occurrence of item x in
//                      the List, returns -1 if x is not in the list.
// resetForward():      resets the forward iterator to the front of the list.
// resetReverse():      resets the backward iterator to the end of the list.
// next()               returns the value of the next item in the list using the
//                      forward iterator location.  The forward iterator is then
//                      moved to the next item.
// prev()               returns the value of the next item in the list using the
//                      backward iterator location.  The backward iterator is then
//                      moved to the next (previous) item.
// str()                Converts the List into a string, follows Python format.
//                      Example: "[1, 2, 3]" or "[]"
// cout <<              Overloads the cout << operator for printing. Follows the
//                      same format as in str().
//==============================================================================

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
using namespace std;

#define ItemType    int         // where you can change the type of item stored in the list

class List
{
  public:
    List();                                                 // default constructor
    List(const List& source);                               // copy constructor
    ~List();                                                // destructor
 
    List &      operator=   (const List& source);           // assignment operator
    int         length      ()    const { return size; }    // return the length of the list
    void        append      (const ItemType& x);            // append an item to the end of the list
    void        insert      (int index, const ItemType& x); // insert an item in position index
    ItemType    pop         (int index = -1);               // delete item at position index (or last
                                                            // item if no index given)
    ItemType &  operator[]  (int index);                    // indexing operator
    int         index       ( const ItemType &x );          // return the index of the first occurrence of x
    string      str();					    // return the string representation
 
    void        resetForward(void);                         // reset forward iterator to the head of the list
    ItemType    next();                                     // return the next item in the list and advance
                                                            // forward iterator pointer
    void        resetReverse(void);                         // reset reverse iterator to the tail of the list
    ItemType    prev        (void);                         // return the prev item in the list and advance
                                                            // reverse iterator pointer
 private:
    Node        *head,                                      // head of the linked list
                *tail,                                      // tail of the linked list
                *currentFwd,                                // current pointer for the forward iterator
                *currentRev;                                // current pointer for the reverse iterator
    int         size;                                       // length of the list
                      

    void        copy        (const List& source);           // copy source list to this list
    void        dealloc     ();                             // deallocate the list
    Node*       _find       (int index);                    // return a pointer to the node in position index
    Node*	_delete	    (int index);		    // delete node in position index and return the node
 
    friend ostream&    operator<<  (ostream& os, const List& l);
};

//================================================================
// IndexEror
// This class implements an exception for an indexing error.
//================================================================

class IndexError {					    // index error exception
public:
	IndexError() {};
	~IndexError() {};
	const char *Reason () const { return "Index out of bounds."; }
};

//==============================================================================
// StopIteration
// This class implements an exception for iterating (forward or backward) beyond
// the start/end of the list.
//==============================================================================
class StopIteration {       				    // stop iteration exception
public:
	StopIteration() {};
	~StopIteration() {};
	const char *Reason() const { return "Iteration goes off bounds."; }
};

#endif // _LIST_H
