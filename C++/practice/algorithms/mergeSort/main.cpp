/*
    Date:           8-20-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten
					Interviewbit.com (see credit)


    Purpose:        To sort a given set of numbers using the bubble sort method. 
                    In doing so, I will learn about how this algorithm works and
                    will be able to compare it's efficiency to other algorithms
                    when I come in contact with them. 

    sample input:
                    Random generator written in main(). 

    Questions to think about:
        1. What is bubble sortings's time/space complexity?

	Credit:
		1. Interviewbit.com: "https://www.interviewbit.com/tutorial/merge-sort-algorithm/"
			Relied on this website to learn about the algorithm. After attempting it myself, I 
			came back to their code to fill in gaps in my understanding. It looks very similar.
*/

#include <iostream>
#include <memory>
using namespace std;


// Function declarations
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void printArr(int *arr, int end);

/*
	Purpose: 	initalizes the array of numbers and randomly generates the 
				contents. It calls the functions to sort and print out the 
				values.  
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
	Purpose:	Recursivley call itself to split an array into individual
				cells that amount to the length of the array
			
	Arguments:	int *arr: 	pointer to an array of x values initialized to 
							unsorted values
				int start:  the position of the first value in the array
				int end:	the position of the last value in the array 
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

/*
	Purpose:	To put the cells that were created from "mergeSort()" back into
				the array but in a sorted ascending order. 
			
	Arguments:	int *arr: 	pointer to an array of x values initialized to 
							unsorted values
				int start:	the position of the first value in the array  
				int mid:	the middle position in the array 
				int end:	the position of the last value in the array
*/
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

	while(i <= mid){		// if j finishes first, and there are left over i's
		tmp[k] = arr[i];
		i++;
		k++;
	}

	while(j <= end){		// if i finishes first, and there are left over j's
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
	Purpose:	Give the user a visualization of the array by printing it out
			
	Arguments:	int *arr: 	pointer to an array of x values initialized to 
							unsorted values
				int end:	the position of the last value in the array 
							( end in arr[end] ) 
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