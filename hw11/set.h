//=====================
// James Le - CS173
// May 4, 2015
// Homework 11 (set.h)
//=====================

#ifndef SET_H
#define SET_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"
#include <cstdlib>

using namespace std;

template <class ItemType>
class Set
{
public:
	Set(); // default constructor
	Set(const Set& source); // copy constructor
	~Set(); // destructor

	Set & operator= (const Set& source); // assignment operator
	int size(); // return the size of the set
	void insert(const ItemType& x); // insert an element into the set
	void remove(const ItemType& x); // remove an element from the set

	bool contains(const ItemType& x); // check if the set contains a particular element

	Set Union(const Set& source); // take another set as a parameter and insert all its elements into this set

	Set intersection(const Set& source); //take another set as a parameter and only retain elements also contained in it
	string str(); // output

private:
	List<ItemType> L; // inclusion to list class
};
#include "set.cpp"
#endif
