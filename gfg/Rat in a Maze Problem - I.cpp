// Rat in a Maze Problem - I
// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
// Example 1:
// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

class Solution{
    bool isSafe(vector<vector<int>> &m, int n,vector<vector<int>>& visited,int x, int y){
        if((x>=0 && x<n) && (y>=0 && y<n) && (m[x][y]==1) && (visited[x][y]==0)){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solution(vector<vector<int>> &m, int n, vector<vector<int>>& visited, int x, int y, vector<string>& ans, string& path)
    {
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        // 4 choices - D, L, R, U
        
        // Down
        int newX = x+1;
        int newY = y;
        if(isSafe(m, n, visited, newX, newY)){
            path.push_back('D');
            solution(m,n,visited,newX, newY,ans,path);
            // backtracking
            path.pop_back();
        }
        
        // Left
        newX = x;
        newY = y-1;
        if(isSafe(m, n, visited, newX, newY)){
            path.push_back('L');
            solution(m,n,visited,newX, newY,ans,path);
            // backtracking
            path.pop_back();
        }
        
        // Right
        newX = x;
        newY = y+1;
        if(isSafe(m, n, visited, newX, newY)){
            path.push_back('R');
            solution(m,n,visited,newX, newY,ans,path);
            // backtracking
            path.pop_back();
        }
        
        // Up
        newX = x-1;
        newY = y;
        if(isSafe(m, n, visited, newX, newY)){
            path.push_back('U');
            solution(m,n,visited,newX, newY,ans,path);
            // backtracking
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0){
            return ans;
        }
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        string path = "";
        solution(m,n,visited,0,0,ans,path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
