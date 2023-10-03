#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge arrays
    int index1 = 0;
    int index2 = 0;
    int mainIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] > second[index2])
            arr[mainIndex++] = second[index2++];
        else
        {
            arr[mainIndex++] = first[index1++];
        }
    }
    while (index1 < len1){
        arr[mainIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainIndex++] = second[index2++];
    }
    delete []first;
    delete[] second;
}
//--------->> another merge function 
void merge(int *arr, int low, int high){
    int mid = (low+high)/2;
    int left = low;
    int right =  mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left++]);
        }
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    
}
// -------------------------------------------
void mergeSort(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    if (s >= e)
        return;
    // left part
    mergeSort(arr, s, mid);
    // right part
    mergeSort(arr, mid + 1, e);
    // merge sorted arrays
    merge(arr, s, e);
}
int main()
{
    int arr[] = {2, 56, 85, 4, 10, 6, 4, 8, 1, 7};
    int n = 10;
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}
