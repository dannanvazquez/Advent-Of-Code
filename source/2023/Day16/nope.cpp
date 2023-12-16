#include <string>
#include <iostream>

#include "node.h"

Node::Node(char data, int row, int col) {
    this->data = data;
    this->row = row;
    this->col = col;
}