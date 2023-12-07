#include <string>

#pragma once

class Hand { 
    private:
        std::string hand;
        int bidAmount;
        int handTypeValue;  // High card is worth 0, one pair is worth 1, two pair is worth 2, three of a kind is worth 3, full house is worth 4, four of a kind is worth 5, and five of a kind is worth 6.
        Hand* nextHand = NULL;
    public:
        Hand(std::string, int);
        int GetBidAmount();
        int GetHandTypeValue();
        Hand* GetNextHand();
        void SetNextHand(Hand*);
        bool HasStrongerCards(Hand*);
        void PrintHandInfo();
};