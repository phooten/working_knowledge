/*
    Date:           2-19-2021
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten
					HackerRank (see Credits)

    Purpose:        To familiarize myself with pointers while completing a 
					Hackerrank problem.

    sample input:
                    1 4 

	Credits:
		1. Hackerrank
				built off of code from -> https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
		
*/

#include <math.h>
#include <stdio.h>

void update(int* a, int* b);

int main(){
	// Variables
	int a, b;
	int* pa = &a;
	int* pb = &b;
	
	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d %d\n",a, b);
	
	return 0;
}

/*
	Purpose:	To change value of variables through pointers.
*/
void update(int* a, int* b){
	// variables
	int aa, bb;

	aa = *a + *b;
	bb = abs(*a - *b);

	*a = aa;	
	*b = bb;

	return; 
}

