class Solution {
public:
    
    vector<vector<int>>ans;
    
    void make_subsets(vector<int>& nums, int i, vector<int>cur){
        
        if(i == nums.size()){
            ans.push_back(cur);
            return;
        }
        
        cur.push_back(nums[i]);
        make_subsets(nums, i+1, cur);
        
        cur.pop_back();
        make_subsets(nums, i+1, cur);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        ans.clear();
        
        make_subsets(nums, 0, {});        
        
        return ans;
    }
};