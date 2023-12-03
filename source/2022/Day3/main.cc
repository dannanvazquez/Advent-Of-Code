#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int sumTypes = 0;
    int sumPrioTypes = 0;

    string elves[3] = {""};

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        istringstream iss(line);
        if (line.empty()) continue;

        string firstCompartment = line.substr(0,line.length() / 2);
        string secondCompartment = line.substr(line.length() / 2, line.length());

        vector<char> similarChars;

        for (int i = 0; i < firstCompartment.length(); i++) {
            if (find(similarChars.begin(), similarChars.end(), firstCompartment[i]) != similarChars.end()) continue;

            for (int j = 0; j < secondCompartment.length(); j++) {
                if (firstCompartment[i] == secondCompartment[j]) {
                    similarChars.push_back(firstCompartment[i]);
                    break;
                }
            }
        }

        for (char c : similarChars) {
            sumTypes += (int)(isupper(c) ? c - 38 : c - 96);
        }

        // Part 2
        
        if (elves[0] == "") elves[0] = line;
        else if (elves[1] == "") elves[1] = line;
        else if (elves[2] == "") {
            elves[2] = line;
            char badge = '\0';
            for (int i = 0; i < elves[0].length(); i++) {
                for (int j = 0; j < elves[1].length(); j++) {
                    if (elves[0][i] == elves[1][j]) {
                        for (int k = 0; k < elves[2].length(); k++) {
                            if (elves[0][i] == elves[2][k]) {
                                badge = elves[0][i];
                                break;
                            }
                        }
                    }
                    if (badge != '\0') break;
                }
                if (badge != '\0') break;
            }
            sumPrioTypes += (int)(isupper(badge) ? badge - 38 : badge - 96);
            elves[0] = "";
            elves[1] = "";
            elves[2] = "";
        }
    }

    cout << "Sum of item types: " << sumTypes << endl;
    cout << "Sum of priority item types: " << sumPrioTypes << endl;
}