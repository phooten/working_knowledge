#define INF 10000000   // 7 zero's

#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

class Graph{
private:
    int V;                              // Number of Vertices
    list<pair<int, int>> *adj;          // Pointer to adjacency list (vertex, weight)

public:
    Graph(int v);                       // Constructor prototype
    void addEdge(int v1, int v2, int weight);   // Method to add an edge/weight pair
    void shortestPath(int s);           // Method for shortest path
};


Graph::Graph(int v){
    V = v;                              // set number of vertices
    adj = new list<pair<int, int>>[v];  // Create new adjacency list
}


void Graph::addEdge(int v1, int v2, int weight){
    adj[v1].push_back(make_pair(v2, weight));
}

/*
    Purpose:

    Arguments:  s -  starting point
*/
void Graph::shortestPath(int s){
    // Create set to store vertices
    // Use this to extract the shortest path
    set<pair<int, int>> extract_set;

    // Vector for distances
    // All paths are initialized to a large value
    vector<int> distance(V, INF);   // Size of V, all filled to infinity

    
    // Insert the entry point into the set
    // Initialize distance to 0, s is the starting point
    extract_set.insert(make_pair(0, s));
    distance[s] = 0;

    // Continue until all shortest distances are finialized
    while(!extract_set.empty()){
        // Extract the minimum distances
        pair<int, int> tmp = *(extract_set.begin());
        extract_set.erase(extract_set.begin());

        // Get the vertex number
        int u = tmp.second;

        // Go over the adjaceny list
        for(auto i = adj[u].begin(); i != adj[u].end(); i++){
            // Get the vertex and weight
            int v = (*i).first;
            int weight = (*i).second;

            // Check if we have found a shorted path to v
            if(distance[v] > distance[u] + weight){
                
                // Remove the current distance if it is in the set
                if(distance[v] != INF){
                    extract_set.erase(extract_set.find(make_pair(distance[v], v)));
                }

                // Update the distance
                distance[v] = distance[u] + weight;
                extract_set.insert(make_pair(distance[v], v));

                
            }
        }
    }
    
    cout << "minimum Distance from vertex: " << s << endl;
    for(int i = 0; i < V; i++){
        cout << "Vertex: " << i << "\tDistance: " << distance[i] << endl;
    }
}




int main(){


    return 0;
}