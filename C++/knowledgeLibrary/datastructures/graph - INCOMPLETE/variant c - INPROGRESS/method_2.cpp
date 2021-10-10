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

    void addVertex(std::vector<Vertex> &v){
        v_.push_back(v);

        return;
    }


};


int main(){
    int v0 = 0;
    int v1 = 1;
    int v2 = 2;
    int v3 = 3;

    std::set<int> s0 = {1, 2};
    std::set<int> s1 = {1, 2};
    std::set<int> s2 = {1, 2};
    std::set<int> s3 = {1, 2};
    
    Vertex vs0(v0, s0); 
    Vertex vs1(v1, s1);
    Vertex vs2(v2, s2);
    Vertex vs3(v3, s3);

    Graph(vs0);    
    
    // Graph g( { Vertex(0, {1, 2}), Vertex(1, {0, 2, 3, 4}), Vertex(2, {1, 2}), Vertex(3, {1, 2}) } );

    // std::cout << g.IsEulerWalkable() << std::endl;

    return 0;
} 