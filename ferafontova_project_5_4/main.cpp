#include <QCoreApplication>
#include <iostream>
#include "tvariance.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int size;
    qDebug() << "Enter the array size:";
    std::cin >> size;

    if (size <= 0) {
        qDebug() << "Error: Invalid size!";
        return -1;
    }

    TVariance arr(size);

    // Ввод элементов
    for (int i = 0; i < size; ++i) {
        qDebug() << "Enter element" << i << ":";
        float val;
        std::cin >> val;
        arr.setValue(i, val);
    }

    // Демонстрация оператора ~
    qDebug() << "\nCurrent data:";
    ~arr;

    // Изменение данных
    arr.setValue(0, 15.5f);
    arr.resize(size + 1);
    arr.setValue(size, 100.0f);

    qDebug() << "\nAfter changes:";
    ~arr;

    // Вывод статистики
    qDebug() << "\nStatistics:";
    arr.print();

    return a.exec();
}
