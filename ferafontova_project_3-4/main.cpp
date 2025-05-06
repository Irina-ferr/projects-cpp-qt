#include <QCoreApplication>
#include <iostream>
#include "tacf.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Incorrect array size!" << std::endl;
        return -1;
    }

    TACF array(size);

    for (int i = 0; i < size; ++i) {
        float value;
        std::cout << "Enter element" << i << ": ";
        std::cin >> value;
        array.setValue(i, value);
    }

    array.compute();

    std::cout << "\n\nAnalysis results:";
    array.print();
    std::cout << "\n";

    return a.exec();
}
