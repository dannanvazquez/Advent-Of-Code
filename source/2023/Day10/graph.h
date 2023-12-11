#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph { 
    private:
        std::vector<std::vector<Node*>> nodes;
        Node* animalTile;
        Node* furtherTile;
        std::vector<Node*> loop;
    public:
        void InsertRow(std::string);
        std::vector<Node*> AdjacentNodes(Node*);
        Node* FurthestNodeAway();
        int EnclosedTilesAmount();
        void OutputGraph();
        void OutputSteps();
        void OutputFurthestPath();
        void OutputLoop();
};