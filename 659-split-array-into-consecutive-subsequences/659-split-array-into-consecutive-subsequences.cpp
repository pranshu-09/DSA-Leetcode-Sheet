class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> cnt, tails;
        
        for(auto x : nums) 
            cnt[x]++;
        
        for(auto x : nums){
            if(!cnt[x]) 
                continue;
            
            cnt[x]--;
            
            if(tails[x-1] > 0){
                tails[x-1]--;
                tails[x]++;
            }
            else if(cnt[x+1] && cnt[x+2]){
                cnt[x+1]--;
                cnt[x+2]--;
                tails[x+2]++;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};