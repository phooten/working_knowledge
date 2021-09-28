# Date:         1-4-2019
# File:         similarElements.py
# Version:      1.0
# Status        INCOMPLETE
# Contributers	Parker Hooten
#
# Purpose:      to complete a problem statement from hackerrank relating to
# 				arrays and finding similar characteristics:
# 				https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/pairs-having-similar-element-eed098aa/description/






# so far this just solves similar pairs WITHOUT transitivity property
def calc(arr, n):
	# Varriables
	matches = 0							# total similarity matches
	difference = 0						# used to determine if similar
	track = 0							# tracks element position in "trans[]"
	pairs = []
	trans = []
	
	# compares every number in the array using "Selective sort"
	for i in range(0, n):
		for j in range(i+1, n):	

			# checks if numbers are similar
			difference = arr[i] - arr[j]
			if difference == 1 or difference == -1:
				matches = matches + 1
				pairs.append((i, j))
				# print("length: ", len(pairs), " ", pairs)
				
	# print("unsorted: ", pairs)
	pairs.sort()
	# print("sorted: ", pairs)
	
	# tracks matched pairs, checks for transitivity
	for k in range(0, len(pairs)-1):	
		if pairs[k][1] == pairs[k+1][1]:			# Possibly skips checking "pairs[0][0]", see log
			matches += 1
			trans.append(pairs[k][1])
			trans.append(pairs[k+1][1])
		
		if pairs[k][1] == pairs[k+1][0]:
			matches += 1
			trans.append(pairs[k][1])
			trans.append(pairs[k+1][0])
		# print(trans)
	return matches


# MAIN
#----------------------------------------------------

# print("Number of elements in the array: ")
n = int(input())

# print("location of \"i\" element: ")
arrayInput = list(map(int, input().split()))

pairs = calc(arrayInput, n)
print(pairs)

#----------------------------------------------------
