#include <iostream>
#include "Node.cpp"
#include "LinkedList.cpp"
#include <string>
using namespace std;


// Strategy:
// 1. Use the Length() function to get the length of the list
// 2. Declare an array of size 100 to store data
// 3. Set up for loop to remove first item in list and store in next spot in array, effectively transferring it to the array
// 4. Set up for loop to go in order through the array adding each item to the front, effectively reversing the list

// FunctionName: reverseItems
// Parameter: Single linked, unordered list
// Goal of function: reverse the order of the items in the list (ie. first item swaps with last, second item swaps with second-to-last item, etc.)
void reverseItems(LinkedList myList) {
    // Get length of linked list
    int length = myList.Length();

    // Declare array to store data
    string data[100];

    // Traverse through list, removing items from front and adding to array
    for (int i = 0; i < length; i++) {
        data[i] = myList.GetItemFront();
    }

    // Traverse through the array, adding next item to front of list to reverse the list
    for (int i = 0; i < length; i++) {
        string item = data[i];
        myList.AddItemFront(&item);
    }

}