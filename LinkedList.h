#ifndef LINKEDLIST2_H
#define LINKEDLIST2_H
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class LinkedList {
    private:
    Node *head = nullptr;
    int count = 0;
    Node *location = head;

    public:
    void AddItemFront(string *item);
    void AddItemEnd(string *item);
    string GetItem(string *item);
    string GetItemFront();
    bool IsInList(string *item);
    bool IsEmpty();
    int Length();
    string SeeNext();
    string SeeAt(int *location);
    void Reset();
    void Print();

};
#endif