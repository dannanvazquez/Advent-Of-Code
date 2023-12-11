#include <string>
#include <iostream>
#include <stdlib.h>

#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    // Find what rows are empty.
    for (int i = 0; i < inputData.size(); i++) {
        if (inputData[i].find('#') == std::string::npos) {
            this->emptyRows.push_back(i);
        }
    }

    // Find what columns are empty.
    for (int i = 0; i < inputData[0].size(); i++) {
        bool isExpandable = true;
        for (int j = 0; j < inputData.size(); j++) {
            if (inputData[j][i] == '#') {
                isExpandable = false;
                break;
            }
        }

        if (isExpandable) {
            this->emptyCols.push_back(i);
        }
    }

    // Convert the now expanded data into nodes.
    for (int i = 0; i < inputData.size(); i++) {
        std::vector<Node*> rowOfNodes;
        for (int j = 0; j < inputData[i].size(); j++) {
            Node* newNode = new Node(i, j);
            if (inputData[i][j] == '#') {
                newNode->isGalaxy = true;
                this->galaxies.push_back(newNode);
            }
            rowOfNodes.push_back(newNode);
        }
        this->nodes.push_back(rowOfNodes);
    }
}

uint64_t Graph::SumOfLengths(int emptySpaceAmount) {
    uint64_t sumOfLengths = 0;
    
    for (int i = 0; i < this->galaxies.size()-1; i++) {
        int thisGalaxyRow = this->galaxies[i]->row;
        int thisGalaxyCol = this->galaxies[i]->col;
        for (int j = 1; j < this->galaxies.size()-i; j++) {
            int destinationGalaxyRow = this->galaxies[i+j]->row;
            int destinationGalaxyCol = this->galaxies[i+j]->col;
            sumOfLengths += abs(thisGalaxyRow - destinationGalaxyRow) + abs(thisGalaxyCol - destinationGalaxyCol);
            
            // Add empty space from rows
            if (destinationGalaxyRow > thisGalaxyRow) {
                for (int emptyRow : emptyRows) {
                    if (emptyRow > thisGalaxyRow && emptyRow < destinationGalaxyRow) {
                        sumOfLengths += emptySpaceAmount-1;
                    }
                }
            } else if (destinationGalaxyRow < thisGalaxyRow) {
                for (int emptyRow : emptyRows) {
                    if (emptyRow < thisGalaxyRow && emptyRow > destinationGalaxyRow) {
                        sumOfLengths += emptySpaceAmount-1;
                    }
                }
            }

            // Add empty space from cols
            if (destinationGalaxyCol > thisGalaxyCol) {
                for (int emptyCol : emptyCols) {
                    if (emptyCol > thisGalaxyCol && emptyCol < destinationGalaxyCol) {
                        sumOfLengths += emptySpaceAmount-1;
                    }
                }
            } else if (destinationGalaxyCol < thisGalaxyCol) {
                for (int emptyCol : emptyCols) {
                    if (emptyCol < thisGalaxyCol && emptyCol > destinationGalaxyCol) {
                        sumOfLengths += emptySpaceAmount-1;
                    }
                }
            }
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