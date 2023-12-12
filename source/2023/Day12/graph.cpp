#include <string>
#include <iostream>

#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    for (auto row : inputData) {
        Node* newNode = new Node(row);
        this->nodes.push_back(newNode);
    }
}

int Graph::TotalArrangements() {
    int totalArrangements = 0;

    for (auto node : this->nodes) {
        totalArrangements += node->ArrangementsCount();
    }

    return totalArrangements;
}

void Graph::PrintGraph() {
    for (auto node : this->nodes) {
        std::cout << node->springs;
        for (auto group : node->groupsDamaged) {
            std::cout << " " << group;
        }
        std::cout << "; Arrangements: " << node->arrangements << std::endl;
    }
}