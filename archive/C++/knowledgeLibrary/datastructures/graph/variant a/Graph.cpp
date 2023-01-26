#include "Graph.h"


/*
    Purpose:    Default constructor
*/
Graph::Graph() : m_size(0) {
   printDebug("____Graph::Graph()____\n");
    
}


/*
    Purpose:    Default deconstructor
*/
Graph::~Graph(){
    printDebug("____Graph::~Graph()____\n");
    
}


/*
    Purpose:    Adds a vertex to the graph structure

    Argument:   otherVertex - Vertex to be added to the graph
*/
void Graph::addVertex(Vertex&& otherVertex){
    printDebug("____Graph::addVertex(Vertex& otherVertex)____\n");
    
    m_verticesVector.push_back(otherVertex);
    m_size++;

    return;
}


/*
    Purpose:    Adds an adjacent vertex and weight to a certain vertex in the
                Graph structure

    Argument:   position -  Position of the vertex in the graph to add an 
                            adjacent point to.  
                otherPair - Adjacent vertex and weight respectivley to be added
*/
void Graph::addAdjacentVertex(int position, std::pair<int, int> otherPair){
    printDebug("____Graph::addAdjacentVertex()____\n");

    m_verticesVector[position].add_adjacentVertex(otherPair);
    
    return;
}


/*
    Purpose:    looks to see if a vertex is adjacent to another vertex. It will
                return the weight if it is. 

    Argument:   name -          name of the vertex being looked at  
                adjacentName -  name of the vertex that will be scanned in 
                                "name"'s adjacent vertices vector 

    Return:     weight of the vertex if it's adjacent, else -1
*/
int Graph::get_adjacentWeight(int name, int adjacentName) const {
    printDebug("____Graph::isAdjacent(int name, int adjacentName)____\n");
    
    // Variables
    int weight;

    weight = m_verticesVector[name].get_adjacentVertex_weight(adjacentName);

    return weight;
}


/*
    Purpose:    returns how many vertices are currently in the graph
*/
int Graph::get_vertices_count() const { 
    return m_verticesVector.size(); 
}


/*
    Purpose:    returns the graph vertices vector to be accessed
*/
std::vector<Vertex> Graph::get_verticesVector() const { 
    return m_verticesVector; 
}


/*
    Purpose:    returns the adjacent vertices vector of a specificied graph vertex
*/
std::vector<std::pair<int, int>> Graph::get_adjacentVertices_vector(int name) const {    
    return m_verticesVector[name].get_adjacentVertices_vector();
}


/*
    Purpose:    Print out the contents of what is currently in the graph
*/
void Graph::print_graphContents(){
    printDebug("____Graph::printContents()____\n");
    
    std::cout << "_______ Graph Created ______ \n";
    std::cout << "Total Vertices: " << m_size << std::endl;
    std::cout << "Nodes and Adjacent Nodes: \n\n";
    for(int i = 0; i < m_size; i++){

        std::cout << i << ": " << m_verticesVector[i].get_vertexName();
        std::cout << "\tAdjacent Vertices: "  << m_verticesVector[i].get_adjacentVertices_size() << std::endl;
        m_verticesVector[i].printContents();
        printf("\n");
    }
    printf("\n");

    return;
}


/*
    Purpose:    Print out the contents of what is currently in the graph
*/
void Graph::print_adjacentDetails(int name){
    printDebug("____Graph::print_adjacentDetails()____\n");
    
    std::cout << "_______ " << name << " : Adjacent Details ______ \n";
    std::cout << "\tTotal Adjacent Vertices: "  << m_verticesVector[name].get_adjacentVertices_size() << std::endl;
    m_verticesVector[name].printContents();
    printf("\n");

    return;
}
