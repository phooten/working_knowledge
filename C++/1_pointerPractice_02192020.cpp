// started 2/19/2020

// built off of code from -> https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

#include <stdio.h>

void update(int* a, int* b){
	// a' = 4 + 5 = 9
	printf("%p %d end 1\n", a, *a);	
	*a = 4 + 5;	
	printf("%p %d end 2\n", a, *a);
	
	printf("%p %d end 3\n", b, *b);
	*b = 4 - 5;
	if(*b < 0){
		*b *= -1;
	}
	printf("%p %d end 4\n", b, *b);
	// b' = |4 - 5| = 1
}

int main(){
	int a, b;
	int* pa = &a;
	int* pb = &b;

	scanf("%d %d", &a, &b);
	update(pa, pb);
	//printf("%d %d\n",a, b);
	return 0;
}
