// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n = s.length();
        if(n == 1){
            return 1;
        }
        int ans = 0;
        map<char, int> count;
        while(j<n){
            count[s[j]]++;
            if(count[s[j]] >=2){
                ans = max(ans, j-i);
                i++;
                j = i;
                count.clear();
            }
            else{
                j++;
                ans = max(ans, j-i);
            }
        }
        return ans; 
    }
};
