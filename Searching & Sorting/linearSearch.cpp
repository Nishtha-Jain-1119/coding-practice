#include <iostream>
using namespace std;
bool lSearch(int *arr, int n, int key){
    if(n==0)
        return false;
    if (key == arr[0])
    return true;

    return lSearch(arr + 1, n - 1, key);
}
int main()
{
    int arr[] = {1, 23, 45, 66, 7};
    int key = 234;
    cout << lSearch(arr, 5, key);
    return 0;
}