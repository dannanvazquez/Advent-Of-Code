#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

#include "hand.h"

bool sortbysec(const std::pair<char, int> &a, const std::pair<char, int> &b) {
    return a.second > b.second;
}
    
Hand::Hand(std::string hand, int bidAmount) {
    this->hand = hand;
    this->bidAmount = bidAmount;

    std::map<char, int> charMap;
    for (auto c : hand) {
        charMap[c]++;
    }

    std::vector<std::pair<char, int>> sortedCharAmounts; 
    for (auto it : charMap) { 
        sortedCharAmounts.push_back(it); 
    } 
    sort(sortedCharAmounts.begin(), sortedCharAmounts.end(), sortbysec);

    switch(sortedCharAmounts[0].second) {
        case 5:
            this->handTypeValue = 6;  // Five of a kind
            break;
        case 4:
            this->handTypeValue = 5;  // Four of a kind
            break;
        case 3:
            if (sortedCharAmounts[1].second == 2) {
                this->handTypeValue = 4;  // Full house
            } else {
                this->handTypeValue = 3;  // Three of a kind
            }
            break;
        case 2:
            if (sortedCharAmounts[1].second == 2) {
                this->handTypeValue = 2;  // Two pair
            } else {
                this->handTypeValue = 1;  // One pair
            }
            break;
        default:
            this->handTypeValue = 0;  // High card
    }
}

int Hand::GetBidAmount() {
    return this->bidAmount;
}

int Hand::GetHandTypeValue() {
    return this->handTypeValue;
}

Hand* Hand::GetNextHand() {
    return this->nextHand;
}

void Hand::SetNextHand(Hand* nextHand) {
    this->nextHand = nextHand;
}

bool Hand::HasStrongerCards(Hand* handB) {
    char cardTypes[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    std::string handAData = this->hand;
    std::string handBData = handB->hand;

    for (size_t i = 0; i < handAData.size(); i++) {
        char cardA = handAData[i];
        char cardB = handBData[i];
        if (cardA == cardB) continue;

        for (size_t j = 0; j < sizeof(cardTypes); j++){
            char cardType = cardTypes[j];
            if (cardA == cardType) {
                return false;
            } else if (cardB == cardType) {
                return true;
            }
        }
    }

    return false;
}

void Hand::PrintHandInfo() {
    std::cout << "Hand: " << this->hand << "; Bid: " << this->bidAmount << "; Hand Type Value: " << this->handTypeValue << std::endl;
}