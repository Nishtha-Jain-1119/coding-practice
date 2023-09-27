#include <iostream>
using namespace std;

bool bSearch(int *arr, int s,int e, int key){
    // base case
    if(s>e)
        return false;
    
    int mid = (s + e) / 2;
    if(arr[mid] == key)
        return true;
    if(arr[mid]<key)
        return bSearch(arr, mid + 1, e, key);
    else{
        return bSearch(arr, s, mid - 1, key);
    }
}
int main()
{
    int arr[] = {1, 23, 45, 66, 79};
    int key = 45;
    cout << bSearch(arr, 0, 4 , key);
    return 0;
}
