#ifndef TMEAN_H
#define TMEAN_H

#include "tarray.h"

class TMean : public TArray {
public:
    using TArray::TArray;
    float calculateMean() const;
    virtual void print() const override;
};

#endif // TMEAN_H
