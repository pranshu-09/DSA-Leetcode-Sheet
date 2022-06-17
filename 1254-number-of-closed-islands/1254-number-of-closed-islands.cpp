// TC : O(NxM)
class Solution {
public:
    
    int n, m;
    
    bool is_closed(vector<vector<int>>& grid, int i, int j){
        
        if(i<0 or i>=n or j<0 or j>=m){
            return false;
        }
        
        if(grid[i][j] == 1){
            return true;
        }
        
        grid[i][j] = 1;
        
        bool left = is_closed(grid, i, j-1);
        bool right = is_closed(grid, i, j+1);
        bool up = is_closed(grid, i-1, j);
        bool down = is_closed(grid, i+1, j);
        
        return (left & right & up & down);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int isl = 0;
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j] == 0){
                    if(is_closed(grid, i, j)){
                        isl++;
                    }
                }
            }
        }
        
        return isl;
    }
};