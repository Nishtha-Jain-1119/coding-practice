class Solution
{
    public:
    void subset(int i, vector<int> &set, vector<vector<int>> & ans, vector<int>& A, int n)
    {
        // base case
        if(i == n){
            ans.push_back(set);
            return ;
        }
        // take value at index
        set.push_back(A[i]);
        subset(i+1, set, ans, A, n);
        // not take
        set.pop_back();
        subset(i+1, set, ans, A, n);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> set;
        subset(0, set, ans, A, A.size());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
