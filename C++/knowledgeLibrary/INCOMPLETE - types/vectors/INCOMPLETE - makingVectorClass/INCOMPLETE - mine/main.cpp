#include"vector.h"
#include<iostream>
#include<string>
using namespace std;



void printer(string str, int var);

int main(){
    vector a;

    a.print();
    printer("capacity: ", a.capacity());
    printer("size: ", a.size());
    a.push_back(1);
    a.print();
    
    printer("capacity: ", a.capacity());
    printer("size: ", a.size());

    return 0;
}

void printer(string str, int var){
    cout << str << ": "<< var << endl;
    
    return;
}
