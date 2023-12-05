#pragma once

class CardsVector { 
    std::vector<Card*> cards;
  
    public: 
        void InsertCard(std::string); 
        int GetPointValue(); 
        int GetCardTotal();
        Card* GetCardByID(int);
};