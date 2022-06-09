class Solution {
public:
    
    int n, m;
    
    void find_island(vector<vector<char>>& grid, int i, int j){
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]=='0')
            return;
        
        grid[i][j] = '0';
        
        find_island(grid, i-1, j);
        find_island(grid, i+1, j);
        find_island(grid, i, j-1);
        find_island(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        if(n==1 and m==1){
            return grid[0][0]-'0';
        }
                
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    find_island(grid, i, j);
                    ans++;
                }
            }
        }
        
        return ans;        
    }
};