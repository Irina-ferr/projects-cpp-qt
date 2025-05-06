#include <QCoreApplication>
#include <iostream>
#include "tvariance.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    int size;
    qDebug() << "Введите размер массива:";
    std::cin >> size;

    if (size <= 0) {
        qDebug() << "Некорректный размер массива!";
        return -1;
    }

    TVariance array(size);

    for (int i = 0; i < size; ++i) {
        std::cout << "Введите элемент " << i << ": ";
        float value;
        std::cin >> value;
        array.setValue(i, value);
    }

    qDebug() << "\nСтатистические характеристики массива:";
    array.print();

    return a.exec();
}
