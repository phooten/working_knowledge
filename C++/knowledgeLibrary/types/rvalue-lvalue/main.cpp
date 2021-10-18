#include <iostream>
#include <string>

int GetValue_A(){

    return 10;
}

int& GetValue_B(){              // This is an lvalue reference
    static int value = 10;
    return value;
}

void SetValue_A(int value){

}

void SetValue_B(int& value){
    
}

void PrintName_A(std::string& name){
    std::cout << "[lvalue]: " << name << std::endl;
}

void PrintName_B(const std::string& name){
    std::cout << name << std::endl;
}

void PrintName_C(std::string&& name){
    std::cout << "[rvalue]: " << name << std::endl;
}

int main(){
    // EXAMPLE 1
    int i = GetValue_A();   // GetValue_A returns an "rvalue"
    //GetValue_A() = 5      // This will not work because GetValue_A() is an rvalue
    GetValue_B() = 5;       // GetValue_B is returning an address, so we can assign it


    // EXAMPLE 2
    int j = 10;
    SetValue_A(i);
    SetValue_A(10);
    SetValue_B(i);
    // SetValue_B(10);         // This error is cause bc we can't take reference from a rvalue


    // EXAMPLE 3
    //  Everything on the left: lValue, everything on the right: rvalue
    std::string firstName = "Charge";
    std::string lastName = "Point";
    std::string fullName = firstName + lastName;

    // EXAMPLE 4
    PrintName_A(fullName);                   // works bc fullname is an lvalue
    // PrintName_A(firstName + lastName);    // won't work bc it's an rvalue
    PrintName_B(fullName);                   
    PrintName_B(firstName + lastName);       // works bc the argument takes in as const reference
    //PrintName_C(fullName);                 // won't work bc PrintName_C has 2 &'s. This means we can only take in temp values: rvalues. It's the opposite of PrintName_A 
    PrintName_C(firstName + lastName);       // works bc argument is temporary

    return 0;
}