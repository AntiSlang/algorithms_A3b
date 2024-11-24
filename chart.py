import matplotlib.pyplot as plt
import numpy as np

step = 100
start_points = 500
max_points = 10100
points = np.arange(start_points, max_points, step)

files = [
    "random.txt",
    "random_hybrid.txt",
    "reversed.txt",
    "reversed_hybrid.txt",
    "swap.txt",
    "swap_hybrid.txt"
]

data = {}
for filename in files:
    with open(filename, "r") as file:
        data[filename] = [float(line.strip()) for line in file]

for i in range(0, len(files), 2):
    quick_file = files[i]
    intro_file = files[i + 1]

    quick_data = data[quick_file]
    intro_data = data[intro_file]

    plt.figure(figsize=(10, 6))
    plt.plot(points, quick_data, label="Quick Sort", color="blue")
    plt.plot(points, intro_data, label="Intro Sort", color="green")
    plt.xlabel("Длина массива, элементы")
    plt.ylabel("Время, мс")
    plt.title(f"Сравнение времени сортировки для Quick SORT и Intro SORT ({quick_file.split('.')[0]})")
    plt.legend()
    plt.grid(True)
    plt.show()
