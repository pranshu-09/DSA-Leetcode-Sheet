// TC : O(NxM)
// SC : O(NxM)
class Solution {
public:
    
    bool check(vector<vector<int>>& grid, int i, int j, int n, int m){
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=1){
            return false;
        }
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;        
        queue<pair<int, int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        int days = 0;
        int dxy[5] = {-1, 0, 1, 0, -1};
        
        while(!q.empty()){
            
            int sz = q.size();
            int r = 0;
            
            while(sz--){
                
                auto p = q.front();
                q.pop();
                
                int cx = p.first;
                int cy = p.second;
                
                for(int i=0;i<4;i++){
                    
                    int x = cx + dxy[i];
                    int y = cy + dxy[i+1];
                    
                    if(check(grid, x, y, n, m)){
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                        
                        if(r==0){
                            days++;
                            r++;
                        }
                    } 
                }
            }
        }
        
        if(fresh == 0){
            return days;
        }
                       
        return -1;
    }
};