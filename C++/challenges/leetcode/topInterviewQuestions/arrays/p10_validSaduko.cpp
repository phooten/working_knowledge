
/*
    Date:       11-28-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/

    Overview:
        Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need 
        to be validated according to the following rules:

        1.  Each row must contain the digits 1-9 without repetition.
        2.  Each column must contain the digits 1-9 without repetition.
        3.  Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 
            1-9 without repetition.
        
        Note:
            A Sudoku board (partially filled) could be valid but is not necessarily solvable.
            Only the filled cells need to be validated according to the mentioned rules.
        
*/

#include <iostream> 
#include <vector>
#include <set>
using namespace std;

void printVector(vector<int>& tmp);
 

class Solution {
public:
    /*
        First attempt
        beat 99.07 % of submissions :)
    */
    bool A(vector<vector<char> >& board) {
        set<int> valid_numbers;
        set<int> curr_numbers;

        for(int i = 1; i < 10; i++){
            valid_numbers.insert(i);
        }

        // Row Check
        for(int i = 0; i < 9; i++){
            curr_numbers = valid_numbers;

            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && curr_numbers.erase(board[i][j])){
                    return false;
                }
            }
        }
        
        // Column Check
        for(int j = 0; j < 9; j++){
            curr_numbers = valid_numbers;

            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.' && curr_numbers.erase(board[i][j])){
                    return false;
                }
            }
        }
        
        // 3x3 Check

        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                curr_numbers = valid_numbers;

                // Go through 3x3
                for(int i = x * 3; i < (x*3)+3; i++){
                    for(int j = y * 3; j < (y*3)+3; j++){
                        if(board[i][j] != '.' && curr_numbers.erase(board[i][j])){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    // vector<int> B(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> tmp;

    //     return tmp;
    // }

};


int main(){
    
    // char arr[9][9] = { {'5','3','.','.','7','.','.','.','.'}
    //                     ,{'6','.','.','1','9','5','.','.','.'}
    //                     ,{'.','9','8','.','.','.','.','6','.'}
    //                     ,{'8','.','.','.','6','.','.','.','3'}
    //                     ,{'4','.','.','8','.','3','.','.','1'}
    //                     ,{'7','.','.','.','2','.','.','.','6'}
    //                     ,{'.','6','.','.','.','.','2','8','.'}
    //                     ,{'.','.','.','4','1','9','.','.','5'}
    //                     ,{'.','.','.','.','8','.','.','7','9'}};

    char arr[9][9] = {{'8','3','.','.','7','.','.','.','.'},
                        {'6','.','.','1','9','5','.','.','.'},
                        {'.','9','8','.','.','.','.','6','.'},
                        {'8','.','.','.','6','.','.','.','3'},
                        {'4','.','.','8','.','3','.','.','1'},
                        {'7','.','.','.','2','.','.','.','6'},
                        {'.','6','.','.','.','.','2','8','.'},
                        {'.','.','.','4','1','9','.','.','5'},
                        {'.','.','.','.','8','.','.','7','9'}};

    // int arr[1] = {0};
    vector<char> input;
    vector<vector<char> > vec;
    const int size = sizeof(arr) / sizeof(arr[0]);
    
    Solution Sol;

    for(int i = 0; i < 9; i++){ 
        for(int j = 0; j < 9; j++){
            input.push_back(arr[i][j]);
        }
        vec.push_back(input);
    }
    
    // printf("Pre removal\n");
    // printVector(vec);
    // printf("\n\n");

    bool k;
    k = Sol.A(vec);    
    // k = Sol.B(vec1, vec2);    
    

    printf("Answer:\n");
    printf("%s", k ? "true" : "false");
    

    return 0;
}


void printVector(vector<int>& tmp){
    
    for(int i = 0; i < tmp.size(); i++){
        printf("%d, ", tmp[i]);
    }
    return;
}