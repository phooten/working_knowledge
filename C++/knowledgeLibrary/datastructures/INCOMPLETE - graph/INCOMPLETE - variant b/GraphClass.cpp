#include "GraphClass.h"

Graph::Graph(int totalVertices){

    this->totalVertices = totalVertices;
    verticesPtr = new std::list<int>[totalVertices];

}

/*
    Purpose:    Add a connection between two vertices

    Arguments:  base:   the first vertex
                target: the vertex to connect to

*/
void Graph::addEdge(int base, int target){
    verticesPtr[base].push_back(target);
    verticesPtr[target].push_back(base);

    return;
}