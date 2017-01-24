/*========================================================
Sorting Project (Homework 3)
James Le
12/02/2015
CS 173, Spring 2015
=========================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

void bubbleSort     ( int n, int array[] );
void selectionSort  ( int n, int array[] );
void insertionSort  ( int n, int array[] );

void printList      ( int n, int array[] );
void copyList       ( int n, int a[], int b[] );
bool isSorted       ( int n, int array[] );

int main ( int argc, char *argv[] )
{
    int n = 10;         // default number of items in list
    if ( argc >= 2 )    // possibly read array size from command line
        n = atoi(argv[1]);
        
    int cap = 100;      // numbers range from 1 to cap
    int a[n];           // original unsorted list
    int b[n];           // temporary sorted list
    
    // seed the random number generator with current time
    srand(time(NULL));
    
    // fill the array with random integers between 1 and cap
    for ( int i = 0; i < n; i++ )
    {
        a[i] = rand() % cap + 1;
    }
    
    if ( n <= 10 ) printList(n,a);
    
    copyList(n,a,b);                    // copy the list from a to b
    selectionSort(n,b);                 // sort list b
    if (isSorted(n,b))                  // verify it is sorted
    	cout << "selection passed" << endl;
    else
    	cout << "selection failed" << endl;
    if ( n <= 10 ) printList(n,b);      // maybe print small list

	copyList(n,a,b);                    // copy the list from a to b
    bubbleSort(n,b);                    // sort list b
    if (isSorted(n,b))                  // verify it is sorted
    	cout << "bubble passed" << endl;
    else
    	cout << "bubble failed" << endl;
    if ( n <= 10 ) printList(n,b);      // maybe print small list
    
    copyList(n,a,b);                    // copy the list from a to b
    insertionSort(n,b);                 // sort list b
    if (isSorted(n,b))                  // verify it is sorted
    	cout << "insertion passed" << endl;
    else
    	cout << "insertion failed" << endl;
    if ( n <= 10 ) printList(n,b);      // maybe print small list
    
    return 0;
}

/*=========================================================
bubbleSort
preconditions: input n, list of integers with at least one in it
postconditions: list of integers being sorted
==========================================================*/

void bubbleSort (int n, int array [])
{
  bool swapped = true;
  int j = 0;
  int temp;
  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < n - j; i++) { // creates a nested loop
      if (array[i] > array[i+1]) { // compares two indices
	temp = array[i]; // creates a temporary placeholder for value of index i
	array[i] = array[i+1]; // swaps index i with index i + 1
	array[i+1] = temp; // swaps index i + 1 with original value of index i
	swapped = true;
      }
    }
  }
}

/*========================================================
selectionSort
preconditions: input n, list of integers with at least one in it
postconditons: list of integers being sorted
=========================================================*/

void selectionSort (int n, int array [])
{
  int i, j, minIndex, temp;
  for (i = 0; i < n - 1; i++) { // creates a nested for loop
    minIndex = i; // assignment of the smallest value in the list
    for (j = i + 1; j < n; j++)
      if (array[j] < array[minIndex])
	minIndex = j;
    if (minIndex != i) {
      temp = array[i]; // creates a temporary placeholder for value of index i
      array[i] = array[minIndex]; // swaps index i with the minimum index
      array[minIndex] = temp; // swaps minimum index with original value of index i
    }
  }
}

/*========================================================
insertionSort
preconditions: input n, list of integers with at least one in it
postconditions: list of integers being sorted
=========================================================*/

void insertionSort (int n, int array[])
{
  int i, j, item;
  for (i = 1; i < n; i++) { // creates a nested loop
    item = array[i]; // assign the value for item
    j = i - 1;
    while (j >= 0 && array[j] > item) { // compares two indices and look for the smaller one
      array[j + 1] = array[j]; // assign later item with earlier item
      j--; // j moves towards the left
    }
    array[j + 1] = item; // reassign value for item
  }
}

/*=========================================================
printList
This algorithm takes a list of integers as input and prints
them, one per line.  
inputs:     n: number of integeres in the list
            array: the list of integers
outputs:    no return value
            list of integers printed to screen
preconditions:
            input n, list of integers
postconditions:
            list of integers printed to screen
========================================================*/
void printList (int n, int array[])
{
  for (int i = 0; i<n; i++)
    {
      cout << array[i] << " ";
    }
  cout << "\n";

}

/*========================================================
copyList
 This algorithm copies of list of integers from array a to
 array b.
 inputs:    n: number of integers in both lists
 			a: the list of original integers
 outputs:   no return value
 			b: the copied list of original integers
 preconditions:
 input n, array a of integers
 postconditions:
 array b of integers which is an exact copy of array a
 ========================================================*/
void copyList (int n, int a[], int b[])
{
  {
     for (int i = 0; i < n; i++)
       {
	 b[i] = a[i];
       }
   }
 }

 /*========================================================
isSorted
 An algorithm to test if an array of integers is in sorted
 ascending order.
 inputs:        n = number of integers in array
                array = array of possibly sorted integers
 outputs:       true if array is in sorted order
                false if not
 preconditions: valid input of n integers
 postconditions: proper return value of true/false
 ========================================================*/

bool isSorted (int n, int array[])
{
  int count = 0;
  for (int i = 0; i < n - 1; i++)
    {
      if (array[i] > array[i + 1])
	{
	  count = count + 1;
	}
    }
  if (count == 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}
