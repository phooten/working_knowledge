/*
	Author:
	Purpose:
	Language:
*/

// log
//---------------------------------
// [1/8/2020]
//		- 
//---------------------------------


// Challenge:
//		1. select subparts containing even numbers
//		2. reverse the selected subpart

#include <iostream>
#include <stdlib.h>
using namespace std;

#define	arrSize 2001

int main(){
/*
	int num;
	scanf("%d", &num);
	printf("Input number is %d.\n", num);
*/
	// Variables
	int arr[arrSize];
	int n;
	int temp;

	// Gets input
	scanf("%i", &n);
	for(long int i = 0; i < n; ++i){
		scanf("%i", &temp);
		arr[i] = temp;
	}

	// Prints out results
	printf("\n\n");
	for(int j = 0; j < 10; j++){
		printf(" %i ", arr[j]);
	}
	printf("\n\n");

	return 0;
}
