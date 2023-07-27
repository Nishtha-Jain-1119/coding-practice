// 85. Maximal Rectangle
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

class Solution {
private:
    vector<int> getVector(vector<char> arr, int size){
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            if(arr[i] == '0')
                ans[i] = 0;
            else
                ans[i] = 1;
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        int curr;
        for(int i=n-1;i>=0;i--){
            curr = arr[i];
            while((s.top() != -1) && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i); 
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        int curr;
        for(int i=0;i<n;i++){
            curr = arr[i];
            while((s.top() != -1) && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i); 
        }
        return ans;
    }

    int maxArea(vector<int>& arr){
        int n = arr.size();
        vector<int> next;
        next = nextSmaller(arr, n);

        vector<int> prev;
        prev = prevSmaller(arr, n);

        int area = INT_MIN;
        int length, breadth;

        for(int i=0;i<n;i++){
            length = arr[i];
            if(next[i] == -1){
                next[i] = n;
            }
            breadth =  next[i] - prev[i] - 1;
            int temp = length*breadth;
            area = max(area, temp);
        }
        return area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> row = getVector(matrix[0], cols);
        int area = maxArea(row);
        for(int i=1;i<rows;i++){
            vector<int> new_row = getVector(matrix[i], cols);
            for(int j=0;j<cols;j++){
                if(new_row[j] != 0)
                    new_row[j] += row[j];
                else
                    new_row[j] = 0;
            }
            area = max(area, maxArea(new_row));
            row = new_row;
        }

        return area;
    }
};
