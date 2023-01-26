#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
#include"Vertex.h"
#include"macros.h"

class Graph {
public:
    // Default constrcutor/destructor
    Graph();
    ~Graph();
    
    
    // Graph manipulation 
    void addVertex(Vertex&& otherVertex);
    void addAdjacentVertex(int position, std::pair<int, int> otherPair);
    

    // Getters
    int get_vertices_count() const;
    int get_adjacentWeight(int name, int adjacentName) const;
    std::vector<Vertex> get_verticesVector() const;
    std::vector<std::pair<int, int>> get_adjacentVertices_vector(int name) const;
    

    // Printing functionality
    void print_graphContents();
    void print_adjacentDetails(int name);

private:
    // Variables
    int m_size;                             
    std::vector<Vertex> m_verticesVector;   

};


#endif // GRAPH_H