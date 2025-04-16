#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {
    seed = 1;
    start = 1;
    end = 1000;
}

void RandomGenerator::setSeed(int p_seed) {
    seed = p_seed;
    srand(seed);
}

void RandomGenerator::setBounds(int p_start, int p_end) {
    if (p_start < p_end){
        start = p_start;
        end = p_end;
    } else {
        start = p_end;
        end = p_start;
    }
}

int RandomGenerator::getRandomNumber() {
    return rand() % (end - start + 1) + start;
}