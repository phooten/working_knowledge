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



    for(int i = 0; i < 23; i++){
        a.push_back(i);
    }
    testFunctionality(&a);

    a.erase(a.backPosition());
    a.erase(a.backPosition());
    a.erase(a.backPosition());
    a.erase(a.backPosition());
    a.erase(a.backPosition());
    a.insert(17, 55);
    
    testFunctionality(&a);
    
    a.erase(a.search(55));
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
    printer("front: ", vectorPtr->front());
    printer("frontPosition: ", *vectorPtr->frontPosition());
    printer("back: ", vectorPtr->back());
    printer("backPosition: ", vectorPtr->backPosition());
    printer("upSize: ", vectorPtr->upSize());
    printer("downSize: ", vectorPtr->downSize());
    std::cout << "------------------------------------" << std::endl << std::endl;
    

    return;
}