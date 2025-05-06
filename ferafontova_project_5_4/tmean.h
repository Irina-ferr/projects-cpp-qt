#pragma once
#include "tarray.h"

class TMean : public TArray {
public:
    using TArray::TArray;

    float calculateMean() const {
        if (data.isEmpty()) return 0.0f;
        float sum = 0.0f;
        for (float val : data) sum += val;
        return sum / data.size();
    }

    void print() const override {
        TArray::print();
        qDebug() << "Average value:" << calculateMean();
    }
};
