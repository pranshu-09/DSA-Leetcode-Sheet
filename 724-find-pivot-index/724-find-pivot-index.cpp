// TC : O(N)
// SC : O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        int left_sum = 0;
        int right_sum = 0;
        
        // add all the terms for the right_sum
        for(auto x : nums)
            right_sum += x;
        
        for(int i=0;i<n;i++){
            
            if(left_sum == (right_sum-nums[i])){
                return i;
            }
            
            right_sum -= nums[i];
            left_sum += nums[i];
        }
        
        return -1;
    }
};