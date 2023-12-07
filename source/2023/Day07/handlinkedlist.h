#include <string>

#include "hand.h"

#pragma once

class HandLinkedList { 
    private:
        Hand* heads[7] = {NULL};
    public:
        void InsertHand(Hand*);
        void PrintHands();
        int GetTotalWinnings();
};