// enQueue(q,  x)
//   1) Push x to stack1 (assuming size of stacks is unlimited).
// Here time complexity will be O(1)

// deQueue(q)
//   1) If both stacks are empty then error.
//   2) If stack2 is empty
//        While stack1 is not empty, push everything from stack1 to stack2.
//   3) Pop the element from stack2 and return it.
// Here time complexity will be O(n)


#include <bits/stdc++.h> 
class Queue{
    // Stacks to be used in the operations.
    stack<int> stk1, stk2;
    
    public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    bool enqueue(int X){
        // Write your code here.
        stk1.push(X);
        return true;
    }

    /*
      Dequeues top element from queue. Returns -1 if the queue is empty, 
      otherwise returns the popped element.
    */
    int dequeue(){
        // Write your code here.
        if(stk1.empty() && stk2.empty()){
            return -1;
        }
        if(stk2.empty() && !stk1.empty()){
            while(!stk1.empty()){
                int val = stk1.top();
                stk1.pop();
                stk2.push(val);
            }
        }
        int val = stk2.top();
        stk2.pop();
        return val;
    }
};
