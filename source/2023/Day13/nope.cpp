#include <string>
#include <vector>
#include <iostream>

#include "node.h"

Node::Node(std::vector<std::string> data) {
    this->data = data;
}

int GetHorizontalReflection(std::vector<std::string> data) {
    int reflectionScore = 0;

    for (int i = 0; i < data.size()-1; i++) {
        int isAReflection = true;

        for (int j = 0; j < i + 1; j++) {
            if (i+1+j == data.size()) break;
            
            if (data[i-j] != data[i+1+j]) {
                isAReflection = false;
                break;
            }
        }

        if (isAReflection) reflectionScore += i+1;
    }

    return reflectionScore;
}

int Node::ReflectionScore() {
    int reflectionScore = 0;

    // Check for horizontal reflection.
    reflectionScore += GetHorizontalReflection(this->data) * 100;

    // Rotate data to get the vertical reflection using the horizontal reflection algorithm.
    std::vector<std::string> rotatedData(this->data[0].size(), "");
    for (int i = 0; i < this->data.size(); i++) {
        for (int j = 0; j < this->data[0].size(); j++) {
            rotatedData[j] = rotatedData[j] + this->data[i][j];
        }
    }

    // Check for vertical reflection.
    reflectionScore += GetHorizontalReflection(rotatedData);

    return reflectionScore;
}