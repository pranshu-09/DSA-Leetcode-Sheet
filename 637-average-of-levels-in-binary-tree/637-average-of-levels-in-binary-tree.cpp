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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            long temp=0;
            int sz = q.size();
            
            for(int i=0; i<sz; i++){
                TreeNode*f = q.front();
                q.pop();
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                
                temp += f->val;
            }
            
            ans.push_back((double)temp/sz);
        }
        
        return ans;
    }
};