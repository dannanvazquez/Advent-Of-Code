#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Gear { 
    public: 
        int row, col;
        vector<int> partNumbers;
    
        Gear(int row, int col, int partNumber) { 
            this->row = row; 
            this->col = col;
            this->partNumbers.push_back(partNumber);
        }

        int GetGearRatio() {
            if (partNumbers.size() == 2) {
                return partNumbers[0] * partNumbers[1];
            } else {
                return 0;
            }
        }
}; 

class GearsVector { 
    vector<Gear*> gears;
  
    public: 
        void insertGear(int, int, int); 
        int getGearRatioSum(); 
};

void GearsVector::insertGear(int row, int col, int partNumber) { 
    for (auto gear : gears) {
        if (gear->row == row && gear->col == col) {
            gear->partNumbers.push_back(partNumber);
            return;
        }
    }

    Gear* newGear = new Gear(row, col, partNumber);
    gears.push_back(newGear);
} 
  
int GearsVector::getGearRatioSum() { 
    int gearRatioSum = 0;

    for (auto gear : gears) {
        gearRatioSum += gear->GetGearRatio();
    }

    return gearRatioSum;
} 

int main() {
    GearsVector gearsVector;

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

                bool hasSpaceLeft = j > 0;
                bool hasSpaceRight = lines[i].size() > j + digitSize;
                bool hasSpaceAbove = i > 0;
                bool hasSpaceBelow = lines.size() > i + 1;

                // Check left of the number.
                if (hasSpaceLeft && lines[i][j-1] == '*') {
                    string fullNumber;
                    for (size_t k = 0; k < digitSize; k++) fullNumber = fullNumber + lines[i][j+k];
                    gearsVector.insertGear(i, j-1, stoi(fullNumber));
                    if (hasSpaceRight) {
                        j += digitSize - 1;
                        continue;
                    } else break;
                }

                // Check right of the number.
                if (hasSpaceRight && lines[i][j+digitSize] == '*') {
                    string fullNumber;
                    for (size_t k = 0; k < digitSize; k++) fullNumber = fullNumber + lines[i][j+k];
                    gearsVector.insertGear(i, j+digitSize, stoi(fullNumber));
                    j += digitSize - 1;
                    continue;
                }

                // Check above the number.
                if (hasSpaceAbove) {
                    bool foundGear = false;
                    for (int k = (hasSpaceLeft ? -1 : 0); k < digitSize + (hasSpaceRight ? 1 : 0); k++) {
                        char currentChar = lines[i-1][j+k];
                        if (currentChar == '*') {
                            string fullNumber;
                            for (size_t k = 0; k < digitSize; k++) fullNumber = fullNumber + lines[i][j+k];
                            gearsVector.insertGear(i-1, j+k, stoi(fullNumber));
                            foundGear = true;
                            break;
                        }
                    }

                    if (foundGear) {
                        if (hasSpaceRight) {
                            j += digitSize - 1;
                            continue;
                        } else break;
                    }
                }

                // Check below the number.
                if (hasSpaceBelow) {
                    bool foundGear = false;
                    for (int k = (hasSpaceLeft ? -1 : 0); k < digitSize + (hasSpaceRight ? 1 : 0); k++) {
                        char currentChar = lines[i+1][j+k];
                        if (currentChar == '*') {
                            string fullNumber;
                            for (size_t k = 0; k < digitSize; k++) fullNumber = fullNumber + lines[i][j+k];
                            gearsVector.insertGear(i+1, j+k, stoi(fullNumber));
                            foundGear = true;
                            break;
                        }
                    }

                    if (foundGear) {
                        if (hasSpaceRight) {
                            j += digitSize - 1;
                            continue;
                        } else break;
                    }
                }
            }
        }
    }
    
    int gearRatioSum = gearsVector.getGearRatioSum();
    cout << "Total sum: " << gearRatioSum << endl;
}