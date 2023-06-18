// 1047. Remove All Adjacent Duplicates In String
// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

class Solution {
public:
    string removeDuplicates(string s) {
        long i=0;
        while(i<s.length()){
            if(s[i] == s[i+1]){
                s.erase(i,2);
                if(i>=1) //edge case-> if the first element is duplicate.
                    i--;
            }
            else{
                i++;
            }
        }
        return s;
    }
};
