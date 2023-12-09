#include <string>
#include <vector>

#pragma once

struct Sequence { 
        std::vector<int> sequence;

        Sequence(std::string);
        int ExtrapolatedValue(std::vector<int>);
};