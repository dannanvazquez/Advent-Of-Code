#include <iostream>
#include <cmath>

#include "race.h"
    
Race::Race(int64_t time, int64_t distance) {
    this->time = time;
    this->distance = distance;
}

int Race::GetRecordPossibilitiesCount() {
    int minPossibility = ceil((-(this->time) + sqrt(this->time * this->time - 4 * this->distance)) / -2 + 0.01f);
    int maxPossibility = floor((-(this->time) - sqrt(this->time * this->time - 4 * this->distance)) / -2 - 0.01f);

    return maxPossibility - minPossibility + 1;
}