/*
    Date:           11-10-2021
    File:           main.cpp
    Version:        1.0
    
    Contributers:   Parker Hooten

    Purpose:        To sort a given set of numbers using the insert sort method. 
                    In doing so, I will learn about how this algorithm works and
                    will be able to compare it's efficiency to other algorithms
                    when I come in contact with them. 


    Questions to think about:
        1. What is the time/space complexity?
        2. How does it compare to bubble sort and selection sort?
*/

#include <iostream>
#include <time.h>

// Default Array Values 
#define DEFAULT_LENGTH 10
#define DEFAULT_MAX 100

// Declarations
void bubble(int *arr, int size);
int* randomArray(int n=DEFAULT_LENGTH, int r=DEFAULT_MAX);
void printArray(int *ptr, int len=DEFAULT_LENGTH);
void printAddress(int *ptr);


int main(){
    // Variables
    int size = 20;                      // Size of random array
    int *inputPtr;                      // Array pointer

    inputPtr = randomArray(size);       // Gets array

    bubble(inputPtr, size);         // sorts array

    std::cout << "\nSorted Array: \n";
    printArray(inputPtr, size);
     
    // clean up
    delete [] inputPtr;                 // 'new' was used in 'randomArray()'

    return 0;
}


/*
    purpose:    Sort sort an array 

    arguments:  arr -  pointer to the random array created in main()
                size - size of random array created in main()
*/

void bubble(int* arr, int size){
    int tmp;
    int minPos;

    for(int i = 0; i < size; i++){
        
        minPos = i;
        for(int j = i; j < size; j++){
            if(arr[j] < arr[minPos]){
                minPos = j;
            }
        }

        tmp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = tmp;
    }


    return;
}


/*
    purpose:    create a random array of size n with max value of r

    arguments:  n - Number of elements in the array (10 is default value)
                r - Max size of random values (100 is default value)

    return:     int* -  pointer to the array just created. this pointer needs
                        to be deleted, as this function doesn't do so. 
*/
int* randomArray(int n, int r){
    // Variables
    int randNum;
    int *arr = new int[n];      // Gets deleted in main 
    

    // Fills array with random numbers
    for(int i = 0; i < n; i++){
        randNum = rand() % r;
        arr[i] = randNum; 
    }
    
    std::cout << "Original Array:\n";
    printArray(arr, n);


    return arr;
}


/*
    purpose:    prints out values in an array

    arguments:  ptr -   pointer to the first element of an array
                len -   length of the arry input with 'ptr'
*/
void printArray(int *ptr, int len){

    for(int i = 0; i < len - 1; i++){
        std::cout << ptr[i] << ", ";
    }
    std::cout << ptr[len - 1];
    printf("\n");

    return;
}


/*
    purpose:    prints the address of a pointer
*/
void printAddress(int* input){
    
    std::cout << input << "\n";

    return;
}


