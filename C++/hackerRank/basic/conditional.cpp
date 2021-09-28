
/*
    Date:           8-11-2021
    File:           class.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To complete hackerrank challenge surrounding condition 
                    statements. The problem statement can be found here: 
                    https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem

*/

#include <bits/stdc++.h>
using namespace std;

// Function declarations (provided by hackerrank)
string ltrim(const string &);
string rtrim(const string &);


int main() {
    // converts user input into an int
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));
    string results = "";

    // converts integer into the number written with lettewrs
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

/*
  Purpose:
    Removes any space to the left of the string. The string should be in the 
    form of a user input number that has been taken in as a string
*/
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

/*
  Purpose:
    Removes any space to the right of the string. The string should be in the 
    form of a user input number that has been taken in as a string
*/
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
