#ifndef VERTEX_H
#define VERTEX_H

#include<iostream>
#include<vector>
#include"macros.h"

class Vertex {
public:
    
    // Constructors / Destructors
    Vertex(int otherName);
    ~Vertex();
    Vertex(const Vertex& other);
    Vertex(Vertex&& other);

    // Copy / Move
    Vertex& operator=(const Vertex& other);
    Vertex& operator=(Vertex&& other);

    // Vertex manipulation 
    void add_adjacentVertex(std::pair<int, int> otherPair);

    // Getters
    int get_vertexName() const;
    int get_adjacentVertex_weight(int name) const;
    int get_adjacentVertices_size() const;
    std::vector<std::pair<int, int>> get_adjacentVertices_vector() const;

    // Setters
    void set_vertexName(int otherName);

    // Printing functionality
    void printContents();
    
private:
    // Variables
    int m_name;
    std::vector<std::pair<int, int>> m_adjacentVector;

};

#endif // VERTEX_H