import csv
import sys

temp = []
date = []

csv.register_dialect('semi', delimiter = ';')



with open(sys.argv[1], 'r') as f:
	reader = csv.reader(f, dialect = 'semi')
	header = next(reader)
	for row in reader:
		temp.append(row[7])
		date.append(row[8])

print temp

print date
