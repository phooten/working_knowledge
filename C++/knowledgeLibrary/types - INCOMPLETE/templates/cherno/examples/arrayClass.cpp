/*
    Date:           10-3-2021
    File:           arrayClass.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten
                    The Cherno (see Credits)

    Purpose:        To show how a template might be used in a class setting. This
                    code is meant to be used as a reference and a learning tool.
                    Not for any other purpose. 

    Credits:
        The Cherno:
            -   This code was written by this youtube channel. All I have done is
                broken up different sections into examples to be refrenced. Video
                Link:  https://www.youtube.com/watch?v=I-hZkUa9mIs
*/

#include <iostream>
#include <string>


template<typename T, int N> // N = number
class Array{
    public:
        int GetSize() const { return N; }
    private:
        T m_Array[N];
};

int main(){
    Array<int, 5> array;

    return 0;
}

