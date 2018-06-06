import csv
import sys
import math

from pulp import *

temp = []
d = []

csv.register_dialect('semi', delimiter = ';')

with open(sys.argv[1], 'rU') as f:
	reader = csv.reader(f, dialect = 'semi')
	header = next(reader)
	for row in reader:
		temp.append(row[7])
		d.append(row[8])

# print temp

# print d


# declare your variables
x0 = LpVariable("x0")
x1 = LpVariable("x1")
x2 = LpVariable("x2")
x3 = LpVariable("x3")
x4 = LpVariable("x4")
x5 = LpVariable("x5")


# defines the problem
prob = LpProblem("problem", LpMaximize)

# defines the constraints
# prob += 2*x1+x2 <= 100


# defines the objective function to maximize
prob += x0 + (x1*d) + (x2*math.cos((2*math.pi)/365.25)) + (x3*math.sin((2*math.pi*d)/365.25)) + (x4*math.cos((2*math.pi*d)/3,908.175)) + (x5*math.sin((2*math.pi*d)/3,908.175))

# solve the problem
status = prob.solve(GLPK(msg=0))
LpStatus[status]

# print the results x1 = 20, x2 = 60
value(x0)
value(x1)
value(x2)
value(x3)
value(x4)
value(x5)
