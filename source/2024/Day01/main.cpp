#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

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

    vector<string> inputData = InputData();

    vector<int> firstRow;
    vector<int> secondRow;

    // Get needed rows of data.
    for (string s : inputData) {
        std::istringstream ss(s);
        int temp1, temp2;

        ss >> temp1 >> temp2;

        firstRow.push_back(temp1);
        secondRow.push_back(temp2);
    }

    // Sort rows from smallest to largest.
    sort(firstRow.begin(), firstRow.end());
    sort(secondRow.begin(), secondRow.end());

    // Get final results
    int result = 0;
    for (int i = 0; i < firstRow.size(); i++) {
        result += abs(firstRow[i] - secondRow[i]);
    }

    cout << "Final results: " << result << endl; 

    auto executionDuration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count();
    cout << "Execution duration: " << executionDuration << " ms\n";
}