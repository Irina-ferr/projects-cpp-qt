#pragma once
#include <QVector>
#include <QString>
#include <QDebug>

class TArray {
protected:
    QVector<float> data;

public:
    TArray() : data(10, 0.0f) {}
    TArray(int length, float initialValue = 0.0f) : data(length, initialValue) {}
    virtual ~TArray() = default;

    void operator~() const {
        QStringList elements;
        for (float val : data)
            elements << QString::number(val);
        qDebug() << "Содержимое массива:" << elements.join(' ');
    }
    void resize(int newSize) {
        data.resize(newSize);
    }

    virtual void print() const {
        QStringList elements;
        for (float val : data)
            elements << QString::number(val);
        qDebug() << "Элементы массива:" << elements.join(' ');
    }

    int getSize() const { return data.size(); }
    float getValue(int index) const {
        return (index >= 0 && index < data.size()) ? data[index] : 0.0f;
    }
    void setValue(int index, float value) {
        if (index >= 0 && index < data.size())
            data[index] = value;
    }
};
