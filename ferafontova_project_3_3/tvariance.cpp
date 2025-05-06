#include "tvariance.h"
#include <cmath>
#include <iostream>

float TVariance::calculateVariance() const {
    if (size < 2) return 0.0f;

    float mean = calculateMean();
    float sumSqDiff = 0.0f;

    for (int i = 0; i < size; ++i) {
        float diff = data[i] - mean;
        sumSqDiff += diff * diff;
    }

    return sumSqDiff / size;
}

float TVariance::calculateStdDev() const {
    return sqrt(calculateVariance());
}

void TVariance::print() const {
    TMean::print();
    std::cout << "\nDispersion:" << calculateVariance();
    std::cout << "\nStandard deviation: " << calculateStdDev();
}
