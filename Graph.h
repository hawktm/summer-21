#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <string>
#include "Node.cpp"
using namespace std;
class Graph {
    private:
        int numVertices = 0;
        Node vertices[1000];
        int nextVertex = 0;
    public:
        Graph();
        Graph(int givenVertices);
        void addEdge(string i, string j);
        bool removeEdge(string i, string j);
        bool hasEdge(string i, string j);
        vector<string> outEdges(string i);
        vector<string> inEdges(string i);
        ~Graph();
        void Print();
        void AddStates();

        bool shareThird(string i, string j);
};
#endif