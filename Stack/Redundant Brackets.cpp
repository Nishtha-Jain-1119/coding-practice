// Redundant Brackets
// Sample Input 1 :
// 2
// (a+b)
// (a+c*b)+(c))
// Sample Output 1 :
// No
// Yes

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    char ch;
    for(int i=0;i<s.length();i++){
        ch = s[i];
        if((ch=='(') || (ch=='+') || (ch=='-') || (ch=='*') || (ch=='/')){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isredundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if((top=='+') || (top=='-') || (top=='*') || (top=='/')){
                        isredundant = false;
                        st.pop();
                    }
                }
                st.pop();
                if(isredundant){
                    return true;
                }

            }
        }
    }
    return false;
}
