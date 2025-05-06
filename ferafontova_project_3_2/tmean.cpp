#include "tmean.h"
#include <iostream>

// Вычисление среднего арифметического
float TMean::calculateMean() const {
    if (size == 0) return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

// Перегруженный метод print
void TMean::print() const {
    TArray::print(); // Вывод массива (из базового класса)
    std::cout << "\nAverage value: " << calculateMean(); // Дополнительный вывод среднего
}
