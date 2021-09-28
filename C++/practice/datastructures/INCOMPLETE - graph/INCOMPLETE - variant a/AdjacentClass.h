#ifndef ADJACENTCLASS_H
#define ADJACENTCLASS_H


#include "GeneralHeaders.h"

class AdjacentVertex {
    AdjacentVertex* m_next;
    std::string* m_name;
    int*m_weight;

    AdjacentVertex();
    AdjacentVertex(std::string* name, int* weight);
    ~AdjacentVertex();

};

#endif