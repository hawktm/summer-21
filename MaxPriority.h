#ifndef MAXPRIORITY_H
#define MAXPRIORITY_H
#include "Node.h"
#include <iostream>
using namespace std;

class MaxPriority {
    private:
        Node *head = nullptr;
        int count = 0;

    public:
        void Insert(int *item);
        int Remove();
        int Remove(int *item);
        void PrintQueue();
};
#endif