#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

#include "node.h"
#include "graph.h"

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    Graph graph;

    std::ifstream infile("input.txt");
    std::string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        graph.InsertRow(line);
    }

    int furthestStepAway = graph.FurthestStepAway();
    std::cout << "Furthest step away: " << furthestStepAway << std::endl;

    auto executionDuration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count();
    std::cout << "Execution duration: " << executionDuration << " ms\n";
}