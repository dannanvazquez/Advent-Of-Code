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

        bool IsPossibleConfiguration = true;

        for (size_t i = 2; i < words.size(); i += 2) {
            int cubeAmount = stoi(words[i]);
            string cubeColor = words[i+1];
            if (cubeColor[cubeColor.length()-1] == ',' || cubeColor[cubeColor.length()-1] == ';') cubeColor.pop_back();

            if ((cubeAmount > 12 && cubeColor == "red") || (cubeAmount > 13 && cubeColor == "green") || (cubeAmount > 14 && cubeColor == "blue")) {
                IsPossibleConfiguration = false;
                break;
            }
            
        }
        
        if (IsPossibleConfiguration) {
            string id = words[1];
            id.pop_back();
            totalSum += stoi(id);
        }
    }

    cout << "Total sum: " << totalSum << endl;
}