#include <iostream>

#include "race.h"

#define HOLDINGSPEEDMULTIPLIER 0
#define RELEASESPEEDMULTIPLIER 1
    
Race::Race(int time, int distance) {
    this->time = time;
    this->distance = distance;
}

int Race::GetRecordPossibilitiesCount() {
    int recordPossibilitiesCount = 0;

    // i references how long the button is held down for.
    for (int i = 0; i <= this->time; i++) {
        int holdingDistance = i * HOLDINGSPEEDMULTIPLIER;
        int releaseDistance = (this->time - i) * i * RELEASESPEEDMULTIPLIER;
        if (holdingDistance + releaseDistance > this->distance) {
            recordPossibilitiesCount++;
        } else if (recordPossibilitiesCount > 0) {  // Break out of the loop once we stop beating the record.
            break;
        }
    }

    return recordPossibilitiesCount;
}