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


bool Vertex::addAdjacent(std::string name, unsigned int weight){
    std::vector<std::string> currName = m_adjacentVertices;
    std::vector<unsigned int> currWeight = m_adjacentWeight;

    m_adjacentVertices.push_back(name);
    m_adjacentWeight.push_back(weight);

    return true;
}


// Setters:
void Vertex::setName(std::string& name) { m_name = name; return; }


// Getters:
std::string Vertex::getName() { return m_name; }
int Vertex::getAdjacentListLength() { return m_adjacentVertices.size(); }


void Vertex::printContent(){
    std::cout << "______ Vertex: Contents ______h" << std::endl;
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "Adjacent Verticies: " << this->getAdjacentListLength() << std::endl;
    std::cout << "Adjcacent List: ";
    if(this->m_adjacentVertices.size() == 0){
        std::cout << "EMPTY";
    } else {
        for(int i = 0; i < this->m_adjacentVertices.size(); i++){
            std::cout << this-> m_adjacentVertices[i] << " (";
            std::cout << this->m_adjacentWeight[i] << "), ";
        }
    }
    std::cout << std::endl;


    return;
}
