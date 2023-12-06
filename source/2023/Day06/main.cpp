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
    std::vector<std::string> raceTimesData;
    if (getline(infile, line)) {
        std::string tmp; 
        std::stringstream ss(line);
        while(getline(ss, tmp, ' ')) {
            if (tmp == "Time:" || tmp.empty() || tmp == " ") continue;

            raceTimesData.push_back(tmp);
        }
    }

    // Get data about race record distances
    std::vector<std::string> raceDistancesData;
    if (getline(infile, line)) {
        std::string tmp; 
        std::stringstream ss(line);
        while(getline(ss, tmp, ' ')) {
            if (tmp == "Distance:" || tmp.empty() || tmp == " ") continue;

            raceDistancesData.push_back(tmp);
        }
    }

    // Check if we retrieved the same amount of race time and distance data.
    if (raceTimesData.size() != raceDistancesData.size()) {
        std::cout << "raceTimes and raceDistances are not the same size.\n";
        exit(0);
    }

    // Preparing to store variables for later when we determine the long race record possibilities.
    std::string longRaceTimeData;
    std::string longRaceDistanceData;

    // Iterate through each race to get the possible record possibilities count and multiply it to a total. Also, figure out the numbers for the longer race.
    int totalRaceRecordPossibilitiesMultiplied = 1;
    for (int i = 0; i < raceTimesData.size(); i++) {
        Race newRace(stoi(raceTimesData[i]), stoi(raceDistancesData[i]));
        totalRaceRecordPossibilitiesMultiplied *= newRace.GetRecordPossibilitiesCount();

        longRaceTimeData = longRaceTimeData + raceTimesData[i];
        longRaceDistanceData = longRaceDistanceData + raceDistancesData[i];
    }

    // Get the possible record possibility in one long race.
    Race longRace(stoll(longRaceTimeData), stoll(longRaceDistanceData));
    int longRaceRecordPossibilities = longRace.GetRecordPossibilitiesCount();

    std::cout << "Total number of ways to beat each record multiplied by each other: " << totalRaceRecordPossibilitiesMultiplied << std::endl;
    std::cout << "Numbers of ways to beat the record of the longer race: " << longRaceRecordPossibilities << std::endl;
}