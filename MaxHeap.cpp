#include "MaxHeap.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MaxHeap::Insert(int item) {
    count++;
    data[count] = item;
    ReheapUp();
}

int MaxHeap::Remove() {
    if (count == 0) {
        cout << "No items to delete: heap is empty" << endl;
        return -1;
    }

    int retVal = data[1];
    data[1] = data[count];
    data[count] = 0;
    count--;
    ReheapDown();
    return retVal;
}

int MaxHeap::Remove(int item) {
    if (count == 0) {
        cout << "No items to delete: heap is empty" << endl;
        return -1;
    }

    int find = 1;
    while(data[find] != item && find <= count) {
        find++;
    }

    if (find > count) {
        cout << "Item not found in heap" << endl;
        return -1;
    }

    int retVal = data[find];
    data[find] = data[count];
    data[count] = 0;
    count--;
    ReheapDown(find);
    return retVal;
}

void MaxHeap::PrintHeap() { // FIXME - NOT IN PRIORITY ORDER NECESSARILY
    cout << "Contents of heap: " << endl;
    // for (int i = 1; i <= count; i++) {
    //     cout << data[i] << endl;
    // }

    vector<int> printData;
    for (int i = 1; i <= count; i++) {
        printData.push_back(data[i]);
    }

    // Information about the sort function found at https://www.cplusplus.com/articles/NhA0RXSz/
    sort(printData.begin(), printData.end());

    for (int i = count; i > 0; i--) {
        cout << printData[i - 1] << endl;
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

    while (data[parent] < data[newItem]) {// new item needs to move up
	    Swap(parent, newItem); // swaps values at two indexes
	    newItem = ParentOf(newItem);
	    parent = ParentOf(newItem);
	}
}

void MaxHeap::ReheapDown() {
    int parent = 1;

    while (data[parent] < data[LeftChild(parent)] || data[parent] < data[RightChild(parent)]) {
	// new item needs to move up
        if (data[RightChild(parent)] < data[LeftChild(parent)]) {
            Swap(parent, LeftChild(parent)); // swaps values at two indexes
            parent = LeftChild(parent);
        } else {
            Swap(parent, RightChild(parent)); // swaps values at two indexes
            parent = RightChild(parent);
        }
	}
}

void MaxHeap::ReheapDown(int itemIndex) {
    int parent = itemIndex;

    while (data[parent] < data[LeftChild(parent)] || data[parent] < data[RightChild(parent)]) {
	// new item needs to move up
        if (data[RightChild(parent)] < data[LeftChild(parent)]) {
            Swap(parent, LeftChild(parent)); // swaps values at two indexes
            parent = LeftChild(parent);
        } else {
            Swap(parent, RightChild(parent)); // swaps values at two indexes
            parent = RightChild(parent);
        }
	}
}