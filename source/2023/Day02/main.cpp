#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int totalSum = 0;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        string tmp; 
        stringstream ss(line);
        vector<string> words;
        while(getline(ss, tmp, ' ')) words.push_back(tmp);

        int minimumRed = 0, minimumGreen = 0, minimumBlue = 0;
        
        for (size_t i = 2; i < words.size(); i += 2) {
            int cubeAmount = stoi(words[i]);
            string cubeColor = words[i+1];
            if (cubeColor[cubeColor.length()-1] == ',' || cubeColor[cubeColor.length()-1] == ';') cubeColor.pop_back();

            if (cubeColor == "red") {
                if (cubeAmount > minimumRed) {
                    minimumRed = cubeAmount;
                }
            } else if (cubeColor == "green") {
                if (cubeAmount > minimumGreen) {
                    minimumGreen = cubeAmount;
                }
            } else {
                if (cubeAmount > minimumBlue) {
                    minimumBlue = cubeAmount;
                }
            }
        }
        
        int powerOfSet = minimumRed * minimumGreen * minimumBlue;
        totalSum += powerOfSet;
    }

    cout << "Total sum: " << totalSum << endl;
}