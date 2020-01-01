# source:
#	->https://www.hackerearth.com/practive/data-structures/arrays/1-d/practice-problems/maximize-the-earning-137963bc-323025a6/





# INSERT PROBLEM STATEMENET HERE



# so far this just solves similar pairs WITHOUT transitivity property
def calc(arr, n):
	# Varriables
	matches = 0
	difference = 0
	count = 0

	# compares every number in the array"Selective sort"
	for i in range(0, n):
		for j in range(i+1, n):	
			# determines if numbers are similar
			difference = arr[i] - arr[j]
			if difference == 1 or difference == -1:
				
matches = matches + 1
				print("Match with ", arr[i], " and ", arr[j], " total: ", matches, "\n")  
		
	return matches


print("Number of elements in the array: ")
n = int(input())

print("location of \"i\" element: ")
arrayInput = list(map(int, input().split()))

pairs = calc(arrayInput, n)
print("done: ", pairs)


