/*
    Date:           8-1-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn about vectors in C++ and complete the Hacker Rank 
                    problem statement:  https://www.hackerrank.com/challenges/vector-sort/problem

    sample input:
                    "sampleInput.txt"

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Function declartions
void printV(vector<int>_v, int _n);

int main() {
    // Variables
    int n;        // number of numbers
    int number;
    vector<int>v;

    // User input
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> number;
      v.push_back(number);
    }

    sort(v.begin(), v.end());
    printV(v, n);

    return 0;
}


/*
  Purpose:
    to print out contents of a vector
*/
void printV(vector<int>_v, int _n){

  for(int j = 0; j < _n; j++){
    cout << _v.at(j) << " ";
  }
  cout << endl << endl;

  return;
}