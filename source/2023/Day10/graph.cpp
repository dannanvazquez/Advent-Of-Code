#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "node.h"
#include "graph.h"

void Graph::InsertRow(std::string row) {
    std::vector<Node*> emptyVector;
    this->nodes.push_back(emptyVector);
    
    for (char c : row) {
        Node* newNode = new Node(c, this->nodes.size()-1, this->nodes[this->nodes.size()-1].size());
        if (c == 'S') this->animalTile = newNode;
        this->nodes[newNode->row].push_back(newNode);
    }
}

std::vector<Node*> Graph::AdjacentNodes(Node* node) {
    std::vector<Node*> adjacentNodes;

    switch (node->pipe) {
        case '|':
            if (node->row > 0 && this->nodes[node->row-1][node->col]->isFacingSouth && this->nodes[node->row-1][node->col]->stepsAway == 0 && this->nodes[node->row-1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row-1][node->col]);  // Check north
            if (node->row < this->nodes.size()-1 && this->nodes[node->row+1][node->col]->isFacingNorth && this->nodes[node->row+1][node->col]->stepsAway == 0 && this->nodes[node->row+1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row+1][node->col]);  // Check south
            break;
        case '-':
            if (node->col > 0 && this->nodes[node->row][node->col-1]->isFacingEast && this->nodes[node->row][node->col-1]->stepsAway == 0 && this->nodes[node->row][node->col-1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col-1]);  // Check west
            if (node->col < this->nodes[node->row].size()-1 && this->nodes[node->row][node->col+1]->isFacingWest && this->nodes[node->row][node->col+1]->stepsAway == 0 && this->nodes[node->row][node->col+1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col+1]);  // Check east
            break;
        case 'L':
            if (node->row > 0 && nodes[node->row-1][node->col]->isFacingSouth && this->nodes[node->row-1][node->col]->stepsAway == 0 && this->nodes[node->row-1][node->col]->pipe != 'S') adjacentNodes.push_back(nodes[node->row-1][node->col]);  // Check north
            if (node->col < this->nodes[node->row].size()-1 && this->nodes[node->row][node->col+1]->isFacingWest && this->nodes[node->row][node->col+1]->stepsAway == 0 && this->nodes[node->row][node->col+1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col+1]);  // Check east
            break;
        case 'J':
            if (node->row > 0 && nodes[node->row-1][node->col]->isFacingSouth && this->nodes[node->row-1][node->col]->stepsAway == 0 && this->nodes[node->row-1][node->col]->pipe != 'S') adjacentNodes.push_back(nodes[node->row-1][node->col]);  // Check north
            if (node->col > 0 && this->nodes[node->row][node->col-1]->isFacingEast && this->nodes[node->row][node->col-1]->stepsAway == 0 && this->nodes[node->row][node->col-1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col-1]);  // Check west
            break;
        case '7':
            if (node->col > 0 && this->nodes[node->row][node->col-1]->isFacingEast && this->nodes[node->row][node->col-1]->stepsAway == 0 && this->nodes[node->row][node->col-1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col-1]);  // Check west
            if (node->row < this->nodes.size()-1 && this->nodes[node->row+1][node->col]->isFacingNorth && this->nodes[node->row+1][node->col]->stepsAway == 0 && this->nodes[node->row+1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row+1][node->col]);  // Check south
            break;
        case 'F':
            if (node->col < this->nodes[node->row].size()-1 && this->nodes[node->row][node->col+1]->isFacingWest && this->nodes[node->row][node->col+1]->stepsAway == 0 && this->nodes[node->row][node->col+1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col+1]);  // Check east
            if (node->row < this->nodes.size()-1 && this->nodes[node->row+1][node->col]->isFacingNorth && this->nodes[node->row+1][node->col]->stepsAway == 0 && this->nodes[node->row+1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row+1][node->col]);  // Check south
            break;
        case 'S':
            if (node->row > 0 && nodes[node->row-1][node->col]->isFacingSouth && this->nodes[node->row-1][node->col]->stepsAway == 0 && this->nodes[node->row-1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row-1][node->col]);  // Check north
            if (node->col < this->nodes[node->row].size()-1 && this->nodes[node->row][node->col+1]->isFacingWest && this->nodes[node->row][node->col+1]->stepsAway == 0 && this->nodes[node->row][node->col+1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col+1]);  // Check east
            if (node->row < this->nodes.size()-1 && this->nodes[node->row+1][node->col]->isFacingNorth && this->nodes[node->row+1][node->col]->stepsAway == 0 && this->nodes[node->row+1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row+1][node->col]);  // Check south
            if (node->col > 0 && this->nodes[node->row][node->col-1]->isFacingEast && this->nodes[node->row][node->col-1]->stepsAway == 0 && this->nodes[node->row][node->col-1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col-1]);  // Check west
            break;
    }

    return adjacentNodes;
}

int Graph::FurthestStepAway() {
    int furthestStepAway = 0;
    
    std::vector<Node*> currentNodes { this->animalTile };
    std::vector<Node*> nextNodes;
    while (currentNodes.size() > 0) {
        for (Node* node : currentNodes) {
            node->stepsAway = furthestStepAway;

            std::vector<Node*> adjacentNodes = AdjacentNodes(node);
            nextNodes.insert(nextNodes.end(), adjacentNodes.begin(), adjacentNodes.end());
        }

        currentNodes = nextNodes;
        nextNodes.clear();
        furthestStepAway++;
    }

    return furthestStepAway - 1;
}

void Graph::PrintGraph() {
    std::ofstream outfile("output.txt");
    for (auto row : this->nodes) {
        for (auto node : row) {
            outfile << node->pipe;
        }
        outfile << std::endl;
    }
    outfile.close();
}

void Graph::PrintSteps() {
    std::ofstream outfile("output.txt");
    for (auto row : this->nodes) {
        for (auto node : row) {
            if (node->pipe == 'S') {
                outfile << "S ";
            } else if (node->pipe == '.') {
                outfile << ". ";
            } else {
                outfile << node->stepsAway << " ";
            }
        }
        outfile << std::endl;
    }
    outfile.close();
}