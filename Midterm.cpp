#include <iostream>
#include "Node.cpp"
#include "LinkedList.cpp"
#include <string>
using namespace std;

// Strategy: (can use public members of LinkedList from modules/labs)
// 1. Use the Length() function to get the length of the list
// 2. Set up for loop to traverse through the list "length / 2" times (note: traversing through "length" times reverses and then reverses again, effectively ending where you started)
// 3. Use SeeAt() function to return data at length / 2 location
// 4. Remove this data and store in variable
// 5. Repeat steps 3 and 4
// 6. Add first item removed to the end and add second item removed to front
// Note: tested on paper to work for even and odd-length lists

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

    // // Use length to traverse through the list the correct number of times
    // for (int i = 0; i < length / 2; ++i) {
    //     int location = length / 2;

    //     // Return data at location
    //     string item1 = myList.SeeAt(&location);
    //     // Remove item1 and store
    //     item1 = myList.GetItem(&item1);

    //     // Return data at location
    //     string item2 = myList.SeeAt(&location);
    //     // Remove item2 and store
    //     item2 = myList.GetItem(&item2);

    //     // Insert item2 at front and item2 at end
    //     myList.AddItemFront(&item2);
    //     myList.AddItemEnd(&item1);

    // }

    string data[100];
    for (int i = 0; i < length; i++) {
        data[i] = myList.GetItemFront();
    }

    for (int j = 0; j < length; j++) {
        string item = data[j];
        myList.AddItemFront(&item);
    }

}

int main() {

    LinkedList myList1;
    int menuOption = 1;
    string item;

    while (menuOption != 0) {
        cout << "Enter item for storing into list: ";
        cin >> item;

        if (item != "done") {
            myList1.AddItemEnd(&item);
        } else {
            menuOption = 0;
        }
    }

    myList1.Print();
    cout << myList1.Length() << endl;
    reverseItems(myList1);
    myList1.Print();

    return 0;
}