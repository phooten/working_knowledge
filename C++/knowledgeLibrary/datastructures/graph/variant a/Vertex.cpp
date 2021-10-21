#include "Vertex.h"


/*
    Pupose:     Default constructor
*/
Vertex::Vertex(int otherName) : m_name(otherName){
    printDebug("____Vertex(int otherName)____\n");
}


/*
    Pupose:     Default deconstructor
*/
Vertex::~Vertex(){
    printDebug("____~Vertex()____\n");
    
}


/*
    Purpose:    Copy constructor    
*/
Vertex::Vertex(const Vertex& other){ 
    printDebug("____Vertex::Vertex(const Vertex& other)____\n");
    printDebug("Copy.\n");

    m_name = other.get_vertexName();
}


/*
    Purpose:    Move constructor
*/
Vertex::Vertex(Vertex&& other){ 
    printDebug("____Vertex(Vertex&& other)____\n");
    printDebug("Move.\n");

    m_name = other.get_vertexName();
}


/*
    Purpose:    copy assignment operator
*/
Vertex& Vertex::operator=(const Vertex& other) {
    printDebug("____Vertex& operator=(const Vertex& other)____\n");
    printDebug("Copy.\n");

    m_name = other.get_vertexName();
    
    return *this;
}


/*
    Purpose:    move assignment operator
*/
Vertex& Vertex::operator=(Vertex&& other) {
    printDebug("____Vertex& operator=(Vertex&& other)____\n");
    printDebug("Move.\n");

    m_name = other.get_vertexName();
    
    return *this;
}


/*
    Purpose:    Add a vertex to a list of adjacent nodes along with the weight
                it takes to get there from the original vertex

    Argument:   otherPair - Adjacent vertex and weight respectivley to be added 
*/
void Vertex::add_adjacentVertex(std::pair<int, int> otherPair){
    printDebug("____Vertex::addAdjacent(std::pair<int, int> otherPair)____\n");
    m_adjacentVector.push_back(otherPair);

    return;
}

/*
    Pupose:     returns the vertex name
*/    
int Vertex::get_vertexName() const { return m_name; }


/*
    Purpose:    Searches for a name in this vertex's adjacent list

    Argument:   name - name of adjacent vertex being looked for 

    Returns:    weight of the adjacent vertex if it excists, -1 otherwise
*/
int Vertex::get_adjacentVertex_weight(int name) const {
    //Variables
    int weight = -1;

    // Looking for name in adjacent list
    for(int curr = 0; curr < m_adjacentVector.size(); curr++){
        // Returns weight if found
        if(m_adjacentVector[curr].first == name){
            weight = m_adjacentVector[curr].second;
            return weight;
        }
    }

    return weight;
}

/*
    Pupose:     returns the size of the adjacent vector bound to this vertex
*/    
int Vertex::get_adjacentVertices_size() const { return m_adjacentVector.size(); }

/*
    purpose:    returns adjacent vector bound to this vertex for external copying
*/
std::vector<std::pair<int, int>> Vertex::get_adjacentVertices_vector() const { return m_adjacentVector; }

/*
    purpose:    sets the vertex name
*/
void Vertex::set_vertexName(int otherName) { m_name = otherName; return; }


/*
    Purpose:    Print out the contents of the current Vertex
*/
void Vertex::printContents(){
    printDebug("____Vertex::printContents()____\n");
    
    for(int i = 0; i < m_adjacentVector.size(); i++){
        std::cout << "Name: " << m_adjacentVector[i].first;
        std::cout << "\tWeight: " << m_adjacentVector[i].second << std::endl;
    }
    
    return;
}

