#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

#include<iostream>
#include<list>


class Graph{
public:
    int totalVertices;
    std::list<int> *verticesPtr;

    // Graph();
    Graph(int totalVertices);
    // ~Graph();

    void addEdge(int base, int target);

private:


};

#endif