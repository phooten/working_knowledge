/*
    Notes:
        - Cannot be used if edges have negative weight
        - Versions: 
            - "Lazy" Dijkstra's
            - 

    Algorithm:
        - Initialize all distances to get to each node from node A to infinity
        - Assign start node to be 0
        - Visit all nodes directly attached to node 0, and reassign shortest distances IF they are shorter
        - Visit the next most promising node in the priority queue

    References: 
        - Graph Data Structure 4. Dijkstra’s Shortest Path Algorithm: https://www.youtube.com/watch?v=pVfj6mxhdMw
        - 
*/

/**
    Overview: Description of the file
    @file       main.cpp
    @author     Parker Hooten
    @version    1.1 
    @date       9/23/2021 [ D/M/Y ]
*/

/**
    Description of the function
	@param input the input into the function.
    @return what is being returned.


*/

//#include<stdio.h>

#include "GeneralHeaders.h"
#include "GraphClass.h"



// Controls operation of the program.
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
