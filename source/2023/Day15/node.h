#include <string>

#pragma once

struct Node {
    std::string data;

    Node(std::string);
    int HASHValue();
};