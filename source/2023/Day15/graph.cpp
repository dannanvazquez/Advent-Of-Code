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
        totalHASHValue += node->EntireHASHValue();
    }

    return totalHASHValue;
}

int Graph::FocusingPower() {
    for (auto node : this->nodes) {
        node->DistributeData();
        if (node->focalLength > 0) {
            if (this->hashMap.count(node->labelHash)) {
                this->hashMap[node->labelHash]->InsertNode(node);
            } else {
                ChainingHash* newHash = new ChainingHash(node);
                this->hashMap[node->labelHash] = newHash;
            }
        } else {
            if (this->hashMap.count(node->labelHash)) {
                this->hashMap[node->labelHash]->RemoveLabel(node->label);
            } 
        }
    }

    int focusingPower = 0;

    for (auto hash : this->hashMap) {
        focusingPower += hash.second->FocusingPower();
    }

    return focusingPower;
}

void Graph::PrintGraph() {
    for (auto node : this->nodes) {
        std::cout << node->data << std::endl;
    }
}

void Graph::PrintFocusingPower() {
    for (auto hash : this->hashMap) {
        hash.second->Print();
    }
}