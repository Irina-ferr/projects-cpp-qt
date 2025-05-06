#include <QCoreApplication>
#include <iostream>
#include "tvariance.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    int size;
    qDebug() << "Enter the array size:";
    std::cin >> size;

    if (size <= 0) {
        qDebug() << "Incorrect array size!";
        return -1;
    }

    TVariance array(size);

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter the item " << i << ": ";
        float value;
        std::cin >> value;
        array.setValue(i, value);
    }

    qDebug() << "\nStatistical characteristics of the array:";
    array.print();

    return a.exec();
}
