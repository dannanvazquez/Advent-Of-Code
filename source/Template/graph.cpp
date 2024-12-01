#include <string>
#include <iostream>

#include "graph.h"

using namespace std;

Graph::Graph(vector<string> inputData) {
    for (auto row : inputData) {
        if (row.empty()) continue;
        
        vector<Node*> rowOfNodes;
        for (auto c : row) {
            Node* newNode = new Node(c);
            rowOfNodes.push_back(newNode);
        }
        this->nodes.push_back(rowOfNodes);
    }
}

void Graph::PrintGraph() {
    for (auto row : this->nodes) {
        for (auto node : row) {
            cout << node->data;
        }
        cout << endl;
    }
}