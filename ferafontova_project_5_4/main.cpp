#include <QCoreApplication>
#include <iostream>
#include "tvariance.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int size;
    qDebug() << "Введите размер массива:";
    std::cin >> size;

    if (size <= 0) {
        qDebug() << "Ошибка: некорректный размер!";
        return -1;
    }

    TVariance arr(size);

    // Ввод элементов
    for (int i = 0; i < size; ++i) {
        qDebug() << "Введите элемент" << i << ":";
        float val;
        std::cin >> val;
        arr.setValue(i, val);
    }

    // Демонстрация оператора ~
    qDebug() << "\nТекущие данные:";
    ~arr;

    // Изменение данных
    arr.setValue(0, 15.5f);
    arr.resize(size + 1);
    arr.setValue(size, 100.0f);

    qDebug() << "\nПосле изменений:";
    ~arr;

    // Вывод статистики
    qDebug() << "\nСтатистика:";
    arr.print();

    return a.exec();
}
