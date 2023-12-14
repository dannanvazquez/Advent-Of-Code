#include <string>
#include <iostream>

#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    for (auto row : inputData) {
        if (row.empty()) continue;
        
        this->data.push_back(row);
    }
}

int Graph::NorthLoad() {
    int northLoad = 0;

    std::vector<std::string> northTilt = this->data;

    for (int i = 0; i < northTilt.size(); i++) {
        for (int j = 0; j < northTilt[i].size(); j++) {
            if (northTilt[i][j] == 'O') {
                for (int k = 0; k <= i; k++) {
                    if (i-k-1 >= 0 && northTilt[i-k-1][j] == '.') {
                        northTilt[i-k-1][j] = 'O';
                        northTilt[i-k][j] = '.';
                    } else {
                        northLoad += northTilt.size() - i + k;
                        break;
                    }
                }
            }
        }
    }

    return northLoad;
}

void Graph::PrintGraph() {
    for (auto row : this->data) {
        std::cout << row << std::endl;
    }
}