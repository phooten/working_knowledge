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
#include "Array.h"
#include "Vector.h"

// Vector 3 struct
struct Vector3{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    Vector3() {}
    
    Vector3(float scalar) 
        : x(scalar), y(scalar), z(scalar) {}
    
    Vector3(float x, float y, float z) 
        : x(x), y(y), z(z) {}
    
    Vector3(const Vector3& other) 
        : x(other.x), y(other.y), z(other.z) {
        std::cout << "Copy\n";
    }

    Vector3(const Vector3&& other) 
        : x(other.x), y(other.y), z(other.z) {
        std::cout << "Move\n";
    }

    ~Vector3() {
        std::cout << "Destroy\n";
    }


    // Vector3& operator=(const Vector3& other){
    //     std::cout << "Copy\n";
    //     x = other.x;
    //     y = other.y;
    //     z = other.z;
    //     return *this;
    // }
    
    // Vector3& operator=(const Vector3&& other){
    //     std::cout << "Mover\n";
    //     x = other.x;
    //     y = other.y;
    //     z = other.z;
    //     return *this;
    // }
};


// Print out vector
template<typename T>
void PrintVector(const Vector<T>& vector){
    for(size_t i = 0; i < vector.Size(); i++){
        std::cout << vector[i] << std::endl;
    }

    std::cout << "-----------------------------\n";
}

// SPECIAL: Print out vector
template<>
void PrintVector(const Vector<Vector3>& vector){
    for(size_t i = 0; i < vector.Size(); i++){
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    }

    std::cout << "-----------------------------\n";
}



int main(){
    // Vector<std::string> vector;
    // vector.PushBack("koffee");    
    // vector.PushBack("tastes");    
    // vector.PushBack("good"); 

    Vector<Vector3> vector;
    vector.PushBack(Vector3(1.0f));
    vector.PushBack(Vector3(2, 3, 4));
    vector.PushBack(Vector3());

    PrintVector(vector);

    return 0;
}

