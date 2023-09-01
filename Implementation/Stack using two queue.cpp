class Stack {
	// Define the data members.

   public:
    queue<int> q1;
    queue<int> q2;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        if(q1.empty()){
            q1.push(element);
            return ;
        }
        while(!q1.empty()){
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
        q1.push(element);
        while(!q2.empty()){
            int val = q2.front();
            q2.pop();
            q1.push(val);
        }
        return ;
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty()){
            return -1;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty()){
            return -1;
        }
        int val = q1.front();
        return val;
    }
};
