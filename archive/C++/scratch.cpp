int main(){
    int arr[10];
    int size = 0;
    int curr = 0;
    
    
    for(int i = 1; i < size; i++){
        curr = i;
        while(arr[curr] < arr[curr - 1] && curr != 0){
            // swap
            curr--;
        }
    }


        
    return 0;
}