#include <string>
#include <iostream>

#include "graph.h"

Graph::Graph(std::vector<std::string> inputData) {
    for (auto row : inputData) {
        if (row.empty()) continue;
        
        std::vector<Node*> rowOfNodes;
        for (auto c : row) {
            Node* newNode = new Node(c, this->nodes.size(), rowOfNodes.size());
            rowOfNodes.push_back(newNode);
        }
        this->nodes.push_back(rowOfNodes);
    }
}

Node* Graph::AdjacentNode(Node* node, Direction direction) {
    switch(direction) {
        case Direction::North:
            if (node->row > 0) {
                return this->nodes[node->row-1][node->col];
            } else {
                return nullptr;
            }
        case Direction::East:
            if (node->col < this->nodes[node->row].size()-1) {
                return this->nodes[node->row][node->col+1];
            } else {
                return nullptr;
            }
        case Direction::South:
            if (node->row < this->nodes.size()-1) {
                return this->nodes[node->row+1][node->col];
            } else {
                return nullptr;
            }
        case Direction::West:
            if (node->col > 0) {
                return this->nodes[node->row][node->col-1];
            } else {
                return nullptr;
            }
    }

    return nullptr;
}

int Graph::ReceiveRay(Node* node, Direction rayDirection) {
    int energizedNodes = (node->rayDirections.size() > 0 ? 0 : 1);
    if (node->rayDirections.size() > 0) {
        for (Direction ray : node->rayDirections) {
            if (ray == rayDirection) return 0;
        }
    }
    node->rayDirections.push_back(rayDirection);

    switch(node->data) {
        case '.': {
            Node* nextNode = this->AdjacentNode(node, rayDirection);
            if (nextNode) energizedNodes += this->ReceiveRay(nextNode, rayDirection);
        } break;
        case '/': {
            Direction turnedDirection;
            if (rayDirection == Direction::North) turnedDirection = Direction::East;
            else if (rayDirection == Direction::East) turnedDirection = Direction::North;
            else if (rayDirection == Direction::South) turnedDirection = Direction::West;
            else if (rayDirection == Direction::West) turnedDirection = Direction::South;

            Node* nextNode = this->AdjacentNode(node, turnedDirection);
            if (nextNode) energizedNodes += this->ReceiveRay(nextNode, turnedDirection);
        } break;
        case '\\': {
            Direction turnedDirection;
            if (rayDirection == Direction::North) turnedDirection = Direction::West;
            else if (rayDirection == Direction::East) turnedDirection = Direction::South;
            else if (rayDirection == Direction::South) turnedDirection = Direction::East;
            else if (rayDirection == Direction::West) turnedDirection = Direction::North;

            Node* nextNode = this->AdjacentNode(node, turnedDirection);
            if (nextNode) energizedNodes += this->ReceiveRay(nextNode, turnedDirection);
        } break;
        case '|': {
            if (rayDirection == Direction::North || rayDirection == Direction::South) {
                Node* nextNode = this->AdjacentNode(node, rayDirection);
                if (nextNode) energizedNodes += this->ReceiveRay(nextNode, rayDirection);
            } else {
                Node* northNode = this->AdjacentNode(node, Direction::North);
                if (northNode) energizedNodes += this->ReceiveRay(northNode, Direction::North);
                Node* southNode = this->AdjacentNode(node, Direction::South);
                if (southNode) energizedNodes += this->ReceiveRay(southNode, Direction::South);
            }
        } break;
        case '-': {
            if (rayDirection == Direction::East || rayDirection == Direction::West) {
                Node* nextNode = this->AdjacentNode(node, rayDirection);
                if (nextNode) energizedNodes += this->ReceiveRay(nextNode, rayDirection);
            } else {
                Node* eastNode = this->AdjacentNode(node, Direction::East);
                if (eastNode) energizedNodes += this->ReceiveRay(eastNode, Direction::East);
                Node* westNode = this->AdjacentNode(node, Direction::West);
                if (westNode) energizedNodes += this->ReceiveRay(westNode, Direction::West);
            }
        } break;
    }

    return energizedNodes;
}

void Graph::ResetNodes() {
    for (auto row : this->nodes) {
        for (auto node : row) {
            node->rayDirections.clear();
        }
    }
}

int Graph::EnergizedNodes() {
    this->ResetNodes();
    return ReceiveRay(this->nodes[0][0], Direction::East);
}

void Graph::PrintGraph() {
    for (auto row : this->nodes) {
        for (auto node : row) {
            std::cout << node->data;
        }
        std::cout << std::endl;
    }
}

void Graph::PrintEnergizedNodes() {
    for (auto row : this->nodes) {
        for (auto node : row) {
            if (node->rayDirections.size() > 0) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}