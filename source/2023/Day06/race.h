#pragma once

class Race { 
    private:
        int time;
        int distance;
    public:
        Race(int, int);
        int GetRecordPossibilitiesCount();
};