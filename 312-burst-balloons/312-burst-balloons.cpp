// TC : O(N^3)
// SC : (N^2)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        
        for(int len=0;len<n;len++){
            
            for(int i=0, j=len; j<n; i++, j++){
                
                int max_sum = 0;
                for(int k=i;k<=j;k++){
                    
                    int left = k==i ? 0 : dp[i][k-1];
                    int right = k==j ? 0 : dp[k+1][j];
                    
                    int sum = (left + right) + (i==0 ? 1 : nums[i-1])*nums[k]*(j==n-1 ? 1 : nums[j+1]);    
                    
                    max_sum = max(max_sum, sum);                    
                }
                
                dp[i][j] = max_sum;                
            }
        }
        
        
        return dp[0][n-1];
    }
};