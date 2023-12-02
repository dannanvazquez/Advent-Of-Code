#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Knot {
    int x = 0;
    int y = 0;
    vector<pair<int, int>> visitedPositions = { {0, 0} };  // The pairs work as (x, y)
    Knot* child = NULL;

public:
    // Moves the knot in the direction(U, R, D, L) passed in and adds the new position to visitedPositions if not added already.
    void MoveDirection(char dir) {
        if (dir == 'U') y++;
        else if (dir == 'R') x++;
        else if (dir == 'D') y--;
        else if (dir == 'L') x--;
        else exit(1);

        if (child != NULL) child->FollowKnot(this);

        // Check if the new position was visited already before adding to visitedPositions.
        for (auto& pos : visitedPositions) if (pos.first == x && pos.second == y) return;
        visitedPositions.push_back(make_pair(x, y));
    }

    // Given the knot that this knot is following, make sure that this knot is always next to the head. This is automatically called after the parent moves.
    void FollowKnot(Knot* parent) {
        if (parent->x - x < 2 && parent->x - x > -2 && parent->y - y < 2 && parent->y - y > -2) return;  // Don't move if the knot is still next to its parent.

        if (parent->x == x) {  // If the x is the same as parent, then parent must be up or down.
            if (parent->y > y) y++;
            else y--;
        }
        else if (parent->y == y) {  // If the y is the same as parent, then parent must be right or left.
            if (parent->x > x) x++;
            else x--;
        }
        else {  // The parent must be diagonal
            if (parent->x > x) {
                if (parent->y > y) {
                    x++;
                    y++;
                }
                else {
                    x++;
                    y--;
                }
            }
            else {
                if (parent->y > y) {
                    x--;
                    y++;
                }
                else {
                    x--;
                    y--;
                }
            }
        }

        if (child != NULL) child->FollowKnot(this);

        // Check if the new position was visited already before adding to visitedPositions.
        for (auto& pos : visitedPositions) if (pos.first == x && pos.second == y) return;
        visitedPositions.push_back(make_pair(x, y));
    }

    void InsertTail(Knot* _child) {
        if (child == NULL) child = _child;
        else child->InsertTail(_child);
    }

    int TailsUniqueVisits() { 
        if (child == NULL) return visitedPositions.size();
        else return child->TailsUniqueVisits();
    }
};

int main() {
    Knot* head = new Knot;
    for (int i = 0; i < 9; i++) {
        Knot* temp = new Knot;
        head->InsertTail(temp);
    }

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        char dir;
        int amount;
        stringstream ss(line);
        ss >> dir;
        ss >> amount;

        for (int i = 0; i < amount; i++) {
            head->MoveDirection(dir);
        }
    }

    cout << "Amount of unique positions that the tail has visited: " << head->TailsUniqueVisits() << endl;
}
