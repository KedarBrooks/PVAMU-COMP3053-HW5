//
//  main.cpp
//  heap
//
//  Created by Lei Huang on 4/17/20.
//

#include <iostream>
#include "heap.c"
// Max Heap C++ implementation
int main()
{
    int A[] = {2,9,7,6,5,8};
    int size = 6;
    // construct a heap
    heap h(A, size);
    
    cout << "Before the heap construction:" << endl;
    // This is a complete binary tree
    h.print();
    
    // Perform downheap() to create a heap
    h.construct();
    // This is a heap now
    cout << "After the heap construction:" << endl;
    h.print();

    h.insert(4);  // need to do upheap() to fix the heap when inserting a new number
    h.print();
    
    h.insert(10);
    h.print();
    
    cout << "Sorted Heap: " << endl; 
    h.heapsort();
    h.print();  // I should see a sorted list now

    return 0;
}
