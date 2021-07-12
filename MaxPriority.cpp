#include "MaxPriority.h"
#include <iostream>
using namespace std;

// Inserts item into correct location in queue based on priority
// param 1 - int item to add
// return - NONE
void MaxPriority::Insert(int *item) {
    Node *newNode = new Node(item);

    // Linked list is empty
    if (count == 0) {
        head = newNode;
        count++;
        return;
    }

    // If node is highest priority
    if (newNode->data > head->data) {
        newNode->next = head;
        head = newNode;
        count++;
        return;
    }

    // If node needs to be inserted elsewhere in the list
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data > newNode->data) {
        temp = temp->next;
    }

    Node *temp2 = temp->next;
    temp->next = newNode;
    newNode->next = temp2;
    count++;

}

// Removes highest priority item from the queue
// param 1 - NONE
// return - int value removed
int MaxPriority::Remove() {
    if (count == 0) {
        cout << "No items to delete: queue is empty" << endl;
        return -1;
    }

    int retVal = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    count--;
    return retVal;
}

int MaxPriority::Remove(int *item) {
    if (count == 0) {
        cout << "No items to delete: queue is empty" << endl;
        return -1;
    }

    int retVal;
    if (*item == head->data) {
        retVal = Remove();
        return retVal;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != *item) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Item not found in queue" << endl;
        return -1;
    }

    retVal = temp->next->data;
    Node *remove = temp->next;
    temp->next = temp->next->next;
    delete remove;
    count--;
    return retVal;
}

// Prints out contents of queue in priority order
// param 1 - NONE
// return - NONE
void MaxPriority::PrintQueue() {
    Node *temp = head;
    cout << "Contents of queue:" << endl;
    if (count != 0){
        for (int i = 0; i < count; i++){
            cout << temp->data << endl;
            temp = temp->next;
        }
    } else {
        cout << "List is empty"<< endl;
    }
}

