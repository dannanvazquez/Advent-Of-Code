#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "seed.h"
#include "range.h"
#include "map.h"

#define MAPAMOUNT 7

uint64_t GetLocationOfSeedNumber(uint64_t seedNumber, Map maps[]) {
    Seed newSeed(seedNumber);
    uint64_t nextSourceNumber = seedNumber;
    for (size_t i = 0; i < MAPAMOUNT; i++) {
        nextSourceNumber = maps[i].GetDestinationNumber(nextSourceNumber);
        newSeed.SetCorrespondingNumber(i, nextSourceNumber);
    }
    return nextSourceNumber;
}

int main() {
    Map *maps = new Map[MAPAMOUNT]; // Order is soil, fertilizer, water, light, temperature, humidity, and location.

    std::string line;
    std::ifstream infile("input.txt");

    // Get data about seeds first.
    std::vector<uint64_t> seedData;
    if (getline(infile, line)) {
        std::string tmp; 
        std::stringstream ss(line);
        while(getline(ss, tmp, ' ')) {
            if (tmp == "seeds:" || tmp.empty() || tmp == " ") continue;

            seedData.push_back(stoll(tmp));
        }
    }

    // Get data for each map.
    int mapsIndex = -1;
    while (getline(infile, line)) {
        if (line.empty()) continue;

        if (line.find("map") != std::string::npos) {
            mapsIndex++;
            continue;
        }
        maps[mapsIndex].AddRange(line);
    }

    // Find the lowest location number of all seeds.
    uint64_t lowestLocationNumberFirstPart = LLONG_MAX;
    uint64_t lowestLocationNumberSecondPart = LLONG_MAX;

    uint64_t rangeStart = 0;
    for (size_t i = 0; i < seedData.size(); i++) {
        uint64_t currentNumber = seedData[i];
        uint64_t currentlocationNumber = GetLocationOfSeedNumber(currentNumber, maps);
        if (currentlocationNumber < lowestLocationNumberFirstPart) {
            lowestLocationNumberFirstPart = currentlocationNumber;
        }

        // First, check for an even number since we're looking for pairs and index starts at 0.
        if (i % 2 == 0) { 
            rangeStart = currentNumber;
        } else {
            for (int j = 0; j < currentNumber; j++) {
                uint64_t currentlocationNumber = GetLocationOfSeedNumber(rangeStart + j, maps);
                if (currentlocationNumber < lowestLocationNumberSecondPart) {
                    lowestLocationNumberSecondPart = currentlocationNumber;
                }
            }
        }   
    }

    std::cout << "Lowest location number of first part: " << lowestLocationNumberFirstPart << std::endl;
    std::cout << "Lowest location number of second part: " << lowestLocationNumberSecondPart << std::endl;
}