#include <bits/stdc++.h> 
class Deque
{
public:
    // Initialize your data structure.
    int *dq;
    int front, rear, size;
    Deque(int n)
    {
        // Write your code here.
        size = n;
        dq = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if((front==0 && rear==size-1) || (front != 0 && rear == (front-1)%(size-1)))
        {
            return false;
        }
        if(front == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
        }
        else{
            front--;
        }
        dq[front] = x;
        return true;

    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            return false;
        }
        if(rear == -1){
            front = rear = 0;
        }
        else if(front != 0 && rear == size-1){
            rear = 0;
        }
        else{
            rear++;
        }
        dq[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(front == -1){
            return -1;
        }
        int val = dq[front];
        if(front == rear){
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(rear == -1){
            return -1;
        }
        int val = dq[rear];
        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return val;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(front == -1){
            return -1;
        }
        else{
            return dq[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(rear == -1){
            return -1;
        }
        else{
            return dq[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(rear == -1 && front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1)))
        {
            return true;
        }
        else{
            return false;
        }
    }
};
