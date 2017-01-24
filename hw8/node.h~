// node.h

#ifndef _LISTNODE_H
#define _LISTNODE_H

#include <cstdlib> // for NULL
typedef int ItemType;

class ListNode
{
  	friend class LList;
public:
  	ListNode(ItemType item, ListNode *link = NULL);
private:
	ItemType item_;
	ListNode *link_;
};
inline ListNode::ListNode(ItemType item, ListNode *link)
{
  	item_ = item;
  	link_ = link;
}

#endif // _LISTNODE_H
