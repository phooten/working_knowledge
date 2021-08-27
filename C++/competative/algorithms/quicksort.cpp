/*
	Author:		Parker Hooten
	Purpose:	Study of Quicksort
	Language:	C++
	Date: 		August 26, 2021
*/

// Status: INCOMPLETE - [x/x/xxxx]

// Log:
//-------------------------------------------------------
// [x/x/xxxx]
//		-
//-------------------------------------------------------

/*
	Notes:
		- Averages: O(n logn) 
		- Worst Case: O(n^2)
		- "divide and conquer algorithm"
		- Recursivley perform: Bring PIVOT to where left of the pivot is smaller than the right, 
			quick sort left, quick sort right
		- 
*/

#include <iostream>
using namespace std;

void printArr(int arr[], int len){
	for(int i = 0; i < len; i++){
		cout << "a[" << i <<"]: " << arr[i] << endl; 
	}

	return;
}


/*
int quickSort(int arr[], int start, int end){
	if(start < end){
		int pivot;
		// pivot = partition(arr, start, end);
		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}
}
*/
/*
int partition(int arr[], int start, int end){
	len = len(arr);
	int pivot = arr[end];
	int i = begin - 1;

	for(int j = begin; j <= end - 1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[end]);
		}
	}
	swap(&arr[i + 1], &arr[end]);

	return (i + 1);
}
*/
int main(){
	int length = 100;
	int data[length];

	// Generate random array values	
	for(int i = 0; i < length; i++){
		data[i] = rand() % 10000;
	}

	printArr(data, length);

	return 0;
}






