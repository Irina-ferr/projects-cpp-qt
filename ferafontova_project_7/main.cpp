#include <QCoreApplication>
#include <iostream>

namespace Graphic {
const int WIDTH = 80;
const int HEIGHT = 25;
char** field = nullptr;

void clear() {
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

void bar(int& x, int& y, int& width, int& height) {
    if (!check(x, y, width, height)) {
        return;
    }
    for (int i = y; i < y + height && i < HEIGHT; ++i) {
        for (int j = x; j < x + width && j < WIDTH; ++j) {
            field[i][j] = static_cast<char>(219); // заполнение закрашенной полосы
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

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
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
