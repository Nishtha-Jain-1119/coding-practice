#include <bits/stdc++.h> 
class Queue {
public:
    int *q;
    int rare, qfront, size;
    Queue() {
        // Implement the Constructor
        size = 1000;
        q = new int[size];
        rare = 0;
        qfront = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rare){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rare == size){
            return;
        }
        q[rare] = data;
        rare++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == rare){
            return -1;
        }
        int val = q[qfront];
        qfront++;
        if(qfront == rare){
            rare = 0;
            qfront = 0;
        }
        return val;
    }

    int front() {
        // Implement the front() function
        if(qfront == rare){
            return -1;
        }
        return q[qfront];
    }
};
