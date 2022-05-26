// TC : O(N)
// SC : O(N)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int>m;
        
        int sum = 0;
        
        m[0] = -1;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum%k;
            
            if(m.find(rem) != m.end()){
                int dis = i - (m[rem]+1) + 1;
                
                if(dis > 1){
                    return true;
                }
            }
            else{
                m[rem] = i;
            }
        }
        
        return false;
    }
};