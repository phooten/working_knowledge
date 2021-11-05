#include <iostream> 
#include <vector>
using namespace std;


void printVector(vector<int>& tmp){
    
    for(int i = 0; i < tmp.size(); i++){
        printf("%d, ", tmp[i]);
    }
    return;
}

int removeDuplicates_solutionA(vector<int>& nums){
    int copy_size = nums.size();
    int new_size = 1;

    printf("size: %d\n", nums.size());

    for(int i = 1; i < copy_size; i++){
        if(nums[new_size] == nums[new_size - 1] ){
            cout << nums[new_size] << " == " << nums[new_size + 1] << " ... Erasing pos[" << + new_size << "]\n";
            nums.erase(nums.begin() + new_size);
        } else {
            cout << nums[new_size] << " == " << nums[new_size + 1] << " ... Passed\n";
            new_size++;
        }
    }

    return new_size;
}

int removeDuplicates_solutionB(vector<int>& nums){
    int size = nums.size();
    int index = 1;

    if(size == 0){
        return 0;
    }

    for(int i = 1; i < size; i++){
        if(nums[i] != nums[i - 1] ){
            nums[index] = nums[i];
            index++;
        } 
    }

    return index;
}


int main(){
    const int size = 3;
    int arr[size] = {1,1,2}; // 3
    // int arr[size] = {0,0,1,1,1,2,2,3,3,4}; // 10
    vector<int> vec;


    for(int i = 0; i < size; i++){
        vec.push_back(arr[i]);
    }

    printf("Pre removal\n");
    printVector(vec);
    int k = removeDuplicates_solutionB(vec);     // Calls your implementation
    printf("\nafter \n");
    printVector(vec);
    
    

    return 0;
}
