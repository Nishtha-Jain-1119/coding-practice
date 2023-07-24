// 84. Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

class Solution {
    vector<int> nextSmaller(vector<int> heights, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        int curr;
        for(int i=n-1;i>=0;i--){
            curr = heights[i];
            while((s.top() != -1) && heights[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> heights, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        int curr;
        for(int i=0;i<n;i++){
            curr = heights[i];
            while((s.top() != -1) && heights[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next;
        next = nextSmaller(heights, n);

        vector<int> prev;
        prev = prevSmaller(heights, n);

        int area = INT_MIN;
        int length;
        int breadth;
        int tempArea;
        for(int i=0;i<n;i++){
            length = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            breadth = next[i] - prev[i] - 1;
            tempArea = length*breadth;
            area = max(area, tempArea);
        }

        return area;
    }
};
