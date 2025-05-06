// 2.1
#include <QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "I am\n" <<"programming in\n" << "Qt C++\n";


    return a.exec();
}
