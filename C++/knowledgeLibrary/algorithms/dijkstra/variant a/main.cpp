/*
    Date:           9-23-2021
    File:           main.cpp
    Version:        1.0
    
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
#include"../../../datastructures/graph/~variant a/Graph.h"
#include "../../../datastructures/graph/~variant a/Vertex.h"
#include"../../../datastructures/graph/~variant a/macros.h"

// Declarations
void buildGraph(Graph& graph);
unsigned int dijkstra(int start, int end, Graph& map);
void testFunctionality(Graph& graph);


int main(){
    int ans;

    Graph map;
    buildGraph(map);
    map.printContents();
    
    ans = dijkstra(0, 4, map);

    std::cout << "\n\nreturn: " << ans  << std::endl;

    
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

    // Adds Adjacent Vertex/Weights     **THESE ARE SORTED BY WEIGHT
    {
        graph.addAdjacentVertex(0, {1, 4});
        graph.addAdjacentVertex(0, {7, 8});
        
        graph.addAdjacentVertex(1, {0, 4});
        graph.addAdjacentVertex(1, {2, 8});
        graph.addAdjacentVertex(1, {7, 11});
        
        graph.addAdjacentVertex(2, {8, 2});
        graph.addAdjacentVertex(2, {3, 7});
        graph.addAdjacentVertex(2, {1, 8});
        
        graph.addAdjacentVertex(3, {2, 7});
        graph.addAdjacentVertex(3, {4, 9});
        graph.addAdjacentVertex(3, {5, 14});
        
        graph.addAdjacentVertex(4, {3, 9});
        graph.addAdjacentVertex(4, {5, 10});
        
        graph.addAdjacentVertex(5, {6, 2});
        graph.addAdjacentVertex(5, {4, 10});
        graph.addAdjacentVertex(5, {3, 14});
        
        graph.addAdjacentVertex(6, {7, 1});
        graph.addAdjacentVertex(6, {5, 2});
        graph.addAdjacentVertex(6, {8, 6});
        
        graph.addAdjacentVertex(7, {6, 1});
        graph.addAdjacentVertex(7, {8, 7});
        graph.addAdjacentVertex(7, {0, 8});
        graph.addAdjacentVertex(7, {1, 11});
        
        graph.addAdjacentVertex(8, {2, 2});
        graph.addAdjacentVertex(8, {6, 6});
        graph.addAdjacentVertex(8, {7, 7});
    }

    return;
}


/*
    Purpose:    Find the shortest path from one node to every other node in the
                graph

    Arguments:  start - The start node used as a reference to every other node
                end -   The node which a weight to the start node is requested
                map -   graph class used to reprent every vertex and details added  

    Return:     
*/
unsigned int  dijkstra(int start, int end, Graph& map){
    printEveryTime("\n____dijkstra(int start, Graph& map)____\n");
    
    // Variables
    bool qPresent;
    unsigned int INFINITY = -1;
    unsigned int shortestDistance = -1;
    unsigned int pqIndex, pqNode, pqWeight;
    unsigned int bestIndex, bestWeight;
    unsigned int runningWeight;
    unsigned int mapSize = map.get_vertices_count();
    
    bool visited[mapSize] = {};
    unsigned int distances[mapSize];
    std::vector<std::pair<int, int>> priorityQueue;         // (index, distance)
    std::vector<std::pair<int, int>> avCopy;                // Adjacent Vector Copy

    // Initializing
    for(unsigned int &i : distances)
        i = INFINITY;


    // Adds starting point to Queue
    distances[start] = 0;
    priorityQueue.push_back( {start, 0});
        

    // Goes through Queue until it's been through every point
    while(!priorityQueue.empty()){
        std::cout << "\n __________________ PQ_LOOP __________________ STOP: \n";
        
        std::cout << "\n\t____Priority Queue____ \n";
        for(auto i : priorityQueue)
            std::cout << "\t->   index: " << i.first << "   weight: " << i.second << std::endl;

        std::cout << "\n\t____Distance____ \n\t" ;
        for(auto i : distances)
            std::cout << i << ", ";
        std::cout << std::endl;

        std::cout << "\n\t____Visited____ \n\t" ;
        for(auto i : visited)
            std::cout << i << ", ";
        std::cout << std::endl;
        
        std::cout << "\n\t____adjacent vector copy____ \n" ;
        for(auto i : avCopy)
            std::cout << "\t->   index: " << i.first << "   weight: " << i.second << std::endl;
        std::cout << std::endl;


        // Picks the next best choice in the priority queue
        //      --  Currently the adjacent nodes are sorted when building graph
        //          so the next best node is next
        pqWeight = INFINITY;
        for(int i = 0; i < priorityQueue.size(); i++){
            if(priorityQueue[i].second < pqWeight){
                pqNode = priorityQueue[i].first;
                pqWeight = priorityQueue[i].second;
                pqIndex = i;
            }
        }
        std::cout << "\n\t\t-> pqNode: " << pqNode << std::endl;
        std::cout << "\t\t-> pqWeight: " << pqWeight << "\n\n"; // << " + " << distances[pqNode] << "\n\n";

        // Marks the current priority Q as seen
        if(pqWeight < distances[pqNode]){
            distances[pqNode] = pqWeight;
        }
        visited[pqNode] = true;
        priorityQueue.erase(priorityQueue.begin() + pqIndex);
        
        // checks adjacent nodes not visited
        avCopy = map.get_adjacentVertices_vector(pqNode);
        while(!avCopy.empty() ){
            std::cout << "\n\t____adjacent vector copy____ " << std::endl;
            for(auto i : avCopy)
                std::cout << "\t->   index: " << i.first << "   weight: " << i.second << std::endl;
            std::cout << std::endl;



            if(visited[ avCopy[0].first ] == false){
                // std::cout << "\n____ visited[ avCopy[0].first ] == false ____\n";
                
                // Checks to see if adjacent nodes are in priority q
                qPresent = false;
                for(int i = 0; i < priorityQueue.size(); i++){
                    if(priorityQueue[i].first == avCopy[0].first ){

                        qPresent = true;
                        
                        // updates distance in queue if needed
                        if(priorityQueue[i].second > avCopy[0].second + distances[pqNode]){
                            priorityQueue[i].second = avCopy[0].second + distances[pqNode];
                        }
                    }
                }

                // if not present in queue, add it
                if(qPresent == false){
                    priorityQueue.push_back( { avCopy[0].first, avCopy[0].second + distances[pqNode]} );
                    std::cout << "\n\t\tqPresent == false " << std::endl;
                    std::cout << "\n\t\t-> avCopy[0].first: " << avCopy[0].first << std::endl;
                    std::cout << "\t\t-> avCopy[0].second + distances[pqNode]: " << avCopy[0].second + distances[pqNode] << "\n";
                    std::cout << "\t\t-> distances[pqNode]: " << distances[pqNode] << "\n\n";
                        
                }
            }
            avCopy.erase(avCopy.begin());
        }
    }

    shortestDistance = distances[end];
    return shortestDistance;
}


/*
    Purpose:    Test functionality of Graph class and Vertex Class

    Argument:   Graph - Modifies the graph from main  
*/
void testFunctionality(Graph& graph){
    printEveryTime("\n\n");
    printEveryTime("____testFunctionality(Graph& graph)____\n");
    
/*
    // Testing isAdjacent function
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