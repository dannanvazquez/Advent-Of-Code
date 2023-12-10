#include <string>
#include <vector>

#pragma once

struct Node {
        char pipe;
        int row, col;
        int stepsAway = 0;
        bool isFacingNorth, isFacingEast, isFacingSouth, isFacingWest;
        Node(char, int, int);
};