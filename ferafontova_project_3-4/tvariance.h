#ifndef TVARIANCE_H
#define TVARIANCE_H

#include "tmean.h"

class TVariance : public TMean {
public:
    using TMean::TMean;
    float calculateVariance() const;
    float calculateStdDev() const;
    virtual void print() const override;
};

#endif // TVARIANCE_H
