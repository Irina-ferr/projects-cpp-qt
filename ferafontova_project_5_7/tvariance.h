#pragma once
#include "tmean.h"
#include <QtMath>

class TVariance : public TMean {
public:
    using TMean::TMean;

    float calculateVariance() const {
        if (data.size() < 2) return 0.0f;
        float mean = calculateMean();
        float sum = 0.0f;
        for (float val : data)
            sum += qPow(val - mean, 2);
        return sum / data.size();
    }

    float calculateStdDev() const {
        return qSqrt(calculateVariance());
    }

    void print() const override {
        TMean::print();
        qDebug() << "Dispersion:" << calculateVariance();
        qDebug() << "Standard deviation:" << calculateStdDev();
    }
};
