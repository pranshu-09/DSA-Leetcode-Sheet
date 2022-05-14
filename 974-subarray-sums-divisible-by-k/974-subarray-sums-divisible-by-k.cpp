// TC : O(N)
// SC : O(N)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // map to store frequency of remainder
        unordered_map<int, int>rem;
        
        rem[0]++;
        
        int cur_sum = 0;
        
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            cur_sum += nums[i];
            
            // find remainder
            int r = cur_sum%k;
            
            if(r < 0){
                r += k;
            }
            
            if(rem.find(r) != rem.end()){
                count += rem[r];
            }
            
            rem[r]++;
        }
        
        return count;
    }
};