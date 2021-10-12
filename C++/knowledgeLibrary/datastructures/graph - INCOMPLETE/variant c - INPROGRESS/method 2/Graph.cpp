#include "Graph.h"

// Constrcutors
Graph::Graph() : m_size(0) {
   printDebug("____Graph::Graph()____\n");
    
}
// Graph(int size) : m_size(size) {}

Graph::~Graph(){
    printDebug("____Graph::~Graph()____\n");
    
}


// Main Functionality
bool Graph::addVertex(Vertex&& otherVertex){
    printDebug("____Graph::addVertex(Vertex& otherVertex)____\n");
    
    m_vertices.push_back(otherVertex);
    m_size++;

    return true;
}


void Graph::printContents(){
    printDebug("____Graph::printContents()____\n");
    
    std::cout << "Total Vertices: " << m_size << std::endl;
    std::cout << "Names: " << std::endl;
    for(int i = 0; i < m_size; i++){

        std::cout << i << ": " << m_vertices[i].getName();
        std::cout << "\tAdjacent Vertices: "  << std::endl;
        // for(int j = 0; j <  ){

        // }  
    }
    printf("\n");

    return;
}
