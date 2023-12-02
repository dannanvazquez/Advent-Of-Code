#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int totalSum = 0;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        // Assuming there are no numbers of 0.
        char firstDigit = '0';
        char lastDigit = '0';

        for (int i = 0; i < line.length(); i++) {
            char c = line[i];
            if (isdigit(c)) {
                if (firstDigit == '0') firstDigit = c;
                lastDigit = c;
            }
        }

        string finalNumber;
        finalNumber = finalNumber + firstDigit + lastDigit;
        totalSum += stoi(finalNumber);
    }

    cout << "Total sum: " << totalSum << endl;
}