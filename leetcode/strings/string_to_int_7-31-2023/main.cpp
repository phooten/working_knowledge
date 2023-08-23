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

        if ( s.size() == 0 )
        {
            return 0;
        }

        // Variables
        double ans_doub = 0.0;
        int ans = 0;
        int int_offset = 48;    // ascii 0 starts at 48
        bool neg = false;
        bool num_start = false;
        string tmp = "";
        char last = ' ';

        for( int curr = 0; curr < s.size(); curr++ )
        {
            cout << "curr: " << s[curr] << endl;
            if( num_start && s[curr] != ' ' )
            {
                cout << "line 32" << endl;
                if( s[curr] < '0' || s[curr] > '9' )
                {
                    cout << "Not a number" << endl;
                    break;
                }

                if( s[curr] == '-' )
                {
                    neg = true;
                    cout << "-" << endl;
                }
                else if( s[curr] == '+' )
                {
                    neg = false;
                    cout << "+" << endl;
                }

                tmp += s[curr];
                cout << tmp << endl;

            }

            if( s[curr] == ' ' )
            {
                cout << "Space" << endl;
                continue;
            }


            if( s[curr] >= '0' && s[curr] <= '9' )
            {
                num_start = true;
                cout << "num = true" << endl;
            }
            curr++;
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
