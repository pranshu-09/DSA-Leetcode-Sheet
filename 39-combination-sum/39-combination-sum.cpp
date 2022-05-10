class Solution {
public:
    
    set<vector<int>>s;
    
    void combination(vector<int>& candidates, int target, int sum, vector<int>cur){
        
        if(sum == target){
            sort(cur.begin(), cur.end());
            s.insert(cur);
            return;
        }
        
        if(sum > target){
            return;
        }
        
        for(auto x : candidates){
            if(sum + x <= target){
                cur.push_back(x);
                combination(candidates, target, sum+x, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        s.clear();
        
        combination(candidates, target, 0, {});
        
        vector<vector<int>>ans(s.begin(), s.end());
        
        return ans;
    }
};