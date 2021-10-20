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

    // Copy / Move
    Vertex(const Vertex& other);
    Vertex& operator=(const Vertex& other);

    Vertex(Vertex&& other);
    Vertex& operator=(Vertex&& other);


    bool add_adjacentVertex(std::pair<int, int> otherPair);
    int search_adjacentVertex(int name);

    // getters
    int get_name() const;
    int get_adjacentVertices_size() const;
    std::vector<std::pair<int, int>> get_adjacentVertices_vector() const;

    // setters
    void set_name(int otherName);

    // printing
    void printContents();
    
private:
    // Variables
    int m_name;
    std::vector<std::pair<int, int>> m_adjacentVector;

};

#endif // VERTEX_H