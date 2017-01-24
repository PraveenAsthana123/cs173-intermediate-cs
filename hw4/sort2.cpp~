/*========================================================
Sorting Project (Homework 4)
James Le
26/02/2015
CS 173, Spring 2015
=========================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

int  comparisons;       // the number of comparisons in a sort
int  exchanges;         // the number of exchanges in a sort

void bubbleSort     ( int n, int array[] );
void selectionSort  ( int n, int array[] );
void insertionSort  ( int n, int array[] );

void mergeSort      ( int start, int end, int a[] );

void quickSort      ( int start, int end, int a[] );
int partition       ( int start, int end, int a[] );

void printList      ( int n, int array[] );
void copyList       ( int n, int a[], int b[] );
bool isSorted       ( int n, int array[] );

/*========================================================
 main
 This routine calls the five sorting methods and prints the
 results.
 ========================================================*/
int main (  int argc, char *argv[]  )
{
    int n = 10;         // default number of items in list
    if ( argc >= 2 )    // possibly read array size from command line
        n = atoi(argv[1]);
    int a[n];      		// original unsorted list
    int b[n];       	// sorted list
    
    // seed the random number generator
    srand(time(NULL));
    
    // fill the array with random integers between 1 and 20
    for ( int i = 0; i < n; i++ )
    {
        a[i] = rand() % 100 + 1;
    }
    
    if ( n <= 10 ) {
        printf("Original list: ");
        printList(n,a);
    }
    
    copyList(n,a,b);
    comparisons = exchanges = 0;
    bubbleSort(n,b);
    if (!isSorted(n,b))                  // verify it is sorted
    	cout << "bubble failed" << endl;
    printf("bubble (%d,%d,%d)\n",comparisons,exchanges,comparisons+exchanges);
    if ( n <= 10 ) printList(n,b);
    
    copyList(n,a,b);
    comparisons = exchanges = 0;
    selectionSort(n,b);
    if (!isSorted(n,b))                  // verify it is sorted
    	cout << "selection failed" << endl;
    printf("selection (%d,%d,%d)\n",comparisons,exchanges,comparisons+exchanges);
    if ( n <= 10 ) printList(n,b);
    
    copyList(n,a,b);
    comparisons = exchanges = 0;
    insertionSort(n,b);
    if (!isSorted(n,b))                  // verify it is sorted
    	cout << "insertion failed" << endl;
    printf("insertion (%d,%d,%d)\n",comparisons,exchanges,comparisons+exchanges);
    if ( n <= 10 ) printList(n,b);
    
    copyList(n,a,b);
    comparisons = exchanges = 0;
    mergeSort(0,n-1,b);
        if (!isSorted(n,b))                  // verify it is sorted
    	cout << "merge failed" << endl;
    printf("merge (%d,%d,%d)\n",comparisons,exchanges,comparisons+exchanges);
    if ( n <= 10 ) printList(n,b);
    
    copyList(n,a,b);
    comparisons = exchanges = 0;
    quickSort(0,n-1,b);
    if (!isSorted(n,b))                  // verify it is sorted
    	cout << "quick failed" << endl;
    printf("quick (%d,%d,%d)\n",comparisons,exchanges,comparisons+exchanges);
    if ( n <= 10 ) printList(n,b);
    
    return 0;
}

/*========================================================
 quickSort
Pre-conditions: a list of integers, positions of the first
integer and the last integer
Post-conditions: a sorted list of integers
 ========================================================*/
void quickSort(int start, int end, int a[])
{
  int p;
  if (start < end)
    {
      p = partition(start, end, a);
      /* Recursively sort two parts of the array */
      quickSort(start, p - 1, a);
      quickSort(p + 1, end, a);
    }
}

int partition(int start, int end, int a[])
{
  int i = start, j = end;
  int temp;
  int pivot = a[start]; // assign the first integer as the pivot
  while (start < end) {
    while (a[i] < pivot) { // check for integers smaller than pivot
      i++;
      comparisons ++;
    }
    while (a[j] > pivot) { // check for integers bigger than pivot
      j--;
      comparisons ++;
    }
    if (i < j) {
      // swap index i with index j
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
      exchanges ++;
    } else {
      // swap index i with the pivot
      temp = pivot;
      pivot = a[i];
      a[i] = temp;
      exchanges ++;
      break;
    }
  };
  return i;
}

/*========================================================
 mergeSort
Pre-conditions: a list of integers, positions of the first,
middle, and last integers
Post-conditions: a sorted list of integers
 =========================================================*/
