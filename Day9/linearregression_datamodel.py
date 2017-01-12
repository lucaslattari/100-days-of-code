import numpy as np
import matplotlib.pyplot as plt

number_of_points = 500

x_point = []
y_point = []

a = 0.22
b = 0.78

for i in range(number_of_points):
	x = np.random.normal(0.0, 0.5)
	y = a*x + b + np.random.normal(0.0, 0.1)
	x_point.append([x])
	y_point.append([y])

plt.plot(x_point, y_point, 'o', label='Input Data')
plt.legend()
plt.show()
