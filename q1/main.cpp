#include <QCoreApplication>
#include "tarray.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TArray   x(5);
    for ( int i = 0; i < x.Count(); i++ )
        x.setData( i, i + 1 ) ;
    x.print();

    return a.exec();
}
