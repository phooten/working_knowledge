#************************************************************************
# this code was take from geeksforgeeks.org/how-to-begin-with-competative-programming/
#
# THIS IS NOT MY CODE!! it is only being used to better understand
# python and competative programming. 
#************************************************************************

# Date:         12-29-2019
# File:         challengeWarmup.py
# Purpose:      to complete a problem statement from geeksforgeeks and 
#               practice writing code in python


# Function declartions
def search (arr, x):
	# searches through the user input array for a certain number
    n = len(arr)
    for j in range(0, n):
        if(x == arr[j]):
            return j
    return -1

# Input number of test cases
print("Number of test cases: ")
t = int(input())
print("\n")

# One by One run for all input test cases
for i in range(0, t):
    
	# Input size of array
    print("Size of the array: ")
    n = int(input())
    print("\n")
    
	# Input the array
    print("Array of numbers: ")
    arr = map(int, input().split())  
    print("\n")
    
	# Input the element to be searched
    print("Number to be looked for: ")
    x = int(input())
    print("\n")

	# in python3, map returns an object. to counter this, it was cast into a "list()"
    print(search(list(arr), x))

#End
