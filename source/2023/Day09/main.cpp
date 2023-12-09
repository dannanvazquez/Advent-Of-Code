#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

#include "sequence.h"

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    int sumOfExtrapolatedValues = 0;

    std::ifstream infile("input.txt");
    std::string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        Sequence newSequence(line);
        sumOfExtrapolatedValues += newSequence.ExtrapolatedValue(newSequence.sequence);
    }

    std::cout << "Sum of extrapolated values: " << sumOfExtrapolatedValues << std::endl;

    std::cout << "Execution duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count() << " ms\n";
}