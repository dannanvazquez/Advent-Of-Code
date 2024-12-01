#include <string>
#include <vector>

#include "node.h"

using namespace std;

#pragma once

class Graph {
    private:
        vector<vector<Node*>> nodes;
    public:
        Graph(vector<string>);
        void PrintGraph();
};