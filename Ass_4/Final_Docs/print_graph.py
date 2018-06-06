import sys
import math
import csv

import matplotlib.pyplot as plt
import numpy as np



# get input from file
temp = []
day = []

csv.register_dialect('semi', delimiter = ';')

with open(sys.argv[1], 'rU') as f:
	reader = csv.reader(f, dialect = 'semi')
	header = next(reader)
	for row in reader:
		temp.append(row[7])
		day.append(row[8])


temp = map(float, temp)
day = map(float, day)

points = [[day[i], temp[i]] for i in range(len(day))]



# plot graph
x = np.linspace(0, 22304, 22305)

y1 = 8.02142 + (0.000106948*x) + (4.28089*np.cos((2*np.pi)/365.25)) + (8.18686*np.sin((2*np.pi*x)/365.25)) + (-0.790631*np.cos((2*np.pi*x)/3908.175)) + (-0.29536*np.sin((2*np.pi*x)/3908.175))
y2 = 8.02142 + (0.000106948*x)

plt.plot(day,temp, 'g')
plt.plot(x,y1,'r')
plt.plot(x,y2,'b')

plt.suptitle('Corvallis Temperature Data Trends', fontsize=20)
plt.xlabel('Time (Days)', fontsize=15)
plt.ylabel('Temperature (Celsius)', fontsize=15)

plt.show()
