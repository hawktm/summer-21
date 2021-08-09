#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node() {
    next = nullptr;
}

Node::Node(string *item){
    data = *item;
    next = nullptr;    
}