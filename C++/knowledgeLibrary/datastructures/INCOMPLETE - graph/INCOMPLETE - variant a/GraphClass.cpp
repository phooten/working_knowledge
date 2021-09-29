#include "GraphClass.h"

/*
    Contsructor
*/
Graph::Graph(int num) {
    m_totalVertices = num;
    M_VerticesPtr = new Vertex[m_totalVertices];
    
    std::cout << std::endl;

}

/*
    Desctructor
*/
Graph::~Graph() {
    delete[] M_VerticesPtr;
}


/*
    Description:
        Adds a vertex to the end of the array
*/
void Graph::addVertex(std::string name){
    std::cout << std::endl << "__Graph::addVertex__" << std::endl;
    
    Vertex* tmp; 
    
    m_totalVertices++;
    
    // Copies contents into new, larger array
    tmp = M_VerticesPtr;
    M_VerticesPtr = new Vertex[m_totalVertices];
    for(int i = 0; i < m_totalVertices - 1; i++){   // Just added another point, so without "- 1" it would exceed old array bounds
        M_VerticesPtr[i] = tmp[i];
    }

    M_VerticesPtr[m_totalVertices - 1].m_name = name;

    // clean up
    delete[] tmp;
    
    return;
}

/*
    Description:
        Adds a vertex to the end of the array
*/
void Graph::removeVertex(std::string name){
    std::cout << std::endl << "__Graph::removeVertex__" << std::endl;
    
    if(searchVertex(name)){
        Vertex* tmp; 
        int currPos = 0;
        
        // Copies contents into new, larger array
        tmp = M_VerticesPtr;
        m_totalVertices--;
        M_VerticesPtr = new Vertex[m_totalVertices];
        
        for(int i = 0; i < m_totalVertices + 1; i++){   
            if(tmp[i].m_name != name){
                M_VerticesPtr[currPos] = tmp[i];
                currPos++;
            }
        }        

        // clean up
        delete[] tmp;
    } else {
        std::cout << "Couldn't find: \"" << name << "\"" <<  std::endl;
    }
    
    return;
}

bool Graph::searchVertex(std::string name){
    std::cout << std::endl << "__Graph::searchVertex__" << std::endl;
    
    for(int i = 0; i < m_totalVertices; i++){
        if(M_VerticesPtr[i].m_name == name){
            return true;
        }
    }

    return false;
}


/*
    Description:
        Fills the vetex classes in Graph with basic values. Mostly used for testing.
*/
void Graph::fillDefault(){
    std::cout << std::endl << "__Graph::fill__" << std::endl;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  
    for(int i = 0; i < m_totalVertices; i++){
        M_VerticesPtr[i].m_name = alphabet[i];
    }

    return;
}

/*
    Description:
        Prints out contents of Graph
*/
void Graph::print() {
    std::cout << std::endl << "__Graph::print__" << std::endl;
    for(int i = 0; i < m_totalVertices; i++){
        std::cout << i << ": [" << M_VerticesPtr[i].m_name << ", " << M_VerticesPtr[i].m_visited << "]" << std::endl;
    }
    std::cout << std::endl;

    return;
}

