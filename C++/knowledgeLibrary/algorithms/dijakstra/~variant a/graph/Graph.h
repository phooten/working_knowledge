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
    

    // 
    bool addVertex(Vertex&& otherVertex);
    bool addAdjacent(int position, std::pair<int, int> otherPair);
    int isAdjacent(int name, int adjacentName);

    // Debugging member functions
    void printContents();

private:
    // Variables
    std::vector<Vertex> m_vertices;
    int m_size;

};


#endif // GRAPH_H