#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int mostCalories = 0;
    int secondMostCalories = 0;
    int thirdMostCalories = 0;

    int currentCalories = 0;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) {  // Finished listing calories for the current elf, now check if the elf has more calories than the current top three.
            if (currentCalories > mostCalories) {
                thirdMostCalories = secondMostCalories;
                secondMostCalories = mostCalories;
                mostCalories = currentCalories;
            } else if (currentCalories > secondMostCalories) {
                thirdMostCalories = secondMostCalories;
                secondMostCalories = currentCalories;
            } else if (currentCalories > thirdMostCalories) {
                thirdMostCalories = currentCalories;
            }
            currentCalories = 0;
        } else {  // Not done listing calories for the current elf.
            istringstream iss(line);
            currentCalories += stoi(line);
        }
    }

    cout << "Most calories: " << mostCalories << endl;
    cout << "Second most calories: " << secondMostCalories << endl;
    cout << "Third most calories: " << thirdMostCalories << endl;
    cout << "Total calories: " << mostCalories + secondMostCalories + thirdMostCalories << endl;
}