#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

class Node {
    	
    public:	
    string data;	
    Node *next;
    Node();
    Node(string *item);
};
#endif