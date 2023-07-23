#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku( vector <vector <char> >& board) {
        set<int> valid_numbers;
        set<int> curr_numbers;

        // Valid numbers are 1 to 9. 
        for(int i = 1; i <= 9; i++){
            valid_numbers.insert(i);
        }

        // Row Check
        for(int row = 0; row <= 8; row++){
            curr_numbers = valid_numbers;

            for(int col = 0; col <= 8; col++){
                if(board[row][col] != '.' && curr_numbers.erase( (int)board[row][col])){
                    return false;
                }
            }
        }
        
        // Column Check
        for(int col = 0; col < 9; col++){
            curr_numbers = valid_numbers;

            for(int row = 0; row < 9; row++){
                if(board[row][col] != '.' && curr_numbers.erase( (int)board[row][col])){
                    return false;
                }
            }
        }
        
        // 3x3 Check
        // there are 9 blocks. 1,1 1,2 1,3 2,1 2,2 2,3, etc
        for( int row = 0; row <= 2; row++ ){
            for( int col = 0; col <= 2; col++ ){
                curr_numbers = valid_numbers;

                // Go through 3x3
                for( int i = row * 3; i < ( row * 3) + 3; i++ )
                {
                    for(int j = col * 3; j < ( col * 3 ) + 3; j++)
                    {
                        bool result = false;
                        if( curr_numbers.erase( (int)board[i][j] ) > 0 )
                        {
                            result = true;
                        }

                        if( board[i][j] != '.' && result == false ){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


int main()
{
    Solution test;
//    char arr[9][9] = { { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
//                       { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
//                       { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
//                       { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
//                       { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
//                       { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
//                       { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
//                       { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
//                       { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

    char arr[9][9] = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                       { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                       { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                       { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                       { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                       { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                       { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                       { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                       { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };


    
    int row_len = sizeof(arr) / sizeof(arr[0]);
    int col_len = sizeof(arr[0]) / sizeof(arr[0][0]);
    cout << endl << "row: " << row_len << "\ncol: " << col_len << endl;
    vector< vector<char> > vect;

    for( int x = 0; x < row_len; x++ )
    {
        vect.push_back( vector<char>() );
        for( int y = 0; y < col_len; y++ )
        {
            vect[x].push_back( arr[x][y] );
            //cout << arr[x][y] << endl;
        }
    }


    cout << endl << endl << "answer: " << test.isValidSudoku(vect) << endl;
}
