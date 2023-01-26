#ifndef GENERATE_H
#define GENERATE_H

#include <iostream>
#include <time.h>

#define DEFAULT_LENGTH 10
#define DEFAULT_MAX 100

class Generate{
public:
    Generate();
    ~Generate();

    int* Array(int length=DEFAULT_LENGTH, int max=DEFAULT_MAX);
    void PrintArray();

private:
    int* m_arrPtr;
    int m_arrayLength;

};

#endif // ~GENERATE_H