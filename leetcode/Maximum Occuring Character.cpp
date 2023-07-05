// Geeks for geeks
// Maximum Occuring Character
// Given a string str of lowercase alphabets. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

// Example 1:

// Input:
// str = testsample
// Output: e
// Explanation: e is the character which
// is having the highest frequency.

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int count[26] = {0};
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];
            int n = ch - 'a';
            count[n]++;
        }
        int ans = -1;
        int max = 0;
        for(int i=0;i<26;i++){
            if(max<count[i]){
                ans = i;
                max =  count[i];
            }
        }
        char finalAns = 'a'+ans;
        return finalAns;
    }

};
