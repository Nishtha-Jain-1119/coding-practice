// Check If The String Is A Palindrome
// Sample Input 1 :
// 2
// N2 i&nJA?a& jnI2n
// A1b22Ba

// Sample Output 1 :
// Yes
// No

#include <bits/stdc++.h>
bool isValid(char c){
    if((c>='a' && c<='z') || (c>='0' && c<='9')){
        return true;
    }
    return false;
}
bool checkPalindrome(string s)
{
    int n = s.length();
    if(n==1){return true;}
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = tolower(s[i]);
        }
    }
    int f = 0;
    int l = n-1;
    while(f<=l){
        if(isValid(s[f]) && isValid(s[l])){
            if(s[f] != s[l]){
                return false;
            }
            else{
                f++;
                l--;
            }
        }
        else if(!isValid(s[f])){
            f++;
        }
        else{
            l--;
        }
    }
    return true;
}

// 97 -- 122
