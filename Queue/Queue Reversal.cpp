//  By using a stack
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        int x;
        while(!q.empty()){
            x = q.front();
            q.pop();
            s.push(x);
        }
        while(!s.empty()){
            x = s.top();
            s.pop();
            q.push(x);
        }
        return q;
    }
};
