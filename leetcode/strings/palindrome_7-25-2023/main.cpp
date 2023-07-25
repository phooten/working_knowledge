#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome( string s ) {
        short alpha_diff = (int)'a' - (int)'A';

        // remove all puntuations
        string s_ref;
        for( auto i = 0; i < s.size(); i++ )
        {
            if( ( s[i] >= 'a' && s[i] <= 'z' ) || 
                ( s[i] >= '0' && s[i] <= '9' ) )
            {
                s_ref += s[i];
            }
            else if( s[i] >= 'A' && s[i] <= 'Z' )
            {
                s_ref += (char)(s[i] + alpha_diff);
            }
        }


        // Special case
        int len = s_ref.size();
        if( len <= 1 )
        {
             return true;
        }

        for( auto curr = 0; curr < len / 2; curr++ )
        {
            if( s_ref[curr] != s_ref[len - 1 - curr] )
            {
                 return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution test;
    // string input = "race a car";
    // string input = "A man, a plan, a canal: Panama";
    string input = "0B";

    bool ans = test.isPalindrome( input );

    cout << ( ans ? "True" : "False" ) << endl;

    return 0;
}
