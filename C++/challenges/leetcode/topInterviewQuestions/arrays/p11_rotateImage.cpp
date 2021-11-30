
/*
    Date:       11-29-2021
    Status:     
    Source:     https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/

    Overview:
        You are given an n x n 2D matrix representing an image, rotate the image 
        by 90 degrees (clockwise).

        You have to rotate the image in-place, which means you have to modify 
        the input 2D matrix directly. DO NOT allocate another 2D matrix and do 
        the rotation.
        
*/

#include <iostream> 
#include <vector>
using namespace std;

void printVector(vector<vector<int> >& tmp);
 

class Solution {
public:
    /*
        First attempt
        beat 100 % of submissions :) Mistake?
    */

    vector<vector<int> > A(vector<vector<int> >& matrix) {
        int size = matrix[0].size() - 1;
        int rel_size = size;    // relative size
        int tmp;                
        int row = 0;            
        int start = 0;          // tracks smaller matrix inside bigger

        while(rel_size > 0){
            // Start with outside and rotate
            for(int col = start; col < rel_size + start; col++){
                
                // Rotates 4 points around the matrix
                tmp = matrix[row][col];
                matrix[row][col] = matrix[size - col][row];
                matrix[size - col][row] = matrix[size - row][size - col];
                matrix[size - row][size - col] = matrix[col][size - row];
                matrix[col][size - row] = tmp;
                
            }

            // adjusts starting positions
            row++;
            start++;
            rel_size -= 2;
        }

        return matrix;
    }

    vector<vector<int> > B(vector<vector<int> >& matrix) {

        return matrix;
    }
};


int main(){
    
    // int arr[3][3] = {{1,2,3},
    //                 {4,5,6},
    //                 {7,8,9}};
    int arr[4][4] = {{5,1,9,11},
                    {2,4,8,10},
                    {13,3,6,7},
                    {15,14,12,16}};
    // int arr[1][1] = {{1}};
    // int arr[2][2] = {{1,2},
    //                 {3,4}};
    vector<int> input;
    vector< vector<int> > vec;
    const int size = sizeof(arr) / sizeof(arr[0]);
    Solution Sol;

    for(int i = 0; i < size; i++){ 
        input.erase(input.begin(), input.end());
        for(int j = 0; j < size; j++){
            input.push_back(arr[i][j]);
        }
        vec.push_back(input); 
    }
    
    printf("Pre rotation\n");
    printVector(vec);
    printf("\n\n");

    vector<vector<int> > k;
    k = Sol.A(vec);    
    // k = Sol.B(vec1, vec2);    
    

    printf("Answer:\n");
    printVector(k);

    return 0;
}


void printVector(vector<vector<int> >& tmp){
    
    for(int i = 0; i < tmp.size(); i++){
        for(int j = 0; j < tmp[0].size(); j++){
            printf("%d, ", tmp[i][j]);
        }
        printf("\n");
    }
    return;
}