/*
  FINISHED
  8-11-2021

  Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-functions/problem

*/

#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
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
      // // print array
      // cout << "list: ";
      // for(int j = 0; j < length; j++)
      // cout << lst[j] << " ";
      // cout << "\n\n";

      // sort
      for(int i = 0; i < length - 1; i++){
        if(lst[i] < lst[i + 1]){
          tmp = lst[i];
          // cout << "tmp: " << tmp << " lst[i]: " << lst[i] << " lst[i+1]: " << lst[i+1] << " i: " << i << "\n";
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
    printf("%d", ans);

    return 0;
}
