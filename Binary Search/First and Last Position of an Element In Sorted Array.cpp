// First and Last Position of an Element In Sorted Array
// Sample Input 1:
// 2
// 6 3
// 0 5 5 6 6 6
// 8 2
// 0 0 1 1 2 2 2 2
// Sample Output 1:
// -1 -1 
// 4 7

#include <bits/stdc++.h> 
int firstPos(vector<int>& arr, int n, int k){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int left = -1;
    while(s<=e){
        if(k==arr[mid]){
            left = mid;
            e = mid-1;
        }
        else if (k>arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return left;
}
int lastPos(vector<int>& arr, int n, int k){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    int right = -1;
    while(s<=e){
        if(k==arr[mid]){
            right = mid;
            s = mid+1;
        }
        else if (k>arr[mid]){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return right;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> ans;
    ans.first = firstPos(arr, n, k);
    ans.second = lastPos(arr, n, k);
    return ans;
}