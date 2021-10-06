/*
    Date:           9-28-2021
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten
                    CodingBlocks (see Credits)

    Purpose:        To learn and understand the data structure of Graphs. This 
                    Code will be heavily referenced from other for the purpose
                    of learning.  

    sample input:
                    ?? 

    Questions to think about:
        1. ??
    
    Credits:
        1. CodingBlocks:
            https://www.youtube.com/watch?v=dhgKr8942rs
            This tutorial was watched and referenced so there will be alot of 
            similarities. 
*/


#include "GraphClass.h"
#include <iostream>
using namespace std;

int main(){

    Graph graph(4);

    // sample.addEdge(0, 1);
    // sample.addEdge(0, 2);
    // sample.addEdge(1, 2);
    // sample.addEdge(2, 3);
    
    cout << graph.totalVertices << endl;
    for(int i = 0; i < graph.totalVertices; i++ ){
        cout << "testing" << endl;
        //cout << graph.verticesPtr[i] << ", ";
    }    
    cout << endl;

    return 0;
}