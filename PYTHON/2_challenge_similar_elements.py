# Status: [
#		incomplete as of [1/4/2020]
#		1 forseeable issue
# Purpose: 
#		Complete a challenge from "hackerearth.com" relating to arrays and finding similar
#		characteristics.
# Problem Source: 
# 		-> https://www.hackerearth.com/practice/data-structures/arrays
#		   /1-d/practice-problems/algorithm/pairs-having-similar-element-eed098aa/description/


# Log
#--------------------------------------------------------------------------------------
# [12/31/2019]
#     - Most of the code is completed with ease. Ran into a transitivity matching issue. I can't 
#		seem to complete this without a massive chunk of code.
# [1/1/2020] 
#     - still having issues with the transitivity portion. I forsee an issue where the number of 
#		of matches will out number what I have alloted for the array
# [1/4/2020]
#     - Found another way to add dynamically add to matches list AND nest lists, helping with keep
#		track of pairs. Transitiviy checking doesn't account for the first element of the 
#			first element in pairs() i.e. pairs[0][0] 
#--------------------------------------------------------------------------------------



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
