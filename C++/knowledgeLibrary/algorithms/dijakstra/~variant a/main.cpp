/*
    Date:           9-23-2021
    File:           main.cpp
    Version:        1.0
    Status:         INCOMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To sort a given set of numbers using Dijakstra's method. 
                    In doing so, I will learn about how this algorithm works and
                    will be able to compare it's efficiency to other algorithms
                    when I come in contact with them. 


    Latest Status [ 10-12-2021 ]:
                I have created my own Graph class that i've copied into this 
                folder which will be used to complete dijkstra's algo  


    Questions to think about:
        1. What is Dijkstra's time/space complexity?
        2. What are some different variations of this algorithm?


*/


#include<iostream>
#include<vector>
#include"graph/Graph.h"
#include "graph/Vertex.h"
#include"graph/macros.h"

// Declarations
void buildGraph(Graph& graph);
void testFunctionality(Graph& graph);

int main(){

    Graph map;
    buildGraph(map);
    map.printContents();

    
    return 0;
} 


/*
    Purpose:    Build a graph wihtout muddying up the main function

    Argument:   Graph - Modifies the graph from main  
*/
void buildGraph(Graph& graph){
    printDebug("____buildGraph(Graph& graph)____\n");
    
    // Variables
    int name = 0;
    int count = 9;

    // Adding Vertices
    for(name; name < count; name++){
        printf("adding: %i\n", name);
        graph.addVertex(Vertex(name));
    }   

    // Adds Adjacent Vertex/Weights
    {
        graph.addAdjacent(0, {1, 4});
        graph.addAdjacent(0, {7, 8});
        
        graph.addAdjacent(1, {0, 4});
        graph.addAdjacent(1, {2, 8});
        graph.addAdjacent(1, {7, 11});
        
        graph.addAdjacent(2, {1, 8});
        graph.addAdjacent(2, {3, 7});
        graph.addAdjacent(2, {8, 2});
        
        graph.addAdjacent(3, {2, 7});
        graph.addAdjacent(3, {4, 9});
        graph.addAdjacent(3, {5, 14});
        
        graph.addAdjacent(4, {3, 9});
        graph.addAdjacent(4, {5, 10});
        
        graph.addAdjacent(5, {3, 14});
        graph.addAdjacent(5, {4, 10});
        graph.addAdjacent(5, {6, 2});
        
        graph.addAdjacent(6, {5, 2});
        graph.addAdjacent(6, {7, 1});
        graph.addAdjacent(6, {8, 6});
        
        graph.addAdjacent(7, {0, 8});
        graph.addAdjacent(7, {1, 11});
        graph.addAdjacent(7, {6, 1});
        graph.addAdjacent(7, {8, 7});
        
        graph.addAdjacent(8, {2, 2});
        graph.addAdjacent(8, {6, 6});
        graph.addAdjacent(8, {7, 7});
    }

    return;
}


/*
    Purpose:    Test functionality of Graph class and Vertex Class

    Argument:   Graph - Modifies the graph from main  
*/
void testFunctionality(Graph& graph){
    printEveryTime("\n\n");
    printEveryTime("____testFunctionality(Graph& graph)____\n");
    
    // Testing isAdjacent function
/*
    int a = 2, b = 6, 
        c = 0, d = 8,
        e = 4, f = 6;

    std::cout << "testing:\t" << a << " and " << b << "\t\tWeight = " << graph.isAdjacent(a, b);
    printf("\n");
    std::cout << "testing:\t" << c << " and " << d << "\t\tWeight = " << graph.isAdjacent(c, d);
    printf("\n");
    std::cout << "testing:\t" << e << " and " << f << "\t\tWeight = " << graph.isAdjacent(e, f);
    printf("\n");
*/
}