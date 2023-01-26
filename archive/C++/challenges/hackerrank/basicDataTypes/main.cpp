/*
    Date:           8-11-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn about printing basic data types in C++ and complete 
                    The Hacker Rank problem statement:  https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

    sample input:
                "sampleInput.txt"

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
