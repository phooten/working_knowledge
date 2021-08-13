/*
  FINISHED
  8-11-2021

  Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
  sample input:

  8
  11

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    int upper, lower;
    int n, m;
    string results;

    cin >> a >> b;
    if(a > b){
      upper = a;
      lower = b;
    } else {
      upper = b;
      lower = a;
    }

    for(n = lower; n <= upper; n++){
      if(n > 9){
        m = n % 2;
        if(m == 0){
          results = "even";
        } else {
          results = "odd";
        }
      } else if(n == 0){
        results = "zero";
      } else if(n == 1){
        results = "one";
      } else if(n == 2){
        results = "two";
      } else if(n == 3){
        results = "three";
      } else if(n == 4){
        results = "four";
      } else if(n == 5){
        results = "five";
      } else if(n == 6){
        results = "six";
      } else if(n == 7){
        results = "seven";
      } else if(n == 8){
        results = "eight";
      } else if(n == 9){
        results = "nine";
      }

      printf("%s\n", results.c_str());
    }

    return 0;
}
