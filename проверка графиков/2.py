import matplotlib.pyplot as plt
import numpy as np

def read_data(filename):
    with open(filename, 'r') as f:
        return [float(line.strip()) for line in f]

time_series = read_data('1.txt')
acf_values = read_data('acf_results.txt')

plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(time_series, marker='o', linestyle='-', color='b', markersize=4)
plt.title('Временной ряд')
plt.xlabel('Время (отсчёты)')
plt.ylabel('Значение')
plt.grid(True)

plt.subplot(1, 2, 2)
lags = np.arange(len(acf_values))
plt.plot(lags, acf_values)
plt.title('Автокорреляционная функция (АКФ)')
plt.ylabel('Значение АКФ')
plt.grid(True)

plt.tight_layout()
plt.show()