#include "Vertex.h"

// Constructors / Destructors
Vertex::Vertex(int otherName) : m_name(otherName){
    printDebug("____Vertex(int otherName)____\n");
}

Vertex::~Vertex(){
    printDebug("____~Vertex()____\n");
    
}


// Copy / Move
Vertex::Vertex(const Vertex& other){ 
    printDebug("____Vertex::Vertex(const Vertex& other)____\n");
    printDebug("Copy.\n");

    m_name = other.getName();
}

Vertex& Vertex::operator=(const Vertex& other) {
    printDebug("____Vertex& operator=(const Vertex& other)____\n");
    printDebug("Copy.\n");

    m_name = other.getName();
    
    return *this;
}

Vertex::Vertex(Vertex&& other){ 
    printDebug("____Vertex(Vertex&& other)____\n");
    printDebug("Move.\n");

    m_name = other.getName();
}

Vertex& Vertex::operator=(Vertex&& other) {
    printDebug("____Vertex& operator=(Vertex&& other)____\n");
    printDebug("Move.\n");

    m_name = other.getName();
    
    return *this;
}



// getters
int Vertex::getName() const { return m_name; }

// setters
void Vertex::setName(int otherName) { m_name = otherName; return; }



void Vertex::printContents(){
    printDebug("____Vertex::printContents()____\n");
    
    std::cout << "Name: " << m_name << std::endl;
    
    return;
}
