#include"Vertex.h"

/*
*/
Vertex::Vertex(){
    loc(printf("_____ Vetex::Vertex _____\n"));
    m_name = "";
}


/*
*/
Vertex::~Vertex(){
    loc(printf("_____ Vetex::~Vertex _____\n"));

}


/*
*/
Vertex::Vertex(const Vertex& other){
    loc(printf("_____ Vetex::Vertex - COPY _____\n"));
    m_name = other.m_name;

}


/*
*/
Vertex::Vertex(Vertex&& other){
    loc(printf("_____ Vetex::Vertex - MOVE _____\n"));
    m_name = other.m_name;

}


/*
*/
Vertex& Vertex:: operator=(const Vertex& other){
    loc(printf("_____ Vetex:: operater= - COPY _____\n"));

    m_name = other.m_name;

    return *this;
}


/*
*/
Vertex& Vertex:: operator=(Vertex&& other){
    loc(printf("_____ Vetex:: operater= - MOVE _____\n"));

    m_name = other.m_name;

    return *this;
}


// Setters:
void Vertex::setName(std::string& name) { m_name = name; return; }


// Getters:
std::string Vertex::getName() { return m_name; }

