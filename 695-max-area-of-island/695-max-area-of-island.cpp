// TC: O(N^2)

// DFS
class Solution {
public:
    
    int find_max(vector<vector<int>>& grid, int i, int j, int n, int m){
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0){
            return 0;
        }
        
        grid[i][j] = 0;
        
        int left = find_max(grid, i-1, j, n, m);
        int right = find_max(grid, i+1, j, n, m);
        int up = find_max(grid, i, j+1, n, m);
        int down = find_max(grid, i, j-1, n, m);
        
        return left + right + up + down + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int max_area = INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    max_area = max(max_area, find_max(grid, i, j, n, m));
                }
            }
        }
        
        if(max_area == INT_MIN)      
            return 0;
        
        return max_area;
    }
};