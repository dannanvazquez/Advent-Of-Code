#include <string>
#include <vector>

#pragma once

enum class Direction { North, East, South, West };

struct Node {
    char data;
    int row, col;
    std::vector<Direction> rayDirections;  // The directions a ray has been shot towards from this node. Used to prevent looping.

    Node(char, int, int);
};