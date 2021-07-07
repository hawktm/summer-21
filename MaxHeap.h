#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <limits>
using namespace std;

class MaxHeap {
    private:
        // Information on how to set data[0] to "infinity" found at https://stackoverflow.com/questions/8690567/setting-an-int-to-infinity-in-c
        int data[100] = {numeric_limits<int>::max()};
        int count = 0;

    public:
        void Insert(int item);
        int Remove();
        void PrintHeap();

        int ParentOf(int itemIndex);
        int RightChild(int itemIndex);
        int LeftChild(int itemIndex);
        void Swap(int parentIndex, int childIndex);
        void ReheapUp();
        void ReheapDown();


};
#endif