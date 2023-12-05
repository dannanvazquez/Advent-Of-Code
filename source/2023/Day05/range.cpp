#include <vector>
#include <string>
#include <sstream>

#include "range.h"
    
Range::Range(std::string data) {
    std::string tmp; 
    std::stringstream ss(data);
    std::vector<uint64_t> numbers;
    while(getline(ss, tmp, ' ')) {
        if (tmp.empty() || tmp == " ") continue;

        numbers.push_back(stoll(tmp));
    }

    this->destinationRangeStart = numbers[0];
    this->sourceRangeStart = numbers[1];
    this->rangeLength = numbers[2];
}

bool Range::IsInRange(uint64_t sourceNumber) {
    return (sourceNumber >= this->sourceRangeStart && sourceNumber < this->sourceRangeStart + rangeLength);
}

uint64_t Range::GetDestinationNumber(uint64_t sourceNumber) {
    return (sourceNumber - (this->sourceRangeStart - this->destinationRangeStart));
}