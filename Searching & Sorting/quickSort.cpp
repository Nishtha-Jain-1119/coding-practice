#include <iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<=pivot)
            cnt++;
    }
    // place pivot in right place
    int pos = s + cnt; 
    swap(arr[pos], arr[s]);

    // left and rigth wala part according to condition
    int i = s;
    int j = e;
    while(i<pos && j>pos){
        if(arr[i]>pivot && arr[j]<pivot){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
    }
    return pos;
}
// -------->> another partion function
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high){
            i++;
        }
        while(arr[j]>pivot && j>=low){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}
// ----------------------------------
void quickSort(int *arr, int s, int e){
    // base case
    if(s>=e)
        return;
    // do partition
    int p = partition(arr, s, e);
    // left part
    quickSort(arr, s, p - 1);
    // right part
    quickSort(arr, p + 1, e); 
}
int main()
{
    int arr[] = {-6, -6, -6, -4, -2,6, 2, 6,-9};
    int n = 9;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}
