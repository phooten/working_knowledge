/*
    Date:           2-29-2021
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten
					
    Purpose:        
		
*/

#include"vector.h"
#include<iostream>
#include<string>
using namespace std;



void printer(string str, int var);

int main(){
    vector a;

    // a.print();
    // printer("capacity: ", a.capacity());
    // printer("size: ", a.size());
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.print();
    for(int i = 0; i < a.capacity(); i++){
        std::cout << i << ": " << *(a.frontPosition() + i) << std::endl;
    }
    // printer("capacity: ", a.capacity());
    // printer("size: ", a.size());

    return 0;
}

void printer(string str, int var){
    cout << str << ": "<< var << endl;
    
    return;
}
