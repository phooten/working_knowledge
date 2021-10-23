/*
    Date:           9-19-2021
    File:           main.cpp
    Version:        1.0
    Status:         COMPLETE
    Contributer:    koffee-byte 

    Purpose:        To sort a given set of numbers using the bubble sort method. 
                    In doing so, we will learn about how this algorithm works and
                    will be able to compare it's efficiency to other algorithms
                    when we come in contact with them.  

    Questions to think about:
        1. What is bubble sortings's time/space complexity?

*/

#include <cstdlib>
#include<iostream>
using namespace std;


// Variable declarations
void bubbleSort(int* ptr, unsigned int len);
void printArr(int* ptr, unsigned int len);

int main(){
    // Variables
    unsigned int length = 10;
    unsigned int rNum;
    int arr[length];

    // Creates a random array of numbers
    for(unsigned int i = 0; i < length; i++){
        rNum = rand() % 100;
        arr[i] = rNum;
    }

    // Prints out unsorted array 
    printArr(&arr[0], length);

    // Sorts the array
    bubbleSort(&arr[0], length);
    
    // Prints out sorted array
    printArr(&arr[0], length);

    return 0;
}

/*
    Purpose:   to sort an array of numbers in accending order
    
    Arguments: *ptr:  pointer to the array arr[]
               len:   length of arr[]
*/
void bubbleSort(int* ptr, unsigned int len){
    // Variables
    int curr, tmp;
    unsigned int i;

    // Sorts the array
    for(i = 0; i < len; i++){
        for(curr = 0; curr < len - i -1; curr++){
            if(ptr[curr] > ptr[curr + 1]){
                tmp = ptr[curr];
                ptr[curr] = ptr[curr + 1];
                ptr[curr + 1] = tmp;    
            }
        }
    }

    return;
}

/*
    Purpose:   to print out an array in order
    
    Arguments: *ptr:  pointer to the array arr[]
               len:   length of arr[]
*/
void printArr(int* ptr, unsigned int len){
    unsigned int i;
    
    for(i = 0; i < len - 1; i++){
        cout << ptr[i] << ", ";
    }
    cout << ptr[i] << endl;

    return;
}
