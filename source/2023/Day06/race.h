#pragma once

class Race { 
    private:
        int64_t time;
        int64_t distance;
    public:
        Race(int64_t, int64_t);
        int GetRecordPossibilitiesCount();
};