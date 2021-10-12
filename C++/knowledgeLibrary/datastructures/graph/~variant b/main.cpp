/*
    Date:           10-5-2021
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

#include <iostream>
#include "macros.h"
#include "Graph.h"


Graph buildGraph();

int main(){
    std::string a = "";
    std::string b = "";
    int c = 0;

    Graph MapPtr = buildGraph();
    a = "C";
    b = "A";
    c = 5;
    MapPtr.addAdjacent(a, b, c);
    a = "B";
    b = "A";
    c = 7;
    MapPtr.addAdjacent(a, b, c);
    a = "C";
    b = "B";
    c = 9;
    MapPtr.addAdjacent(a, b, c);

    MapPtr.printContents();
    MapPtr.m_vertices[2].printContent();    

    return 0;
}


/*
    Purpose:    Builds the contents of the Graph
*/
Graph buildGraph(){
    // Variables
    unsigned short vLen = 5;
    //std::string verticesList[vLen];
    std::string verticesList[vLen] = {"A", "B", "C", "D", "E"};


    // Declares node names
    // for(int i = 0; i < vLen; i++){
    //     verticesList[i] = 'A' + i;
    //     std::cout << verticesList[i] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl << "-------------------------------------" << std::endl;


    
    Graph Map;

    // Vertex Set up
    for(int i = 0; i < vLen; i++){
        Map.addVertex(verticesList[i]);
    }

    // Adjacent Setup

    return Map;
}

