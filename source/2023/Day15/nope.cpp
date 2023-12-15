#include <string>
#include <iostream>

#include "node.h"

Node::Node(std::string data) {
    this->data = data;
}

int Node::HASHValue() {
    int value = 0;

    for (char c : this->data) {
        value += (int)c;
        value *= 17;
        value %= 256;
    }

    return value;
}