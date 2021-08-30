/*
	Author:		Parker Hooten
	Date: 		August 30, 2021
	Purpose:
		Create a program that sorts an array using merge sort in order to 
		learn about and study this algorithm. 
	Credit:
		1. 
        2. Coppied format code and functions from my previous program: 0_quicksort_08292021.cpp

*/

// Status: INCOMPLETE - [8/30/2021]

// Personal Log:
//-----------------------------------------------------------------------------
// [8/30/2021]
//		- created skeleton code 
// [//2021]
//		- 
//-----------------------------------------------------------------------------

/*
	Notes:
		- Averages: O(n + k) 
		- Worst Case: O(n + k)
        - Space Complexity: O(k)
        - 
		- 
*/

#include <iostream>
#include <memory>
using namespace std;


// Initializers
void mergeSort(int *arr, int end);
void printArr(int *arr, int end);

/*
	main:
		initalizes the array of numbers and randomly generates the contents. It
		calls the functions to sort and print out the values.  
*/
int main(){
	// variables
	int length = 10;
	int *array = new int[length];
	int start = 0;
	int end = length - 1;

	// Generate random array values	
	for(int i = 0; i < length; i++){
		array[i] = rand() % 10000;
	}


	printArr(array, end);
	mergeSort(array, end);
	printArr(array, end);
	
	// clean up memory
	delete[] array;

	return 0;
}

/*
	check:
		Purpose/Functionality:
			
		Arguments:
			int *arr - 	pointer to an array of x values initialized to unsorted values
			int end - 	the position of the last value in the array ( end in arr[end] ) 
*/
void mergeSort(int *arr, int end){
    int *tmpArr = new int[end + 1];

    delete[] tmpArr;
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