/*
	Author:		Parker Hooten
	Date: 		August 28, 2021
	Purpose:
		Create a program that sorts an array using quick sort in order to 
		learn about and study this algorithm. 
	Credit:
		1. GeeksForGeeks: https://www.geeksforgeeks.org/quick-sort/
			Relied on this website to learn about the algorithm. I studied it, then came back and tried to
			re-write the code based on what I learned. It probably looks very similar. 

*/

// Status: COMPLETE - [8/29/2021]

// Personal Log:
//-----------------------------------------------------------------------------
// [8/26/2021]
//		- Wrote the skeleton of the program which relied on GeeksForGeeks. Random
//			generator is functioning.
// [8/29/2021]
//		- Finished the program. The random generated numbers can still be 
// 			adjusted to function more randomly, but everything else appears to 
//			be working. I was thinking the next branch of this code I'll try to 
//			use a doubly linked list rather than an array. 
//-----------------------------------------------------------------------------

/*
	Notes:
		- Averages: O(n logn) 
		- Worst Case: O(n^2)
		- "divide and conquer algorithm"
		- Recursivley perform: Bring PIVOT to where left of the pivot is smaller than the right
*/

#include <iostream>
#include <memory>
using namespace std;


// Initializers
void quickSort(int *arr, int start, int end);
int partision(int *arr, int start, int end);
void swap(int *arr, int x, int y);
void printArr(int *arr, int end);

/*
	main:
		initalizes the array of numbers and randomly generates the contents. It
		calls the functions to sort and print out the values.  
*/
int main(){
	// variables
	int length = 1000;
	int *array = new int[length];
	int start = 0;
	int end = length - 1;

	// Generate random array values	
	for(int i = 0; i < length; i++){
		array[i] = rand() % 10000;
	}


	printArr(array, end);
	quickSort(array, start, end);
	printArr(array, end);
	check(array, end);

	// clean up memory
	delete[] array;

	return 0;
}


/*
	quickSort:
		Purpose/Functionality:
			This is the controler function to sort an array through recursion and partitioning. 
			The sorted array will have the smallest numbers in the beginning and largest at the end. 
			It relies upon "int partition()", and "void swap()" to handle the back end and calculations.  

		Arguments:
			int *arr - 	pointer to an array of x values initialized to unsorted values
			int start - the position of the first value in the array ( 0 in arr[0] )
			int end - 	the position of the last value in the array ( end in arr[end] )
*/
void quickSort(int *arr, int start, int end){
	int pivotPos;			// Pivot Position, will always be the last value in the partition

	if(start < end){
		pivotPos = partition(arr, start, end);

		quickSort(arr, start, pivotPos - 1);
		quickSort(arr, pivotPos + 1, end);
	}

	return;
}


/*
	partition:
		Purpose/Functionality:
			Sorts an array of number values where the lowest value will be at the begining of the array
			and the highest value will be at the end. This will return the position of the pivot so the
			right and left of this point can be properly sorted as well. 

		Arguments:
			int *arr - 	pointer to an array of x values initialized to unsorted values
			int start - the position of the first value in the array ( 0 in arr[0] )
			int end - 	the position of the last value in the array ( end in arr[end] )
*/

int partition(int *arr, int start, int end){
	// Variables
	int pivot = arr[end];					// pivot is the end of the array
	int i = start - 1;						// keeps track of left side of partition
	
	for(int j = start; j < end; j++){		// pivot is the end, so end - 1 should be the max of the loop
		if(arr[j] < pivot){					// left side of partition is < pivot, right side is > pivot 
			i++;
			swap(arr, i, j);
		}
	}
	
	swap(arr, end, i + 1);
	return i + 1;
}



/*
	swap:
		Purpose/Functionality:
			Switches two positions in the array and cleans up code

		Arguments:
			int *arr - 	pointer to an array of x values initialized to unsorted values
			int x - 	1st position to be switched with 2nd position  
			int y - 	2nd position to be switched with 1st position
*/
void swap(int *arr, int x, int y){
	int tmp;

	tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;

	return;
}



/*
	printArr:
		Purpose/Functionality:
			give the user a visualization of the array 

		Arguments:
			int *arr - 	pointer to an array of x values initialized to unsorted values
			int end - 	the position of the last value in the array ( end in arr[end] ) 
*/
void printArr(int *arr, int end){
	int i = 0;	

	cout << "arr[]: ";
	for(i = 0; i < end; i++){
		cout << arr[i] << ", ";
	}
	cout << arr[end] << endl << endl;

	return;
}


/*
	check:
		Purpose/Functionality:
			To go through the array and ensure there are no out of order values.  

		Arguments:
			int *arr - 	pointer to an array of x values initialized to unsorted values
			int end - 	the position of the last value in the array ( end in arr[end] ) 
*/
void check(int *arr, int end){
	for(int i = 1; i <= end; i++){
		if(arr[i - 1] > arr[i]){
			cout << "ERROR:" << endl;
			cout << endl << "arr[" << i - 1 << "] = " << arr[i-1] << " arr[" << i << "] = " << arr[i] << endl;
			return;
		}
	} 

	return;
}
