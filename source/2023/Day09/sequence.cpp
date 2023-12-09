#include <string>
#include <iostream>
#include <sstream>

#include "sequence.h"

Sequence::Sequence(std::string sequence) {
    std::stringstream ss(sequence);
    std::string value;
    while (getline(ss, value, ' ')) {
        this->sequence.push_back(stoi(value));
    }
}

int Sequence::PostExtrapolatedValue(std::vector<int> sequence) {
    if (sequence.size() == 1) return sequence[0];

    // Check if all numbers in the vector are zero.
    bool isAllZeroes = true;
    for (auto a : sequence) {
        if (a != 0) {
            isAllZeroes = false;
            break;
        }
    }
    if (isAllZeroes) return 0;

    std::vector<int> differences;
    for (int i = 0; i < sequence.size()-1; i++) {
        differences.push_back(sequence[i + 1] - sequence[i]);
    }

    return sequence[sequence.size()-1] + this->PostExtrapolatedValue(differences);
}

int Sequence::PreExtrapolatedValue(std::vector<int> sequence) {
    if (sequence.size() == 1) return sequence[0];

    // Check if all numbers in the vector are zero.
    bool isAllZeroes = true;
    for (auto a : sequence) {
        if (a != 0) {
            isAllZeroes = false;
            break;
        }
    }
    if (isAllZeroes) return 0;

    std::vector<int> differences;
    for (int i = 0; i < sequence.size()-1; i++) {
        differences.push_back(sequence[i + 1] - sequence[i]);
    }

    return sequence[0] - this->PreExtrapolatedValue(differences);
}