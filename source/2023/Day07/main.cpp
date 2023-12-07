#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "hand.h"
#include "handlinkedlist.h"

int main() {
    HandLinkedList hands;

    std::string line;
    std::ifstream infile("input.txt");

    while (getline(infile, line)) {
        std::string handData; 
        std::string betData;
        std::stringstream ss(line);
        if (getline(ss, handData, ' ') && getline(ss, betData, ' ')) {
            Hand* newHand = new Hand(handData, stoi(betData));
            hands.InsertHand(newHand);
        }
    }
    
    int totalWinnings = hands.GetTotalWinnings();

    std::cout << "Total winnings: " << totalWinnings << std::endl;
}