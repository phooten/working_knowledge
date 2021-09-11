/*
  FINISHED
  8-1-2021

  Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-class/problem
  sample input:

  15
  john
  carmack
  10

*/


#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student{
  private:
    int _age, _standard;
    string _ageS, _standardS;
    string _first_name, _last_name;
    string _output;

  public:
    void set_age(int age){                  _age = age;}
    void set_standard(int standard){        _standard = standard;}
    void set_first_name(string first_name){ _first_name = first_name;}
    void set_last_name(string last_name){   _last_name = last_name;}

    int get_age(){            return _age;}
    int get_standard(){       return _standard;}
    string get_first_name(){  return _first_name; }
    string get_last_name(){   return _last_name; }



    string to_string(){
      string _space = ", ";
      _ageS = std::to_string(_age);
      _standardS = std::to_string(_standard);

      _output = _ageS + _space + _first_name + _space + _last_name + _space + _standardS + "\n";

      return _output;
    }

};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
