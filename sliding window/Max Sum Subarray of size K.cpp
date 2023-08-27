// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
// NOTE*: A subarray is a contiguous part of any given array.

// Example 1:

// Input:
// N = 4, K = 2
// Arr = [100, 200, 300, 400]
// Output:
// 700
// Explanation:
// Arr3  + Arr4 =700,
// which is maximum.

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i = 0;
        int j = 0;
        long ans = 0;
        long sum = 0;
        while(j<N){
            sum += Arr[j];
            int size = j-i+1;
            if(size < K){
                j++;
            }
            else if(size == K){
                ans = max(sum, ans);
                sum -= Arr[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
