// 1009. Complement of Base 10 Integer
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0){
            return 1; //edge case
        }
        int n1 = n;
        int mask = 0;
        // creating a mask variable which can restore the last bits of ~n and rest bits will be zeros
        // ex:
        // given n = 5, --> 00000 101
        //          ~n  --> 11111 010 
        // but we need 00000 010 
        // so we will make a variable - mask -->  00000 111
        // and do AND operation with ~n      -->  11111 010 & 00000 111 = 00000 010
        while(n1 != 0){
            n1 = n1>>1; // right shift
            mask = (mask<<1) | 1; //left shift , OR with 1
        }
        int ans = (~n)&mask; //(not of n)AND mask
        return ans;
    }
};