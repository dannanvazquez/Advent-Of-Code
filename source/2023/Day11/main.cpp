#include <vector>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "node.h"
#include "graph.h"

std::vector<std::string> InputData() {
    std::vector<std::string> inputData;

    std::ifstream infile("input.txt");
    std::string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        inputData.push_back(line);
    }

    return inputData;
}

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    Graph graph(InputData());

    uint64_t sumOfLengths1 = graph.SumOfLengths(2);
    std::cout << "Sum of lengths with two empty spaces: " << sumOfLengths1 << std::endl;

    uint64_t sumOfLengths2 = graph.SumOfLengths(1'000'000);
    std::cout << "Sum of lengths with a million empty spaces: " << sumOfLengths2 << std::endl;

    auto executionDuration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count();
    std::cout << "Execution duration: " << executionDuration << " ms\n";
}