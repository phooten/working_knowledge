/*
	Author:		Parker Hooten
	Date: 		August 30, 2021
	Purpose:
		Create a program that sorts an array using merge sort in order to 
		learn about and study this algorithm. 
	Credit:
		1. Interviewbit.com: "https://www.interviewbit.com/tutorial/merge-sort-algorithm/"
			Relied on this website to learn about the algorithm. After attempting it myself, I 
			came back to their code to fill in gaps in my understanding. It looks very similar.
		2. Coppied format code and functions from my previous program: 0_quicksort_08292021.cpp

*/

// Status: COMPLETE - [8/30/2021]

// Personal Log:
//-----------------------------------------------------------------------------
// [8/30/2021] : 12:30 PM
//		- created skeleton code: basic functions and structure 
// [//2021]	: 10:50 PM
//		- worked through my self to try and figure this out after reading a basic
// 			description and pseudo code. I got the partition easily, but I couldn't
//			conceptually understand how to go about sorting the array without altering the 
//			original array. I was close in my thought process but couldn't pull it 
//			together completeley. In the end I studied "interviewbit.com"'s code and 
//			got it to work. I feel I have a good understanding about this algorithm now. 
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
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void printArr(int *arr, int end);

/*
	main:
		initalizes the array of numbers and randomly generates the contents. It
		calls the functions to sort and print out the values.  
*/
int main(){
	// variables
	int length = 100;
	int *array = new int[length];
	int start = 0;
	int end = length - 1;

	// Generate random array values	
	for(int i = 0; i < length; i++){
		array[i] = rand() % 10000;
	}


	printArr(array, end);
	mergeSort(array, start, end);
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
void mergeSort(int *arr, int start, int end){
	int mid;
	
	if(start < end){	// indicates there are more than one element
		mid = (start + end) / 2;
		// cout << "MS -> start: " << start << " mid: " << mid << " end: " << end << endl; 
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);

		merge(arr, start, mid, end);
	}

    return;
}

void merge(int *arr, int start, int mid, int end){
	int *tmp = new int[end - start + 1];	// CHECK HERE IF SEG FAULT

	// cout << "start: " << start << " mid: " << mid << " end: " << end << endl; 
	// cout << "merge 1 -> ";
	// printArr(arr, end);

	int i = start;
	int j = mid + 1;
	int k = 0;
	while(i <= mid && j <= end){		// left side is smallest values
		if(arr[i] < arr[j]){
			tmp[k] = arr[i];
			i++;						// i is smaller, so i gets placed and increased 
		} else{
			tmp[k] = arr[j];
			j++;
		}
		k++;
	}

	while(i <= mid){		// in case j finishes first, and there are left over i's
		tmp[k] = arr[i];
		i++;
		k++;
	}

	while(j <= end){		// in case j finishes first, and there are left over j's
		tmp[k] = arr[j];
		j++;
		k++;
	}

	for(i = start; i <= end; i++){
		arr[i] = tmp[i - start];
	}



	// cout << "merge 2 -> ";
	// printArr(arr, end);

	delete[] tmp;

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

	cout << "arr: ";
	for(i = 0; i < end; i++){
		cout << arr[i] << ", ";
	}
	cout << arr[end] << endl << endl;

	return;
}