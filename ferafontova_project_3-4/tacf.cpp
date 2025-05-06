#include "tacf.h"
#include <iostream>
#include <cmath>

void TACF::calculateACF() {
    float mean = calculateMean();
    float variance = calculateVariance();
    int maxLag = size / 2;

    acfValues.resize(maxLag + 1);

    for (int lag = 0; lag <= maxLag; ++lag) {
        float sum = 0.0f;
        int count = size - lag;

        for (int i = 0; i < count; ++i) {
            sum += (data[i] - mean) * (data[i + lag] - mean);
        }

        float acfValue = (variance != 0.0f) ? sum / (count * variance) : 0.0f;
        acfValues.setValue(lag, acfValue);
    }
}

void TACF::compute() {
    calculateACF();
}

float TACF::getACFValue(int lag) const {
    return acfValues.getValue(lag);
}

void TACF::printACF() const {
    std::cout << "\nACF values: ";
    for (int i = 0; i < acfValues.getSize(); ++i) {
        std::cout << "r(" << i << ")=" << acfValues.getValue(i) << "  ";
    }
}

void TACF::print() const {
    TVariance::print();
    printACF();
}
