//======================
// James Le - CS173
// May 4, 2015
// Homework 11 (set.cpp)
//======================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "list.h"

template <class ItemType>
Set<ItemType>::Set(void) // Default constructor
{}

template <class ItemType>
Set<ItemType>::Set(const Set& source) // Copy Constructor
{
	L = source.L;
}

template <class ItemType> // Destructor
Set<ItemType>::~Set(void)
{}

template <class ItemType>
Set<ItemType>& Set<ItemType>::operator=(const Set& source) // Assignment Operator
{
	L = source.L;
	return *this;
}

template <class ItemType>
string Set<ItemType>::str()
{
	string a = L.str();
	return a;
}

//This method adds an non existence item into the set, do nothing if the item is in the set
//precondition: an non existence item (float, int, char, ...)
//postcondition: the item is added into the set if that item was not in the list
template <class ItemType>
void Set<ItemType>::insert(const ItemType& x) // Insert Method
{
	if (contains(x) == false)
	{
		L.append(x); // add using list append
	}
}

//This method removes an item in the set, do nothing if the item does not exist
//precondition: an item
//postcondition: remove the item if it is in the set
template <class ItemType>
void Set<ItemType>::remove(const ItemType& x) // Remove Method
{
	int i = L.index(x);
	if (i != -1) // if that item is in the set
	{
		L.pop(i); // delete using pop command
	}
}

//This method checks if an item is in the set or not
//precondition: an item
//postcondition: return true or false
template <class ItemType>
bool Set<ItemType>::contains(const ItemType& x) // Contains Method
{
	int i = L.index(x);
	if (i == -1)
	{
		return false; // item is not in the set, return false
	}
	return true; // else true
}

template <class ItemType>
int Set<ItemType>::size() // Size Method
{
	int length;
	length = L.length();
	return length;
}

//This method merge 2 sets into 1, no duplicate
//precondition: 2 sets
//postcondition: a new set with all item of the 2 sets (no duplicate)
template <class ItemType>
Set<ItemType> Set<ItemType>::Union(const Set& source) // Union Method
{
	Set<ItemType> s1 = source;	// copy set 1 to new set
	L.resetForward();
	for(int i = 0; i < L.length(); i++)	// copy set 2 to new set
	{
		ItemType a = L.next();
		if (s1.contains(a) == false)	// only copy if the item is not in the new set
		{
			s1.insert(a);
		}
	}
	return s1;
}

//This method take all the common items from 2 sets and put into 1
//precondition: 2 sets
//postcondition: a new set that contains all the similar items of the 2 sets
template <class ItemType>
Set<ItemType> Set<ItemType>::intersection(const Set& source) // Intersection Method
{
	Set<ItemType> s1;	// create new set
	source.L.resetForward();
	L.resetForward();
	for(int i = 0; i < source.size(); i++)	// run through set 1
	{
		ItemType a = source.L.next();
		for (int ii = 0; ii < size(); ii++)	// run through set 2
		{
			ItemType b = L.next();
			if (a == b and s1.contains(a) == false)
			{
				s1.insert(a);	// add if the item is in both set
			}
		}
		L.resetForward();
	}
	return s1;
}
