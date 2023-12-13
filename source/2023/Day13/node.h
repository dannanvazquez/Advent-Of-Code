#include <string>
#include <vector>

#pragma once

struct Node {
    std::vector<std::string> data;

    Node(std::vector<std::string>);
    int ReflectionScore();
};