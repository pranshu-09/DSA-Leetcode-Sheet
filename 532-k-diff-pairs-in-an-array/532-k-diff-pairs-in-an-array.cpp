// TC : O(N)
// SC : O(N)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int>m;
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        if(k==0){
            for(auto x : m){
                if(x.second >= 2){
                    count++;
                }
            }
            return count;
        }
        
        for(auto x : m){
            if(m.find(x.first-k) != m.end()){
                count++;
            }
        }
        
        return count;
    }
};