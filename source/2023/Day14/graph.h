#include <string>
#include <vector>

#pragma once

class Graph {
    private:
        std::vector<std::string> data;
    public:
        Graph(std::vector<std::string>);
        int NorthLoad();
        int SpinCycle(int);
        void PrintGraph();
};