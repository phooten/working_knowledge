/*
  FINISHED
  8-1-2021

  Problem Statement: https://www.hackerrank.com/challenges/vector-sort/problem
  sample input:
  5
  1 6 10 8 4

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printV(vector<int>_v, int _n){
  for(int j = 0; j < _n; j++){
    cout << _v.at(j) << " ";
  }
  cout << endl << endl;
}

int main() {
    int n;  // number of numbers
    int number;

    cin >> n;

    vector<int>v;
    int size = v.size();
    // cout << "size: "<< size << endl;

    for(int i = 0; i < n; i++){
      cin >> number;
      v.push_back(number);
    }
    // printV(v, n);
    sort(v.begin(), v.end());
    printV(v, n);
    return 0;
}
