import matplotlib.pyplot as plt

filename = input("Введите имя файла с данными: ")

try:
    with open(filename, 'r') as file:
        values = [float(line.strip()) for line in file]
    
    plt.figure(figsize=(10, 5))
    plt.plot(values, label='Гармонический сигнал')
    plt.title('Визуализация сигнала')
    plt.xlabel('Отсчеты')
    plt.ylabel('Амплитуда')
    plt.grid(True)
    plt.legend()
    plt.show()

except FileNotFoundError:
    print(f"Файл {filename} не найден!")
except Exception as e:
    print(f"Ошибка: {e}")