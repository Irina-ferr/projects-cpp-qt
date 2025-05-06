/*Создать базовый класс TArray, который инкапсулирует и обслуживает динамический
 * массив вещественных чисел. Класс должен включать:
•	конструктор по умолчанию, создающий массив заданной длины и инициализирующий его нулями;
•	параметризованный конструктор, создающий массив заданной длины и инициализирующий
его заданными значениями;
•	деструктор, удаляющий созданные динамические структуры данных;
•	метод, позволяющий во время выполнения программы создавать динамический массив
заданной длины или изменять размер массива, если тот уже существует, в этом случае
 значения, уже хранящиеся в массиве, не должны быть потеряны (при увеличении длины
хвост дополняется нулями, при уменьшении длины теряются лишь значения в хвосте массива);
•	метод print(), распечатывающий на экране значения массива в строку;
•	методы-аксессоры, обеспечивающие чтение/запись значений массива и его длины
Поля и служебные методы класса должны быть скрыты в приватных или защищенных разделах.
Класс должен быть утилизирован в соответствии с рекомендациями C++. Создать консольную программу,
для демонстрации работы класса. Программа создает 2 объекта класса и независимо изменяет содержимое
 массивов, уменьшает и увеличивает длины массивов, выводит их содержимое после каждого этапа изменения
 значений и размеров на экран, используя методы класса.
*/
#include <QCoreApplication>
#include <iostream>

class TArray {
private:
    int size;
    float* data;

public:
    // Конструктор по умолчанию
    TArray() : size(10) {
        data = new float[size](); // Инициализация нулями
        std::cout << "Default constructor TArray\n";
    }

    // Параметризованный конструктор
    TArray(int length, float initialValue) : size(length) {
        data = new float[size];
        for(int i = 0; i < size; ++i) {
            data[i] = initialValue;
        }
        std::cout << "Constructor TArray\n";
    }

    // Деструктор
    ~TArray() {
        delete[] data;
        std::cout << "Destructor TArray\n";
    }

    // Изменение размера массива
    void resize(int newSize) {
        if(newSize == size) return;

        float* newData = new float[newSize]{};
        int copySize = (newSize < size) ? newSize : size;

        for(int i = 0; i < copySize; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;

    }

    // Вывод массива
    void print() const {
        for(int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Аксессоры
    int getSize() const { return size; }

    float getValue(int index) const {
        if(index >= 0 && index < size) return data[index];
        return 0.0f;
    }

    void setValue(int index, float value) {
        if(index >= 0 && index < size) data[index] = value;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    TArray array1(5, 1.0f);
    std::cout << "array1: ";
    array1.print();

    TArray array2(3, 2.5f);
    std::cout << "array2: ";
    array2.print();

    array1.setValue(2, 3.14f);
    array2.setValue(0, 7.77f);
    std::cout << "\nAfter modification:" << std::endl;
    std::cout << "array1: ";
    array1.print();
    std::cout << "array2: ";
    array2.print();

    std::cout << "\nResize array1 to 7" << std::endl;
    array1.resize(7);
    std::cout << "array1: ";
    array1.print();

    std::cout << "\nResize array2 to 2" << std::endl;
    array2.resize(2);
    std::cout << "array2: ";
    array2.print();

    array1.setValue(5, 5.5f);
    array1.setValue(6, 6.6f);
    std::cout << "\narray1 after new values:" << std::endl;
    array1.print();
    return a.exec();
}
