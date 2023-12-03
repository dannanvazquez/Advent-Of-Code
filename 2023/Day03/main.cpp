#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int totalSum = 0;

    string line;
    ifstream infile("input.txt");
    vector<string> lines;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        lines.push_back(line);
    }

    for (size_t i = 0; i < lines.size(); i++) {
        for (size_t j = 0; j < lines[i].size(); j++) {
            if (isdigit(lines[i][j])) {
                // Check how many chars the number takes up.
                int digitSize = 1;
                while (lines[i].size() > j + digitSize && isdigit(lines[i][j+digitSize])) digitSize++;

                // Check for adjacent symbols.
                bool isPartNumber = false;

                bool hasSpaceLeft = j > 0;
                bool hasSpaceRight = lines[i].size() > j + digitSize;
                bool hasSpaceAbove = i > 0;
                bool hasSpaceBelow = lines.size() > i + 1;

                if (hasSpaceLeft && lines[i][j-1] != '.') {  // Check left of the number.
                    isPartNumber = true;
                } else if (hasSpaceRight && lines[i][j+digitSize] != '.') {  // Check right of the number.
                    isPartNumber = true;
                } else {
                    if (hasSpaceAbove) {  // Check above the number.
                        for (int k = (hasSpaceLeft ? -1 : 0); k < digitSize + (hasSpaceRight ? 1 : 0); k++) {
                            char currentChar = lines[i-1][j+k];
                            if (!isdigit(currentChar) && currentChar != '.') {
                                isPartNumber = true;
                                break;
                            }
                        }
                    }
                    if (!isPartNumber && hasSpaceBelow) {  // Check below the number.
                        for (int k = (hasSpaceLeft ? -1 : 0); k < digitSize + (hasSpaceRight ? 1 : 0); k++) {
                            char currentChar = lines[i+1][j+k];
                            if (!isdigit(currentChar) && currentChar != '.') {
                                isPartNumber = true;
                                break;
                            }
                        }
                    }
                }

                // Finally, add to the sum if the entire number is a part number.
                if (isPartNumber) {
                    string fullNumber;
                    for (size_t k = 0; k < digitSize; k++) {
                        fullNumber = fullNumber + lines[i][j+k];
                    }
                    
                    totalSum += stoi(fullNumber);
                }

                // Iterate the for loop past the numbers.
                if (hasSpaceRight) {
                    j += digitSize - 1;
                } else {
                    break;
                }
            }
        }
    }
    

    cout << "Total sum: " << totalSum << endl;
}