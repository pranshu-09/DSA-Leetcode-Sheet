// TC : O(N)
// SC : O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        int n = nums.size();
        
        int min_prod = nums[0];
        int max_prod = nums[0];
        
        int ans = nums[0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i] < 0){
                swap(min_prod, max_prod);
            }
            
            min_prod = min(nums[i], min_prod*nums[i]);
            max_prod = max(nums[i], max_prod*nums[i]);
            
            ans = max(ans, max_prod);
        }
        
        return ans;
    }
};