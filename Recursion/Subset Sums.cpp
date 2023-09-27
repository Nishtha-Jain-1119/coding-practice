class Solution
{
public:
    void subset(int i, vector<int> arr, int n, vector<int> &ans, int sum){
        // base case
        if(i == n){
            ans.push_back(sum);
            return ;
        }
        // take
        subset(i+1, arr, n, ans, (sum+arr[i]));
        // not take
        subset(i+1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        subset(0, arr, N, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
