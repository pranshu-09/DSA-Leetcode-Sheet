// TC: O(NlogN)
// SC: O(1)

bool compare(vector<int>&a, vector<int>&b){
    if(a[0]==b[0]){
        return a[1] > b[1];
    }
    else{
        return a[0] < b[0];
    }
}

class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        if(envelopes.size() < 2){
            return envelopes.size();
        }
        
        sort(envelopes.begin(), envelopes.end(), compare);
        
       vector<int>dp;
        
        for(auto x : envelopes){
            
            int idx = lower_bound(dp.begin(), dp.end(), x[1]) - dp.begin();
            
            if(idx >= dp.size()) 
                dp.push_back(x[1]);
            else 
                dp[idx] = x[1];
            
        }
        
        return dp.size();
    }
};