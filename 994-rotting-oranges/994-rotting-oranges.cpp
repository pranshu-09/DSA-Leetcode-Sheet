class Solution {
public:
    
    bool is_safe(vector<vector<int>>& grid, int i, int j, int n, int m){
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]!=1){
            return false;
        }
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size();
        int days=0, fresh=0;
        
        queue<pair<int, int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        int dxy[5] = {-1, 0, 1, 0, -1};
        
        while(!q.empty()){
            
            int k = q.size();
            bool check_first = true;
            
            while(k--){
                
                auto f = q.front();
                q.pop();
                
                int cx = f.first;
                int cy = f.second;
                
                for(int j=0; j<4; j++){
                    
                    int x = cx + dxy[j];
                    int y = cy + dxy[j+1];
                    
                    if(is_safe(grid, x, y, n, m)){
                        
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                        
                        if(check_first){
                            days++;
                            check_first = false;
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