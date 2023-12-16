#include <string>
#include <iostream>

#include "node.h"

Node::Node(std::string data) {
    this->data = data;
}

int Node::EntireHASHValue() {
    int value = 0;

    for (char c : this->data) {
        value += (int)c;
        value *= 17;
        value %= 256;
    }

    return value;
}

void Node::DistributeData() {
    int operatorIndex = 0;
    for (int i = 0; i < this->data.size(); i++) {
        if (this->data[i] == '-') return;
        if (this->data[i] == '=') {
            operatorIndex = i;
            break;
        }

        label += this->data[i];

        labelHash += (int)this->data[i];
        labelHash *= 17;
        labelHash %= 256;
    }

    this->focalLength = std::stoi(this->data.substr(operatorIndex + 1, this->data.size()));
}