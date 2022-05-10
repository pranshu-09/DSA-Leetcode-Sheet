class Solution {
public:
    
    vector<vector<int>>ans;
    
    void combination(int k, int target, int sum, int cur_elem, vector<int>cur){
        
        if(target == sum and k==0){
            ans.push_back(cur);
            return;
        }
        
        if(k<=0 or sum > target or cur_elem>9){
            return;
        }
        
        cur.push_back(cur_elem);
        combination(k-1, target, sum + cur_elem, cur_elem+1, cur);
        
        cur.pop_back();
        combination(k, target, sum, cur_elem+1, cur);        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        ans.clear();
        
        combination(k, n, 0, 1, {});
        
        return ans;
    }
};