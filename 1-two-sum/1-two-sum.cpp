// TC : O(N)
// SC : O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        unordered_map<int, int>m;
        
        for(int i=0;i<nums.size();i++){
            
            if(m.find(target - nums[i]) != m.end()){
                ans = {m[target-nums[i]], i}; 
            }
            else{
                m[nums[i]] = i;
            }
        }
        
        return ans;
    }
};