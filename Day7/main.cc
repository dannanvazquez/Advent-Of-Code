#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Directory {
    string name;
    int size = 0;
    Directory* parentDir = NULL;
    vector<Directory*> directories;
    unordered_map<string, int> files;  // Currently not used, but may be useful in the future to manage individual file sizes.

    void InsertDir(string _name) {
        Directory* temp = new Directory;
        temp->name = _name;
        temp->parentDir = this;
        directories.push_back(temp);
    }

    Directory* GetDir(string _name) {
        for (auto dir : directories) if (dir->name == _name) return dir;
        return NULL;
    }

    void InsertFile(string _name, int _size) {
        this->files.insert({_name, _size});
    }
};

int total_size = 0;  // Total sum of directories that are only under a set limit. This is set by the function SumOfDirectories;
int max_size = 0;  // The limit that should be compared under when adding to the total sum of directories. This is set by user input.

void SumOfDirectories(Directory* root, int& size) {
    if (root->size < max_size) size += root->size;
    for (auto dir : root->directories) {
        SumOfDirectories(dir, size);
    }
}

int main() {
    cout << "I will look for the sum of all directories that are under a specific limit.\n";
    cout << "Please input what that limit should be:\n";
    cin >> max_size;

    Directory* root = new Directory;
    root->name = "/";
    Directory* currentDir = root;

    string line;
    ifstream infile("input.txt");
    while (getline(infile, line)) {
        if (line.empty()) continue;

        string word;
        vector<string> input;
        stringstream ss(line);
        while (getline(ss, word, ' ')) {
            input.push_back(word);
        }

        if (input[0] == "$") {
            if (input[1] == "cd") {
                if (input[2] == "..") currentDir = currentDir->parentDir;
                else if (input[2] == "/") currentDir = root;
                else currentDir = currentDir->GetDir(input[2]);
            } else if (input[1] == "ls") continue;
        } else {
            if (input[0] == "dir") currentDir->InsertDir(input[1]);
            else {
                // When a file is added, increase the directory's size along with the directories traversed upwards.
                int file_size = stoi(input[0]);
                currentDir->InsertFile(input[1], file_size);
                currentDir->size += file_size;
                Directory* traverse_up = currentDir;
                while (traverse_up->parentDir != NULL) {
                    traverse_up = traverse_up->parentDir;
                    traverse_up->size += file_size;
                }

            }
        }
    }

    SumOfDirectories(root, total_size);

    cout << "The total sum of directories with a size under " << max_size << ": " << total_size << endl;
}
