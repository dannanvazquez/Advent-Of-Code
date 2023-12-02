#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../Include/BigInt.hpp"

using namespace std;

struct Monkey {
    vector<BigInt> items;  // List of items the monkey is currently holding.
    string operation;  // Formula to get the new worry level. Example: old * 19
    int test;  // Check if the new worry level is divisible.
    int ifTrue;  // If the above test is divisible, go to this monkey.
    int ifFalse;  // If the above test is NOT divisible, go to this monkey.
    int inspectedCount = 0;  // How many times this monkey has inspected an item.
};

int main() {
    vector<Monkey*> monkeys;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        Monkey* new_monkey = new Monkey;

        // Get the starting items
        getline(infile, line);
        line.erase(0, 18);
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (word.back() == ',') word.pop_back();
            new_monkey->items.push_back(stoll(word));
        }

        // Get the operation
        getline(infile, line);
        line.erase(0, 19);
        new_monkey->operation = line;

        // Get the divisible by test
        getline(infile, line);
        line.erase(0, 21);
        new_monkey->test = stoi(line);

        // Get the if true monkey number
        getline(infile, line);
        line.erase(0, 29);
        new_monkey->ifTrue = stoi(line);

        // Get the if false monkey number
        getline(infile, line);
        line.erase(0, 30);
        new_monkey->ifFalse = stoi(line);

        monkeys.push_back(new_monkey);
    }

    cout << "How many rounds of monkey business?\n";
    int rounds;
    cin >> rounds;

    while (rounds > 0) {
        rounds--;

        for (auto monkey : monkeys) {
            //cout << "Monkey!\n";
            while (monkey->items.size() > 0) {
                BigInt item = monkey->items[0];
                BigInt firstNum;
                char op;
                BigInt secNum;

                istringstream iss(monkey->operation);
                string word;

                iss >> word;
                if (word == "old") firstNum = item;
                else firstNum = stoll(word);

                iss >> word;
                op = word[0];

                iss >> word;
                if (word == "old") secNum = item;
                else secNum = stoll(word);

                if (op == '*') item = firstNum * secNum;
                else if (op == '+') item = firstNum + secNum;

                item /= 3;

                if (item % monkey->test == 0) {
                    //cout << "moving " << item << " to monkey " << monkey->ifTrue << endl;
                    monkeys[monkey->ifTrue]->items.push_back(item);
                }
                else {
                    //cout << "moving " << item << " to monkey " << monkey->ifFalse << endl;
                    monkeys[monkey->ifFalse]->items.push_back(item);
                }

                monkey->items.erase(monkey->items.begin());
                monkey->inspectedCount++;
            }
        }

        
        cout << "== After round " << 30 - rounds << " ==\n";
        for (int i = 0; i < monkeys.size(); i++) {
            cout << "Monkey " << i << " inspected items " << monkeys[i]->inspectedCount << " times.\n";
            for (auto& item : monkeys[i]->items) {
                cout << " - " << item << endl;
            }
        }
        cout << endl;
        
    }

    BigInt mostActive = 0;
    BigInt secondMostActive = 0;

    for (auto monkey : monkeys) {
        cout << monkey->inspectedCount << endl;
        if (monkey->inspectedCount > mostActive) {
            secondMostActive = mostActive;
            mostActive = monkey->inspectedCount;
        }
        else if (monkey->inspectedCount > secondMostActive) {
            secondMostActive = monkey->inspectedCount;
        }
    }

    cout << "Level of monkey business: " << mostActive * secondMostActive << endl;
}
