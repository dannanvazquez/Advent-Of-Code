#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph { 
    private:
        std::vector<std::vector<Node*>> nodes;
        Node* animalTile;
    public:
        void InsertRow(std::string);
        std::vector<Node*> AdjacentNodes(Node*);
        int FurthestStepAway();
        void PrintGraph();
        void PrintSteps();
};