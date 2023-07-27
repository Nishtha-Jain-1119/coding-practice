// The Celebrity Problem
// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        // step-1 push all elements in stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        // step-2 remove other non-celebrity elements from stack
        while(s.size() != 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            // if a knows b
            if(M[a][b] == 1){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        // step-3 now single element in stack is left which is the potenial celebrity
        int ans = s.top();
        // checking row of ans
        for(int i=0;i<n;i++){
            if(M[ans][i] != 0){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(i != ans){
                if(M[i][ans] != 1){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};
