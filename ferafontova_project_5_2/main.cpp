// main.cpp
#include <QCoreApplication>
#include "tarray.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Демонстрация для целых чисел
    qDebug() << "TArray with int";
    TArray<int> intArray1(5, 1);
    qDebug() << "intArray1:";
    intArray1.print();

    TArray<int> intArray2(3, 2);
    qDebug() << "intArray2:";
    intArray2.print();

    intArray1.setValue(2, 3);
    intArray2.setValue(0, 7);
    qDebug() << "\nAfter modification:";
    qDebug() << "intArray1:";
    intArray1.print();
    qDebug() << "intArray2:";
    intArray2.print();

    qDebug() << "\nResize intArray1 to 7";
    intArray1.resize(7);
    intArray1.setValue(5, 5);
    intArray1.setValue(6, 6);
    qDebug() << "intArray1 after resize and new values:";
    intArray1.print();

    // Демонстрация для вещественных чисел
    qDebug() << "\nTArray with float";
    TArray<float> floatArray1(5, 1.0f);
    qDebug() << "floatArray1:";
    floatArray1.print();

    TArray<float> floatArray2(3, 2.5f);
    qDebug() << "floatArray2:";
    floatArray2.print();

    floatArray1.setValue(2, 3.14f);
    floatArray2.setValue(0, 7.77f);
    qDebug() << "\nAfter modification:";
    qDebug() << "floatArray1:";
    floatArray1.print();
    qDebug() << "floatArray2:";
    floatArray2.print();

    qDebug() << "\nResize floatArray1 to 7";
    floatArray1.resize(7);
    qDebug() << "floatArray1:";
    floatArray1.print();

    qDebug() << "\nResize floatArray2 to 2";
    floatArray2.resize(2);
    qDebug() << "floatArray2:";
    floatArray2.print();

    floatArray1.setValue(5, 5.5f);
    floatArray1.setValue(6, 6.6f);
    qDebug() << "\nfloatArray1 after new values:";
    floatArray1.print();

    return a.exec();
}
