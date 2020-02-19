// started 2/19/2020

// built off of code from -> https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

#include <stdio.h>

void increment(int *v){
	(*v)++;
}

int main(){
	int a;
	scanf("%d",&a);
	increment(&a);
	printf("%d\n",a);
	return 0;
}
