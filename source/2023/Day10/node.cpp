#include <string>
#include <iostream>
#include <sstream>

#include "node.h"

Node::Node(char pipe, int row, int col) {
    this->pipe = pipe;
    this->row = row;
    this->col = col;

    switch (pipe) {
        case '|':
            this->isFacingNorth = true;
            this->isFacingSouth = true;
            break;
        case '-':
            this->isFacingEast = true;
            this->isFacingWest = true;
            break;
        case 'L':
            this->isFacingNorth = true;
            this->isFacingEast = true;
            break;
        case 'J':
            this->isFacingNorth = true;
            this->isFacingWest = true;
            break;
        case '7':
            this->isFacingSouth = true;
            this->isFacingWest = true;
            break;
        case 'F':
            this->isFacingEast = true;
            this->isFacingSouth = true;
            break;
        case 'S':
            this->isFacingNorth = true;
            this->isFacingEast = true;
            this->isFacingSouth = true;
            this->isFacingWest = true;
            break;
        default:
            return;
    }
}