#ifndef VERTEXCLASS_H
#define VERTEXCLASS_H

#include "GeneralHeaders.h"
#include "AdjacentClass.h"

class Vertex {
    public:
        // Variables
        std::string m_name;
        AdjacentVertex* m_adjListPtr;
        bool m_visited;

        // Constructors/Destructors
        Vertex();
        Vertex(AdjacentVertex* adjListPtr);
        

        // Functions
        void addAdjVertex(std::string name, int weight);
        void removeAdjVertex(std::string name, int weight);
        void printAdjList();
        
};

#endif