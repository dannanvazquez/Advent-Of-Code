#include <string>
#include <iostream>

#include "node.h"
#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    std::vector<std::string> data;
    for (auto row : inputData) {
        if (row.empty()) {
            this->InsertNode(data);
            data.clear();
        } else {
            data.push_back(row);
        }
    }

    if (data.size() > 0) {
        this->InsertNode(data);
        data.clear();
    }
}

void Graph::InsertNode(std::vector<std::string> data) {
    Node* newNode = new Node(data);
    this->nodes.push_back(newNode);
}

int Graph::ReflectionSummary() {
    int reflectionSummary = 0;

    for (auto node : this->nodes) reflectionSummary += node->ReflectionScore();

    return reflectionSummary;
}

void Graph::PrintGraph() {
    for (auto node : this->nodes) {
        for (std::string row : node->data) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }
}