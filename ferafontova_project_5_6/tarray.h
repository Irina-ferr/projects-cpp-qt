#pragma once
#include <QVector>
#include <QString>
#include <QDebug>
#include <QFile>


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
    bool loadFromFile(const QString& filename) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла для чтения!";
            return false;
        }

        data.clear();
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            bool ok;
            float val = line.toFloat(&ok);
            if (ok) data.append(val);
            else qDebug() << "Некорректное значение:" << line;
        }
        file.close();
        return true;
    }

    bool saveToFile(const QString& filename) const {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла для записи!";
            return false;
        }

        QTextStream out(&file);
        for (float val : data) {
            out << QString::number(val, 'f', 3) << "\n"; // Запись с 3 знаками после запятой
        }
        file.close();
        return true;
    }
};
