// Reverse Stack Using Recursion
// Sample Input 1 :
// 3
// 2 1 3
// Sample Output 1 :
// 3 1 2

void insertAtBootom(stack<int>& myStack, int x){
    // base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    // recursive call
    insertAtBootom(myStack, x);
    
    myStack.push(num);
}
void reverseStack(stack<int> &stack) {
   if(stack.empty()){
       return;
   }
   int num = stack.top();
   stack.pop();
   reverseStack(stack);
   insertAtBootom(stack, num);
}
