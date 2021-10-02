#ifndef VECTOR_H
#define VECTOR_H

#define _DEBUG true
#if _DEBUG == true
    #define debug(x) x
#else 
    #define debug(x) //

#endif

#include<string>
#include<iostream>
#include<cmath>

struct vector{
public:

    // debug vars:
    //-----------
    
    //-----------

    // Goal is to input "int, short, string, etc" into this vector
    // vector operator< (typedef choose) const;
    
    vector();
    vector(int size);
    ~vector();

    bool upSize();
    bool downSize();
    bool push_back(int value);
    // void erase();
    // void insert();
    int front();
    int* frontPosition();
    int back();
    int*backPosition();
    int size();
    int capacity();
    void print();

private:
    const double M_INTMAX = pow(2, 29);
    int m_capacity;
    int m_size;
    int* vectorPtr;




};

#endif // ~VECTOR_H