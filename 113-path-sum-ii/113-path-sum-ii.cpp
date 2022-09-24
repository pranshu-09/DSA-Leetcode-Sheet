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
    
    void path(TreeNode*root, int sum, vector<int>p, vector<vector<int>>&ans){
        
        if(root == NULL){
            return;
        }
        
        if(root->val==sum and root->left==NULL and root->right==NULL){
            p.push_back(root->val);
            ans.push_back(p);
            return;
        }
        
        p.push_back(root->val);
        
        path(root->left, sum - root->val, p, ans);
        path(root->right, sum - root->val, p, ans);
        
        p.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>p;
        
        path(root, targetSum, p, ans);
        
        return ans;
    }
};