// Unbounded Knapsack type approach
class Solution {
public:
    
    vector<vector<int>>ans;
    
    void combination(vector<int>& candidates, int target, int sum, int i, vector<int>cur){
        
        if(sum == target){
            ans.push_back(cur);
            return;
        }
        
        if(i==candidates.size() or sum > target){
            return;
        }
        
        cur.push_back(candidates[i]);
        combination(candidates, target, sum+candidates[i], i, cur);
        
        cur.pop_back();
        combination(candidates, target, sum, i+1, cur);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        ans.clear();
        
        combination(candidates, target, 0, 0, {});
        
        return ans;
    }
};

// class Solution {
// public:
    
//     set<vector<int>>s;
    
//     void combination(vector<int>& candidates, int target, int sum, vector<int>cur){
        
//         if(sum == target){
//             sort(cur.begin(), cur.end());
//             s.insert(cur);
//             return;
//         }
        
//         if(sum > target){
//             return;
//         }
        
//         for(auto x : candidates){
//             if(sum + x <= target){
//                 cur.push_back(x);
//                 combination(candidates, target, sum+x, cur);
//                 cur.pop_back();
//             }
//         }
//     }
    
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
//         s.clear();
        
//         combination(candidates, target, 0, {});
        
//         vector<vector<int>>ans(s.begin(), s.end());
        
//         return ans;
//     }
// };