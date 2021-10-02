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



void testFunctionality(vector* vectorPtr);

void printer(string str, int var);

int main(){
    vector a;



    for(int i = 0; i < 20; i++){
        a.push_back(i);
    }

    testFunctionality(&a);

    return 0;
}

void printer(string str, int var){
    cout << str << ": "<< var << endl;
    
    return;
}

void testFunctionality(vector* vectorPtr){
    std::cout << std::endl << "--------------Testing--------------" << std::endl;
    vectorPtr->print();
    printer("capacity: ", vectorPtr->capacity());
    printer("size: ", vectorPtr->size());
    printer("size: ", vectorPtr->front());
    printer("front: ", *vectorPtr->frontPosition());
    printer("size: ", vectorPtr->back());
    printer("capacity: ", *vectorPtr->backPosition());
    printer("size: ", vectorPtr->upSize());
    printer("capacity: ", vectorPtr->downSize());
    std::cout << "------------------------------------" << std::endl << std::endl;
    

    return;
}