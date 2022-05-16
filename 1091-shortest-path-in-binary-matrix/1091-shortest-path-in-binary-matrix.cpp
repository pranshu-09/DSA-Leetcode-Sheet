class Solution {
public:
       
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(n == 0) 
            return -1;
        
        if(grid[0][0] != 0 or grid[n-1][n-1] != 0)   
            return -1;
        
        queue<pair<int,int>> q;
        vector<pair<int,int>> dxy = {{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
        
        grid[0][0] = 1;
        q.push({0,0});
        
        while(!q.empty())
        {
            auto f = q.front();
            int x = f.first;
            int y = f.second;
            
            if(x==n-1 and y==n-1) 
                return grid[x][y];
            
            for(auto d : dxy){
                int xn = x + d.first;
                int yn = y + d.second;
                
                if(xn>=0 and xn<n and yn>=0 and yn<n and grid[xn][yn]==0){
                    grid[xn][yn] = 1 + grid[x][y];
                    q.push({xn,yn});
                }
            }
            q.pop();
        }
        
        return -1;  
    }
};