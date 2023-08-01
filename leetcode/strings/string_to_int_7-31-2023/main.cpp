#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>
#include<cstring>
#include<locale>

using namespace std;

class Solution {
public:
    int myAtoi( string s ) {
        // Variables
        double ans_doub = 0.0;
        int ans = 0;
        int int_offset = 48;    // ascii 0 starts at 48
        bool neg = false;
        string tmp = "";

        // Find blank until first -/+
        // find -/+ until first #
        // find # until first A/Z


        for( int curr = 0; curr < s.size(); curr++ )
        {
            if( s[curr] == ' ' )
            {
                continue;
            }
            else if( s[curr] == '-' )
            {
                neg = true;
            }
            else if( s[curr] >= '0' && s[curr] <= '9' )
            {
                tmp += s[curr];
            }
            else
            {
                cout << "Issue: " << s[curr] << endl;
            }
        }

        for( int i = 0; i < tmp.size(); i++ )
        {
            double x = (int)tmp[tmp.size() - i - 1] - int_offset;
            ans_doub += ( x * ( pow(10, i) ) );
        }
        cout << "ans_doub: " << ans_doub << endl;

        if( neg )
        {
            ans_doub *= -1;
        }
        else
        {
            
        }
        ans = (int)ans_doub;

        cout << endl << "Tmp: " << tmp << endl;

        return ans;
    }
};

int main()
{
    string s1 = "   -42";

    Solution test;
    int ans = test.myAtoi( s1 );

    cout << endl << endl << "answer: " << ans << endl << endl << endl;
}
