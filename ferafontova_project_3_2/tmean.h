#ifndef TMEAN_H
#define TMEAN_H

#include "tarray.h"

class TMean : public TArray {
public:
    // Наследуем конструкторы TArray
    using TArray::TArray;

    // Метод вычисления среднего арифметического
    float calculateMean() const;

    // Перегруженный метод print (с выводом среднего)
    void print() const override;
};

#endif // TMEAN_H
