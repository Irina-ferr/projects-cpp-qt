#include "tarray.h"
#include <iostream>

TArray::TArray() : size(10) {
    data = new float[size]();
}

TArray::TArray(int length, float initialValue) : size(length) {
    data = new float[size];
    for (int i = 0; i < size; ++i) {
        data[i] = initialValue;
    }
}

TArray::~TArray() {
    delete[] data;
}

void TArray::resize(int newSize) {
    if (newSize == size) return;

    float* newData = new float[newSize]();
    int elementsToCopy = (newSize < size) ? newSize : size;

    for (int i = 0; i < elementsToCopy; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    size = newSize;
}

void TArray::print() const {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
}

int TArray::getSize() const {
    return size;
}

float TArray::getValue(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return 0.0f;
}

void TArray::setValue(int index, float value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}
