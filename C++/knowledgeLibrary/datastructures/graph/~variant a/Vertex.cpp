#include "Vertex.h"

// Default Constructor
Vertex::Vertex(int otherName) : m_name(otherName){
    printDebug("____Vertex(int otherName)____\n");
}


// Default deconstructor
Vertex::~Vertex(){
    printDebug("____~Vertex()____\n");
    
}



/*
    Purpose:    

    Argument:   
*/
Vertex::Vertex(const Vertex& other){ 
    printDebug("____Vertex::Vertex(const Vertex& other)____\n");
    printDebug("Copy.\n");

    m_name = other.getName();
}


/*
    Purpose:    

    Argument:   
*/
Vertex& Vertex::operator=(const Vertex& other) {
    printDebug("____Vertex& operator=(const Vertex& other)____\n");
    printDebug("Copy.\n");

    m_name = other.getName();
    
    return *this;
}


/*
    Purpose:    

    Argument:   
*/
Vertex::Vertex(Vertex&& other){ 
    printDebug("____Vertex(Vertex&& other)____\n");
    printDebug("Move.\n");

    m_name = other.getName();
}


/*
    Purpose:    

    Argument:   
*/
Vertex& Vertex::operator=(Vertex&& other) {
    printDebug("____Vertex& operator=(Vertex&& other)____\n");
    printDebug("Move.\n");

    m_name = other.getName();
    
    return *this;
}



/*
    Purpose:    Add a vertex to a list of adjacent nodes along with the weight
                it takes to get there from the original vertex

    Argument:   otherPair - Adjacent vertex and weight respectivley to be added 

    Returns:    True if successful, False if not
*/
bool Vertex::addAdjacent(std::pair<int, int> otherPair){
    printDebug("____Vertex::addAdjacent(std::pair<int, int> otherPair)____\n");
    m_adjacent.push_back(otherPair);

    return true;
}

/*
    Purpose:    Searches for a name in this vertex's adjacent list

    Argument:   name - name of adjacent vertex being looked for 

    Returns:    weight of the adjacent vertex if it excists, -1 otherwise
*/
int Vertex::searchAdjacent(int name){
    //Variables
    int weight = -1;

    // Looking for name in adjacent list
    for(int curr = 0; curr < m_adjacent.size(); curr++){
        // Returns weight if found
        if(m_adjacent[curr].first == name){
            weight = m_adjacent[curr].second;
            return weight;
        }
    }

    return weight;
}


// getters
int Vertex::getName() const { return m_name; }
int Vertex::getAdjacentListSize() const { return m_adjacent.size(); }

// setters
void Vertex::setName(int otherName) { m_name = otherName; return; }


/*
    Purpose:    Print out the contents of the current Vertex
*/
void Vertex::printContents(){
    printDebug("____Vertex::printContents()____\n");
    
    for(int i = 0; i < m_adjacent.size(); i++){
        std::cout << "Name: " << m_adjacent[i].first;
        std::cout << "\tWeight: " << m_adjacent[i].second << std::endl;
    }
    
    return;
}
