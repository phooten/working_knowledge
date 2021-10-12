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


    bool addAdjacent(std::pair<int, int> otherPair);
    int searchAdjacent(int name);

    // getters
    int getName() const;
    int getAdjacentListSize() const;

    // setters
    void setName(int otherName);


    void printContents();

private:
    // Variables
    int m_name;
    std::vector<std::pair<int, int>> m_adjacent;

};

#endif // VERTEX_H