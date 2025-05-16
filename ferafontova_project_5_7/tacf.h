#pragma once
#include "tvariance.h"
#include <QFile>
class TACF : public TVariance {
    QVector<float> acfValues;

public:
    using TVariance::TVariance;

    void computeACF() {
        float mean = calculateMean();
        float variance = calculateVariance();
        int maxLag = data.size() / 2;

        acfValues.resize(maxLag + 1);

        for(int lag = 0; lag <= maxLag; ++lag) {
            float sum = 0.0f;
            int count = data.size() - lag;

            for(int i = 0; i < count; ++i) {
                sum += (data[i] - mean) * (data[i + lag] - mean);
            }

            acfValues[lag] = (variance != 0.0f) ? sum / (count * variance) : 0.0f;
        }
    }

    void saveToFile(const QString& filename) {
        QFile file(filename);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            for(auto it = acfValues.begin(); it != acfValues.end(); ++it) {
                out << *it << "\n";
            }
        }
    }

    void print() const override {
        TVariance::print();
        qDebug() << "\nACF values:";
        for(int i = 0; i < acfValues.size(); ++i) {
            qDebug() << QString("r(%1) = %2").arg(i).arg(acfValues[i], 0, 'f', 4);
        }
    }
};
