//
//  heap.hpp
//  heap
//
//  Created by Lei Huang on 4/17/20.
//

#ifndef heap_hpp
#define heap_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class heap
{
private:
    int size; 
    vector<int> A;      // heap data: int A[];
    
public:
    heap(int list[], int N); // construct a heap
    int PARENT(int i);   // parent index = child indx / 2
    int LEFT();          // Before Construction: Returns index Start
    int RIGHT();         // Before Construction: Returns index End
    int LEFT(int i);     // left index = parent index * 2
    int RIGHT(int i);    // right index = (parent index * 2) + 1
    
    void downheap(int i);  // going down the heap to correct it
    void upheap(int i);    // going up the heap to correct it
    void construct();      // construct the heap
    void insert(int data); // insert a new data into the heap
    void heapsort();   // print a sorted list by extracting the root one by one
    void print();
};


#endif /* heap_hpp */
