// NOTE: built off of code from -> https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

/*
	Author:		Parker Hooten (see note above, not all mine)
	Purpose:	to familiarize myself with the basic usage of pointers
	Language:	C++
*/


// Status: INCOMPLETE - [2/19/2020]


// Log:
//--------------------------------------------------------------------------
// [2/23/2020]
//		- Submitted the working code to the website. I'd rather add onto to this
// 		  rather than stopping here. 
//--------------------------------------------------------------------------


// Sample Input/Output:
/*
 	1:	4 5

	gives:

	1:	9 1
*/


#include <math.h>
#include <stdio.h>



void update(int* a, int* b){
	// variables
	int aa, bb;

	aa = *a + *b;
	bb = abs(*a - *b);

	*a = aa;	
	*b = bb;
}

int main(){
	int a, b;
	int* pa = &a;
	int* pb = &b;
	
	// user input
	scanf("%d %d", &a, &b);
	
	// calculation function
	update(pa, pb);
	
	// output
	printf("%d %d\n",a, b);
	
	return 0;
}



