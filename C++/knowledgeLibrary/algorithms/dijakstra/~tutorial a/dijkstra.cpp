#define INF 10000000   // 7 zero's

#include <iostream>
#include <list>
using namespace std;

class Graph{
private:
    int V;                      // Number of Vertices
    list<pair<int, int>> *adj;  // Pointer to adjacency list

public:
    Graph(int v);               // Constructor prototype
    void addEdge(int v1, int v2, int weight);   // Method to add an edge/weight pair
    void shortestPath(int s);   // Method for shortest path
};

Graph::Graph(int v){
    V = v;                              // set number of vertices
    adj = new list<pair<int, int>>[v];  // Create new adjacency list
}

void Graph::addEdge(int v1, int v2, int weight){
    
}