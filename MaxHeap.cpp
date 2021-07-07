#include "MaxHeap.h"
#include <iostream>
using namespace std;

void MaxHeap::Insert(int item) {
    count++;
    data[count] = item;
    ReheapUp();
}

int MaxHeap::Remove() {
    data[1] = data[count];
    data[count] = 0;
    count--;
    ReheapDown();
}

void MaxHeap::PrintHeap() { // FIXME - NOT IN PRIORITY ORDER NECESSARILY
    cout << "Contents of heap: " << endl;
    for (int i = 0; i < count; i++) {
        cout << data[i] << endl;
    }
}

int MaxHeap::ParentOf(int itemIndex) {
    return itemIndex / 2;
}

int MaxHeap::RightChild(int itemIndex) {
    return itemIndex * 2;
}

int MaxHeap::LeftChild(int itemIndex) {
    return itemIndex * 2 + 1;
}

void MaxHeap::Swap(int parentIndex, int childIndex) {
    int temp = data[parentIndex];
    data[parentIndex] = data[childIndex];
    data[childIndex] = temp;
}

void MaxHeap::ReheapUp() {
    int newItem = count;
    int parent = ParentOf(count);

    while (data[parent] > data[newItem]) {// new item needs to move up
	    Swap(parent, count); // swaps values at two indexes
	    newItem = ParentOf(newItem);
	    parent = ParentOf(newItem);
	}
}

void MaxHeap::ReheapDown() {
    int parent = data[1];

    while (data[parent] > data[LeftChild(parent)] || data[parent] > data[RightChild(parent)]) {
	// new item needs to move up
        if (data[RightChild(parent)] > data[LeftChild(parent)]) {
            Swap(parent, LeftChild(parent)); // swaps values at two indexes
            parent = LeftChild(parent);
        } else {
            Swap(parent, RightChild(parent)); // swaps values at two indexes
            parent = RightChild(parent);
        }
	}
}