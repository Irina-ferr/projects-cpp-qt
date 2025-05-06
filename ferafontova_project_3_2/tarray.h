#ifndef TARRAY_H
#define TARRAY_H

class TArray {
protected:
    float* data;    // Указатель на динамический массив
    int size;       // Текущий размер массива

public:
    // Конструкторы
    TArray();                               // Конструктор по умолчанию (размер 10, нули)
    TArray(int length, float initialValue = 0.0f);  // Параметризованный конструктор

    // Деструктор
    virtual ~TArray();

    // Методы
    void resize(int newSize);               // Изменение размера массива
    virtual void print() const;             // Вывод массива на экран (виртуальный)

    // Аксессоры (геттеры и сеттеры)
    int getSize() const;                    // Получить размер массива
    float getValue(int index) const;        // Получить значение по индексу
    void setValue(int index, float value);  // Установить значение по индексу
};

#endif // TARRAY_H
