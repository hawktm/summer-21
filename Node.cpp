#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node(int *item){
    data = *item;
    next = nullptr;    
}