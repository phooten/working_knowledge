#include "Graph.h"

/*
*/
Graph::Graph(){
    loc(printf("_____ Graph::Graph _____\n"));

    m_vertexCount = 0;
}


/*
*/
Graph::~Graph(){
    loc(printf("_____ Graph::~Graph _____\n"));

}


/*
    Purpose:    Add a connection between two vertices

    Arguments:  base:   the first vertex
                target: the vertex to connect to

    Return:     True if successful, false if not successful
*/
bool Graph::addVertex(std::string& name){
    m_vertices.push_back(Vertex());
    m_vertices[m_vertexCount].setName(name);
    m_vertexCount++;

    return true;
}


// Getters:
unsigned int Graph::getVertexCount() { return m_vertexCount; }


/*
    Pupose:     Print all contents held in Graph
*/
void Graph::printContents(){
    for(int i = 0; i < m_vertexCount; i++){
        std::cout << i << ": " << m_vertices[i].getName() << " " << std::endl;
    }


    return;
}




