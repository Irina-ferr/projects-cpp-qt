#include <QCoreApplication>
#include <iostream>
#include "tmean.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Incorrect array size!" << std::endl;
        return -1;
    }

    TMean array(size);

    // Ввод значений с клавиатуры
    for (int i = 0; i < size; ++i) {
        float value;
        std::cout << "Enter element " << i << ": ";
        std::cin >> value;
        array.setValue(i, value);
    }

    // Вывод массива и среднего значения
    std::cout << "\nArray and its average:\n";
    array.print();
    std::cout << std::endl;

    return a.exec();
}
