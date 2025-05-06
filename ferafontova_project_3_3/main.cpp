#include <QCoreApplication>
#include <iostream>
#include "tvariance.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Incorrect array size!" << std::endl;
        return -1;
    }

    TVariance array(size);

    for (int i = 0; i < size; ++i) {
        float value;
        std::cout << "Enter element" << i << ": ";
        std::cin >> value;
        array.setValue(i, value);
    }

    std::cout << "\nStatistical characteristics of the array:\n";
    array.print();
    std::cout << std::endl;

    return a.exec();
}
