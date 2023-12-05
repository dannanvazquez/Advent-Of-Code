#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

#include "card.h"
#include "cardsvector.h"

    
Card::Card(CardsVector* cardsVector, std::string data) {
    this->cardsVector = cardsVector;

    std::string tmp; 
    std::stringstream ss(data);
    int wordIndex = 0;
    bool isIndexingWinningNumbers = true;
    while(getline(ss, tmp, ' ')) {
        if (tmp.empty() || tmp == " ") continue;
        wordIndex++;

        if (wordIndex == 1) continue;  // Ignore the first word saying "Card."
        if (wordIndex == 2) {  // Identify the card ID.
            tmp.pop_back();
            this->id = stoi(tmp);
            continue;
        }

        // Find the seperator for winning numbers and my numbers.
        if (tmp == "|") {
            isIndexingWinningNumbers = false;
            continue;
        }

        if (isIndexingWinningNumbers) {
            this->winningNumbers.push_back(tmp);
        } else {
            this->myNumbers.push_back(tmp);
        }
    }
}

int Card::GetId() {
    return id;
}

int Card::GetPointValue() {
    int pointValue = 0;

    for (auto winningNumber : winningNumbers) {
        if (std::find(myNumbers.begin(), myNumbers.end(), winningNumber) != myNumbers.end()) {
            if (pointValue == 0) pointValue = 1;
            else pointValue *= 2;
        }
    }

    return pointValue;
}

// Uses recursion to find how many copies this card creates, then how many copies those copies make, and so on...
int Card::GetCardTotal() {
    if (this->cardTotal == 0) {
        int cardCopies = 0;

        for (auto winningNumber : winningNumbers) {
            if (std::find(myNumbers.begin(), myNumbers.end(), winningNumber) != myNumbers.end()) {
                cardCopies++;
            }
        }

        int cardCopiesTotal = 0;
        if (cardCopies > 0) {
            for (size_t i = 0; i < cardCopies; i++) {
                cardCopiesTotal += cardsVector->GetCardByID(this->id + i + 1)->GetCardTotal();
            }
        }

        this->cardTotal = cardCopiesTotal + 1;
    }
    return this->cardTotal;
}