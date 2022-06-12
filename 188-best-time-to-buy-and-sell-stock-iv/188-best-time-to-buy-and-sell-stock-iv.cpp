// TC : O(NxK)
// SC : O(NxK)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        if(n==0 or k==0){
            return 0;
        }
        
        int dp[k+1][n];
        
        for(int i=0;i<n;i++){
            dp[0][i] = 0;
        }
        
        for(int i=0;i<=k;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=k;i++){
            
            int max_p = INT_MIN;
            
            for(int j=1;j<n;j++){
                
                if(dp[i-1][j-1] - prices[j-1] > max_p){
                    max_p = dp[i-1][j-1] - prices[j-1];
                }
                
                dp[i][j] = max(dp[i][j-1], max_p + prices[j]);
            }
        }
        
        return dp[k][n-1];
    }
    
};