#include <iostream>
#include <time.h>

#define DEFAULT_LENGTH 10
#define DEFAULT_MAX 100

int* randomArray(int n=DEFAULT_LENGTH, int r=DEFAULT_MAX);
void printArray(int *ptr, int len=DEFAULT_LENGTH);
void printAddress(int *ptr);

int main(){
    int *inputPtr;
    
    printAddress(inputPtr);
    
    // printAddress(*inputPtr);
    inputPtr = randomArray();
    
    printAddress(inputPtr);
    // int *testing = new int[inputLen];
    // std::cout << "inputPtr: " << inputPtr << " testing: " << testing << "\n";

    std::cout << "\n";
    printArray(inputPtr);

    // clean up
    delete [] inputPtr;

    return 0;
}



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



void printArray(int *ptr, int len){

    for(int i = 0; i < len - 1; i++){
        std::cout << ptr[i] << ", ";
    }
    std::cout << ptr[len];
    printf("\n");

    return;
}

void printAddress(int* ptr){
    
    std::cout << ptr << "\n";

    return;
}