// TC : O(N)
// SC : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int cur_sum = 0, max_sum = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            cur_sum = max(cur_sum+nums[i], nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        
        return max_sum;
    }
};