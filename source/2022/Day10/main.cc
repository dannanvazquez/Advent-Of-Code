#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int sumSignalStrengths = 0;
int cycle = 0;
int xCPU = 1;

vector<int> pixelData;
int xCRT = 1;

void NextCycle() {
    if (cycle % 40 == 0) xCRT = cycle + 1;
    pixelData.push_back(xCRT);

    cycle++;
    if ((cycle - 20) % 40 == 0) sumSignalStrengths += xCPU * cycle;
}

int main() {
    string line;
    ifstream infile("input.txt");

    while (getline(infile, line)) {
        if (line.empty()) continue;

        NextCycle();

        string command;
        stringstream ss(line);
        ss >> command;

        if (command == "addx") {
            NextCycle();

            int num;
            ss >> num;
            xCPU += num;
            xCRT += num;
        }
    }

    cout << "The sum of the six signal strengths: " << sumSignalStrengths << endl;

    for (int i = 0; i < pixelData.size(); i++) {
        cout << pixelData[i];
        if (pixelData[i] < 10) cout << "   ";
        else if (pixelData[i] < 100) cout << "  ";
        else cout << " ";
        if ((i + 1) % 40 == 0) cout << endl;
    }
    cout << endl;

    cout << "Image processed by the CRT:\n";
    for (int i = 0; i < pixelData.size(); i++) {
        if (pixelData[i] >= i - 1 && pixelData[i] <= i + 1) cout << "#";
        else cout << " ";
        if ((i + 1) % 40 == 0) cout << endl;
    }
}
