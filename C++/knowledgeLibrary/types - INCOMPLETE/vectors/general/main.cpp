/*
    Date:           9-29-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To practice, provide examples, and learn about the vectors
                    data type in c++. There is no real purpose or functionality


    sample input:
                    Random generator written in main(). 

    Questions to think about:
        1. What is bubble sortings's time/space complexity?

*/
#include<iostream>
#include<vector>


void learningTwt();     // Learning - "Tec with Tim" (youtube)
void learningCherno();  // Learning - "The Cherno" (youtube)
void scratch();


int main(){
    
    // scratch();
    learningCherno();
    // learningTwt();
    

    return 0;
}



/*
    Purpose:    to provide an area for testing and experimentation if I am to 
                come back to this file at a later date. Nothing in this function
                should be assumed to be saved.  
*/
void scratch(){

    return;
}



/*
    Purpose:    to show examples of what one can do with vectors. These followed
                examples provided by "The Cherno" on youtube. 
*/
void learningCherno(){
    // Variables
    int length = 10;
    std::vector<int> vertices;
    

    for(int i = 0; i < length; i++)
        vertices.push_back(i);

    // Another way to cycle through the vector
    // This does copy "int v" which isn't space efficient, so an "&"
    // needs to be added in front of the "v" for it to pass as reference
    //
    //      for(int v : vertices)
    //          std::cout << v << std:: endl;
    //
    for(int& v : vertices)
        std::cout << v << std:: endl;
    return;
}



/*
    Purpose:    to show examples of what one can do with vectors. These followed
                examples provided by "tecwithtim" on youtube. 
*/
void learningTwt(){
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

    return;
}