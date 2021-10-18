/*
    Date:           10-3-2021
    File:           arrayClass.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten
                    The Cherno (see Credits)

    Purpose:        To show the basic use case of a template. In this scenario, 
                    we see how the template can be called explicitly or implicitly. 
                    This code is meant to be used as a reference and a learning tool.
                    Not for any other purpose.  

    Credits:
        The Cherno:
            -   This code was written by this youtube channel. All I have done is
                broken up different sections into examples to be refrenced. Video
                Link:  https://www.youtube.com/watch?v=I-hZkUa9mIs
*/

#include <iostream>
#include <string>


template<typename T>
void Print(T value){
    std::cout << value << std::endl;
}


int main(){
    // Getting the types implicitly
    Print(5);
    Print("Hello! - Implicit");
    Print(5.5f);

    // Getting the types explicitly
    Print<int>(10);
    Print<std::string>("Hello! - Explicit");
    Print<float>(10.99f);


    return 0;
}