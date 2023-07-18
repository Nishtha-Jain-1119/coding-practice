// Sort a Stack
// Sample Input 1:
// 1
// 5
// 5 -2 9 -7 3
// Sample Output 1:
// 9 5 3 -2 -7

#include <bits/stdc++.h> 
void sortedInsert(stack<int> &stack, int num){
	if((stack.empty()) || (stack.top() <= num)){
		stack.push(num);
		return;
	}
	else{
		int n = stack.top();
		stack.pop();
		sortedInsert(stack, num);
		stack.push(n);
	}
}
void sortStack(stack<int> &stack)
{
	// base case
	if(stack.empty()){
		return ;
	}
	int num = stack.top();
	stack.pop();

	// recursive call
	sortStack(stack);

	sortedInsert(stack, num);
}
