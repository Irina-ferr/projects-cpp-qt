// 2.2
#include <QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int x, y, z;
    cout << "Enter the lenght of the first side of the rectangle" << endl;
    cout << "x= ";
    cin >> x;
    cout << endl << "Enter the lenght of the second side of the rectangle" << endl;
    cout << "y= ";
    cin >> y;
    z = x + x + y + y;
    cout << "The perimeter of the rectangle is " << z;
    return a.exec();
}
