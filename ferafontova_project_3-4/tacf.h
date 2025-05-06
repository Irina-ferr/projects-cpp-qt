#ifndef TACF_H
#define TACF_H

#include "tvariance.h"
#include "tarray.h"

class TACF : public TVariance {
private:
    TArray acfValues;

    void calculateACF();

public:
    using TVariance::TVariance;

    void compute();
    float getACFValue(int lag) const;
    void printACF() const;
    virtual void print() const override;
};

#endif // TACF_H
