// 125. Valid Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

class Solution {
public:
    bool isValid(char c){ //checking for valid character
        if(c>='a' && c<='z' || (c>='0' && c<='9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = tolower(s[i]);
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(isValid(s[i])){
                temp.push_back(s[i]);
            }
        }

        for(int i=0;i<temp.length();i++)
        {
            cout<<temp[i];
        }
        //checking for palindrome
        int f= 0;
        int l = temp.length()-1;
        while(f<=l){
            if(temp[f] != temp[l]){
                return false;
            }
            else{
                f++;
                l--;
            }
        }
        return true;
    }
};