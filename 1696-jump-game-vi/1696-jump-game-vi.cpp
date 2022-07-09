// TC : O(NlogK)
// SC : O(N)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int>dp(n);
        dp[n-1] = nums[n-1];
        
        priority_queue<pair<int, int>>pq;
        pq.push({dp[n-1], n-1});
        
        for(int i=n-2;i>=0;i--){
            
            while(!pq.empty() and pq.top().second > i+k){
                pq.pop();
            }
            
            dp[i] = pq.top().first + nums[i];
            
            pq.push({dp[i], i});            
        }
        
        return dp[0];
    }
};

/*
// TC : O(NxK)
// SC : O(1)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++){
            
            int j = i-1;
            int max_score = INT_MIN;
            
            while(j>=0 and i-j<=k){
                max_score = max(max_score, nums[j]);
                j--;
            }
            
            if(i != 0){
                nums[i] += max_score;
            }
        }
        
        return nums[nums.size()-1];
    }
};
*/