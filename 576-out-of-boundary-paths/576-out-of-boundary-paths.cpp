#define mod 1000000007

class Solution {
public:
    
    int dp[51][51][51];

    int count_path(int m, int n, int maxMove, int i, int j){
        
        if(i<0 or i>=m or j<0 or j>=n){
            return 1;
        }
        
        if(maxMove==0){
            return 0;
        }
        
        if(dp[i][j][maxMove] != -1){
            return dp[i][j][maxMove];
        }
        
        int ans = 0;
        
        ans = (ans%mod + count_path(m, n, maxMove-1, i, j-1)%mod)%mod;
        ans = (ans%mod + count_path(m, n, maxMove-1, i, j+1)%mod)%mod;
        ans = (ans%mod + count_path(m, n, maxMove-1, i-1, j)%mod)%mod;
        ans = (ans%mod + count_path(m, n, maxMove-1, i+1, j)%mod)%mod;
        
        return dp[i][j][maxMove] = ans%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp, -1, sizeof dp);
        
        int ans = count_path(m, n, maxMove, startRow, startColumn)%mod;
        
        return ans%mod;
    }
};