// 46. Permutations
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
    void solution(vector<int>& nums,  vector<vector<int>>& ans, int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solution(nums, ans, index+1);
            // backtracking
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solution(nums, ans, index);
        return ans;
    }
};
