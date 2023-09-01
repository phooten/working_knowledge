#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>
#include<cstring>
#include<locale>
#include<cmath>

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
        char last = ' ';

        // Instructions:
        //  1. Read in any leading white space
        //  2. Check if next character is - or + 
        //  3. Read in all digits until non-digit. Ignore anything after
        //  4. Read in leading 0's
        //  5. If out of range, clamp to an integer
        bool leading_space = true;
        bool leading_sign = true;
        bool positive = true;
        bool digits = true;
        string tmp = "";

        for( int curr = 0; curr < s.size(); curr++ )
        {
            // Checks for the space
            if( s[curr] == ' ' && leading_space == true )
            {
                //cout << "Space. Continuing.\n" << endl;
                continue;
            }
            else
            {
                leading_space = false;

                // Checks for the sign
                if( leading_sign == true )
                {
                    leading_sign = false;
                    if( s[curr] == '-' )
                    {
                        cout << "Negative." << endl;
                        positive = false;
                        continue;
                    }
                    else if( s[curr] == '+' )
                    {
                        cout << "Positive." << endl;
                        continue;
                    }
                    else
                    {
                        cout << "No sign. Assuming Positive." << endl;
                    }

                }

                // Digits
                if( digits == true )
                {
                    if( s[curr] >= '0' && s[curr] <= '9' )
                    {
                        tmp += s[curr];
                    }
                    else
                    {
                        digits = false;
                    }
                }
                else
                {
                    cout << "end of parsing." << endl;
                    break;
                }

                // Prints out the remaining letters
                cout << endl << "New Tmp: " << tmp << endl;
            }
        }

        for( int i = 0; i < tmp.size(); i++ )
        {
            int num = pow( 10, tmp.size() - i - 1 ) * ( tmp[i] - '0' );
            cout << "Number: " << num << endl;
            cout << "ans_doub = " << ans_doub << endl;
            ans_doub += num;
        }

        if( ( ans_doub > pow(2, 31) - 1 ) && ( positive == true ) )
        {
            ans_doub = pow(2, 31) - 1;
        }
        else if( ( ans_doub > pow( 2, 31 ) ) && ( positive == false ) )
        {
            ans_doub = pow(2, 31);
        }

        // Make correct sign
        if( ! positive )
        {
            ans_doub *= -1;
        }

        ans = (int)ans_doub;

        cout << endl << "Tmp: " << tmp << endl;

        return ans;
    }
};

int main()
{
    string s1 = "";
    s1 = "42";
    s1 = "   -42";
    s1 = "4193 with words";
    s1 = "-91283472332";

    Solution test;
    int ans = test.myAtoi( s1 );

    cout << endl << "answer: " << ans << endl << endl << endl;
}
