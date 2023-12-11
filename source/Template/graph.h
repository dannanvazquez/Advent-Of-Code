#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph {
    private:
        std::vector<std::vector<Node*>> nodes;
    public:
        Graph(std::vector<std::string>);
        void PrintGraph();
};