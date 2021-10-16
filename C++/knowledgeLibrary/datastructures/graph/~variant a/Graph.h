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
    

    // Main 
    bool addVertex(Vertex&& otherVertex);
    bool addAdjacentVertex(int position, std::pair<int, int> otherPair);
    int isAdjacent(int name, int adjacentName);

    // Getters
    int get_vertices_count() const;
    std::vector<Vertex> get_verticesVector() const;
    std::vector<std::pair<int, int>> get_adjacentVertices_vector(int name) const;
    
    // Debugging member functions
    void printContents();

private:
    // Variables
    int m_size;
    std::vector<Vertex> m_verticesVector;

};


#endif // GRAPH_H