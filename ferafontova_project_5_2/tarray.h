// tarray.h
#ifndef TARRAY_H
#define TARRAY_H

#include <QVector>
#include <QDebug>
#include <QString>

template <typename T>
class TArray {
private:
    QVector<T> data;

public:
    // Конструктор по умолчанию (размер 10, значения по умолчанию)
    TArray() : data(10, T()) {
        qDebug() << "Default constructor TArray";
    }

    // Параметризованный конструктор
    TArray(int length, const T& initialValue) : data(length, initialValue) {
        qDebug() << "Parametrized constructor TArray";
    }

    // Деструктор (явно объявлен только для вывода сообщения)
    ~TArray() {
        qDebug() << "Destructor TArray";
    }

    // Изменение размера массива
    void resize(int newSize) {
        data.resize(newSize);
    }

    // Формирование строки с элементами массива и вывод через qDebug()
    void print() const {
        QStringList elements;
        for (const T& val : data) {
            elements << QString::number(val);
        }
        qDebug() << "Array:" << elements.join(" ");
    }

    // Аксессоры
    int getSize() const { return data.size(); }

    T getValue(int index) const {
        return (index >= 0 && index < data.size()) ? data.at(index) : T();
    }

    void setValue(int index, const T& value) {
        if (index >= 0 && index < data.size())
            data[index] = value;
    }
};

#endif // TARRAY_H
