#include <string>
#include <vector>
#include <map>

#include "node.h"

#pragma once

class ChainingHash {
	Node *root = nullptr;
	public:
	ChainingHash() { this->root = nullptr; }
    ChainingHash(Node* root) {
        this->root = root;
    }
	~ChainingHash() { delete this->root; }

	void InsertNode(Node* newNode) {
		if(!this->root){
			this->root = newNode;
			return;
		}
		Node* temp = this->root;
        Node* parentNode = nullptr;
		while(temp) {
            if (temp->label == newNode->label) {
                if (temp->right == nullptr) {
                    if (parentNode == nullptr) {
                        this->root = newNode;
                    } else {
                        parentNode->right = newNode;
                    }
                } else {
                    if (parentNode == nullptr) {
                        this->root = newNode;
                        newNode->right = temp->right;
                    } else {
                        parentNode->right = newNode;
                        newNode->right = temp->right;
                    }
                }
                delete temp;
                return;
            } else {
                parentNode = temp;
                temp = temp->right;
            }
		}
        
        if (this->root == nullptr || parentNode == nullptr) {
            this->root = newNode;
        } else {
            parentNode->right = newNode;
        }
	}

	void RemoveLabel(std::string label) {
        Node* oldNode = this->root;
        Node* parentNode = nullptr;
        while (oldNode) {
            if (oldNode->label == label) {
                if (oldNode->right == nullptr) {
                    if (parentNode == nullptr) {
                        this->root = nullptr;
                    } else {
                        parentNode->right = nullptr;
                    }
                } else {
                    if (parentNode == nullptr) {
                        this->root = oldNode->right;
                    } else {
                        parentNode->right = oldNode->right;
                    }
                }
                delete oldNode;
                return;
            } else {
                parentNode = oldNode;
                oldNode = oldNode->right;
            }
        }
	}

    void Print() {
        Node *old_node = this->root;
        int slot = 1;
        while (old_node) {
            std::cout << " - " << old_node->label << ": " << old_node->labelHash + 1 << " (box " << old_node->labelHash << ") * " << slot << " (something slot) * " << old_node->focalLength << " (focal length) = " << (old_node->labelHash + 1) * slot * old_node->focalLength << std::endl;
            old_node = old_node->right;
            slot++;
        }
    }

    int FocusingPower() {
        int focusingPower = 0;

        Node *old_node = this->root;
        int slot = 1;
        while (old_node) {
            focusingPower += (old_node->labelHash + 1) * slot * old_node->focalLength;
            old_node = old_node->right;
            slot++;
        }

        return focusingPower;
    }
};

class Graph {
    private:
        std::vector<Node*> nodes;
        std::map<int, ChainingHash*> hashMap;
    public:
        Graph(std::vector<std::string>);
        int TotalHASHValue();
        int FocusingPower();
        void PrintGraph();
        void PrintFocusingPower();
};