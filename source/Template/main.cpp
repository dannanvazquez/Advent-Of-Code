#include <vector>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "node.h"
#include "graph.h"

vector<string> InputData() {
    vector<string> inputData;

    ifstream infile("input.txt");
    string line;
    while (getline(infile, line)) {
        inputData.push_back(line);
    }

    return inputData;
}

int main() {
    auto startTime = chrono::high_resolution_clock::now();

    Graph graph(InputData());
    graph.PrintGraph();

    auto executionDuration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count();
    cout << "Execution duration: " << executionDuration << " ms\n";
}