// tarray.h
#ifndef TARRAY_H
#define TARRAY_H

#include <iostream>

template <typename T>
class TArray {
private:
    int size;
    T* data;

public:
    // Конструктор по умолчанию
    TArray() : size(10) {
        data = new T[size](); // Инициализация значением по умолчанию
        std::cout << "Default constructor TArray\n";
    }

    // Параметризованный конструктор
    TArray(int length, T initialValue) : size(length) {
        data = new T[size];
        for(int i = 0; i < size; ++i) {
            data[i] = initialValue;
        }
        std::cout << "Parametrized constructor TArray\n";
    }

    // Деструктор
    ~TArray() {
        delete[] data;
        std::cout << "Destructor TArray\n";
    }

    // Изменение размера массива
    void resize(int newSize) {
        if(newSize == size) return;

        T* newData = new T[newSize]{}; // Инициализация по умолчанию
        int copySize = (newSize < size) ? newSize : size;

        for(int i = 0; i < copySize; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;
    }

    // Вывод массива
    void print() const {
        for(int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Аксессоры
    int getSize() const { return size; }

    T getValue(int index) const {
        if(index >= 0 && index < size) return data[index];
        return T(); // Возвращает значение по умолчанию для типа T
    }

    void setValue(int index, T value) {
        if(index >= 0 && index < size) data[index] = value;
    }
};

#endif // TARRAY_H
