#pragma once

class Seed { 
    private:
        uint64_t seedNumber;
        uint64_t correspondingNumbers[7] = {0};  // Order is soil, fertilizer, water, light, temperature, humidity, and location.
    public:
        Seed(uint64_t);
        uint64_t GetSeedNumber();
        uint64_t GetCorrespondingNumber(int);
        void SetCorrespondingNumber(int, uint64_t);
        void PrintSeedInfo();
};