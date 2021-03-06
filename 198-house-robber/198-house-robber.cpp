// TC : O(N)
// SC : O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }
        
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++){
            int c = max(b, nums[i]+a);
            a = b;
            b = c;
        }
        
        return b;
    }
};

// TC : O(N)
// SC : O(N)
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }
            
        int dp[n];
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        
        return dp[n-1];
    }
};
*/