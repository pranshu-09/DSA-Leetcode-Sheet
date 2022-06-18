// TC : O(NxM)
// SC : O(NxM)
class Solution {
public:
    
    int n, m;
    
    int find_distance(int x1, int y1, int x2, int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    
    bool is_valid(vector<vector<int>>& grid, int i, int j){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==1){
            return false;
        }
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        int si = -1, sj = -1;
        
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    si = i;
                    sj = j;
                    q.push({i, j});
                }
            }
        }
        
        int fi = -1, fj = -1;
        int dxy[5] = {-1, 0, 1, 0, -1};
        
        int max_dist = 0;
        vector<vector<int>>dist(n, vector<int>(m, 0));
        
        while(!q.empty()){
            
            auto node = q.front();
            int i = node.first;
            int j = node.second;
            q.pop();
            
            for(int k=0;k<4;k++){
                
                int x = i + dxy[k];
                int y = j + dxy[k+1];
                
                if(is_valid(grid, x, y)){
                    fi = x;
                    fj = y;
                    
                    dist[x][y] = dist[i][j] + 1;
                    max_dist = max(max_dist, dist[x][y]);
                    
                    grid[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        
        if(si==-1 or sj==-1 or fi==-1 or fj==-1)
            return -1;
        
        return max_dist;
    }
};