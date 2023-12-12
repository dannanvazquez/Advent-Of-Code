#include <string>
#include <vector>

#pragma once

struct Node {
    std::string springs;
    std::vector<int> groupsDamaged;
    int arrangements = 0;

    Node(std::string);
    int ArrangementsAtPosition(std::vector<int>, int);
    int ArrangementsCount();
};