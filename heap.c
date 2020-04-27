//
//  heap.cpp
//  heap
//
//  Created by Kedar Brooks on 4/27/20.
//
#include "heap.h"

heap::heap(int list[], int N) {
  heap::size = N; 
  for (int i=0; i < heap::size; i++) {
    heap::A.push_back(list[i]);
  }
}

int heap::PARENT(int i) {
  return i/2;   
}

int heap::LEFT(int i) {
  if(i == 0) {return 1;}
  return i*2;
}

int heap::RIGHT(int i) {
  return (i*2)+1;
}
/* Returns index of Left-most item */
int heap::LEFT() {
  return 0;
}
/* Returns index of Right-most item */
int heap::RIGHT() {
  return heap::size-1;
}

void heap::construct() {
    heap::downheap(0);
}

void heap::downheap(int i) {
  int newElement, child;
  newElement=A[i];
  /* k has child(s) */
  while(i <= heap::PARENT(heap::size)) { 
    child = heap::LEFT(i);
    /* pick larger child */
    if(child < heap::size && heap::A[child] < heap::A[child+1])
        child++;
    
    if(newElement >= heap::A[child]) break;
    /* else */
    heap::A[i] = heap::A[child]; /* move child up */
    i = child;
  }
  heap::A[i] = newElement;
}

void heap::insert(int data) {
   heap::size++;  
   heap::A.push_back(data);
   heap::upheap(heap::size-1);
}

void _swap(int x, int y) {
  int t = x;
  x = y; 
  y = t;  
}

void heap::upheap(int i) {
  if (i <= 1) //this handles the condition of the original while loop
    return;
  int p = heap::PARENT(i);
  if (A.at(i) >=1 && A.at(p) >= 1) 
    return; 
  _swap(i, p);
  upheap(p);
}

void heap::heapsort() {
  int i, temp;
   for(i=heap::PARENT(heap::size); i >= 1; i--)
      heap::downheap(i);
   /* a[1..N] is now a heap */

   for(i=heap::size; i >  1; i--)
    { 
      temp = A[i];
      A[i]=A[1]; /* largest of a[1..i] */
      A[1]=temp;

      temp = heap::size; 
      heap::size = i-1; 
      heap::downheap(1); /* restore a[1..i-1] heap */
      heap::size = temp; // restore size
    }
}


/* Prints data stored within data vector */ 
void heap::print() {
  // print RAW values
  for (int i=1; i < heap::size; i++) {
    // ternary operation for formatting
    cout <<  heap::A.at(i) << ((i == heap::size-1) ? "\n" : ", ");
  }
}