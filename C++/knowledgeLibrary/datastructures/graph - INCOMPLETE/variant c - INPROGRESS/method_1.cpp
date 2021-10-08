#include<iostream>
#include<vector>
using namespace std;

class Graph{
    public:
        std::vector<int> v_;                    // Vertices
        std::vector<std::pair<int, int>> e_;    // Edges


        Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e) : v_(v), e_(e) {}
        
        // Is the count of odd-degrees vertices 0 or 2?
        bool IsEulerWalkable(){
            // Variables
            std::vector<int> degrees(v_.size());
            int countOdds = 0;
            
            for(auto e : e_){
                degrees[e.first]++;
                degrees[e.second]++;
            }
            
            for(auto d : degrees){
                if(d % 2 == 1){
                    countOdds++;
                }
            }
            
            return (countOdds == 0 || countOdds == 2);
        }

    
    private:
};

int main(){
    // Variables
    std::vector<int> v = {0, 1, 2, 3};                                      
    std::vector<std::pair<int, int>> e = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};  // Edges between two vertices
    
    Graph g(v, e);

    std::cout << g.IsEulerWalkable() << std::endl; 


    return 0;
}