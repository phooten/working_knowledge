# Date:         1-5-2019
# File:         perfectPair.py
# Version:      1.0
# Status        INCOMPLETE
# Contributers	Parker Hooten
#
# Purpose:      to complete a problem statement from hackerrank relating to
# 				arrays and finding similar characteristics:
# 				https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/pairs-having-similar-element-eed098aa/description/


# Libraries
import math

# Functions
def hash(N, AN):
	total = 0
	sortAN = AN
	sortAN.sort()
	
	# Selection sort to check each number with every other number except when i = j
	for i in range (0, N):
		for j in range (i+1, N):
			# checks for perfect root or cube
			numbers = (AN[i], AN[j])
			if (sum(numbers) ** (1/2)).is_integer():
				total += 1
			elif (sum(numbers) ** (1/3)).is_integer():
				total += 1
			# print(AN[i], " and ", AN[j], " - ", result)
	return total

# MAIN
T = int(input())							# number of test cases

for x in range(0, T):
	"""
	# sets up the hash function
	N = int(input())						# number of elements in array
	AN = [0] * 1001
	for i in input().split():
		AN[int(i)] += 1  						# 1000 possible inputs 
		print(AN)

	B = [0] * 2001
	i = 0
	while(i * i < 2000):
		B[i * i] = 1
		if i * i * i < 2000:
			B[i * i * i] = 1
		i += 1
	"""

	AN = list(map(int, input().split()))	# A1, A2, ... An
	print(AN)
	

	total = hash(AN, AN)
	print(total)
	



