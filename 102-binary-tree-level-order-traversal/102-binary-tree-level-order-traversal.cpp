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
// TC : O(N)
// SC : O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            vector<int>temp;
            int k = q.size();
            
            while(k--){
                
                auto f = q.front();
                q.pop();
                
                temp.push_back(f->val);
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);                
            }
            
            ans.push_back(temp);            
        }
        
        return ans;
    }
};