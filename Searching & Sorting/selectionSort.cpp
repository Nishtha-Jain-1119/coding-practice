#include <iostream>
using namespace std;
void selectionSort(int *arr, int n){
    if(n==0 || n==1)
        return;
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if(arr[minIndex]>arr[i])
            minIndex = i;
    }
    swap(arr[minIndex], arr[0]);
    // recursion call
    selectionSort(arr+1, n-1);
}
int main()
{
    int arr[] = {2,4,3,5,1,46,85,96,43,6};
    int n = 10;
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    
    return 0;
}