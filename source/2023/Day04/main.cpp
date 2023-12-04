#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Card { 
    public:
        string id;
        vector<string> winningNumbers;
        vector<string> myNumbers;
    
        Card(string data) { 
            string tmp; 
            stringstream ss(data);
            int wordIndex = 0;
            bool isIndexingWinningNumbers = true;
            while(getline(ss, tmp, ' ')) {
                if (tmp.empty() || tmp == " ") continue;
                wordIndex++;
                
                if (wordIndex == 1) continue;  // Ignore the first word saying "Card."
                if (wordIndex == 2) {  // Identify the card ID.
                    tmp.pop_back();
                    this->id = tmp;
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

        int GetPointValue() {
            int pointValue = 0;

            for (auto winningNumber : winningNumbers) {
                if (find(myNumbers.begin(), myNumbers.end(), winningNumber) != myNumbers.end()) {
                    if (pointValue == 0) pointValue = 1;
                    else pointValue *= 2;
                }
            }

            return pointValue;
        }
}; 

class CardsVector { 
    vector<Card*> cards;
  
    public: 
        void InsertCard(string); 
        int GetPointValue(); 
};

void CardsVector::InsertCard(string data) { 
    Card* newCard = new Card(data);
    cards.push_back(newCard);
} 
  
int CardsVector::GetPointValue() { 
    int cardPointSum = 0;

    for (auto card : cards) {
        cardPointSum += card->GetPointValue();
    }

    return cardPointSum;
} 

int main() {
    CardsVector cardsVector;

    string line;
    ifstream infile("input.txt");
    vector<string> lines;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        cardsVector.InsertCard(line);
    }
    
    int cardPointSum = cardsVector.GetPointValue();
    cout << "Total sum: " << cardPointSum << endl;
}