#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "race.h"

int main() {
    std::string line;
    std::ifstream infile("input.txt");

    // Get data about race times
    std::vector<int> raceTimes;
    if (getline(infile, line)) {
        std::string tmp; 
        std::stringstream ss(line);
        while(getline(ss, tmp, ' ')) {
            if (tmp == "Time:" || tmp.empty() || tmp == " ") continue;

            raceTimes.push_back(stoi(tmp));
        }
    }

    // Get data about race record distances
    std::vector<int> raceDistances;
    if (getline(infile, line)) {
        std::string tmp; 
        std::stringstream ss(line);
        while(getline(ss, tmp, ' ')) {
            if (tmp == "Distance:" || tmp.empty() || tmp == " ") continue;

            raceDistances.push_back(stoi(tmp));
        }
    }

    // Check if we retrieved the same amount of race time and distance data.
    if (raceTimes.size() != raceDistances.size()) {
        std::cout << "raceTimes and raceDistances are not the same size.\n";
        exit(0);
    }

    // Iterate through each race to get the possible record possibilities count and multiply it to a total.
    int totalRaceRecordPossibilitiesMultiplied = 1;
    for (int i = 0; i < raceTimes.size(); i++) {
        Race newRace(raceTimes[i], raceDistances[i]);
        totalRaceRecordPossibilitiesMultiplied *= newRace.GetRecordPossibilitiesCount();
    }

    std::cout << "Total number of ways to beat each record multiplied by each other: " << totalRaceRecordPossibilitiesMultiplied << std::endl;
}