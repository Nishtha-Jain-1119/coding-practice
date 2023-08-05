// Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    int n = q.size();
    int x;
    // storing first k elements in stack
    for(int i=0;i<k;i++){
        x = q.front();
        q.pop();
        s.push(x);
    }
    // geting elements from stack and adding to queue in reverse order
    for(int i=0;i<k;i++){
        x = s.top();
        q.push(x);
        s.pop();
    }
    // putting the remaining elements at right place
    for(int i=0;i<n-k;i++){
        x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}
