// TC : O(N^2)
// SC : O(N)

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int step = 0;
        
        vector<int>dp(n, INT_MAX);
        
        dp[n-1] = 0;
        
        for(int i=n-2;i>=0;i--){
            int min_step = INT_MAX;
            
            for(int j=i+1;j<n and j<=i+nums[i];j++){
                min_step = min(dp[j], min_step);
            }
            
            dp[i] = min_step==INT_MAX? INT_MAX : min_step+1;
        }
        
        return dp[0];
    }
};