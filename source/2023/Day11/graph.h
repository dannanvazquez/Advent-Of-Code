#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph {
    private:
        std::vector<std::vector<Node*>> nodes;
        std::vector<Node*> galaxies;
        std::vector<int> emptyRows;
        std::vector<int> emptyCols;
    public:
        Graph(std::vector<std::string>);
        uint64_t SumOfLengths(int);
        void PrintGraph();
};