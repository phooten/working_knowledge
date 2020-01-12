
# number array A of length N
# find the amount of perfect pairs in the array
# perfect pair is (Ai, Aj) where (Ai + Aj) is a perfect square and i != j
# Note (Ai, Aj) = (Aj, Ai) and not unique

# Log
#--------------------------------------------------------------------------------------
# [1/2/2019]
# 		- Most of the code is done. I have not incorporated code to check if (Ai, Aj) and (Aj, Ai)
#   	  are both included or not. 
# [1/5/2019]
# 		- I think I need to learn more about hashing then come back to this.   
#--------------------------------------------------------------------------------------

 
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
	

	total = hash(N, AN)
	print(total)
	



