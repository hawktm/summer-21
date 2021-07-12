#include "MaxPriority.cpp"
#include "MaxHeap.cpp"
#include "Node.cpp"
#include <iostream>
using namespace std;

int main() {
    // Create instance of MaxPriority and MaxHeap
    MaxPriority PriorityQueue;
    MaxHeap MyHeap;

    // Create variables to help in menu
    int item;
    int classOption;
    int menuOption;
    int inMenu = 1;

    // Menu of options to choose a data structure
    cout << "1. MaxPriority" << endl << "2. MaxHeap" << endl << "Enter a number to choose a data structure: ";
    cin >> classOption;

    switch(classOption)
    {
        case 1: // Menu of options to perform on MaxPriority
            while (inMenu == 1) {
                cout << "1. Insert item" << endl << "2. Remove item" << endl << "3. Print queue" << endl << "4. Exit menu" << endl << "Enter a number for testing method: ";
                cin >> menuOption;

                switch(menuOption)
                {
                    case 1:
                    // Insert item
                        cout << "Enter an integer to add to the queue: ";
                        cin >> item;
                        PriorityQueue.Insert(&item);
                        cout << item << " had been added to the queue!" << endl;
                        break;
                    
                    case 2:
                    // Remove item
                        item = PriorityQueue.Remove();
                        if (item != -1) {
                            cout << item << " has been removed from the queue!" << endl;
                        }
                        break;
                    
                    case 3:
                    // Print Queue
                        PriorityQueue.PrintQueue();
                        break;

                    case 4:
                    // Exit menu
                        inMenu = 0;
                        break;

                    case 5: 
                        cout << "Enter item to remove: ";
                        cin >> item;
                        item = PriorityQueue.Remove(&item);
                        if (item != -1) {
                            cout << item << " has been removed from the heap!" << endl;
                        }
                        break;
                }
            }
            break;

        case 2: // Menu of options to perform on MaxHeap
            while (inMenu == 1) {
                cout << "1. Insert item" << endl << "2. Remove item" << endl << "3. Print heap" << endl << "4. Exit menu" << endl << "Enter a number for testing method: ";
                cin >> menuOption;
                switch(menuOption)
                {
                    case 1:
                    // Insert item
                        cout << "Enter integer to add to heap: ";
                        cin >> item;
                        MyHeap.Insert(item);
                        cout << item << " has been added to the heap!" << endl;
                        break;
                    
                    case 2:
                    // Remove item
                        item = MyHeap.Remove();
                        if (item != -1) {
                            cout << item << " has been removed from the heap!" << endl;
                        }
                        break;
                    
                    case 3:
                    // Print heap
                        MyHeap.PrintHeap();
                        break;

                    case 4:
                    // Exit menu
                        inMenu = 0;
                        break;

                    case 5:
                        cout << "Enter item to remove: ";
                        cin >> item;
                        item = MyHeap.Remove(item);
                        if (item != -1) {
                            cout << item << " has been removed from the heap!" << endl;
                        }
                        break;
                }
            }
            break;

    }



    return 0;
}