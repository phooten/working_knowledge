#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isPalindrome(string &input);
void printString(string &input, int section);

int main(){
    string s = "A man, a plan, a canal: Panama";    // true
    // string s = " ";                                 // true
    // string s = "race a car";                        // false

    isPalindrome(s);


    return 0;
}


bool isPalindrome(string &input){
    string tmp = input;
    bool ans = false;
    bool odd = false;
    int a = 0;
    
    int len = input.length();
    // Remove capitalization, puntuation, and spaces
    cout << "len: " << len << endl;
    if(len == 0){
        printString(input, 0);
        return false;
    }
    
    int count = 0;
    while(input[count] != '\0'){
        // cout << "count: " << count << " input[count]: " << input[count] <<  endl;
        if(isalpha(input[count])){
            // input[count] = tolower(input[count]);
        } else {
            input.erase(input.begin() + count);
        }
        count++;
    }

    cout << "here" << endl;
    len = input.length();

    if(len == 1){
        printString(input, 1);
        return true;
    } else if(len % 2 == 1) {
        odd = true;
    }

    // 9 -> 4 1 4
    // 9 / 2   4
    for(int i = 0; i < (len / 2); i++ ){
        if(input[i] != input[len - 1])
            printString(input, 2);
            return false;
    }

    printString(input, 3);
    return true;
}


void printString(string &input, int section){
    cout << input << " " << section << endl;
}