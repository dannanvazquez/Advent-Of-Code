#include <string>

#pragma once

struct Node {
    std::string data;
    std::string label;
    int labelHash = 0;
    int focalLength = 0;
    Node* right = nullptr;

    Node(std::string);
    int EntireHASHValue();
    void DistributeData();
};