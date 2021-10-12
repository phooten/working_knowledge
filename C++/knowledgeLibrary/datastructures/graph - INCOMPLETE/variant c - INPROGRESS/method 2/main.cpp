// Adjacentcy list

#include<iostream>
#include<vector>
#include "Graph.h"
#include "Vertex.h"
#include"macros.h"

void buildGraph(Graph& graph);

int main(){

    Graph g;
    buildGraph(g);
    
    g.printContents();

    return 0;
} 

void buildGraph(Graph& graph){
    printf("____buildGraph(Graph& graph)____\n");
    
    int name = -1;
    int count = -10;

    // Adding Verices
    
    for(name = -1 ; name >= count; name--){
        printf("adding: %i\n", name);
        graph.addVertex(Vertex(name));

    }   

    return;
}