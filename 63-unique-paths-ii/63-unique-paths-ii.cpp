// TC : O(NxM)
// SC : O(NxM)
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        int dp[n][m];
        memset(dp, 0, sizeof dp);
        
        if(obstacleGrid[0][0]==0) dp[0][0] = 1;
        
        for(int i=1;i<n;i++){
            if(obstacleGrid[i][0]==0 and dp[i-1][0]!=0){
                dp[i][0] = 1;
            }
        }
        
        
        for(int i=1;i<m;i++){
            if(obstacleGrid[0][i]==0 and dp[0][i-1]!=0){
                dp[0][i] = 1;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
                }
            }
        }
        
        return dp[n-1][m-1];        
    }
};


// TC : O(NxM)
// SC : O(NxM)
/*
class Solution {
public:
    
    int n, m;
    int dp[101][101];
    
    int find_paths(vector<vector<int>>& mat, int i, int j){
        
        if(i<0 or i>=n or j<0 or j>=m or mat[i][j]==1){
            return 0;
        }
        
        if(i==n-1 and j==m-1){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int right = find_paths(mat, i, j+1);
        int bottom = find_paths(mat, i+1, j);
        
        return dp[i][j] = right + bottom;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        
        memset(dp, -1, sizeof dp);
        
        if(obstacleGrid[0][0]==1 or obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        
        return find_paths(obstacleGrid, 0, 0);        
    }
};
*/