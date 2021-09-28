/*
    Date:           9-23-2021
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn and understand binary search trees and to practice
                    implementing classes into code 

    sample input:
                    Random generator written in main(). 

    Questions to think about:
        1. What is binary trees's time/space complexity?

		
*/

//#include<stdio.h>
#include "GeneralHeaders.h"
#include "GraphClass.h"


int main() {

    int count = 5;
    std::string nameList[] = {"A", "B", "C", "D", "E"};
    int nameListLen = sizeof(nameList)/sizeof(nameList[0]);



    // Graph Sample;
    // Sample.print();
    // Sample.fill();
    // Sample.print();

    Graph Sample(0);
    Sample.print();

    // Sample.fill();
    // Sample.addVertex("Marseille");
    // Sample.print();
    

    for(int i = 0; i < nameListLen; i++){
        Sample.addVertex(nameList[i]);
        // std::cout << nameList[i] << std::endl;
    }
    Sample.print();

    Sample.removeVertex("A");
    Sample.print();
    return 0;
}
