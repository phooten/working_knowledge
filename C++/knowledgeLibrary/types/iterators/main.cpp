#include<iostream>
#include<vector>

int main(){
    std::vector<int> values = {1, 2, 3, 4, 5 };

    for(int i = 0; i < values.size(); i++){
        std::cout << values[i] << std::endl; 
    }

    
    for(int i = 0; i < values.size(); i++){
        std::cout << values[i] << std::endl; 
    }
    
    return 0;
}