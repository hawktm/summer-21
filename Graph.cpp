#include "Graph.h"
using namespace std;

Graph::Graph() {
    numVertices = 1000;
}

Graph::Graph(int givenVertices) {
    numVertices = givenVertices;
}

void Graph::addEdge(string i, string j) {
    // Check if i and j are vertices already
    bool foundi = false;
    int iIndex;
    bool foundj = false;
    for (int k = 0; k < nextVertex; k++) {
        if (vertices[k].data == i) {
            foundi = true;
            iIndex = k;
        }

        if (vertices[k].data == j) {
            foundj = true;
        }
    }

    // Create new vertices if i and/or j do not exist yet
    if (foundi == false) {
        vertices[nextVertex] = Node(&i);
        iIndex = nextVertex;
        nextVertex++;
    }

    if (foundj = false) {
        vertices[nextVertex] = Node(&j);
        nextVertex++;
    }


    // Find end of list to add new edge
    Node *temp = &vertices[iIndex];
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node(&j);

}

bool Graph::removeEdge(string i, string j) {
    int iIndex;
    bool foundi = false;

    // Find i in array of vertices
    for (int k = 0; k < nextVertex; k++) {
        if (vertices[k].data == i) {
            iIndex = k;
            foundi = true;
            break;
        }
    }

    // If i does not exist, return false
    if (foundi == false) {
        return false;
    }
    
    // Find j in linked list associated with vertex i
    Node *temp = &vertices[iIndex];
    while (temp->next != nullptr) {
        if (temp->next->data == j) {
            Node *remove = temp->next;
            temp->next = temp->next->next;
            delete remove;
            return true;
        }
        temp = temp->next;
    }

    // If j is found in linked list associated with vertex i
    // if (temp->next->data == j) {
    //     Node *remove = temp->next;
    //     temp->next = temp->next->next;
    //     delete remove;
    //     return true;
    // }

    // If j is not found in linked list associated with vertex i
    return false;
}

bool Graph::hasEdge(string i, string j) {
    int iIndex;
    bool foundi = false;

    // Find i in array of vertices
    for (int k = 0; k < nextVertex; k++) {
        if (vertices[k].data == i) {
            iIndex = k;
            foundi = true;
            break;
        }
    }

    // If i does not exist, return false
    if (foundi == false) {
        return false;
    }
    
    // Find j in linked list associated with vertex i
    Node *temp = &vertices[iIndex];
    while (temp->next != nullptr) {
        if (temp->next->data == j) {
            return true;
        }
        temp = temp->next;
    }

    // If j is found in linked list associated with vertex i
    // if (temp->next->data == j) {
    //     return true;
    // }

    // If j is not found in linked list associated with vertex i
    return false;
}

vector<string> Graph::outEdges(string i) {
    int iIndex;
    bool foundi = false;
    vector<string> retVal;

    // Find i in array of vertices
    for (int k = 0; k < nextVertex; k++) {
        if (vertices[k].data == i) {
            iIndex = k;
            foundi = true;
            break;
        }
    }

    // If i does not exist, return empty vector
    if (foundi == false) {
        return retVal;
    }

    // If i does exist, add all nodes linked to it
    Node *temp = &vertices[iIndex];
    temp = temp->next;
    while (temp != nullptr) {
        retVal.push_back(temp->data);
        temp = temp->next;
    }
    return retVal;
    
}

vector<string> Graph::inEdges(string i) {
    vector<string> retVal;
    Node *temp;

    for (int k = 0; k < nextVertex; k++) {
        Node *temp = &vertices[k];
        temp = temp->next;
        while (temp != nullptr) {
            if (temp->data == i) {
                retVal.push_back(vertices[k].data);
                break;
            }
            temp = temp->next;
        }
    }

    return retVal;
}

Graph::~Graph() {
    for (int k = 0; k < nextVertex; k++) {
        Node *temp = &vertices[0];
        while (temp != nullptr) {
            Node *remove = temp;
            temp = temp->next;
            delete remove;
        }
    }
}

