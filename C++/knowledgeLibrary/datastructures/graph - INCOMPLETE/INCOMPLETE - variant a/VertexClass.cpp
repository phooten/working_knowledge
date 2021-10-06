#include "VertexClass.h"

/*
    Contsructor
*/
Vertex::Vertex() {
    m_name = "";
    m_visited = false;
    m_adjListPtr = NULL;

}

/*
    Contsructor
*/
Vertex::Vertex(AdjacentVertex* adjListPtr) {
    m_adjListPtr = adjListPtr;
}

void Vertex::addAdjVertex(std::string name, int weight){

}

void Vertex::removeAdjVertex(std::string name, int weight){
    
}

void Vertex::printAdjList(){
    std::cout << std::endl << "__Vertex::printAdjList__" << std::endl;

    AdjacentVertex* currAdjVertex = m_adjListPtr;

    while(currAdjVertex != NULL){
        
        currAdjVertex++;
    }
}