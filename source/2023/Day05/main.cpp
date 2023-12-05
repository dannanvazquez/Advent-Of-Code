#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "seed.h"
#include "range.h"
#include "map.h"

#define MAPAMOUNT 7

int main() {
    std::vector<Seed*> seeds;
    Map *maps = new Map[MAPAMOUNT]; // Order is soil, fertilizer, water, light, temperature, humidity, and location.

    std::string line;
    std::ifstream infile("input.txt");

    // Get data about seeds first.
    if (getline(infile, line)) {
        std::string tmp; 
        std::stringstream ss(line);
        std::vector<std::string> seperatedWords;
        while(getline(ss, tmp, ' ')) {
            if (tmp.empty() || tmp == " ") continue;
            seperatedWords.push_back(tmp);
        }

        if (seperatedWords.size() > 1) {
            for (size_t i = 1; i < seperatedWords.size(); i++) {
                Seed* newSeed = new Seed(stoll(seperatedWords[i]));
                seeds.push_back(newSeed);
            }
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

    // Convert the seeds to their corresponding number for each map type.
    for (auto seed : seeds) {
        uint64_t nextSourceNumber = seed->GetSeedNumber();
        for (size_t i = 0; i < MAPAMOUNT; i++) {
            nextSourceNumber = maps[i].GetDestinationNumber(nextSourceNumber);
            seed->SetCorrespondingNumber(i, nextSourceNumber);
        }
    }

    // Find the lowest location number.
    uint64_t lowestLocationNumber = LLONG_MAX;
    for (auto seed : seeds) {
        uint64_t currentLocationNumber = seed->GetCorrespondingNumber(MAPAMOUNT - 1);

        if (currentLocationNumber < lowestLocationNumber) {
            lowestLocationNumber = currentLocationNumber;
        }
    }

    std::cout << "Lowest location number: " << lowestLocationNumber << std::endl;
}