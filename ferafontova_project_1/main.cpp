// 2.1
#include <QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "I am" << endl <<"programming in" << endl << "Qt C++"<< endl;


    return a.exec();
}
