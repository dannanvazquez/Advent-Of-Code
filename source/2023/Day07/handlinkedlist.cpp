#include <string>

#include "hand.h"
#include "handlinkedlist.h"
    
void HandLinkedList::InsertHand(Hand* newHand) {
    if (this->heads[newHand->GetHandTypeValue()] == NULL) {
        this->heads[newHand->GetHandTypeValue()] = newHand;
        return;
    } else if (this->heads[newHand->GetHandTypeValue()]->HasStrongerCards(newHand)) {
        Hand* nextHand = this->heads[newHand->GetHandTypeValue()];
        this->heads[newHand->GetHandTypeValue()] = newHand;
        newHand->SetNextHand(nextHand);
        return;
    }

    Hand* temp = this->heads[newHand->GetHandTypeValue()];
    while (temp->GetNextHand() != NULL && !temp->GetNextHand()->HasStrongerCards(newHand)) {
        temp = temp->GetNextHand();
    }
    
    if (temp->GetNextHand() == NULL) {
        temp->SetNextHand(newHand);
    } else {
        Hand* nextHand = temp->GetNextHand();
        temp->SetNextHand(newHand);
        newHand->SetNextHand(nextHand);
    }
}

void HandLinkedList::PrintHands() {
    for (auto head : this->heads) {
        Hand* temp = head;
        while (temp != NULL) {
            temp->PrintHandInfo();
            temp = temp->GetNextHand();
        }
    }
}

int HandLinkedList::GetTotalWinnings() {
    int totalWinnings = 0;
    int index = 1;

    for (auto head : this->heads) {
        Hand* temp = head;
        while (temp != NULL) {
            totalWinnings += temp->GetBidAmount() * index;
            index++;
            temp = temp->GetNextHand();
        }
    }

    return totalWinnings;
}