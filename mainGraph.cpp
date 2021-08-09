#include "Graph.cpp"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
   
    Graph graph;
    string vert;
    string touch;
    vector<string> outEdge;
    vector<string> inEdge;
    bool success;
    int inMenu = 1;
    int menuOption;
    while (inMenu == 1){
        cout << "Press 1 to add all states" << endl << "Press 2 to add an edge to graph." << endl << "Press 3 to remove an edge from graph." << endl << "Press 4 to find an edge in the graph." << endl << "Press 5 to find the out edges of a vertice." << endl << "Press 6 to find the in edges of a vertice." << endl << "Press 7 to print the graph." << endl << "Press 8 to quit" << endl;
        cin >> menuOption;
        // Checks the menu options entered, and procedes to specified option. Once user is finished in option, it pull back up the list
        switch (menuOption)
        {
            // Add states
            case 1:
                graph.AddStates();
                cout << "All 50 states have been added!" << endl;
                break;
            // Add edge
            case 2: cout << "Enter the vertice of the edge you are adding: ";
                cin >> vert;
                // while (vert != "0"){
                //     cout << "Enter the touching vertices(Enter '0' to stop): ";
                //     cin >> touch;
                //     graph.addEdge(vert, touch);
                // }
                cout << "Enter the ending vertice of the edge you are adding: ";
                cin >> touch;
                graph.addEdge(vert, touch);
                cout << "Edge has been added to graph!" << endl;
                break;
           // Remove edge
            case 3: cout << "Enter the vertice of the edge you are removing:  ";
                cin >> vert;
                // while (vert != "0"){
                //     cout << "Enter the touching vertices(Enter '0' to stop): ";
                //     cin >> touch;
                //     graph.removeEdge(vert, touch);
                // }
                cout << "Enter the ending vertice of the edge you are removing: ";
                cin >> touch;
                success = graph.removeEdge(vert, touch);
                if (success) {
                    cout << "Edge has been removed from the graph!" << endl;
                } else {
                    cout << "Edge not found in the graph" << endl;
                }
                break;
            // Find edge
            case 4: cout << "Enter vertice of the edge you would like to find: ";
                cin >> vert;
                cout << "Enter ending vertice of the edge you would like to find: ";
                cin >> touch;
                success = graph.hasEdge(vert, touch);
                if (success) {
                    cout << "Edge was found in the graph!" << endl;
                } else {
                    cout << "Edge not found in the graph" << endl;
                }
                break;
            // Find out edges
            case 5: cout << "Enter the vertice you would like to know number of out edges for: ";
                cin >> vert;
                outEdge = graph.outEdges(vert);
                cout << "Edges leaving vertex: " << endl;
                for (int i = 0; i < outEdge.size(); i++) {
                    cout << outEdge[i] << endl;
                }
                break;
            // Find in edges
            case 6: cout << "Enter the vertice you would like to know number of in edges for: ";
                cin >> vert;
                inEdge = graph.inEdges(vert);
                cout << "Edges entering vertex: " << endl;
                for (int i = 0; i < inEdge.size(); i++) {
                    cout << inEdge[i] << endl;
                }
                break;
            // Print graph
            case 7: 
                graph.Print();
                break;
            // Exit
            case 8: inMenu = 0;
                break;
            
            // Check thirdEdge
            case 9:
                cout << "Enter vertice i: ";
                cin >> vert;
                cout << "Enter vertice j: ";
                cin >> touch;
                success = graph.shareThird(vert, touch);
                if (success) {
                    cout << "Yes!" << endl;
                } else {
                    cout << "No!" << endl;
                }
        }
    }   




   return 0;
}