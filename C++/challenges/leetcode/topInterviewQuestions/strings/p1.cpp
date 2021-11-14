/*
    Date:       11-6-2021
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
    Overview:
        
*/

#include <iostream> 
#include <vector>
#include <string>
using namespace std;


/*
    First attempt:


*/
class A{
public:
    A(){}

    string reverseString(string input){
        int len = input.length();
        string ans;
        
        // ans[in_len + 1] = '\n';
        for(int i = 0; i <= len; i++){
            cout << "ans[" << i << "] = " << input[len - i] << "\n";
            ans.append(" ");
            ans[i] = input[len - i];
        }


        return ans;
    }

};

/*
    Second attempt:
        only worked for 3/477 cases
*/
class B{
public:
    B(){}

    void reverseString(vector<char>& s){
        int len = s.size();
        vector<char> ans;
        
        cout << "len: " << len << "\n";
        // ans[in_len + 1] = '\n';
        for(int i = 1; i <= len; i++){
            cout << "ans[" << i << "] = " << s[len - i] << "\n";
            ans.push_back(s[len - i]);
        }

        for(int i = 0; i <= len; i++){
            s[i] = ans[i];
        }

        return;
    }
};


/*
    Third attempt:
        Looked at the solution for a better space/time complexity

        Note: 
            Changin left/right += 1 to s[left/right++] saved 8 ms

*/
class C{
public:
    C(){}
    
    void helper(vector<char>& s, int left, int right){
        if(left >= right)
            return;
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        right -= 1;
        left += 1;
        helper(s, left, right);
    }

    void reverseString(vector<char>& s){
        helper(s, 0, s.size() - 1);

        return;
    }

};


int main(){

    // Set up
    string input, output;
    
    input = "hello";
    // input = "Hannah";
    
    vector<char> v_input, v_output;
    for(int i = 0; i < input.length(); i++){
        v_input.push_back(input[i]);
    }
        

    // A A_solution;
    // output = A_solution.reverseString(input);
    // cout << "Answer: " << output << "\n";//<< length: " << output.length() << "\n";

    // B B_solution;
    // B_solution.reverseString(v_input);

    C C_solution;
    C_solution.reverseString(v_input);


    return 0;
}