void merge(int a[], int start, int mid, int end)
{
  int b[end + 1 - start]; // Creates a temporary array
  int h,i,j,k;
  h = start;
  i = 0;
  j = mid + 1;
  // Merges the two array's into b[] until the first one is finished
  while (h <= mid && j <= end)
    {
      if (a[h] <= a[j])
	{
	  b[i] = a[h];
	  h++;
	  exchanges ++;
	  comparisons ++;
	}
      else
	{
	  b[i] = a[j];
	  j++;
	  exchanges ++;
	  comparisons ++;
	}
      i++;
    }
  // Completes the array filling in it the missing values
  if (h > mid) {
    for (k = j; k <= end; k++) {
      b[i] = a[k];
      i++;
      exchanges ++;
    }
  } else {
    for (k = h; k <= mid; k++) {
      b[i] = a[k];
      i++;
      exchanges ++;
    }
  }
  // Prints into the original array
  for (k = 0; k <= (end - start); k++)
    {
      a[k + start] = b[k];
    }
}

void mergeSort(int start, int end, int a[])
{
  if (start < end)
    {
      int mid = (start + end) / 2; // Calculate the midpoint
  /* Recursively sort each half of the range */
      mergeSort(start, mid, a);
      mergeSort(mid+1, end, a);
  /* Merge these two sorted ranges */
      merge(a, start, mid, end);
    }
}

/*========================================================
bubbleSort
Pre-conditions: input n, list of integers
Post-conditions: a sorted list of integers
=========================================================*/
void bubbleSort(int n, int array[] )
{
  bool swapped = true;
  int j = 0;
  int temp;
  while (swapped) {
    swapped = false;
    j++;
    for (int i = 0; i < n - j; i ++) { // creates a nested loop
      if (array[i] > array[i + 1]) { // compares two indices
	temp = array[i]; // creates a temporary placeholder for value of index i
	array[i] = array[i + 1]; // swaps index i with index i + 1
	array[i + 1] = temp; // swaps index i + 1 with original value of index i
	swapped = true;
	exchanges ++;
      }
      comparisons ++;
    }
  }
}

/*=========================================================
 selectionSort
Pre-conditions: input n, list of integers
Post-condition: sorted list of integers
 =========================================================*/
void selectionSort(int n, int array[])
{
  int i, j;
  int minIndex = 0;
  for (i = 0; i < n; i++) { // creates a nested loop
    minIndex = i; // assignment of the smallest value in the list
    for (j = i + 1; j < n; j++) {
      if (array[j] < array[minIndex]) {
	minIndex = j;
      }
      comparisons ++;
    }
    if (minIndex != i) {
      int temp = array[i]; // creates a temporary placeholder for value of index i
      array[i] = array[minIndex]; // swaps index i with the minimum index
      array[minIndex] = temp; // swaps minimum index with original value of index i
      exchanges ++;
    }
 }
}

/*=========================================================
 insertionSort
Pre-conditions: input n, list of integers
Post-condition: sorted list of integers
 =========================================================*/
void insertionSort(int n, int array[])
{
  int i, j, item;
  for (i = 1; i < n; i++) { // creates a nested loop
    item = array[i]; // assigns value for item
    j = i - 1;
    while (j >= 0 && array[j] > item) { // compares two indices and looks for the smaller one
      array[j + 1] = array[j]; // assign later item with earlier item
      j--; // j moves towards the left
      comparisons ++;
    }
    array[j + 1] = item; // reassigns value for item
    exchanges ++;
  }
}

/*========================================================
printList
This algorithm takes a list of integers as input and prints
them all on one line.  
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
    for ( int i = 0; i < n; i++ )
        cout << array[i] << " ";
    cout << endl;
}

/*========================================================
 copyList
 This algorithm copies of list of integers from array a to
 array b.
 inputs:     n: number of integeres in both lists
 a: the list of original integers
 outputs:    no return value
 b: the copied list of original integers
 preconditions:
 input n, array a of integers
 postconditions:
 array b of integers which is an exact copy of array a
 ========================================================*/
void copyList(int n, int a[], int b[])
{
    for (int i = 0; i < n; i++ )
        b[i] = a[i];
}

/*========================================================
 isSorted
 An algorithm to test if an array of integers is in sorted
 ascending order.
 inputs:        n = number of integers in array
                array = array of possibly sorted integers
 outputs:       1 if array is in sorted order
                0 if not
 preconditions: valid input of n integers
 postconditions: proper return value of 1/0 (true/false)
 ========================================================*/
bool isSorted(int n, int array[])
{
    for (int i = 0; i < n-1; i++ )
        if ( array[i] > array[i+1] )
            return false;
    return true;
}
