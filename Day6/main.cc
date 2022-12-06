#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int processedChars = 0;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        istringstream iss(line);
        if (line.empty()) continue;

        // Starting at position i, see if the first three characters(using j) have any duplicates ahead of them(using k) for a total of four characters being searched at a time.
        for (int i = 0; i < line.size() - 3; i++) {
            bool isDuplicate = false;
            for (int j = 0; j < 3; j++) {
                for (int k = 1; k < 4 - j; k++) {
                    if (line[i + j] == line[i + j + k]) {
                        isDuplicate = true;
                        i += j;  // Skip i to where the duplicate is since we already know starting at the characters in between the current starting point and duplicate will result in another failed loop.
                        break;
                    } else if (j == 2) {
                        processedChars = i + 4;
                    }
                    
                }
                if (isDuplicate) break;
            }
            if (!isDuplicate) break;
        }
    }

    cout << "Amount of characters needed to be processed: " << processedChars << endl;
}
