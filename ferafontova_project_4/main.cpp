//2.4.
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

    cout << "Enter width (m >= 1): ";
    cin >> m;
    cout << "Enter height (n >= 1): ";
    cin >> n;

    // проверка
    if (n < 1 || m < 1) {
        cerr << "Error: width and height must be >= 1." << endl;
        return 1;
    }

    // создание
    char** array = new char*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new char[m];
    }

    // заполнение
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array[i][j] = static_cast<char> (219);
        }
    }


    show(n, m, array);

    // освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return a.exec();
}
