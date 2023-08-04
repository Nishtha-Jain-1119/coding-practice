#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int front, rear, size;
    int *q;
    CircularQueue(int n){
        size = n;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // check if queue is overflow
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return false;
        }

        else if(front == -1)  //first element to be pushed
        {
            front = rear = 0;
        }

        else if(front != 0 && rear == size-1)  //aage ke blocks khali h
        {
            rear = 0;
        }

        else{   //general case
            rear++;
        }

        q[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check if queue is underflow
        if(front == -1){
            return -1;
        }
        int val = q[front];
        if(front == rear)  //single element
        {
            front = rear = -1;
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
