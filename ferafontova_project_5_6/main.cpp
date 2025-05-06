#include <QCoreApplication>
#include "tvariance.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    TVariance arr;

    // 1. Загрузка данных из файла
    if (!arr.loadFromFile("test_input.txt")) {
        qDebug() << "Failed to load data!";
        return -1;
    }

    qDebug() << "\nUploaded data:";
    ~arr;

    // 2. Анализ статистики
    qDebug() << "\nInitial statistics:";
    arr.print();

    // 3. Изменение данных и сохранение
    arr.setValue(0, 15.0f);
    arr.resize(6);
    arr.setValue(5, 100.0f);

    if (!arr.saveToFile("modified_data.txt")) {
        qDebug() << "Saving error!";
        return -1;
    }

    qDebug() << "\nModified data:";
    ~arr;

    // 4. Загрузка измененных данных
    TVariance arr2;
    if (!arr2.loadFromFile("modified_data.txt")) {
        qDebug() << "Error loading modified data!";
        return -1;
    }

    qDebug() << "\nUploaded modified data:";
    ~arr2;
    qDebug() << "\nStatistics of changed data:";
    arr2.print();

    return a.exec();
}
