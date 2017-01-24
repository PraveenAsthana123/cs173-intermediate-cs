//===========================
// James Le - CS173
// May 4, 2015
// Homework 11 (test_set.cpp)
//===========================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "list.h"
#include <cassert>
#include "set.h"

void testDefaultConstructor()
{
	Set<int> s1;
	assert(s1.str() == "");
}

void testCopyConstructor(void)
{
	Set<int> s1;
	Set<int> s2;
	s1.insert(21);
	s1.insert(22);
	s2.insert(23);
	s2.insert(24);

	s1 = s2;
	assert(s1.str() == "[23, 24]");
}

void testInsert(void)
{
	Set<int> s;
	s.insert(21);
	s.insert(22);
	s.insert(23);
	assert(s.str() == "[21, 22, 23]");
}

void testRemove(void)
{
	Set<int> s;
	s.insert(21);
	s.insert(22);
	s.insert(23);
	s.insert(24);

	s.remove(24);
	s.remove(22);
	s.remove(20);

	assert(s.str() == "[21, 23]");
}

void testContains(void)
{
	Set<int> s;
	s.insert(21);
	s.insert(22);

	assert(s.contains(21) == true);
	assert(s.contains(24) == false);
}

void testSize(void)
{
	Set<int> s;
	s.insert(21);
	s.insert(22);
	assert(s.size() == 2);

	s.insert(23);
	assert(s.size() == 3);

	s.remove(23);
	assert(s.size() == 2);
}

void testUnion(void)
{
	Set<int> s1;
	Set<int> s2;
	s1.insert(21);
	s1.insert(22);
	s1.insert(23);

	s2.insert(23);
	s2.insert(24);

	s1.Union(s2);
	assert(s1.str() == "[21, 22, 23, 24]");
}

void testIntersection(void)
{
	Set<int> s1;
	Set<int> s2;
	s1.insert(21);
	s1.insert(22);
	s1.insert(23);

	s2.insert(22);
	s2.insert(23);
	s2.insert(24);

	s1.intersection(s2);
	assert(s1.str() == "[22, 23]");
}

int main(void)
{
	testDefaultConstructor();
	testCopyConstructor();
	testInsert();
	testRemove();
	testContains();
	testSize();
	testUnion();
	testIntersection();

	return 0;
}

