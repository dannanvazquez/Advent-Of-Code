#include <iostream>

#include "seed.h"
    
Seed::Seed(uint64_t seedNumber) {
    this->seedNumber = seedNumber;
}

uint64_t Seed::GetSeedNumber() {
    return this->seedNumber;
}

uint64_t Seed::GetCorrespondingNumber(int index) {
    return this->correspondingNumbers[index];
}

void Seed::SetCorrespondingNumber(int index, uint64_t correspondingNumber) {
    this->correspondingNumbers[index] = correspondingNumber;
}

void Seed::PrintSeedInfo() {
    std::cout << "Seed " << this->seedNumber << ", soil " << this->correspondingNumbers[0] << ", fertilizer " << this->correspondingNumbers[1] << ", water " << this->correspondingNumbers[2] << ", light " << this->correspondingNumbers[3] << ", temperature " << this->correspondingNumbers[4] << ", humidity " << this->correspondingNumbers[5] << ", location " << this->correspondingNumbers[6] << ".\n";
}