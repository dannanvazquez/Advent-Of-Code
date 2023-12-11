#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

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

    // TODO: This could look nicer.
    // Check north
    if (node->isFacingNorth && node->row > 0 && this->nodes[node->row-1][node->col]->isFacingSouth && this->nodes[node->row-1][node->col]->stepsAway == 0 && this->nodes[node->row-1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row-1][node->col]);
    // Check east
    if (node->isFacingEast && node->col < this->nodes[node->row].size()-1 && this->nodes[node->row][node->col+1]->isFacingWest && this->nodes[node->row][node->col+1]->stepsAway == 0 && this->nodes[node->row][node->col+1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col+1]);
    // Check south
    if (node->isFacingSouth && node->row < this->nodes.size()-1 && this->nodes[node->row+1][node->col]->isFacingNorth && this->nodes[node->row+1][node->col]->stepsAway == 0 && this->nodes[node->row+1][node->col]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row+1][node->col]);
    // Check west
    if (node->isFacingWest && node->col > 0 && this->nodes[node->row][node->col-1]->isFacingEast && this->nodes[node->row][node->col-1]->stepsAway == 0 && this->nodes[node->row][node->col-1]->pipe != 'S') adjacentNodes.push_back(this->nodes[node->row][node->col-1]);

    return adjacentNodes;
}

Node* Graph::FurthestNodeAway() {
    std::vector<Node*> currentNodes { this->animalTile };
    std::vector<Node*> nextNodes;
    Node* furtherTile = this->animalTile;
    while (currentNodes.size() > 0) {
        for (Node* node : currentNodes) {
            this->loop.push_back(node);
            furtherTile->path.clear();

            std::vector<Node*> adjacentNodes = AdjacentNodes(node);
            for (auto adjacentNode : adjacentNodes) {
                adjacentNode->path = node->path;
                adjacentNode->path.push_back(node);
                adjacentNode->stepsAway = node->stepsAway + 1;
            }
            nextNodes.insert(nextNodes.end(), adjacentNodes.begin(), adjacentNodes.end());
            
            furtherTile = node;
        }

        currentNodes = nextNodes;
        nextNodes.clear();
    }

    this->furtherTile = furtherTile;
    return furtherTile;
}

int Graph::EnclosedTilesAmount() {
    this->OutputSteps();
    int enclosedTilesAmount = 0;
    int numCollisions = 0;
    auto loop = this->loop;
    for (int i = 0; i < this->nodes.size(); i++) {
        for (int j = 0; j < this->nodes[i].size(); j++) {
            if ((this->nodes[i][j]->stepsAway > 0 || this->nodes[i][j]->pipe == 'S') && this->nodes[i][j]->isFacingSouth && i < this->nodes.size()-1 && this->nodes[i+1][j]->isFacingNorth) numCollisions++;

            if ((this->nodes[i][j]->stepsAway == 0 && this->nodes[i][j]->pipe != 'S') && numCollisions % 2 == 1) enclosedTilesAmount++;
        }
    }

    return enclosedTilesAmount;
}

void Graph::OutputGraph() {
    std::ofstream outfile("output.txt");
    for (auto row : this->nodes) {
        for (auto node : row) {
            outfile << node->pipe;
        }
        outfile << std::endl;
    }
    outfile.close();
}

void Graph::OutputSteps() {
    std::ofstream outfile("output.txt");
    for (auto row : this->nodes) {
        for (auto node : row) {
            if (node->pipe == 'S') {
                outfile << "S";
            } else if (node->stepsAway == 0) {
                outfile << ".";
            } else {
                outfile << node->stepsAway % 10;
            }
        }
        outfile << std::endl;
    }
    outfile.close();
}

void Graph::OutputFurthestPath() {
    std::ofstream outfile("output.txt");
    for (auto row : this->nodes) {
        for (auto node : row) {
            std::vector<Node*> loop = furtherTile->path;
            if (node->pipe == 'S') {
                outfile << "S";
            } else if (std::find(loop.begin(), loop.end(), node) != loop.end() || node == this->furtherTile) {
                outfile << node->pipe;
            } else {
                outfile << ".";
            }
        }
        outfile << std::endl;
    }
    outfile.close();
}

void Graph::OutputLoop() {
    std::ofstream outfile("output.txt");
    for (auto row : this->nodes) {
        for (auto node : row) {
            std::vector<Node*> loop = this->loop;
            if (std::find(loop.begin(), loop.end(), node) != loop.end() || node == this->furtherTile) {
                outfile << node->pipe;
            } else {
                outfile << ".";
            }
        }
        outfile << std::endl;
    }
    outfile.close();
}