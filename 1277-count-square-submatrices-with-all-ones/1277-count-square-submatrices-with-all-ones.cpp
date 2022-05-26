// TC : O(NxM)
// SC : O(NxM)

class Solution {
public:
    
    // Continuation of Maximal Square
    // find the max length of a square possible for every (i, j). So, the number of squares that can be formed from this (i, j) is equal to max len
    // Eg => say dp[i][j] = 3, it means a (3x3) matrix can be formed using this (i, j) and same (i,j) will also be able to form squares of len 2 and 1
    
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int dp[n][m];
        memset(dp, 0, sizeof dp);
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            dp[i][0] = matrix[i][0];    
            ans += matrix[i][0];
        }
        
        for(int i=1;i<m;i++){               // dp[0][0] already filled
            dp[0][i] = matrix[0][i];        
            ans += matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    ans += dp[i][j];
                }
            }
        }
        
        return ans;
    }
};