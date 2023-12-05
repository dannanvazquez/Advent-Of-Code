#pragma once

#include <string>

class Range {
    private:
        uint64_t destinationRangeStart;
        uint64_t sourceRangeStart;
        uint64_t rangeLength;
    public:
        Range(std::string);
        bool IsInRange(uint64_t);
        uint64_t GetDestinationNumber(uint64_t);
};