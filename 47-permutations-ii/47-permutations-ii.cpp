class Solution {
public:
    
    vector<vector<int>>ans;
    
    void find_permut(vector<int>nums, int i){
        
        if(i==(nums.size()-1)){
            ans.push_back(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            
            if(j!=i and nums[j]==nums[i]){
                continue;
            }
            
            swap(nums[i], nums[j]);
            find_permut(nums, i+1);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        ans.clear();
        sort(nums.begin(), nums.end());
        
        find_permut(nums, 0);
        
        return ans;
    }
};