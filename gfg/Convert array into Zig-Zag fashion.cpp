// Given an array arr of distinct elements of size N, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 
// arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 

// NOTE: If your transformation is correct, the output will be 1 else the output will be 0. 

// Example 1:
// Input:
// N = 7
// Arr[] = {4, 3, 7, 8, 6, 2, 1}
// Output: 3 7 4 8 2 6 1
// Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1

// User function template for C++
class Solution {
    bool isOkay(int n, int arr[], int i){
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            return true;
        }
        return false;
    }
    void swaping(int *arr, int i){
        if(arr[i-1]>arr[i]){
            swap(arr[i-1],arr[i]);
        }
        if(arr[i+1]>arr[i]){
            swap(arr[i],arr[i+1]);
        }
    }
  public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n) {
        // code here
        int i=1;
        while(i<n){
            if(isOkay(n,arr,i)){
                i += 2;
            }
            else{
                while(!(isOkay(n,arr,i))){
                    swaping(arr, i);
                }
                i += 2;
            }
        }
    }
};
