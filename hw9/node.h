// James Le
// CS 173, Spring 2015
// 05/17/2015
// node.h

#ifndef _LISTNODE_H
#define _LISTNODE_H

#include <cstdlib>
typedef int ItemType;

struct Node
{
	ItemType item; // data item stored in this link
	Node * next; // pointer to the next link in list
	Node * prev; // pointer to the previous link in list
	
	Node () { next = prev = NULL; } // default constructor
	Node (const ItemType & x) { next = prev = NULL; // constructor with item
					item = x; }
};

#endif // _LISTNODE_H
