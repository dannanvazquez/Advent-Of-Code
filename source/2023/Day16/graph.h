#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph {
    private:
        std::vector<std::vector<Node*>> nodes;
    public:
        Graph(std::vector<std::string>);
        Node* AdjacentNode(Node*, Direction);
        int ReceiveRay(Node*, Direction);
        void ResetNodes();
        int EnergizedNodes();
        int MostEnergizedPath();
        void PrintGraph();
        void PrintEnergizedNodes();
};