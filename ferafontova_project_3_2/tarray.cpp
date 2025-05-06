#include "tarray.h"
#include <iostream>

// Конструктор по умолчанию (размер 10, нули)
TArray::TArray() : size(10) {
    data = new float[size](); // Инициализация нулями
}

// Параметризованный конструктор
TArray::TArray(int length, float initialValue) : size(length) {
    data = new float[size];
    for (int i = 0; i < size; ++i) {
        data[i] = initialValue;
    }
}

// Деструктор
TArray::~TArray() {
    delete[] data;
}

// Изменение размера массива
void TArray::resize(int newSize) {
    if (newSize == size) return;

    float* newData = new float[newSize](); // Инициализация нулями
    int elementsToCopy = (newSize < size) ? newSize : size;

    for (int i = 0; i < elementsToCopy; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    size = newSize;
}

// Вывод массива на экран
void TArray::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
}

// Получить размер массива
int TArray::getSize() const {
    return size;
}

// Получить значение по индексу
float TArray::getValue(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return 0.0f;
}

// Установить значение по индексу
void TArray::setValue(int index, float value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}
