// Delete middle element from stack
// Sample Input 1:
// 2
// 4
// 1 2 3 4 5
// 7
// 83 74 67 49 94 8 11 1
// Sample Output 1:
// 1 2 4 5
// 83 74 67 94 8 11 1

#include <bits/stdc++.h> 
void solve(stack<int>&inputStack, int N, int count){
   // base case
   if(count == N/2){
      inputStack.pop();
      return;
   }
   int num = inputStack.top();
   inputStack.pop();
   
   // recursive call
   solve(inputStack, N, count+1);
   
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(inputStack, N, count);
}
