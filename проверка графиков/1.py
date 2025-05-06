import matplotlib.pyplot as plt

def read_data(filename):
    with open(filename, 'r') as file:
        data = [float(line.strip()) for line in file]
    return data

values = read_data("1.txt")

plt.figure(figsize=(10, 5))
plt.plot(values, label='Гармонический сигнал')
plt.title('Визуализация сигнала')
plt.xlabel('Отсчеты')
plt.ylabel('Амплитуда')
plt.grid(True)
plt.legend()
plt.show()
