#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph {
    private:
        std::vector<std::vector<Node*>> nodes;
        std::vector<Node*> galaxies;
    public:
        Graph(std::vector<std::string>);
        int SumOfLengths();
        void PrintGraph();
};