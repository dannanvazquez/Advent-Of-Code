#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> forest;  // 2D array of tree heights. forest[col][row]

bool isSeenFromEdge(int y, int x, int& _highestScore) {
    int treeHeight = forest[y][x];
    
    // Check if edge - Returns true without checking for scenic score because it will multiply out to 0 anyways.
    if (x == 0 || x == forest[y].size() - 1 || y == 0 || y == forest.size() - 1) return true;

    // Check how many trees can be seen left
    int treesSeenLeft = 1;
    for (int i = 1; i < x; i++) {
        if (forest[y][x - i] >= treeHeight) break;
        treesSeenLeft++;
    }

    // Check how many trees can be seen upwards
    int treesSeenUpwards = 1;
    for (int i = 1; i < y; i++) {
        if (forest[y - i][x] >= treeHeight) break;
        treesSeenUpwards++;
    }

    // Check how many trees can be seen right
    int treesSeenRight = 1;
    for (int i = 1; i < forest[y].size() - x - 1; i++) {
        if (forest[y][x + i] >= treeHeight) break;
        treesSeenRight++;
    }

    // Check how many trees can be seen downwards
    int treesSeenDownwards = 1;
    for (int i = 1; i < forest.size() - y - 1; i++) {
        if (forest[y + i][x] >= treeHeight) break;
        treesSeenDownwards++;
    }

    // Determine if this scenic score is the new highest score
    int scenicScore = treesSeenLeft * treesSeenUpwards * treesSeenRight * treesSeenDownwards;
    if (scenicScore > _highestScore) _highestScore = scenicScore;

    // Now that the scenic score has been calculated, return true if the tree can be seen from edge.
    if (treesSeenLeft == x && forest[y][0] < treeHeight) return true;
    if (treesSeenUpwards == y && forest[0][x] < treeHeight) return true;
    if (treesSeenRight == forest[y].size() - x - 1 && forest[y][forest[y].size() - 1] < treeHeight) return true;
    if (treesSeenDownwards == forest.size() - y - 1 && forest[forest.size() - 1][x] < treeHeight) return true;

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
    int highestScore = 0;

    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest[i].size(); j++) {
            if (isSeenFromEdge(i, j, highestScore)) treesSeen++;
        }
    }

    cout << "Total trees that can be seen from the edge: " << treesSeen << endl;
    cout << "Highest scenic score possible: " << highestScore << endl;
}
