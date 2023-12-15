#include <string>
#include <iostream>
#include <sstream>

#include "node.h"
#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    for (auto row : inputData) {
        if (row.empty()) continue;
        
        std::stringstream ss(row);
        std::string tmp;
        while (getline(ss, tmp, ',')) {
            Node* newNode = new Node(tmp);
            this->nodes.push_back(newNode);
        }
    }
}

int Graph::TotalHASHValue() {
    int totalHASHValue = 0;

    for (auto node : this->nodes) {
        totalHASHValue += node->HASHValue();
    }

    return totalHASHValue;
}

void Graph::PrintGraph() {
    for (auto node : this->nodes) {
        std::cout << node->data << std::endl;
    }
}