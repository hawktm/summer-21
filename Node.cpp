#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node(string *item){
    data = *item;
    next = nullptr;    
}