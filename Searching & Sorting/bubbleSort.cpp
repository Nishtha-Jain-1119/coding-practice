#include <iostream>
using namespace std;
void bubbleSort(int *arr, int n){
    if(n==0 || n==1)
        return;

    for (int j = 0; j < n - 1;j++){
        if(arr[j]>arr[j+1])
            swap(arr[j], arr[j + 1]);
    }
    // recursion call
    bubbleSort(arr, n - 1);
}
int main()
{
    int arr[] = {2,56,85,4,10,6,4,8,1,7};
    int n = 10 ;
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    
    return 0;
}