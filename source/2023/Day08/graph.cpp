#include <string>
#include <iostream>

#include "graph.h"
#include "node.h"

void Graph::AddNode(std::string nodeData) {
    std::string id;
    id = id + nodeData[0] + nodeData[1] + nodeData[2];
    Node* newNode = this->GetNodeByID(id);
    if (newNode == NULL) {
        newNode = new Node(id);
        nodes.push_back(newNode);
    }

    std::string leftID;
    leftID = leftID + nodeData[7] + nodeData[8] + nodeData[9];
    newNode->left = this->GetNodeByID(leftID);
    if (newNode->left == NULL) {
        newNode->left = new Node(leftID);
        nodes.push_back(newNode->left);
    }

    std::string rightID;
    rightID = rightID + nodeData[12] + nodeData[13] + nodeData[14];
    newNode->right = this->GetNodeByID(rightID);
    if (newNode->right == NULL) {
        newNode->right = new Node(rightID);
        nodes.push_back(newNode->right);
    }
}

void Graph::SetDirections(std::string directions) {
    this->directions = directions;
}

Node* Graph::GetNodeByID(std::string id) {
    if (nodes.size() > 0) {
        for (auto node : nodes) {
            if (node->id == id) return node;
        }
    }

    return NULL;
}

int Graph::DistanceBetweenNodes(std::string from, std::string to) {
    int stepsRequired = 0;
    
    Node* temp = this->GetNodeByID(from);
    while (temp != NULL && temp->id != to) {
        if (this->directions[stepsRequired % directions.size()] == 'L') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        stepsRequired++;
    }

    return stepsRequired;
}