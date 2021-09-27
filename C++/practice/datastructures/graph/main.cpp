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
#include <iostream>
#include <string>

const unsigned short tmp = 10;

class Vertex
{
public:
    std::string name;
    bool visited;

    Vertex(std::string name)
    {
        name = "";
        visited = false;
    }

private:
};

class Graph
{
public:
    Graph()
    {
        const unsigned int totalVertices;
        Vertex vertices[totalVertices];
        double adjacentcyMatrix[tmp][tmp];
    }

private:
    const unsigned int totalVertices;
    Vertex vertices[tmp];
    double adjacentcyMatrix[tmp][tmp];
};

// Controls operation of the program.
int main()
{

    return 0;
}
