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
    
    class node{
        public:
        int inc;
        int exc;
    };
    
    node find_max(TreeNode*&root){
        
        node p;
        
        if(root==NULL){
            p.inc = p.exc = 0;
            return p;
        }
        
        node left = find_max(root->left);
        node right = find_max(root->right);
        
        // get the value when the root node will be included
        p.inc = root->val + left.exc + right.exc;
        
        // get the value when root not included => get the maximum value from either including or not including the left or right pair values
        p.exc = max(left.inc, left.exc) + max(right.inc, right.exc);
        
        return p;
    }
    
    int rob(TreeNode* root) {
        
        node ans = find_max(root);
        return max(ans.inc, ans.exc);
    }
};