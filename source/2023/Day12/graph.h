#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph {
    private:
        std::vector<Node*> nodes;
    public:
        Graph(std::vector<std::string>);
        int TotalArrangements();
        void PrintGraph();
};