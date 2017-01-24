// James Le - CS 173
// May 4, 2015
// Homework 11 (node.h)

#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>
template <class ItemType>
class List;

//typedef int ItemType

template <class ItemType>
class Node
{
	// template <class ItemType>
	friend class List<ItemType>;

	public:
		// If no new node is specifified, by default it is automatically set to NULL
		Node(ItemType item, Node *next = NULL, Node *prev = NULL);
	private:
		ItemType item; // data item stored in this link
		Node *next;    // pointer to the next link in list
		Node *prev;    // pointer to the previous link in list
};

template <class ItemType>
inline Node<ItemType>::Node(ItemType i, Node *n, Node *p)
{
	item = i;
	next = n;
	prev = p;
}

#endif // _NODE_H
