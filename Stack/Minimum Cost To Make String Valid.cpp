// Minimum Cost To Make String Valid
// Sample Input 1:
// 2
// {{{}
// {{}{}}
// Sample Output 1:
// 1
// 0

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  //  step-1 check if sizr of string is odd
  int size = str.length();
  if(size%2 != 0){
    return -1;
    // not possible
  }
  //  step-2 remove valid part
  char ch;
  stack<char> st;
  for(int i=0;i<size;i++){
    ch = str[i];
    if(ch == '{'){
      st.push(ch);
    }
    else{
      // ch is closed bracket '}'
      if(!st.empty() && (st.top() == '{')){
        st.pop();
      }
      else{
        st.push(ch);
      }
    }
  }
  // now - stack contains the invalid string

  // step-3 count 
  //   ----- a = no.of open bracket, b = no. of close bracket 
  int a = 0;
  int b = 0;
  while(!st.empty()){
    if(st.top() == '{'){
      a++;
    }
    else{
      b++;
    }
    st.pop();
  }
  int ans = ((a+1)/2) + ((b+1)/2);
  return ans;
}
