#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int sumSignalStrengths = 0;
    int x = 1;
    int cycle = 1;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        string command;
        stringstream ss(line);
        ss >> command;
        
        if (command == "addx") {
            cycle++;
            if ((cycle - 20) % 40 == 0) sumSignalStrengths += x * cycle;

            string num;
            ss >> num;
            x += stoi(num);
        }

        cycle++;
        if ((cycle - 20) % 40 == 0) sumSignalStrengths += x * cycle;
    }

    cout << "The sum of the six signal strengths: " << sumSignalStrengths << endl;
}
