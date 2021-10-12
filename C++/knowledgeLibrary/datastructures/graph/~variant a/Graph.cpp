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
    
    m_vertices.push_back(otherVertex);
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
bool Graph::addAdjacent(int position, std::pair<int, int> otherPair){
    printDebug("____Graph::addAdjacentVertex()____\n");

    m_vertices[position].addAdjacent(otherPair);
    
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

    weight = m_vertices[name].searchAdjacent(adjacentName);

    return weight;
}


/*
    Purpose:    Print out the contents of what is currently in the graph
*/
void Graph::printContents(){
    printDebug("____Graph::printContents()____\n");
    
    std::cout << "Total Vertices: " << m_size << std::endl;
    std::cout << "Names: " << std::endl;
    for(int i = 0; i < m_size; i++){

        std::cout << i << ": " << m_vertices[i].getName();
        std::cout << "\tAdjacent Vertices: "  << m_vertices[i].getAdjacentListSize() << std::endl;
        m_vertices[i].printContents();
    }
    printf("\n");

    return;
}
