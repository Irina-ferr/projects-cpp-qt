#include <QCoreApplication>
#include <iostream>
using namespace std;
void show(int n, int m, char** array) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << array[i][j];
        }
        cout << endl;
    }
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    int n, m;

    // Ввод ширины и высоты прямоугольника
    cout << "Enter width (n >= 1): ";
    cin >> n;
    cout << "Enter height (m >= 1): ";
    cin >> m;

    // Проверка корректности входных данных
    if (n < 1 || m < 1) {
        cerr << "Error: width and height must be >= 1." << endl;
        return 1;
    }


    // Создание массива
    char** array = new char*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new char[m];
    }

    // Заполнение массива
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                array[i][j] = static_cast<char> (219); // Рамка
            } else {
                array[i][j] = ' '; // Пустое пространство внутри рамки
            }
        }
    }

    show(n, m, array);

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
