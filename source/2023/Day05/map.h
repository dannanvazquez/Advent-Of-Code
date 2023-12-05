#pragma once

class Map { 
    private:
        std::vector<Range*> ranges;
    public:
        void AddRange(std::string);
        uint64_t GetDestinationNumber(uint64_t);
};