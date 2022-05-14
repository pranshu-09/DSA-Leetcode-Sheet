// TC : O(N)
// SC : O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int jump = 0;
        
        // make a window [l..r] and find the farthest we can go from this window
        // The next window will start from r+1 and end at farthest index.
        // By the end, we will reach the destination (last index)
        int l=0, r=0;
        
        while(r<n-1){
            
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest, nums[i]+i);
            }
            
            l = r+1;
            r = farthest;
            jump++;        
        }
        
        return jump;
    }
};


// TC : O(N^2)
// SC : O(N)

/*
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
*/