/*
    Date:           10-3-2021
    File:           arrayClass.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten
                    The Cherno (see Credits)

    Purpose:        To show what the template is doing. This is how code might
                    be written with a template, and what code is actually doing
                    assuming that a generic template has be called with 3 
                    different types. This code is meant to be used as a 
                    reference and a learning tool. Not for any other purpose.  

    Credits:
        The Cherno:
            -   This code was written by this youtube channel. All I have done is
                broken up different sections into examples to be refrenced. Video
                Link:  https://www.youtube.com/watch?v=I-hZkUa9mIs
*/


#include <iostream>
#include <string>

void Print( int value){
    std::cout << value << std::endl;
}

void Print(std::string value){
    std::cout << value << std::endl;
}

void Print(float value){
    std::cout << value << std::endl;
}



int main(){
    Print(5);
    Print("Hello!");
    Print(5.0f);


    return 0;
}