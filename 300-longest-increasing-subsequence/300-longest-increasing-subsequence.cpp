class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int dp[nums.size()];
        
        for(int i=0;i<nums.size();i++){
            dp[i] = 1;
        }
        
        int lis = 1;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] and dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            
            lis = max(lis, dp[i]);
        }
        
        return lis;
    }
};