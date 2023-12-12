#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "node.h"

Node::Node(std::string data) {
    std::string tmp; 
    std::stringstream ss(data);

    getline(ss, tmp, ' ');
    this->springs = tmp;

    getline(ss, tmp, ' ');
    std::stringstream ss2(tmp);
    while (getline(ss2, tmp, ',')) {
        this->groupsDamaged.push_back(stoi(tmp));
    }
}

int Node::ArrangementsAtPosition(std::vector<int> positions, int index) {
    int arrangementsAtPosition = 0;

    int groupMinimumPosition = 0;
    for (int i = 0; i < index; i++) {
        groupMinimumPosition += positions[i];
        groupMinimumPosition += groupsDamaged[i];
    }
    groupMinimumPosition += index;

    // Loop through possible positions at the index.
    std::vector<int> currentPositions = positions;
    for (int i = 0; i <= positions[index]; i++) {
        if (i + this->groupsDamaged[index] + groupMinimumPosition > this->springs.size()) break;

        currentPositions[index] = i;

        // Loop through the group at the index.
        bool isPossible = true;
        for (int j = 0; j < this->groupsDamaged[index]; j++) {
            if (this->springs[currentPositions[index] + j + groupMinimumPosition] == '.') {
                isPossible = false;
                break;
            }
        }
        if (!isPossible) continue;

        int leftBorder = 0;
        if (index > 0) leftBorder = groupMinimumPosition - 1;

        // Check the left of the group.
        if (currentPositions[index] + groupMinimumPosition > 0) {
            for (int j = leftBorder; j < currentPositions[index] + groupMinimumPosition; j++) {
                if (this->springs[j] == '#') {
                    isPossible = false;
                    break;
                }
            }
            if (!isPossible) continue;
        }

        if (index == currentPositions.size()-1) {
            // Check the right of the group.
            int rightBorder = currentPositions[index] + groupMinimumPosition + this->groupsDamaged[index];
            if (rightBorder < this->springs.size()) {
                for (int j = rightBorder; j < this->springs.size(); j++) {
                    if (this->springs[j] == '#') {
                        isPossible = false;
                        break;
                    }
                }
                if (!isPossible) continue;
            }

            arrangementsAtPosition++;
        } else {
            arrangementsAtPosition += ArrangementsAtPosition(currentPositions, index + 1);
        }
    }

    return arrangementsAtPosition;
}

int Node::ArrangementsCount() {
    int possibilities = this->springs.size() - this->groupsDamaged.size() + 1;
    for (auto group : this->groupsDamaged) possibilities -= group;
    std::vector<int> positions(this->groupsDamaged.size(), possibilities);

    this->arrangements = ArrangementsAtPosition(positions, 0);
    return this->arrangements;
}