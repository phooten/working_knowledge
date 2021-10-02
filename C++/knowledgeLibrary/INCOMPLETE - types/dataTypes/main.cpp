/*
    Date:           10-1-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE (but is in progress)
    
    Contributers:   Parker Hooten

    Purpose:        To test out unique characteristics of certain data types,
                    that I might not use on a regular basis, that I'm not 
                    familiar with, or that I'm curious about. There isn't
                    really a use case except as an organized scratch pad.  

*/

#include <iostream>
using namespace std;

int main(){
    // unsigned int ui_a = -1;
    // unsigned int ui_b = -2;

    // cout << "ui_a: " << ui_a << endl;
    // cout << "ui_b: " << ui_b << endl;

    for(int i = -5; i < 10; i++){
        cout << i << ": " << (unsigned int)i << endl;
    }

    return 0;
}