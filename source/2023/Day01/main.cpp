#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string DecryptNumbers(string line) {
    string result;

    for (size_t i = 0; i < line.length(); i++){
        if (isdigit(line[i])) {  // Check if the char is already a number.
            result = result + line[i];
        } else if (i + 3 <= line.length() && line[i] == 'o' && line[i+1] == 'n' && line[i+2] == 'e') {  // Check if this is the start for "one"
            result = result + '1';
            i += 3-2;
        } else if (i + 3 <= line.length() && line[i] == 't' && line[i+1] == 'w' && line[i+2] == 'o') {  // Check if this is the start for "two"
            result = result + '2';
            i += 3-2;
        } else if (i + 5 <= line.length() && line[i] == 't' && line[i+1] == 'h' && line[i+2] == 'r' && line[i+3] == 'e' && line[i+4] == 'e') {  // Check if this is the start for "three"
            result = result + '3';
            i += 5-2;
        } else if (i + 4 <= line.length() && line[i] == 'f' && line[i+1] == 'o' && line[i+2] == 'u' && line[i+3] == 'r') {  // Check if this is the start for "four"
            result = result + '4';
            i += 4-2;
        } else if (i + 4 <= line.length() && line[i] == 'f' && line[i+1] == 'i' && line[i+2] == 'v' && line[i+3] == 'e') {  // Check if this is the start for "five"
            result = result + '5';
            i += 4-2;
        } else if (i + 3 <= line.length() && line[i] == 's' && line[i+1] == 'i' && line[i+2] == 'x') {  // Check if this is the start for "six"
            result = result + '6';
            i += 3-2;
        } else if (i + 5 <= line.length() && line[i] == 's' && line[i+1] == 'e' && line[i+2] == 'v' && line[i+3] == 'e' && line[i+4] == 'n') {  // Check if this is the start for "seven"
            result = result + '7';
            i += 5-2;
        } else if (i + 5 <= line.length() && line[i] == 'e' && line[i+1] == 'i' && line[i+2] == 'g' && line[i+3] == 'h' && line[i+4] == 't') {  // Check if this is the start for "eight"
            result = result + '8';
            i += 5-2;
        } else if (i + 4 <= line.length() && line[i] == 'n' && line[i+1] == 'i' && line[i+2] == 'n' && line[i+3] == 'e') {  // Check if this is the start for "nine"
            result = result + '9';
            i += 4-2;
        }
    }

    return result;
}

int main() {
    int totalSum = 0;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        // Assuming there are no numbers of 0.
        char firstDigit = '0';
        char lastDigit = '0';

        string decryptedLine = DecryptNumbers(line);

        string finalNumber;
        finalNumber = finalNumber + decryptedLine[0] + decryptedLine[decryptedLine.length()-1];
        totalSum += stoi(finalNumber);
    }

    cout << "Total sum: " << totalSum << endl;
}