//2.8
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
bool check(int& x, int& y, int& width, int& height) {
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (width < 0) {
        width = 0;
    }
    if (height < 0) {
        height = 0;
    }
    if (x + width > WIDTH) {
        width = WIDTH - x;
    }
    if (y + height > HEIGHT) {
        height = HEIGHT - y;
    }
    return true;
}

// полоса
void bar(int x, int y, int width, int height, char fillChar) {
    if (!check(x, y, width, height)) {
        return; // если параметры некорректны, выходим из функции
    }

    for (int i = y; i < y + height; ++i) {
        for (int j = x; j < x + width; ++j) {
            field[i][j] = fillChar; // заполнение заданным символом
        }
    }
}
void rectangle(int x, int y, int outerWidth, int outerHeight) {
    if (!check(x, y, outerWidth, outerHeight)) {
        return; // Если параметры некорректны, выходим из функции
    }

    // рисуем внешний контур прямоугольника
    bar(x, y, outerWidth, 1, static_cast<char> (219)); // верхняя сторона
    bar(x, y + outerHeight - 1, outerWidth, 1, static_cast<char> (219)); // нижняя сторона
    bar(x, y, 1, outerHeight, static_cast<char> (219)); // левый бок
    bar(x + outerWidth - 1, y, 1, outerHeight, static_cast<char> (219)); // правый бок

    // рисуем внутренний контур с зазором в 1 символ
    int innerX = x + 2;
    int innerY = y + 2;
    int innerWidth = outerWidth - 3;
    int innerHeight = outerHeight - 3;

    if (innerWidth > 0 && innerHeight > 0) {
        bar(innerX, innerY, innerWidth-1, 1, static_cast<char> (219)); // верхняя сторона внутреннего контур
        bar(innerX, innerY + innerHeight - 2, innerWidth-1, 1, static_cast<char> (219)); // нижняя сторона внутреннего контура
        bar(innerX, innerY, 1, innerHeight-1, static_cast<char> (219)); // левый бок внутреннего контура
        bar(innerX + innerWidth - 2, innerY, 1, innerHeight-1, static_cast<char> (219)); // правый бок внутреннего контура
    }



    for (int j = innerX + 2; j < innerX + innerWidth - 3; ++j) {
        field[innerY + innerHeight / 2][j] = static_cast<char> (219); // горизонтальная полоса
        field[innerY + (innerHeight / 2)-1][j] = static_cast<char> (219);
    }
}
void free() {
    for (int i = 0; i < HEIGHT; ++i) {
        delete[] field[i];
    }
    delete[] field;
}

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    using namespace Graphic;

    init();

    int left, top, outerWidth, outerHeight;

    std::cout << "left = ";
    std::cin >> left;

    std::cout << "top = ";
    std::cin >> top;

    std::cout << "outer width= ";
    std::cin >> outerWidth;

    std::cout << "outer height= ";
    std::cin >> outerHeight;

    rectangle(left, top, outerWidth, outerHeight);

    show();

    free();

    return 0;
}


