#include <bits/stdc++.h> 
class Queue {
public:
    int *q;
    int rear, qfront, size;
    Queue() {
        // Implement the Constructor
        size = 1000;
        q = new int[size];
        rear = 0;
        qfront = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size){
            return;
        }
        q[rear] = data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == rear){
            return -1;
        }
        int val = q[qfront];
        qfront++;
        if(qfront == rear){
            rear = 0;
            qfront = 0;
        }
        return val;
    }

    int front() {
        // Implement the front() function
        if(qfront == rear){
            return -1;
        }
        return q[qfront];
    }
};
