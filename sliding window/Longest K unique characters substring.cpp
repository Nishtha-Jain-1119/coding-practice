// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output: 
// 7
// Explanation: 
// "cbebebe" is the longest substring with 3 distinct characters.
  
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i = 0;
        int j = 0;
        int ans = -1;
        map<char, int>count;
        while(j<s.length()){
            count[s[j]]++;
          // adding to slide
            if(count.size()<k){
                j++;
            }
            else if(count.size() == k){
                int size = j-i+1;
                ans = max(ans, size);
                j++;
            }
            else{
              // removing from slide
                while(count.size() > k){
                    count[s[i]]--;
                    if(count[s[i]] == 0){
                        count.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
