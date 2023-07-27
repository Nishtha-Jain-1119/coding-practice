// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

class Solution{
    private:
    vector<int> nextSmaller(int* heights, int n){
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
    vector<int> prevSmaller(int* heights, int n){
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
    int largestRectangleArea(int* heights, int n) {
        
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
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // compute first row maximum area
        int rowArea = largestRectangleArea(M[0], m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] != 0){
                    M[i][j] += M[i-1][j];
                }
                else{
                    M[i][j] = 0;
                }
            }
            // next row is updated now caculate max area
            rowArea = max(rowArea, largestRectangleArea(M[i], m));
        }
        return rowArea;
    }
};
