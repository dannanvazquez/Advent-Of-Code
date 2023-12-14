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

int Graph::SpinCycle(int spinTimes) {
    std::vector<std::string> spinData = this->data;
    int results[10] = {0};

    for (int spin = 0; spin < spinTimes; spin++) {
        // Tilt north
        for (int i = 0; i < spinData.size(); i++) {
            for (int j = 0; j < spinData[i].size(); j++) {
                if (spinData[i][j] == 'O') {
                    for (int k = 0; k <= i; k++) {
                        if (i-k-1 >= 0 && spinData[i-k-1][j] == '.') {
                            spinData[i-k-1][j] = 'O';
                            spinData[i-k][j] = '.';
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // Tilt west
        for (int i = 0; i < spinData.size(); i++) {
            for (int j = 0; j < spinData[i].size(); j++) {
                if (spinData[i][j] == 'O') {
                    for (int k = 0; k <= j; k++) {
                        if (j-k-1 >= 0 && spinData[i][j-k-1] == '.') {
                            spinData[i][j-k-1] = 'O';
                            spinData[i][j-k] = '.';
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // Tilt south
        for (int i = spinData.size()-1; i >= 0; i--) {
            for (int j = 0; j < spinData[i].size(); j++) {
                if (spinData[i][j] == 'O') {
                    for (int k = 0; k <= spinData.size()-1-i; k++) {
                        if (i+k+1 < spinData.size() && spinData[i+k+1][j] == '.') {
                            spinData[i+k+1][j] = 'O';
                            spinData[i+k][j] = '.';
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // Tilt east
        for (int i = 0; i < spinData.size(); i++) {
            for (int j = spinData[i].size()-1; j >= 0; j--) {
                if (spinData[i][j] == 'O') {
                    for (int k = 0; k <= spinData[i].size()-1-j; k++) {
                        if (j+k+1 < spinData[i].size() && spinData[i][j+k+1] == '.') {
                            spinData[i][j+k+1] = 'O';
                            spinData[i][j+k] = '.';
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // Cache results of this spin cycle
        results[spin % std::size(results)] = 0;
        for (int i = 0; i < spinData.size(); i++) {
            for (int j = 0; j < spinData[i].size(); j++) {
                if (spinData[i][j] == 'O') {
                    results[spin % std::size(results)] += spinData.size() - i;
                }
            }
        }

        // TODO: Fix this to find the loop early. Right now it currently checks the past 10 but that's not how the loop actually works. Loop instead repeats after multiple spin cycles.
        // Check if the past 10 cache results have been the same.
        /*bool isRepeating = true;
        for (int i = 1; i < std::size(results); i++) {
            if (results[(spin + i) % std::size(results)] != results[spin % std::size(results)]) {
                isRepeating = false;
                break;
            }
        }
        if (isRepeating) return results[spin % std::size(results)];*/
    }

    return results[(spinTimes-1) % std::size(results)];
}

void Graph::PrintGraph() {
    for (auto row : this->data) {
        std::cout << row << std::endl;
    }
}