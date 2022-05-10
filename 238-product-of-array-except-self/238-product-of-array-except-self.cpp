// TC : O(N)
// SC : O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        int zero_count=0;
        
        for(auto x : nums){
            if(x == 0) zero_count++;
        }
        
        // If zero count is >= 2, then the complete ans array will be of 0.
        if(zero_count > 1){
            vector<int>ans(n, 0);
            return ans;
        }
        
        int prod = 1;
        for(auto x : nums){
            if(x != 0){
                prod *= x;
            }
        }
        
        vector<int>ans(n);
        
        if(zero_count == 1){
            for(int i=0;i<n;i++){
                if(nums[i] == 0){
                    ans[i] = prod;
                }
                else{
                    ans[i] = 0;
                }
            }
        }
        else if(zero_count==0){
            for(int i=0;i<n;i++){
                ans[i] = (prod / nums[i]);
            }
        }
        
        return ans;
    }
};