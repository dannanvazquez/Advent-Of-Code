#include <stdint.h>
#include <vector>
#include <string>
#include <sstream>

#include "range.h"
#include "map.h"

void Map::AddRange(std::string data) {
    Range* newRange = new Range(data);
    this->ranges.push_back(newRange);
}

uint64_t Map::GetDestinationNumber(uint64_t sourceNumber) {
    for (auto range : ranges) {
        if (range->IsInRange(sourceNumber)) {
            return range->GetDestinationNumber(sourceNumber);
        }
    }

    return sourceNumber;
}