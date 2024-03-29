/*
    Date:           10-11-2021
    File:           main.cpp
    Version:        1.0
    Contributer:    koffee-byte    

    Purpose:        This is a DEMO for the graphs datastructure I built. It is
                    meant learn about graphs and how to implement implement them. 

    Usage:
        Building the graph relies on 'Graph.h', 'Graph.cpp', 'vertex.h', 'vertex..cpp'
        and 'macro.h'. To build a new graph all you need are these 5 files.  
        
        Code in 'buildGraph()' of 'main.cpp' shows sample code on how to build
        a graph with these files. The code was based on the png's in the document 
        folder which are called 'sample_a.png' and 'sample_b.png'. 'sample_b' is commented
        out.  

*/


#include<iostream>
#include<vector>
#include"Graph.h"
#include"Vertex.h"
#include"macros.h"

// Declarations
void buildGraph(Graph& graph);
void testFunctionality(Graph& graph);

int main(){

    // Making an empty Fraph
    Graph map;

    // Adding the graph
    buildGraph(map);
    
    // Showing graph contents
    map.print_graphContents();
    map.print_adjacentDetails(3);
    
    return 0;
} 


/*
    Purpose:    Build a graph wihtout muddying up the main function

    Argument:   &Graph - Modifies the graph from main  
*/
void buildGraph(Graph& graph){
    printDebug("____buildGraph(Graph& graph)____\n");
    
    // Variables
    int count;          // Total vertices in graph

    //  sample_A ( scope )
    {    
        count = 9;

        // Adding Vertices
        for(int name = 0; name < count; name++){
            // printf("adding: %i\n", name);
            graph.addVertex(Vertex(name));
        }
        
        // Adding Adjcent Vertices
        graph.addAdjacentVertex(0, {1, 1});
        graph.addAdjacentVertex(0, {4, 3});
        
        graph.addAdjacentVertex(1, {0, 1});
        graph.addAdjacentVertex(1, {4, 1});
        graph.addAdjacentVertex(1, {2, 2});
        graph.addAdjacentVertex(1, {5, 7});
        
        graph.addAdjacentVertex(2, {1, 2});
        graph.addAdjacentVertex(2, {3, 2});
        graph.addAdjacentVertex(2, {5, 3});
        
        graph.addAdjacentVertex(3, {8, 1});
        graph.addAdjacentVertex(3, {2, 2});
        
        graph.addAdjacentVertex(4, {1, 1});
        graph.addAdjacentVertex(4, {0, 3});
        graph.addAdjacentVertex(4, {6, 4});
        graph.addAdjacentVertex(4, {7, 4});
        
        graph.addAdjacentVertex(5, {8, 2});
        graph.addAdjacentVertex(5, {2, 3});
        graph.addAdjacentVertex(5, {1, 7});
        
        graph.addAdjacentVertex(6, {7, 1});
        graph.addAdjacentVertex(6, {4, 4});
        
        graph.addAdjacentVertex(7, {6, 1});
        graph.addAdjacentVertex(7, {4, 4});
        graph.addAdjacentVertex(7, {8, 5});
        
        graph.addAdjacentVertex(8, {3, 1});
        graph.addAdjacentVertex(8, {5, 2});
        graph.addAdjacentVertex(8, {7, 5});
    }


    // sample_B ( scope )
    // {    
    //     count = 9;
        
    //     // Adding Vertices
    //     for(int name = 0; name < count; name++){
    //         // printf("adding: %i\n", name);
    //         graph.addVertex(Vertex(name));
    //     }
        
    //     // Adding Adjcent Vertices
    //     graph.addAdjacentVertex(0, {1, 4});
    //     graph.addAdjacentVertex(0, {7, 8});
        
    //     graph.addAdjacentVertex(1, {0, 4});
    //     graph.addAdjacentVertex(1, {2, 8});
    //     graph.addAdjacentVertex(1, {7, 11});
        
    //     graph.addAdjacentVertex(2, {8, 2});
    //     graph.addAdjacentVertex(2, {3, 7});
    //     graph.addAdjacentVertex(2, {1, 8});
        
    //     graph.addAdjacentVertex(3, {2, 7});
    //     graph.addAdjacentVertex(3, {4, 9});
    //     graph.addAdjacentVertex(3, {5, 14});
        
    //     graph.addAdjacentVertex(4, {3, 9});
    //     graph.addAdjacentVertex(4, {5, 10});
        
    //     graph.addAdjacentVertex(5, {6, 2});
    //     graph.addAdjacentVertex(5, {4, 10});
    //     graph.addAdjacentVertex(5, {3, 14});
        
    //     graph.addAdjacentVertex(6, {7, 1});
    //     graph.addAdjacentVertex(6, {5, 2});
    //     graph.addAdjacentVertex(6, {8, 6});
        
    //     graph.addAdjacentVertex(7, {6, 1});
    //     graph.addAdjacentVertex(7, {8, 7});
    //     graph.addAdjacentVertex(7, {0, 8});
    //     graph.addAdjacentVertex(7, {1, 11});
        
    //     graph.addAdjacentVertex(8, {2, 2});
    //     graph.addAdjacentVertex(8, {6, 6});
    //     graph.addAdjacentVertex(8, {7, 7});
    // }
 
    return;
}


/*
    Purpose:    Test functionality of Graph class and Vertex Class. Soley for 
                debugging and scratch usage. 

    Argument:   Graph - Modifies the graph built in main  
*/
void testFunctionality(Graph& graph){
    printEveryTime("\n\n");
    printEveryTime("____testFunctionality(Graph& graph)____\n");
    

}