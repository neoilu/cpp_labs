#pragma once
#include <random>

class RandomGenerator {
    private:
        int seed;
        int start;
        int end;
    
    public:
        RandomGenerator();

        void setSeed(int p_seed);
        void setBounds(int p_start, int p_end);
        int getRandomNumber();
};