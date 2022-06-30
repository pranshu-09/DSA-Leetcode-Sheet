// TC : O(N)
// SC : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int minv = INT_MAX;
        
        for(auto x : nums){
            minv = min(minv, x);
        }
        
        int ans = 0;
        for(auto x : nums){
            ans += (x-minv);
        }
        
        return ans;
    }
};