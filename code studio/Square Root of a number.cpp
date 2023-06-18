// Square Root of a number
// Sample Input 1:
// 6
// Sample Output 1:
// 2
// Explanation Of Sample Input 1:
// The square root of the given number 6 lies between 2 and 3, so the floor value is 2.

int floorSqrt(int n)
{
    int s = 0;
    long e = n;
    long mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e)
    {
        long sq = mid*mid;
        if(n == sq)
        {
            return mid;
        }
        else if(n < sq){
            e = mid-1;
        }
        else{
            s = mid +1;
            ans = mid;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
