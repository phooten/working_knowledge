#ifndef GRAPHCLASS_H
#define GRAPHCLASS_H

#include "GeneralHeaders.h"
#include "VertexClass.h"


class Graph{
    public:
        // Variables
        int m_totalVertices; 
        Vertex* M_VerticesPtr;

        // Constructor/Destructor
        Graph(int num);
        ~Graph();

        // functions
        void addVertex(std::string name);
        void removeVertex(std::string name);
        bool searchVertex(std::string name);
        void print();
        void fillDefault();

};


#endif