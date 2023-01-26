/*
    Date:           8-11-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Efficiency Comment [ 9-28-2021 ]:
                    I know this sorting is very in-efficient with run time and 
                    space. This will never take in more than 4 inputs or be used
                    in a serious program.

    Purpose:        To complete hackerrank challenge surrounding for functions.
                    The problem statement can be found here: 
                    https://www.hackerrank.com/challenges/c-tutorial-functions/problem

    sample input:
                    "sampleInput.txt"  
*/

#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
    // Variables
    int max;
    int length = 4;
    int lst[length];
    int tmp;
    bool sort = false;

    lst[0] = a;
    lst[1] = b;
    lst[2] = c;
    lst[3] = d;

    while(!sort){
      for(int i = 0; i < length - 1; i++){
        if(lst[i] < lst[i + 1]){
          tmp = lst[i];
          lst[i] = lst[i + 1];
          lst[i + 1] = tmp;
        }
      }

      // check if sorted
      sort = true;
      for(int i = 0; i < length - 1; i++){
        if(lst[i] < lst[i + 1]){
            sort = false;
        }
      }
  }
  max = lst[0];
  
  return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("\nMax Value: %d\n", ans);

    return 0;
}
