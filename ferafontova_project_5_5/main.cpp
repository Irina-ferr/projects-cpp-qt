#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

int main() {
    double amplitude, period, phase, offset;
    int num_samples;
    string filename;

    cout << "Amplitude: ";
    cin >> amplitude;
    cout << "Period: ";
    cin >> period;
    cout << "Initial phase (in radians): ";
    cin >> phase;
    cout << "Bias: ";
    cin >> offset;
    cout << "Number of values: ";
    cin >> num_samples;
    cout << "File name: ";
    cin >> filename;

    vector<double> signal;
    signal.reserve(num_samples);

    for (int i = 0; i < num_samples; ++i) {
        double t = i;
        double value = amplitude * sin(2 * M_PI * t / period + phase) + offset;
        signal.push_back(value);
    }

    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &val : signal) {
            file << val << "\n";
        }
        cout << "Data saved in " << filename << endl;
    } else {
        cerr << "Error writing to file!" << endl;
        return 1;
    }

    return 0;
}
/*Амплитуда: 5
Период: 10
Начальная фаза (в радианах): 0
Смещение: 2
Количество значений: 50
Имя файла: signal.txt*/
