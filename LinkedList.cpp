#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

// Adds an item to the front of the list
// param 1 - item to add to list
// return - NONE
void LinkedList::AddItemFront(string *item) {
    Node *object = new Node(item);
    object->next = head;
    head = object;
    count++;
}

// Adds an item to the end of the list
// param 1 - item to add to list
// return - NONE
void LinkedList::AddItemEnd(string *item){
    if(IsEmpty() == false){
        Node *object = new Node(item);
        Node *temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = object;
        count++;
    }
    else{
        AddItemFront(item);
    }

    /*Node *NewNode;
    NewNode=new Node(item);
    NewNode->data=*item;
    NewNode->next=nullptr;

    Node *EndNode;
    EndNode=head;

    if(EndNode == nullptr)
       EndNode=NewNode;
    else
    {
        while(EndNode->next!=nullptr)
            EndNode=EndNode->next;
        EndNode->next=NewNode;

    }*/
}

// Searches the list for given item and removes it from the list.
// param 1 - item to remove from list
// return - removed value
string LinkedList::GetItem(string *item){
    if(IsEmpty() == false){
        string retVal;
        Node *temp = head;
        if (head->data == *item) {
            retVal = head->data;
            head = head->next;
            delete temp;
            count--;
            return retVal;
        }
        for (int i = 0; i < count - 2; i++) {
            temp = temp->next;
            cout << endl;
            if(temp->next->data == *item){
                break;
            }
            if(i == count - 3){
                temp = nullptr;
                return "Error";
                break;
            }
        }
        retVal = temp->next->data;
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        count--;
        return retVal;
    }
    else{
        return "Empty";
    }
}

// Gets the first item in the list
// param 1 - NONE
// return - First value in list
string LinkedList::GetItemFront(){
    if(IsEmpty() == false){
        string retVal = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        count--;
        return retVal;
    }
    else{
        cout << "List is empty" << endl;
        return "Error";
    }
}

// Checks if an item is included in the list
// param 1 - item to find in list
// return - true/false
bool LinkedList::IsInList(string *item){
    Node *temp = head;
    if(IsEmpty() == false){
        if (head->data == *item) {
            return true;
        }
        for (int i = 0; i < count - 2; i++) {
            temp = temp->next;
            cout << endl;
            if(temp->next->data == *item){
                break;
            }
            if(i == count - 3){
                temp = nullptr;
                return false;
                break;
            }
        }
    }
    else{
        cout << "List is empty" << endl;
        return false;
    }
    return true;
}

// Checks if the list is empty
// param 1 - NONE
// return - true/false
bool LinkedList::IsEmpty(){
    if (count == 0){
        return true;
    }
    return false;
}

// Checks the size of the list
// param 1 - NONE
// return - size of list
int LinkedList::Length(){
    return count;

}

// Shows the next item in the list
// param 1 - NONE
// return - Next item in list
string LinkedList::SeeNext(){
    if(IsEmpty() == false){
        if (location == nullptr) {
            location = head;
            //return location->data;
        }
        else{

            location = location->next;
            if(location == nullptr){
                return "Error";
            }
    }
        return location->data;
    } else{
        return "Empty";
    }
}

// Shows the value at a given position
// param 1 - Position
// return - Value at position
string LinkedList::SeeAt(int *positionGiven){
    if(IsEmpty() == false){
        location = 0;
        for (int i = 1; i < *positionGiven; i++){
            cout << "Location: "<< location << endl;
            location = location->next;
            if(location == nullptr){
                return "Error";
                break;
            }
        }
        return location->data;
    } else{
        cout << "List is empty" << endl;
        return "Empty";
    }
}

// Returns location to find values back to head
// param 1 - NONE
// return - NONE
void LinkedList::Reset(){
    location = head;
}

// Prints out all contents of list
// param 1 - NONE
// return - NONE
void LinkedList::Print(){
    cout << "Contents of list: " << endl;
    Node *temp = head;
        if(IsEmpty() == false){
            for(int i = 0; i < count; i++){
                cout << temp->data << endl;
                temp = temp->next;
            }
        } else {
            cout << "List is empty"<< endl;
        }
}