#include "AdjacentClass.h"


AdjacentVertex::AdjacentVertex(){
    m_next = NULL;
    m_name = NULL;
    m_weight = NULL;

}


AdjacentVertex::AdjacentVertex(std::string* name, int* weight){
    m_next = NULL;
    m_name = name;
    m_weight = weight;

}
