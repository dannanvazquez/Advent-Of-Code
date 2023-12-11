#include <string>
#include <vector>

#pragma once

struct Node {
        char pipe;
        int row, col;
        int stepsAway = 0;
        bool isFacingNorth = false, isFacingEast = false, isFacingSouth = false, isFacingWest = false;
        std::vector<Node*> path;
        Node(char, int, int);
};