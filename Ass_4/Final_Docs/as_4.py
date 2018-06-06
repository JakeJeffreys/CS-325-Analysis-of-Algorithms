import csv
import sys
import math

from pulp import *


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


# defines the problem
prob = LpProblem("problem", LpMinimize)


# declare your variables
x0 = LpVariable("x0")
x1 = LpVariable("x1")
x2 = LpVariable("x2")
x3 = LpVariable("x3")
x4 = LpVariable("x4")
x5 = LpVariable("x5")

z = LpVariable("z")

points = [[day[i], temp[i]] for i in range(len(day))]


# defines the objective function to minimize
prob += z


# defines the constraints
for P in points:
    prob += P[1] - (x0 + (x1*P[0]) + (x2*math.cos((2*math.pi*P[0])/365.25)) + (x3*math.sin((2*math.pi*P[0])/365.25)) + (x4*math.cos((2*math.pi*P[0])/3908.175)) + (x5*math.sin((2*math.pi*P[0])/3908.175))) <= z
    prob += P[1] - (x0 + (x1*P[0]) + (x2*math.cos((2*math.pi*P[0])/365.25)) + (x3*math.sin((2*math.pi*P[0])/365.25)) + (x4*math.cos((2*math.pi*P[0])/3908.175)) + (x5*math.sin((2*math.pi*P[0])/3908.175))) >= -z


# solve the problem
status = prob.solve(GLPK(msg=0))
LpStatus[status]


# print the results
print '----- RESULTS -----'
print 'x0 =', value(x0)
print 'x1 =', value(x1)
print 'x2 =', value(x2)
print 'x3 =', value(x3)
print 'x4 =', value(x4)
print 'x5 =', value(x5)



# RESULTS ---------------

# x0 =  8.02142
# x1 =  0.000106948
# x2 =  4.28089
# x3 =  8.18686
# x4 =  -0.790631
# x5 =  -0.29536

# y = 8.02142 + (0.000106948*x) + (4.28089*cos((2*pi)/365.25)) + (8.18686*sin((2*pi*x)/365.25)) + (-0.790631*cos((2*pi*x)/3908.175)) + (-0.29536*sin((2*pi*x)/3908.175))







