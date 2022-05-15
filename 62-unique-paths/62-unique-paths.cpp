// TC : O(MxN)
// SC : O(N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[n];
        
        for(int i=0;i<n;i++){
            dp[i] = 1;
        }
        
        // Here, we can reduce SC from O(NxM) to O(N) as for dp[i][j], we were adding dp[i-1][j] and dp[i][j-1] in it. 
        // We can observe that dp[i-1][j] will be stored at dp[j] itself. we are just adding dp[j-1] in dp[j]. Hence, SC can be reduced.
        
        for(int j=1;j<m;j++){
            for(int i=1;i<n;i++){
                dp[i] = dp[i] + dp[i-1];
            }
        }
        
        return dp[n-1];
    }
};


// TC : O(MxN)
// SC : O(MxN)

/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        
        for(int i=0;i<n;i++){
            dp[0][i] = 1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};
*/