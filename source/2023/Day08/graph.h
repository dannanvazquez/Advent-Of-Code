#include <string>
#include <vector>

#include "node.h"

#pragma once

class Graph { 
    private:
        std::vector<Node*> nodes;
        std::string directions;
    public:
        void AddNode(std::string);
        void SetDirections(std::string);
        Node* GetNodeByID(std::string);
        int DistanceBetweenNodes(std::string, std::string);
};