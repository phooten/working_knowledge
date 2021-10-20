/*
    Problem Statement:

*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int byte = 80;
    int place = 2;
    int bit = 00000001;
    int bits[8];
    
    for(int i = 0; i < 8; i++){
        //place ^= i;
        place = pow(2, i);
        bits[i] = (byte & bit) / place;
        bit = bit << 1;
        printf("bit: %d place: %d\n", bits[i], place);
    }
    
    
    return 0;
}
