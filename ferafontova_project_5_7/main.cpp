#include <QCoreApplication>
#include "tacf.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Загрузка данных из файла
    QFile file("1.txt");
    QVector<float> signal;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while(!in.atEnd()) {
            float value;
            in >> value;
            signal.append(value);
        }
    }

    TACF acf(signal.size());
    for(int i = 0; i < signal.size(); ++i) {
        acf.setValue(i, signal[i]);
    }

    qDebug() << "Signal analysis:";
    ~acf;
    qDebug() << "Min:" << acf.findMin();
    qDebug() << "Max:" << acf.findMax();

    acf.computeACF();
    acf.print();
    acf.saveToFile("acf_results.txt");

    return a.exec();
}
