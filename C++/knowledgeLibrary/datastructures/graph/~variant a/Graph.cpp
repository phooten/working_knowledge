#include "Graph.h"

// Default constructor
Graph::Graph() : m_size(0) {
   printDebug("____Graph::Graph()____\n");
    
}

// Default deconstructor
Graph::~Graph(){
    printDebug("____Graph::~Graph()____\n");
    
}


/*
    Purpose:    Adds a vertex node to the graph structure

    Argument:   otherVertex - Vertex to be added to the graph

    Return:     True if successful, False if not
*/
bool Graph::addVertex(Vertex&& otherVertex){
    printDebug("____Graph::addVertex(Vertex& otherVertex)____\n");
    
    m_verticesVector.push_back(otherVertex);
    m_size++;

    return true;
}


/*
    Purpose:    Adds an adjacent vertex and weight to a certain vertex in the
                Graph structure

    Argument:   position -  Position of the vertex in the graph to add an 
                            adjacent point to.  
                otherPair - Adjacent vertex and weight respectivley to be added

    Return:     True if successful, False if not
*/
bool Graph::addAdjacentVertex(int position, std::pair<int, int> otherPair){
    printDebug("____Graph::addAdjacentVertex()____\n");

    m_verticesVector[position].add_adjacentVertex(otherPair);
    
    return true;
}


/*
    Purpose:    looks to see if a vertex is adjacent to another vertex. It will
                return the weight if it is. 

    Argument:   name -          name of the vertex being looked at  
                adjacentName -  name of the vertex that will be scanned in 
                                "name"'s adjacent list 

    Return:     weight of the vertex if it's adjacent, else -1
*/
int Graph::isAdjacent(int name, int adjacentName){
    printDebug("____Graph::isAdjacent(int name, int adjacentName)____\n");
    
    // Variables
    int weight;

    weight = m_verticesVector[name].search_adjacentVertex(adjacentName);

    return weight;
}


// Getters
int Graph::get_vertices_count() const { return m_verticesVector.size(); }
std::vector<Vertex> Graph::get_verticesVector() const { return m_verticesVector; }

std::vector<std::pair<int, int>> Graph::get_adjacentVertices_vector(int name) const {    
    return m_verticesVector[name].get_adjacentVertices_vector();
}


/*
    Purpose:    Print out the contents of what is currently in the graph
*/
void Graph::printContents(){
    printDebug("____Graph::printContents()____\n");
    
    std::cout << "Total Vertices: " << m_size << std::endl;
    std::cout << "Names: " << std::endl;
    for(int i = 0; i < m_size; i++){

        std::cout << i << ": " << m_verticesVector[i].get_name();
        std::cout << "\tAdjacent Vertices: "  << m_verticesVector[i].get_adjacentVertices_size() << std::endl;
        m_verticesVector[i].printContents();
    }
    printf("\n");

    return;
}
