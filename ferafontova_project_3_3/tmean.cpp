#include "tmean.h"
#include <iostream>

float TMean::calculateMean() const {
    if (size == 0) return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

void TMean::print() const {
    TArray::print();
    std::cout << "\nAverage value: " << calculateMean();
}
