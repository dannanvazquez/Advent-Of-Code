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

    std::string directions;
    getline(infile, directions);
    graph.SetDirections(directions);

    std::string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;
        graph.AddNode(line);
    }

    int distanceBetweenNodes = graph.DistanceBetweenNodes("AAA", "ZZZ");
    std::cout << "Steps to reach ZZZ: " << distanceBetweenNodes << std::endl;

    uint64_t distanceTillAllNodesEndIn = graph.DistanceTillAllNodesEndAt('A', 'Z');
    std::cout << "Steps for all nodes to end at Z: " << distanceTillAllNodesEndIn << std::endl;

    std::cout << "Execution duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count() << " ms\n";
}