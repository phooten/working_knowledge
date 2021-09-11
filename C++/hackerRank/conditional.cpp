/*
  FINISHED
  8-11-2021

  Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem
  sample input:

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    string results = " ";

    if(n > 9){
      results = "Greater than 9";
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

    printf("%s", results.c_str());
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
