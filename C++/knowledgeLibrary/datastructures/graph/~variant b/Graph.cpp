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



/*
    Purpose:    

    Arguments:  

    Return:     
*/
bool Graph::addAdjacent(std::string& name, std::string& adjacentName, unsigned int weight){
    unsigned int position;
    bool successful;

    position = searchVertex(name);
    successful = m_vertices[position].addAdjacent(adjacentName, weight);

    if(successful){
        return true;
    }
    return false;
}


unsigned int Graph::searchVertex(std::string& name){
    unsigned int position;

    for(int curr = 0; curr < m_vertexCount; curr++){
        if(m_vertices[curr].getName() == name){
            return curr;
        }
    }

    // not found
    return -1;
}

// Getters:
unsigned int Graph::getVertexCount() { return m_vertexCount; }


/*
    Pupose:     Print all contents held in Graph
*/
void Graph::printContents(){

    std::cout << "Total Verticies: " << this->getVertexCount() << std::endl;
    std::cout << "Number\tName\tAdjacent Verticies\tWeight" << std::endl;
    
    for(int i = 0; i < m_vertexCount; i++){
        std::cout << i << ": " << m_vertices[i].getName() << " " ;
        std::cout << "\t" << m_vertices[i].getAdjacentListLength() << std::endl;
    }



    return;
}




