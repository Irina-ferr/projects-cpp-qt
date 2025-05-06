#include <QCoreApplication>
#include "tvariance.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    TVariance arr;

    // 1. Загрузка данных из файла
    if (!arr.loadFromFile("test_input.txt")) {
        qDebug() << "Не удалось загрузить данные!";
        return -1;
    }

    qDebug() << "\nЗагруженные данные:";
    ~arr;

    // 2. Анализ статистики
    qDebug() << "\nПервоначальная статистика:";
    arr.print();

    // 3. Изменение данных и сохранение
    arr.setValue(0, 15.0f);
    arr.resize(6);
    arr.setValue(5, 100.0f);

    if (!arr.saveToFile("modified_data.txt")) {
        qDebug() << "Ошибка сохранения!";
        return -1;
    }

    qDebug() << "\nИзмененные данные:";
    ~arr;

    // 4. Загрузка измененных данных
    TVariance arr2;
    if (!arr2.loadFromFile("modified_data.txt")) {
        qDebug() << "Ошибка загрузки измененных данных!";
        return -1;
    }

    qDebug() << "\nЗагруженные измененные данные:";
    ~arr2;
    qDebug() << "\nСтатистика измененных данных:";
    arr2.print();

    return a.exec();
}
