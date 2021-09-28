/*
    Date:           8-2-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn about sets in C++ and complete the Hacker Rank 
                    problem statement:  https://www.hackerrank.com/challenges/cpp-sets/problem

    sample input:
                    "sampleInput.txt"

    Questions to think about:
        1. What is the difference between a vector and set?

    Additional Resources:
        1. https://www.cplusplus.com/reference/set/set/
        2. PRINT OUT SET: https://www.geeksforgeeks.org/setbegin-setend-c-stl/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
  int Q, y, x;
  set<int>s;
  int length=s.size();
  int test;
  set<int>::iterator itr;

  cin >> Q;
  for(int i = 0; i < Q; i++){
    cin >> y >> x;

    if(y == 1){
      // add an element
      s.insert(x);

    } else if(y == 2){
      // delete an element
      s.erase(x);

    } else if(y == 3){
      // print "yes" if x is present else "no"
      itr = s.find(x);
      if(itr == s.end()){
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  }

  return 0;
}
