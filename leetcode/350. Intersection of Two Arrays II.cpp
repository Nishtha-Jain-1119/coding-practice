// 350. Intersection of Two Arrays II
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> ans;
        if(nums1.size()==0 || nums2.size()==0) return ans;
        int m = nums1.size();
        int n = nums2.size(); 

        int i=0,j=0;
        while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            ans.push_back(nums1[i]);
            i++;j++;
        }
    }   

        return ans;
    }
};