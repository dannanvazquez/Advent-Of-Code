#include <string>
#include <vector>

#pragma once

struct Sequence { 
        std::vector<int> sequence;

        Sequence(std::string);
        int PostExtrapolatedValue(std::vector<int>);
        int PreExtrapolatedValue(std::vector<int>);
};