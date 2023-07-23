#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int reverseInt( int i )
    {
        int ans = 0;

        bool neg = false;
        i < 0 ? neg = true : neg = false;

        while( i < 

        cout << "ans: " << neg;

        return ans;
    }

    // Doesnt work for -2147483648
    int wrong_reverseInt(int i) 
    {
        int ans = 0;
        bool neg = false;
        char tmp = ' ';
        if(i < 0)
        {
            neg = true;
            i *= -1;
        }

        // converts to a 
        string tmp_s = to_string(i);
        if( tmp_s.size() >= 33 )
        {
            return 0;
        }
        for( int curr = 0; curr < tmp_s.size()/2; curr++ )
        {
            tmp = tmp_s[curr];
            tmp_s[curr] = tmp_s[tmp_s.size() - curr - 1];
            tmp_s[tmp_s.size() - curr - 1] = tmp;
        }

        cout << tmp_s;
        ans = stoi(tmp_s);
        if( neg == true )
        {
            ans *= -1;
        }
        return ans;
    }
};

int main()
{
    Solution test;
    cout << endl << endl;

    int input = -321;
    int ans = test.reverseInt( input );

    cout << endl << endl << "answer: " << ans << endl;
}
