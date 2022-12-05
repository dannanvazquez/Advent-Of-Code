#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool isNumber(string s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    vector<char> stacksOfCrates[9];

    bool isInitializingCrates = true;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        istringstream iss(line);
        if (line.empty()) continue;

        // Start with initializing the crates from input into its corresponding vector.
        if (isInitializingCrates) {
            if (line == " 1   2   3   4   5   6   7   8   9 ") {
                isInitializingCrates = false;
                continue;
            }
            for (int i = 0; i < 9; i++) {
                if (line[(i*4)+1] != ' ') {
                    stacksOfCrates[i].insert(stacksOfCrates[i].begin(), line[(i*4)+1]);
                }
            }
        } else {
            // Split the input of moving crates into just its numbers.
            string temp;
            vector<int> numbers;
            stringstream ss(line);
            while(getline(ss, temp, ' ')) {
                if (isNumber(temp)) numbers.push_back(stoi(temp));
            }

            // Now move the crates as assigned.
            for (int i = 0; i < numbers[0]; i++) {
                stacksOfCrates[numbers[2] - 1].push_back(stacksOfCrates[numbers[1] - 1].back());
                stacksOfCrates[numbers[1] - 1].pop_back();
            }
        }
    }

    cout << "Crates on top of each stack: ";
    for (auto a : stacksOfCrates) {
        cout << a.back();
    }
    cout << endl;
}
