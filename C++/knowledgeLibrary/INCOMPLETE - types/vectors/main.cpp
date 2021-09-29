#include<iostream>
#include<vector>

int main(){
    std::vector<int> v1 = {1, 2, 3, 4};    
    std::cout << v1[2] << " " << v1[4] << std::endl;
    std::cout << v1.front() << " " << v1.back() << std::endl;

    // size -       how much vector is ACTUALLY holding
    // capacity -   how much the vector CAN hold
    std::cout << v1.size() << " " << v1.capacity() << std::endl;
    
    // Here we push back the vector 5 times, so 9 total elements in v1. At 9
    //  we run out of space so the capacity doubles to 16. When we first declared
    //  the vector, the capactiy was 8
    for(int i = 0; i < 5; i++){
        v1.push_back(9);
    };
    std::cout << v1.size() << " " << v1.capacity() << std::endl;
    

    // if we move back down to 1 element, the capacity stays the same
    for(int i = 0; i < 8; i++){
        v1.pop_back();
    };
    std::cout << v1.size() << " " << v1.capacity() << std::endl;

    // because of the above, we adjust the capacity
    v1.shrink_to_fit();
    std::cout << v1.size() << " " << v1.capacity() << std::endl;

    /*
    v1.insert(v1.begin() + 4, 5);
    std::cout << v1.size() << " " << v1.capacity() << " " <<  v1[0] << " "  << v1[1] << " " << v1[4] << " " << std::endl;
    // std::cout << v1.size() << " " << v1.capacity() << std::endl;

    v1.erase(v1.begin());

    */
    
    // Skip, just adding elements here 
    for(int i = 0; i < 5; i++){
        v1.push_back(i + 2);
    };

   // iterating through the vector
   // EX 1:
    for(auto itr = v1.begin(); itr != v1.end(); ++itr){
        std::cout << *itr << std::endl;
    }


    // weird thought of "let me break this code"
    int limit = v1.size();
    int count = 0;
    for(auto itr = v1.begin(); itr != v1.end(); ++itr){
        std::cout << *itr << std::endl;
        if(count == limit / 2){
            v1.insert(itr, 69);
            std::cout << "HERE" << std::endl;
        }
        count++;
    }

    return 0;
}