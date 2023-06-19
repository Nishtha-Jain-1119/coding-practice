// 240. Search a 2D Matrix II
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rowIndex = 0;
        int colIndex = cols-1;
        while(rowIndex<rows && colIndex>=0){
            int element = matrix[rowIndex][colIndex];
            if(element == target){
                return 1;
            }
            else if(element < target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;
    }
};
