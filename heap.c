//
//  heap.cpp
//  heap
//
//  Created by Kedar Brooks on 4/27/20.
//
#include "heap.h"

/*
 How it works:  
*/

heap::heap(int list[], int N) {
  heap::size = N; 
  for (int i=0; i < heap::size; i++)
  {
    heap::A.push_back(list[i]);
  }
}

int heap::PARENT(int i) {
  return i/2; 
}

int heap::LEFT(int i) {
  return i*2;
}

int heap::RIGHT(int i) {
  return (i*2)+1;
}

/* Prints data stored within data vector */ 
void heap::print() {
  // print RAW values
  for (int i=0; i < heap::size; i++) {
    // ternary operation for formatting
    cout <<  heap::A.at(i) << ((i == heap::size-1) ? "\n" : ", "); // (K-exlusive)
  } 
  cout << "Parent: " << heap::A.at(heap::PARENT(heap::size)) << endl;
  cout << "Left: " << heap::A.at(heap::LEFT(heap::PARENT(heap::size))) 
  << endl;
}