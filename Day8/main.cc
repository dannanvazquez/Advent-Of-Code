#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> forest;  // 2D array of tree heights. forest[col][row]

bool isSeenFromEdge(int y, int x) {
    int treeHeight = forest[y][x];
    
    // Check if edge
    if (x == 0 || x == forest[y].size() - 1 || y == 0 || y == forest.size() - 1) return true;

    // Check left
    for (int i = 1; i <= x; i++) {
        if (forest[y][x - i] >= treeHeight) break;
        if (i == x) return true;
    }

    // Check upwards
    for (int i = 1; i <= y; i++) {
        if (forest[y - i][x] >= treeHeight) break;
        if (i == y) return true;
    }

    // Check right
    for (int i = 1; i < forest[y].size() - x; i++) {
        if (forest[y][x + i] >= treeHeight) break;
        if (i == forest[y].size() - x - 1) return true;
    }

    // Check downwards
    for (int i = 1; i < forest.size() - y; i++) {
        if (forest[y + i][x] >= treeHeight) break;
        if (i == forest.size() - y - 1) return true;
    }

    return false;
}

int main() {
    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        forest.push_back(row);
    }

    int treesSeen = 0;

    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest[i].size(); j++) {
            if (isSeenFromEdge(i, j)) treesSeen++;
        }
    }

    cout << "Total trees that can be seen from the edge: " << treesSeen << endl;
}
