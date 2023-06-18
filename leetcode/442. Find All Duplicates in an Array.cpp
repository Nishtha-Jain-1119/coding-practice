// 442. Find All Duplicates in an Array
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1]){
                ans.push_back(nums[i]);
                i++;
            }
            
        }
        return ans;
    }
};

// 2nd approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> f(size+1,0);
        for(int i = 0;i<size;i++)
        {
            f[nums[i]]++;
        }
        vector<int> ans;
        for(int i = 0;i<=size;i++)
        {
            if(f[i]==2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};