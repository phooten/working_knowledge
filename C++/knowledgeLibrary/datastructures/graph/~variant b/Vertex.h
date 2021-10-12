#ifndef VERTEX_H
#define VERTEX_H

#include<iostream>
#include<string>
#include<vector>
#include "macros.h"

class Vertex{
public:
    // Constructor/Destructor
    Vertex();
    ~Vertex();
    

    Vertex(const Vertex& other);
    Vertex(Vertex&& other);
    Vertex& operator=(const Vertex& other);
    Vertex& operator=(Vertex&& other);
    
    // Member Functionality Functions
    bool addAdjacent(std::string name, unsigned int weight);
    // int seachVertex(std::string name);
    // bool searchWeight(unsigned int weight);
    // bool changeWeight(std::string name);

    // Setters
    void setName(std::string& name);
    
    // Getters
    std::string getName();
    int getAdjacentListLength();
    void printContent();

private:
    std::string m_name;
    std::vector<std::string> m_adjacentVertices;
    std::vector<unsigned int> m_adjacentWeight;

};

#endif