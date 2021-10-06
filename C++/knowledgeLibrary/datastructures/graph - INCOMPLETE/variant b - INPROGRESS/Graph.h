#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include "macros.h"
#include"Vertex.h"




class Graph{
public:
    std::vector<Vertex> m_vertices;

    // Constructor/Destructor
    Graph();
    ~Graph();

    // Util
    bool addVertex(std::string& name);
    
    // Getters
    unsigned int getVertexCount();


    // Debug
    void printContents();

private:
    unsigned int m_vertexCount;

};

#endif