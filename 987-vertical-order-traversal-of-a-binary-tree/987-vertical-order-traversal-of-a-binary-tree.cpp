/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<int>>hd;
        
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            
            int k = q.size();
            vector<pair<int, int>>cur;
            
            while(k--){
                TreeNode*f = q.front().first;
                int dis = q.front().second;

                q.pop();
                
                cur.push_back({dis, f->val});

                if(f->left) q.push({f->left, dis-1});
                if(f->right) q.push({f->right, dis+1}); 
            }
            
            sort(cur.begin(), cur.end());
            
            for(auto x : cur){
                hd[x.first].push_back(x.second);
            }
                           
        }
        
        vector<vector<int>>ans;
        for(auto x : hd){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};