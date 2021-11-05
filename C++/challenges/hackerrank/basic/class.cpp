/*
    Date:           8-1-2021
    File:           class.cpp
    Version:        1.0
    Status:         COMPLETE
    
    Contributers:   Parker Hooten

    Purpose:        To learn about classes in C++ and complete the Hacker Rank 
                    problem statement:  https://www.hackerrank.com/challenges/c-tutorial-class/problem

*/

#include <iostream>
#include <sstream>
using namespace std;

/*
    Purpose:
      Store data about a student and be able to manipulate this data. 
*/
class Student{
  private:
    int _age, _standard;
    string _ageS, _standardS;
    string _first_name, _last_name;
    string _output;

  public:
    // Setters
    void set_age(int age){                  _age = age;}
    void set_standard(int standard){        _standard = standard;}
    void set_first_name(string first_name){ _first_name = first_name;}
    void set_last_name(string last_name){   _last_name = last_name;}

    // Getters
    int get_age(){            return _age;}
    int get_standard(){       return _standard;}
    string get_first_name(){  return _first_name; }
    string get_last_name(){   return _last_name; }

    // Outputs class contents into a string
    string to_string(){
      string _space = ", ";
      _ageS = std::to_string(_age);
      _standardS = std::to_string(_standard);

      _output = _ageS + _space + _first_name + _space + _last_name + _space + _standardS + "\n";

      return _output;
    }

};

int main() {
    // Variables
    int age, standard;
    string first_name, last_name;

    // Input from user
    cin >> age >> first_name >> last_name >> standard;

    // Initializing class
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    // printing out class
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
