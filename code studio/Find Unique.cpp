// Find Unique


// doing it with XOR (^) operator
// ---> a^a=0
// ---> a^0=0
// ex: arr[] = {2,3,1,6,3,6,2} 
// 2^3^1^6^3^6^2= 1


int findUnique(int *arr, int size)
{
    int ans = 0;
    for(int i=0;i<size;i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}