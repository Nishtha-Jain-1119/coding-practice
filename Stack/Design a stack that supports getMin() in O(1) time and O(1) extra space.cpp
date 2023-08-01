class SpecialStack {
    public:
    stack<int> s;
    int min;
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            min = data;
        }
        else{
            if(data < min){
            s.push((2*data) - min);
            min = data;
            }
            else{
                s.push(data);
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        if(s.empty()){
            return;
        }
        else{
            if(s.top() > min){
                s.pop();

            }
            else{
                int val = 2*min - s.top();
                min = val;
                s.pop();
            }
            return;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.top()>min){
            return s.top();
        }
        else{
            return min;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        return min;
    }  
};
