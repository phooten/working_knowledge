#include <iostream>
#include <time.h>

#define DEFAULT_LENGTH 100
#define DEFAULT_MAX 10000

int randomArray(int **arr, int n=DEFAULT_LENGTH, int r=DEFAULT_MAX);
void printArray(int *ptr, int len);
void printAddress(int *ptr);

int main(){
    int *inputPtr;
    
    printAddress(inputPtr);
    int inputLen = randomArray(&inputPtr, 10);
    printAddress(inputPtr);
    
    // int *testing = new int[inputLen];
    // std::cout << "inputPtr: " << inputPtr << " testing: " << testing << "\n";

    std::cout << "\n";
    printArray(inputPtr, inputLen);

    // clean up
    delete [] inputPtr;

    return 0;
}



int randomArray(int **arr, int n, int r){
    int randNum;
    printAddress(*arr);
    *arr = new int[n];      // Gets deleted in main 
    // printAddress(*arr);
    
    // Fills array with random numbers
    for(int i = 0; i < n; i++){
        randNum = rand() % r;
        *arr[i] = randNum; 
    }

    printArray(*arr, n);

    // delete [] arr;

    return n;
}



void printArray(int *ptr, int len){

    for(int i = 0; i < len; i++){
        std::cout << ptr[i] << ", ";
    }
    printf("\n");

    return;
}

void printAddress(int* ptr){
    
    std::cout << ptr << "\n";

    return;
}