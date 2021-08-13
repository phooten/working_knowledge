/*
  FINISHED
  8-11-2021

  Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
  sample input:

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a;
    long int b;
    char c;
    float d;
    double e;

    scanf("%i %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%i \n%ld \n%c \n%f \n%lf", a, b, c, d, e);

    return 0;
}