void Graph::Print() {
    for (int k = 0; k < nextVertex; k++) {
        cout << "Vertex: " << vertices[k].data << "\t";
        cout << "Edges: ";
        Node *temp = &vertices[k];
        temp = temp->next;
        if (temp == nullptr) {
            cout << "None" << endl;
            continue;
        }
        while (temp->next != nullptr) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}

void Graph::AddStates(){
    Graph Graph;

    // Alabama
    addEdge("Alabama", "Mississipppi");
    addEdge("Alabama", "Tennessee");
    addEdge("Alabama", "Georgia");
    addEdge("Alabama", "Florida");

    // Alaska
    addEdge("Alaska", "No State");

    // Arizona
    addEdge("Arizona", "California");
    addEdge("Arizona", "Nevada");
    addEdge("Arizona", "Utah");
    addEdge("Arizona", "New Mexico");
    addEdge("Arizona", "Colorado");

    // Arkansas
    addEdge("Arkansas", "Mississipppi");
    addEdge("Arkansas", "Lousisiana");
    addEdge("Arkansas", "Texas");
    addEdge("Arkansas", "Oklahoma");
    addEdge("Arkansas", "Missouri");
    addEdge("Arkansas", "Tennessee");

    // California
    addEdge("California", "Oregon");
    addEdge("Califonia", "Nevada");
    addEdge("Califonia", "Arizona");

    // Colorado
    addEdge("Colorado", "New Mexico");
    addEdge("Colorado", "Arizona");
    addEdge("Colorado", "Utah");
    addEdge("Colorado", "Wyoming");
    addEdge("Colorado", "Nebraska");
    addEdge("Colorado", "Oklahoma");
    addEdge("Colorado", "Kansas");

    // Connecticut
    addEdge("Connecticut", "New York");
    addEdge("Connecticut", "Rhode Island");
    addEdge("Connecticut", "Massachusettes");

    // Delaware
    addEdge("Delaware", "Maryland");
    addEdge("Delaware", "Pennsylvania");
    addEdge("Delaware", "New Jersey");

    // Florida
    addEdge("Florida", "Georgia");
    addEdge("Florida", "Alabama");

    // Georgia
    addEdge("Georgia", "Florida");
    addEdge("Georgia", "Alabama");
    addEdge("Georgia", "Tennessee");
    addEdge("Georgia", "North Carolina");
    addEdge("Georgia", "South Carolina");

    // Hawaii
    addEdge("Hawaii", "No State");

    // Idaho
    addEdge("Idaho", "Washington");
    addEdge("Idaho", "Oregon");
    addEdge("Idaho", "Nevada");
    addEdge("Idaho", "Utah");
    addEdge("Idaho", "Wyoming");
    addEdge("Idaho", "Montana");

    // Illinois
    addEdge("Illinois", "Wisconsin");
    addEdge("Illinois", "Iowa");
    addEdge("Illinois", "Missouri");
    addEdge("Illinois", "Kentucky");
    addEdge("Illinois", "Indiana");

    // Indiana
    addEdge("Indiana", "Michigan");
    addEdge("Indiana", "Ohio");
    addEdge("Indiana", "Kentucky");
    addEdge("Indiana", "Illinois");
    
    // Iowa
    addEdge("Iowa", "Minnesota");
    addEdge("Iowa", "Wisconsin");
    addEdge("Iowa", "Illinois");
    addEdge("Iowa", "Missouri");
    addEdge("Iowa", "Nebraska");
    addEdge("Iowa", "South Dakota");

    // Kansas
    addEdge("Kansas", "Colorado");
    addEdge("Kansas", "Nebraska");
    addEdge("Kansas", "Missouri");
    addEdge("Kansas", "Oklahoma");

    // Kentucky
    addEdge("Kentucky", "Indiana");
    addEdge("Kentucky", "Ohio");
    addEdge("Kentucky", "West Virginia");
    addEdge("Kentucky", "Virginia");
    addEdge("Kentucky", "Tennessee");
    addEdge("Kentucky", "Missouri");
    addEdge("Kentucky", "Illinois");

    // Louisiana
    addEdge("Louisiana", "Texas");
    addEdge("Louisiana", "Arkansas");
    addEdge("Louisiana", "Mississippi");

    // Maine
    addEdge("Maine", "New Hampshire");

    // Maryland
    addEdge("Maryland", "Virginia");
    addEdge("Maryland", "West Virginia");
    addEdge("Maryland", "Pennsylvania");
    addEdge("Maryland", "Delaware");

    // Massachusettes
    addEdge("Massachusettes", "Rhode Island");
    addEdge("Massachusettes", "Connecticut");
    addEdge("Massachusettes", "New York");
    addEdge("Massachusettes", "Vermont");
    addEdge("Massachusettes", "New Hampshire");

    // Michigan
    addEdge("Michigan", "Ohio");
    addEdge("Michigan", "Indiana");
    addEdge("Michigan", "Wisconsin");

    // Minnesota
    addEdge("Minnesota", "Wisconsin");
    addEdge("Minnesota", "Iowa");
    addEdge("Minnesota", "South Dakota");
    addEdge("Minnesota", "North Dakota");

    // Mississippi
    addEdge("Mississippi", "Lousisiana");
    addEdge("Mississippi", "Arkansas");
    addEdge("Mississippi", "Tennessee");
    addEdge("Mississippi", "Alabama");

    // Missori
    addEdge("Missouri", "Iowa");
    addEdge("Missouri", "Illinois");
    addEdge("Missouri", "Kentucky");
    addEdge("Missouri", "Tennessee");
    addEdge("Missouri", "Arkansas");
    addEdge("Missouri", "Oklahoma");
    addEdge("Missouri", "Kansas");
    addEdge("Missouri", "Nebraska");

    // Montana
    addEdge("Montana", "North Dakota");
    addEdge("Montana", "South Dakota");
    addEdge("Montana", "Wyoming");
    addEdge("Montana", "Idaho");

    // Nebraska
    addEdge("Nebraska", "South Dakota");
    addEdge("Nebraska", "Iowa");
    addEdge("Nebraska", "Missouri");
    addEdge("Nebraska", "Kansas");
    addEdge("Nebraska", "Colorado");
    addEdge("Nebraska", "Wyoming");

    // Nevada
    addEdge("Nevada", "California");
    addEdge("Nevada", "Oregon");
    addEdge("Nevada", "Idaho");
    addEdge("Nevada", "Utah");
    addEdge("Nevada", "Arizona");

    // New Hampshire
    addEdge("New Hampshire", "Maine");
    addEdge("New Hampshire", "Massachusettes");
    addEdge("New Hampshire", "Vermont");

    // New Jersey
    addEdge("New Jersey", "New York");
    addEdge("New Jersey", "Pennsylvania");
    addEdge("New Jersey", "Delware");

    // New Mexico
    addEdge("New Mexico", "Arizona");
    addEdge("New Mexico", "Utah");
    addEdge("New Mexico", "Colorado");
    addEdge("New Mexico", "Oklahoma");
    addEdge("New Mexico", "Texas");

    // New York
    addEdge("New York", "Vermont");
    addEdge("New York", "Massacusettes");
    addEdge("New York", "Connecticut");
    addEdge("New York", "New Jersey");
    addEdge("New York", "Pennsylvania");

    // North Carolina
    addEdge("North Carolina", "South Carolina");
    addEdge("North Carolina", "Georgia");
    addEdge("North Carolina", "Tennessee");
    addEdge("North Carolina", "Virginia");

    // North Dakota
    addEdge("North Dakota", "Minnesota");
    addEdge("North Dakota", "South Dakota");
    addEdge("North Dakota", "Montana");

    // Ohio
    addEdge("Ohio", "Pennsylvania");
    addEdge("Ohio", "West Virginia");
    addEdge("Ohio", "Kentucky");
    addEdge("Ohio", "Indiana");
    addEdge("Ohio", "Michigan");

    // Oklahoma
    addEdge("Oklahoma", "Kansas");
    addEdge("Oklahoma", "Missouri");
    addEdge("Oklahoma", "Arkansas");
    addEdge("Oklahoma", "Texas");
    addEdge("Oklahoma", "New Mexico");
    addEdge("Oklahoma", "Colorado");

    // Oregon
    addEdge("Oregon", "Washington");
    addEdge("Oregon", "Idaho");
    addEdge("Oregon", "Nevada");
    addEdge("Oregon", "California");

    // Pennsylvania
    addEdge("Pennsylvania", "New York");
    addEdge("Pennsylvania", "New Jersey");
    addEdge("Pennsylvania", "Delaware");
    addEdge("Pennsylvania", "Maryland");
    addEdge("Pennsylvania", "West Virginia");
    addEdge("Pennsylvania", "Ohio");

    // Rhode Island
    addEdge("Rhode Island", "Massachusettes");
    addEdge("Rhode Island", "Connecticut");

    // South Carolina
    addEdge("South Carolina", "North Carolina");
    addEdge("South Carolina", "Georgia");
    
    // South Dakota
    addEdge("South Dakota", "North Dakota");
    addEdge("South Dakota", "Minnesota");
    addEdge("South Dakota", "Iowa");
    addEdge("South Dakota", "Nebraska");
    addEdge("South Dakota", "Wyoming");
    addEdge("South Dakota", "Montana");
    
    // Tennessee
    addEdge("Tennessee", "Kentucky");
    addEdge("Tennessee", "Virginia");
    addEdge("Tennessee", "North Carolina");
    addEdge("Tennessee", "Georgia");
    addEdge("Tennessee", "Alabama");
    addEdge("Tennessee", "Mississippi");
    addEdge("Tennessee", "Arkansas");
    addEdge("Tennessee", "Missouri");
    
    // Texas
    addEdge("Texas", "Oklahoma");
    addEdge("Texas", "New Mexico");
    addEdge("Texas", "Louisiana");
    addEdge("Texas", "Arkansas");
    
    // Utah
    addEdge("Utah", "Colorado");
    addEdge("Utah", "Wyoming");
    addEdge("Utah", "Idaho");
    addEdge("Utah", "Nevada");
    addEdge("Utah", "Arizona");
    addEdge("Utah", "New Mexico");
    
    // Vermont
    addEdge("Vermont", "New Hampshire");
    addEdge("Vermont", "New York");
    addEdge("Vermont", "Massachusetts");
    
    // Virginia
    addEdge("Virginia", "West Virginia");
    addEdge("Virginia", "North Carolina");
    addEdge("Virginia", "Tennessee");
    addEdge("Virginia", "Kentucky");
    addEdge("Virginia", "Maryland");
    
    // Washington
    addEdge("Washington", "Oregon");
    addEdge("Washington", "Idaho");
    
    // West Virginia
    addEdge("West Virginia", "Pennsylvania");
    addEdge("West Virginia", "Ohio");
    addEdge("West Virginia", "Kentucky");
    addEdge("West Virginia", "Virginia");
    addEdge("West Virginia", "Maryland");
    
    // Wisconsin
    addEdge("Wisconsin", "Minnesota");
    addEdge("Wisconsin", "Michigan");
    addEdge("Wisconsin", "Illinois");
    addEdge("Wisconsin", "Iowa");
    
    // Wyoming 
    addEdge("Wyoming", "Montana");
    addEdge("Wyoming", "Idaho");
    addEdge("Wyoming", "Colorado");
    addEdge("Wyoming", "Utah");
    addEdge("Wyoming", "Nebraska");
    addEdge("Wyoming", "South Dakota");

}

// Strategy:
// 1. Check to make sure i and j are vertices in graph
//      - If one or both are not, return false
//      - If both are in graph, continue to step 2
// 2. Check to see if j is in list of edges with i (undirected, so only need to check one, not both lists)
//      - If is in list, return false
//      - If not in list, continue to step 3
// 3. Compare outEdges of i and j to see if any are the same (start with first string in i list and compare with all strings in j list, move onto next string if not found)
//      - If one is the same, return true
//      - If none are the same, return false

bool Graph::shareThird(string i, string j) {
    // Find index of i and j
    bool foundi = false;
    bool foundj = false;
    int iIndex;
    int jIndex;
    // nextVertex: variable used to indicate where next added vertex would go (like a counter)
    for (int k = 0; k < nextVertex; k++) {
        if (vertices[k].data == i) {
            foundi = true;
            iIndex = k;
        }

        if (vertices[k].data == j) {
            foundj = true;
            jIndex = k;
        }
    }

    // Verify i and j are in vertice array
    if (foundi == false || foundj == false) {
        cout << "One or both entered strings do not exist in graph" << endl;
        return false;
    }

    // Check to see if j in list of edges for i
    // Set pointer to where i is located
    Node *temp = &vertices[iIndex];
    while (temp != nullptr) {
        if (temp->data == j) {
            return false;
        }
        temp = temp->next;
    }

    // Compare i and j edges
    // Set iEdges pointer to first edge in i list
    Node *iEdges = &vertices[iIndex];
    iEdges = iEdges->next;

    while (iEdges != nullptr) {
        // Set jEdges pointer to first edge in j list
        Node *jEdges = &vertices[jIndex];
        jEdges = jEdges->next;
        while (jEdges != nullptr) {
            if (iEdges->data == jEdges->data) {
                return true;
            }
            jEdges = jEdges->next;
        }
        iEdges = iEdges->next;
    }

    // Return false if none found
    return false;
}