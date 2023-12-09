#include <string>

#pragma once

struct Node { 
        std::string id;
        Node* left = NULL;
        Node* right = NULL;

        Node(std::string);
};