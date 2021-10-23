/*
    Date:           8-29-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Koffee-byte
					GeeksForGeeks (see credit)


    Purpose:        To sort a given set of numbers using the quick sort method. 
                    In doing so, I will learn about how this algorithm works and
                    will be able to compare it's efficiency to other algorithms
                    when I come in contact with them. 

    sample input:
                    Random generator written in main(). 

    Questions to think about:
        1. What is quick sort's time/space complexity?

	Credit:
		1. GeeksForGeeks: https://www.geeksforgeeks.org/quick-sort/
			Relied on this website to learn about the algorithm. I studied it, 
            then came back and tried to re-write the code based on what I learned. It probably looks very similar. 
*/

#include <iostream>
#include <memory>
using namespace std;

// Function declarations
void quickSort(int *arr, int start, int end);
int partision(int *arr, int start, int end);
void swap(int *arr, int x, int y);
void printArr(int *arr, int end);


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
	Purpose:	Controll er function to sort an array through recursion and 
				partitioning. The sorted array will be in ascending order. It 
				relies upon "int partition()", and "void swap()" to handle the 
				back end and calculations.  

	Arguments:	int *arr: 	Pointer to an array of x values initialized to 
							unsorted values
				int start:	the position of the first value in the array
				int end:	the position of the last value in the array 
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
	Purpose:	Sorts an array of int values in ascending order.

	Arguments:	int *arr: 	Pointer to an array of x values initialized to 
							unsorted values
				int start:	the position of the first value in the array
				int end:	the position of the last value in the array 
	
	Return:		will return the position of the pivot so the
				right and left of this point can be properly sorted as well
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
	Purpose:	Switches two positions in the array

	Arguments:	int *arr: 	pointer to an array of x values initialized to unsorted values
				int x:		1st position to be switched with 2nd position  
				int y: 		2nd position to be switched with 1st position
*/
void swap(int *arr, int x, int y){
	int tmp;

	tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;

	return;
}



/*
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
