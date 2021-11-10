#include "Generate.h"

int main(){
    Generate Generating;
    
    int length = 12;
    int* arr = Generating.Array(length);
    Generating.PrintArray();

    return 0;
}