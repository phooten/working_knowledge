// Adjacentcy list

#include<iostream>
#include<vector>
#include<set>


class Vertex {
public:
    int vertex_number;
    std::set<int> adjacents;

    Vertex(int v, std::set<int> &a) : vertex_number(v), adjacents(a) {}

};


class Graph {
public:
    std::vector<Vertex> v_;
    
    Graph(std::vector<Vertex> &v) : v_(v) {}


};


int main(){
    Graph g( Vertex);
    // Graph g( { Vertex(0, {1, 2}), Vertex(1, {0, 2, 3, 4}), Vertex(2, {1, 2}), Vertex(3, {1, 2}) } );

    std::cout << g.IsEulerWalkable() << std::endl;

    return 0;
}