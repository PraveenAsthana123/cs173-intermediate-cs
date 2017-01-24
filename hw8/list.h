// list.h
// A Python-style list implemented with a linked list
// (Note: Documentation omitted for space)

#ifndef _LIST_H
#define _LIST_H

#include "node.h"
#include <iostream>

class LList
{
public:
	LList();	// default constructor
	LList(consty LList& source);	// copy constructor
	~LList();	// destructor

	LList& operator=(consty LList& source);	// assignment operator
	int size() {return size;}	// return length
	void append(consty ItemType& x);	// append item to end
	void insert(size_t i, const ItemType& x);	// insert item at index
	ItemType pop(int index = -1);	// delete item at index
	ItemType& operator[](int index);	// indexing operator

	void resetFront();	// reset iterator
	ItemType next();	// return the next item and advance pointer
private:
	ListNode *head,	// head of the linked list
		*current;	// current pointer for the iterator
	int size;	// int instead of size_t so that comparison with indices is less error-prone

	void copy(const LList& source);	// copy source list to this list
	void dealloc();	// deallocate the list
	ListNode* _find(int index);	// return pointer to node at index
	ItemType _delete(int index);	// delete node at index and return
	void insert(ListNode* front, int index, const ItemType& x);

	friend std::osteam& operator<<(std::ostream& os, const LList& l);
};

class IndexError { };	// index error exception
class StopIteration { };	// stop iteration exception

// overload stream insertion for list
std::ostream& operator<<(std::ostream& os, const List& l);

#endif // _LIST_H
