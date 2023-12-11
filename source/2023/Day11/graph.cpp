#include <string>
#include <iostream>
#include <stdlib.h>

#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    // Expand the input vertically when there are no galaxies.
    std::vector<std::string> verticalExpansion;
    for (auto row : inputData) {
        verticalExpansion.push_back(row);

        if (row.find('#') == std::string::npos) {
            verticalExpansion.push_back(row);
        }
    }

    // Expand the input horizontally when there are no galaxies.
    std::vector<std::string> horizontalExpansion(verticalExpansion.size(), "");
    for (int i = 0; i < verticalExpansion[0].size(); i++) {
        bool isExpandable = true;
        for (int j = 0; j < verticalExpansion.size(); j++) {
            if (verticalExpansion[j][i] == '#') {
                isExpandable = false;
                break;
            }
        }

        for (int j = 0; j < verticalExpansion.size(); j++) {
            horizontalExpansion[j] = horizontalExpansion[j] + verticalExpansion[j][i];
        }

        if (isExpandable) {
            for (int j = 0; j < verticalExpansion.size(); j++) {
                horizontalExpansion[j] = horizontalExpansion[j] + '.';
            }
        }
    }

    // Convert the now expanded data into nodes.
    for (int i = 0; i < horizontalExpansion.size(); i++) {
        std::vector<Node*> rowOfNodes;
        for (int j = 0; j < horizontalExpansion[i].size(); j++) {
            Node* newNode = new Node(i, j);
            if (horizontalExpansion[i][j] == '#') {
                newNode->isGalaxy = true;
                this->galaxies.push_back(newNode);
            }
            rowOfNodes.push_back(newNode);
        }
        this->nodes.push_back(rowOfNodes);
    }
}

int Graph::SumOfLengths() {
    int sumOfLengths = 0;
    
    for (int i = 0; i < this->galaxies.size()-1; i++) {
        for (int j = 1; j < this->galaxies.size()-i; j++) {
            sumOfLengths += abs(this->galaxies[i]->row - this->galaxies[i+j]->row) + abs(this->galaxies[i]->col - this->galaxies[i+j]->col);
        }
    }

    return sumOfLengths;
}

void Graph::PrintGraph() {
    for (auto row : this->nodes) {
        for (auto node : row) {
            std::cout << (node->isGalaxy ? '#' : '.');
        }
        std::cout << std::endl;
    }
}