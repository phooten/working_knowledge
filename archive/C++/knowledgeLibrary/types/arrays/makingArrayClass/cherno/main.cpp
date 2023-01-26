/*
    Date:           10-3-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten
                    The Cherno (see Credits)

    Purpose:        To show how a the standard c++ library makes arrays, or at
                    least give an idea of how they are made. This will involve
                    the use of templates. 

    Credits:
        The Cherno:
            -   This code was written by this youtube channel. It was written
                almost completely based on the following link, with the purposes
                of learning about arrays, and better programming practice.
                Link:  https://www.youtube.com/watch?v=TzB5ZeKQIHM
*/

#include<iostream>
#include<array>
#include<cstring>   // used to allow "memset()" usage
#include "Array.h"


int main(){
    // Variables
    int size = 5;
    Array<int, 5> i_data;
    Array<std::string, 2> s_data;
    

    // Setting memory
    memset(i_data.Data(), 0, i_data.Size() * sizeof(int));
    i_data[1] = 5;
    i_data[4] = 8;
    s_data[0] = "index 0";
    s_data[1] = "index 1";
    


    // Read only version of Array
    const auto& i_dataReadOnly = i_data;
    const auto& s_dataReadOnly = s_data;


    // Printing out contents of arrays
    for(size_t i = 0; i < i_data.Size(); i++){
        // dataReadOnly[i] = 2;       // this won't work because i_dataReadOnly is const, so it's read only
        // i_data[i] = 42;
        std::cout << i_data[i] << std::endl;
    }

    for(size_t j = 0; j < s_data.Size(); j++){
        std::cout << s_data[j] << std::endl;
    }
  
    return 0;
}


