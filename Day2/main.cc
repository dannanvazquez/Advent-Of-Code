#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int winScore = 6;
int drawScore = 3;
int lossScore = 0;

int main() {
    int totalScore = 0;
    
    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        istringstream iss(line);
        if (line.empty()) continue;
        
        // Use numbers to represent choices according to its point value. 1 = rock, 2 = paper, 3 = scissors.
        int opponent = line[0] - 64;
        char result = line[2];

        if (result == 'X') {  // Check for a loss
            totalScore += (((opponent - 1) % 3) == 0 ? 3 : ((opponent - 1) % 3)) + lossScore;
        } else if (result == 'Y')  {  // Check for a draw
            totalScore += opponent + drawScore;
        } else if (result == 'Z') {  // Check for a win
            totalScore += (((opponent + 1) % 3) == 0 ? 3 : ((opponent + 1) % 3)) + winScore;
        }
    }

    cout << "Total score: " << totalScore << endl;
}