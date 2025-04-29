#pragma once
#include <random>

class RandomGenerator {
    private:
        long int seed;
        int start;
        int end;
    
    public:
        RandomGenerator();

        void setSeed(long int p_seed);
        void setBounds(int p_start, int p_end);
        int getRandomNumber();
        std::vector<int> getRandomSequence(int count);
};