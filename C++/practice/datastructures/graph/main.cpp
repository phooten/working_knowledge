

#include <iostream>
#include <string>

class GraphList{
public:
    unsigned int nodeLength;
    unsigned int graph[nodeLength][nodeLength];


    GraphList(){
        nodeLength = 0;
    }

    GraphList(unsigned int input){
        nodeLength = input;    
/*
        for(int i = 0; i < nodeLength; i++){
            for(int j = 0; j < nodeLength; j++){
                unsigned int graph[i][j] = 0;
            }
        }
*/
    }
};

int main(){
       GraphList Sample(100);
}