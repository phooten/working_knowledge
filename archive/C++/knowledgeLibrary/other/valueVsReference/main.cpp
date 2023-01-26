/*

Pass by: 
    value:      means you are making a copy in memory of the actual parameter's 
                value that is passed in, a copy of the contents of the actual 
                parameter. Use pass by value when when you are only "using" the 
                parameter for some computation, not changing it for the client program. 
       
    reference:  (aka: pass by address) a copy of the address of the actual 
                parameter is stored. Use pass by reference when you are changing 
                the parameter passed in by the client program. 

    support:
        -   https://courses.washington.edu/css342/zander/css332/passby.html
*/

#include <iostream>
using namespace std;

void swapThemByVal(int num1, int num2);
void swapThemByRef(int& num1, int& num2);

int main() {
    int i = 10;
    int j = 20;
    
    cout << "original\ti: " << i << "  j: " << j << endl;
    
    swapThemByVal(i, j);
    cout << "by value\ti: " << i << "  j: " << j << endl;
    swapThemByRef(i, j);
    cout << "by refrence\ti: " << i << "  j: " << j << endl;
}

void swapThemByVal(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void swapThemByRef(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}



