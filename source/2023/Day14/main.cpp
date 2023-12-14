#include <vector>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "graph.h"

std::vector<std::string> InputData() {
    std::vector<std::string> inputData;

    std::ifstream infile("input.txt");
    std::string line;
    while (getline(infile, line)) {
        inputData.push_back(line);
    }

    return inputData;
}

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    Graph graph(InputData());
    
    int northLoad = graph.NorthLoad();
    std::cout << "Total load on the north support beams: " << northLoad << std::endl;

    auto executionDuration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count();
    std::cout << "Execution duration: " << executionDuration << " ms\n";
}