#include <string>
#include <iostream>

#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    for (auto row : inputData) {
        if (row.empty()) continue;
        
        std::vector<Node*> rowOfNodes;
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
            std::cout << node->data;
        }
        std::cout << std::endl;
    }
}