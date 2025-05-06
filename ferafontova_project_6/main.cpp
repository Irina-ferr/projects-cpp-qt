//2.6
#include <QCoreApplication>
#include <iostream>

namespace Graphic {
/*пространство имен, в которое включен указатель на этот
двумерный массив и переменные, хранящие его размеры*/
const int WIDTH = 80;
const int HEIGHT = 25;
char** field = nullptr;

void clear() {
    // функцию clear(), заполняющую field
    // пробелами (очищающую графический образ поля псевдографики)
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            field[i][j] = ' '; // заполнение пробелами
        }
    }
}

void init() {
    field = new char*[HEIGHT];
    for (int i = 0; i < HEIGHT; ++i) {
        field[i] = new char[WIDTH];
    }
    clear(); // очистка поля при инициализации
}

void show() {
    // функцию show(), выводящую на экран содержимое field
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

// полоса
void bar(int x, int y, int width, int height) {
// функцию bar(), формирующую в field образ закрашенной полосы.
// У bar() объявить 4 параметра: координаты левого верхнего угла
// полосы относительно поля псевдографики, ширину и высоту полосы
    for (int i = y; i < y + height && i < HEIGHT; ++i) {
        for (int j = x; j < x + width && j < WIDTH; ++j) {
            field[i][j] = static_cast<char> (219);
        }
    }
}

void free() {
    for (int i = 0; i < HEIGHT; ++i) {
        delete[] field[i];
    }
    delete[] field;
}

}
int main() {
    using namespace Graphic;

    init();

    int left, top, width, height;

    std::cout << "left = ";
    std::cin >> left;
    std::cout << "top = ";
    std::cin >> top;
    std::cout << "width= ";
    std::cin >> width;
    std::cout << "height= ";
    std::cin >> height;

    bar(left, top, width, height);

    show();

    free();

    return 0;
}

