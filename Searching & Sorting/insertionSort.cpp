#include <iostream>
using namespace std;
void insertionSort(int *arr, int n){
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j>=0)
        {
            if(arr[j]>temp){
                // right shift
                arr[j + 1] = arr[j];
                j--;
            }
            else{
                break;
            }
            // putting at rigth pos
            arr[j + 1] = temp;
        }
        
    }
    
}

// void insertionSort(int *arr, int n){
//     if(n==0 || n==1)
//         return;

//     int j = 1;
//     int temp = arr[0];
//     while(j>=0){
//         if(arr[j]>temp){
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         else{
//             break;
//         }
//         arr[j + 1] = temp;
//     }
//     insertionSort(arr+1, n-1);
// }
int main()
{
    int arr[] = {2,56,85,4,10,6,4,8,1,7};
    int n = 10 ;
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    
    return 0;
}