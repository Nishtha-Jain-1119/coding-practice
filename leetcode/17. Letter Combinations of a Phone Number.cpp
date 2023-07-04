// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

class Solution {
    void solution(string digits, string output, int index,string *mapping,  vector<string>& ans)
    {
        // base case
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }

        // include
        int number = digits[index]-'0';
        string value = mapping[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solution(digits, output, index+1, mapping, ans);
            // backtracking
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10]  = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs","tuv", "wxyz"};
        int index = 0;
        string output = "";
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        
        solution(digits, output, index, mapping, ans);
        return ans;
    }
};
