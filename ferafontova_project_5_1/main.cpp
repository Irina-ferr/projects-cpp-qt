// main.cpp
#include <QCoreApplication>
#include "tarray.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Демонстрация для целых чисел
    std::cout << "TArray with int\n";
    TArray<int> intArray1(5, 1);
    std::cout << "intArray1: ";
    intArray1.print();

    TArray<int> intArray2(3, 2);
    std::cout << "intArray2: ";
    intArray2.print();

    intArray1.setValue(2, 3);
    intArray2.setValue(0, 7);
    std::cout << "\nAfter modification:\n";
    std::cout << "intArray1: ";
    intArray1.print();
    std::cout << "intArray2: ";
    intArray2.print();

    std::cout << "\nResize intArray1 to 7\n";
    intArray1.resize(7);
    intArray1.setValue(5, 5);
    intArray1.setValue(6, 6);
    std::cout << "intArray1 after resize and new values: ";
    intArray1.print();

    // Демонстрация для вещественных чисел
    std::cout << "\nTArray with float\n";
    TArray<float> floatArray1(5, 1.0f);
    std::cout << "floatArray1: ";
    floatArray1.print();

    TArray<float> floatArray2(3, 2.5f);
    std::cout << "floatArray2: ";
    floatArray2.print();

    floatArray1.setValue(2, 3.14f);
    floatArray2.setValue(0, 7.77f);
    std::cout << "\nAfter modification:\n";
    std::cout << "floatArray1: ";
    floatArray1.print();
    std::cout << "floatArray2: ";
    floatArray2.print();

    std::cout << "\nResize floatArray1 to 7\n";
    floatArray1.resize(7);
    std::cout << "floatArray1: ";
    floatArray1.print();

    std::cout << "\nResize floatArray2 to 2\n";
    floatArray2.resize(2);
    std::cout << "floatArray2: ";
    floatArray2.print();

    floatArray1.setValue(5, 5.5f);
    floatArray1.setValue(6, 6.6f);
    std::cout << "\nfloatArray1 after new values: ";
    floatArray1.print();

    return a.exec();
}
