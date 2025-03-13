//2.3.
#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#include <iostream>


    for (int i = 32; i <= 255; ++i) {
        cout << i << ": " << static_cast<char>(i)<< endl;;
    }
    return 0;


    return a.exec();
}
