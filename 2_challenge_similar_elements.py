# Code by Parker Hooten
# Purpose: 
#	Complete a challenge from "hackerearth.com" relating to arrays and finding similar
#	characteristics.
# Problem Source: 
# 	-> https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/pairs-having-similar-element-eed098aa/description/


# Log
#--------------------------------------------------------------------------------------
# [12/31/2019]
# - Most of the code is completed with ease. Ran into a transitivity matching issue. I can't 
#	seem to complete this without a massive chunk of code.
# [1/1/2020] 
# - still having issues with the transitivity portion. I forsee an issue where the number of 
#	of matches will out number what I have alloted for the array
#--------------------------------------------------------------------------------------



# so far this just solves similar pairs WITHOUT transitivity property
def calc(arr, n):
	# Varriables
	matches = 0							# total similarity matches
	difference = 0						# used to determine if similar
	track = 0							# tracks element position in "trans[]"
	trans = [0 for h in range(0, n)]	# holds match pairs

	# compares every number in the array using "Selective sort"
	for i in range(0, n):
		for j in range(i+1, n):	

			# determines if numbers are similar
			difference = arr[i] - arr[j]
			if difference == 1 or difference == -1:
				matches = matches + 1

				# adds the matched pair to an array
				trans[track] = i
				track += 1
				trans[track] = j
				track += 1
				print("trans = ", trans)
				print("Match with ", arr[i], " and ", arr[j], " total: ", matches, "\n")  
	
	"""	
	# attempt at finding duplicates to find transitivity
	for j in range(0, len(trans), 2):
		for k in range(j, len(trans), 2):
			if trans[j] == trans [k]:
				matches += 1
	"""
	return matches


# main code
print("Number of elements in the array: ")
n = int(input())

print("location of \"i\" element: ")
arrayInput = list(map(int, input().split()))

pairs = calc(arrayInput, n)
print("done: ", pairs)


