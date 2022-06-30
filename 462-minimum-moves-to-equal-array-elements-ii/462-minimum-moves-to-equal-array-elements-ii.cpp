// TC : O(NlogN)
// SC : O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int median = (n&1) ? nums[n/2] : (nums[n/2] + nums[n/2 - 1])/2;
        
        int ans = 0;
        for(auto x : nums){
            ans += (abs(median-x));
        }
        
        return ans;
    }
};