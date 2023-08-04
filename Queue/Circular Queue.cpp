#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int front, rare, size;
    int *q;
    CircularQueue(int n){
        size = n;
        q = new int[size];
        front = -1;
        rare = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // check if queue is overflow
        if((front == 0 && rare == size-1) || (rare == (front-1)%(size-1))){
            return false;
        }

        else if(front == -1)  //first element to be pushed
        {
            front = rare = 0;
        }

        else if(front != 0 && rare == size-1)  //aage ke blocks khali h
        {
            rare = 0;
        }

        else{   //general case
            rare++;
        }

        q[rare] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check if queue is underflow
        if(front == -1){
            return -1;
        }
        int val = q[front];
        if(front == rare)  //single element
        {
            front = rare = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return val;
    }
};
