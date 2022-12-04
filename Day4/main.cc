#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int containingPairs = 0;
    int overlappingPairs = 0;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        istringstream iss(line);
        if (line.empty()) continue;
        
        int pairs[4];  // Will always contain 2 pairs from each line. Order: Min range for first elf, max range for first elf, min range for second elf, max range for second elf.

        string number;
        int i = 0;
        for (char c : line) {
            if (isdigit(c)) {
                number.push_back(c);
            } else {
                pairs[i] = stoi(number);
                number = "";
                i++;
            }
        }
        pairs[3] = stoi(number);

        if ((pairs[0] >= pairs [2] && pairs[1] <= pairs[3]) || (pairs[2] >= pairs [0] && pairs[3] <= pairs[1])) containingPairs++;

        if (pairs[2] <= pairs[1] && pairs[3] >= pairs[0]) overlappingPairs++;
    }

    cout << "The amount of containing pairs: " << containingPairs << endl;
    cout << "The amount of overlapping pairs: " << overlappingPairs << endl;
}