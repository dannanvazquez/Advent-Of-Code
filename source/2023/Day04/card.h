#pragma once

class CardsVector;

class Card { 
    private:
        int id;
        std::vector<std::string> winningNumbers;
        std::vector<std::string> myNumbers;
        CardsVector* cardsVector;
        int cardTotal = 0;
    public:
        Card(CardsVector*, std::string);
        int GetId();
        int GetPointValue();
        int GetCardTotal();
};