#ifndef GRAPH_H
#define GRAPH_H


#include<iostream>
#include<vector>
#include"Vertex.h"
#include"macros.h"

class Graph {
public:

    // Constrcutors
    Graph();
    ~Graph();
    // Graph(int size) : m_size(size) {}


    // Main Functionality
    bool addVertex(Vertex&& otherVertex);

    void printContents();

private:
    std::vector<Vertex> m_vertices;
    int m_size;

};


#endif // GRAPH_H