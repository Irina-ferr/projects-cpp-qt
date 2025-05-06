#include "tarray.h"
#include <iostream>
// Добавить сообщения в конструкторы и деструкторы
// Конструктор по умолчанию (размер 10, нули)
TArray::TArray() : size(10) {
    data = new float[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
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

    float* newData = new float[newSize];
    int elementsToCopy = (newSize < size) ? newSize : size;

    // Копируем старые данные
    for (int i = 0; i < elementsToCopy; ++i) {
        newData[i] = data[i];
    }

    // Если новый размер больше, заполняем хвост нулями
    if (newSize > size) {
        for (int i = size; i < newSize; ++i) {
            newData[i] = 0;
        }
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
    std::cout << std::endl;
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
    return 0;
}

// Установить значение по индексу
void TArray::setValue(int index, float value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}
