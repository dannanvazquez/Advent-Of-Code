#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "card.h"
#include "cardsvector.h"


void CardsVector::InsertCard(std::string data) { 
    Card* newCard = new Card(this, data);
    cards.push_back(newCard);
} 
  
int CardsVector::GetPointValue() { 
    int cardPointSum = 0;

    for (auto card : cards) {
        cardPointSum += card->GetPointValue();
    }

    return cardPointSum;
}

int CardsVector::GetCardTotal() { 
    int cardTotal = 0;

    for (auto card : cards) {
        cardTotal += card->GetCardTotal();
    }

    return cardTotal;
}

Card* CardsVector::GetCardByID(int id) {
    return cards[id-1];  // Assuming cards are in ascending order, start at 1, and have no gaps.
}