/*
    Date:           9-23-2021
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To sort a given set of numbers using Dijakstra's method. 
                    In doing so, I will learn about how this algorithm works and
                    will be able to compare it's efficiency to other algorithms
                    when I come in contact with them. 


    Current Status [ 9-28-2021 ]:
                    I am currently learning how to make a Graph data structure.
                    Once this is complete, i will move back to this algorithm 
                    to finish.  

    Questions to think about:
        1. What is Dijakstra's time/space complexity?
        2. What are some different variations of this algorithm?


*/


//#include<stdio.h>
#include<iostream>

unsigned int dijkstra(unsigned int nodeStart, unsigned int nodeTotal, unsigned int nodeList);
void getGraph();

// Controls operation of the program.
int main() {


    return 0;
}

unsigned int dijkstra(unsigned int nodeStart, unsigned int nodeTotal, unsigned int nodeList) {
    unsigned int dist[nodeTotal] = {0 - 1};       // initialize everything to infinity
    dist[nodeStart] = 0;

    return dist[0];
}

void getGraph() {
    unsigned short length;  // 2^16 = 65,536
    
    std::cin >> length;
    
    unsigned int graph[length][length];
    
    return;
}
