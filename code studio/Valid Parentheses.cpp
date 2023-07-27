// Valid Parentheses
// Sample Input 1 :
// [()]{}{[()()]()}
// Sample Output 1 :
// Balanced
// Explanation Of The Sample Input 1 :
// There is always an opening brace before a closing brace i.e. '{' before '}', '(' before '), '[' before ']'.
// So the 'S' is Balanced.

bool isValidParenthesis(string s)
{
   stack<char> bal;
   char ch;
   for(int i=0;i<s.length();i++){
       ch = s[i];
       if (ch == '(' || ch == '{' || ch == '[') {
         bal.push(ch);
       }
       else{
           if(!bal.empty())
           {
                char top = bal.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']'&& top == '[')){
                    bal.pop();
                }
                else{
                    return false;
                }
           }
           else{
               return false;
           }
       }
   }
   return (bal.empty());
}
