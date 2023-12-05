#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "card.h"
#include "cardsvector.h"

using namespace std;

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
    cout << "Total card point sum: " << cardPointSum << endl;

    int cardTotal = cardsVector.GetCardTotal();
    cout << "Total card count: " << cardTotal << endl;
}