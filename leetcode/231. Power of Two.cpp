// 231. Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 2^0 = 1

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // finding if n is equal to any 2^i where i is from 0 to 30. **range of int is-[-2^31 , 2^31-1]
        for(int i = 0;i<=30;i++)
        {
            if(n == pow(2,i)){
                return true;
            }
        }
        return false;
    }
};

// another approach

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        // edge case
        if(n==1073741824){
            return true;
        }
        for(int i = 0;i<30;i++)
        {
            if(ans == n){
                return true;
            }
            ans = ans*2; //using the previous value
        }
        return false;
    }
};