#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

#include "sequence.h"

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    int sumOfPostExtrapolatedValues = 0;
    int sumOfPreExtrapolatedValues = 0;

    std::ifstream infile("input.txt");
    std::string line;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        Sequence newSequence(line);
        sumOfPostExtrapolatedValues += newSequence.PostExtrapolatedValue(newSequence.sequence);
        sumOfPreExtrapolatedValues += newSequence.PreExtrapolatedValue(newSequence.sequence);
    }

    std::cout << "Sum of post extrapolated values: " << sumOfPostExtrapolatedValues << std::endl;
    std::cout << "Sum of pre extrapolated values: " << sumOfPreExtrapolatedValues << std::endl;

    std::cout << "Execution duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count() << " ms\n";
}