// Search In Rotated Sorted Array
// Sample Input 2:
// 4 3
// 2 3 5 8
// Sample Output 2:
// 1

int getPivot(vector<int>& arr, int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s,int e, int k)
{
    int mid = s + (e-s)/2;
    while(s<=e)
    {
        if(arr[mid] == k) {
            return mid;
        }

        else if(k > arr[mid]) {
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return -1;
}
int search(vector<int>& arr, int n, int k)
{
   int p = getPivot(arr, n);
   if(k>=arr[p] && k<=arr[n-1])
   {
       return binarySearch(arr, p, n-1, k);
   }
   else{
       return binarySearch(arr, 0, p-1, k);
   }
}

