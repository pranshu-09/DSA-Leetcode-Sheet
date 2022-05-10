// TC : O(2^N)
// SC : O(1)
// Using Bitmasking

class Solution {
public:  
    
    vector<vector<int>> subsets(vector<int>& nums){
        
        int n = nums.size();
        
        int sets = 1 << n;
        
        vector<vector<int>>ans(sets);
        
        for(int i=0;i<sets;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    ans[i].push_back(nums[j]);
                }
            }
        }
        
        return ans;
    }
};


// TC : O(2^N)
// Using Recursion

// class Solution {
// public:
    
//     vector<vector<int>>ans;
    
//     void make_subsets(vector<int>& nums, int i, vector<int>cur){
        
//         if(i == nums.size()){
//             ans.push_back(cur);
//             return;
//         }
        
//         cur.push_back(nums[i]);
//         make_subsets(nums, i+1, cur);
        
//         cur.pop_back();
//         make_subsets(nums, i+1, cur);
//     }
    
//     vector<vector<int>> subsets(vector<int>& nums) {
        
//         ans.clear();
        
//         make_subsets(nums, 0, {});        
        
//         return ans;
//     }
// };