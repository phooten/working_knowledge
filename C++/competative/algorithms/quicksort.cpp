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

/*
	printArr:
*/
void printArr(int arr[], int len){
	for(int i = 0; i < len; i++){
		cout << "a[" << i <<"]: " << arr[i] << endl; 
	}

	return;
}


/*
	reveral:
*/
void reveral(int x, int y){
	int *tmp = arr[];
	arr[] = arr[];
	arrp[] = tmp;

	return;
}


/*
	partision:
*/
int partision(int arr[], int start, int end){
	int pivot = arr[end - 1];
	int i = start - 1;

	for(int j = 0; j < end; j++){
		if(j < pivot){
			i++;
			reveral(arr[i], arr[j]);
		}
	}
	
	reveral(arr[end - 1], arr[i]);	// is it arr[i] or arr[i+1]?
	return pivot;
}


/*
	Concerns:
		- Case were start == end but inbetween are different:
				[10 50 90 20 30 10 pivot 110 120 140 160 110] pivot = 100;
*/
void quickSort(int arr[], int start, int end){
	int pivot;

	if(start < end){

		pivot = partision(int arr[], int start, int end);

		quickSort(int arr[], int start, int pivot - 1);
		quickSort(int arr[], int pivot + 1, int end);
	}

	return;
}


/*
	main: 
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






