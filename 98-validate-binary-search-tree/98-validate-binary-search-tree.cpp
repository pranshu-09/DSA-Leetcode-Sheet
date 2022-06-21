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

    bool check_valid(TreeNode*&root, TreeNode*&prev){
        
        if(root==NULL){
            return true;
        }
        
        // Inorder Traversal
        bool left = check_valid(root->left, prev);
        if(left==false) 
            return false;
        
        if(prev!=NULL and prev->val >= root->val)
            return false;
        
        prev = root;
        
        return check_valid(root->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        
        TreeNode*prev = NULL;        
        return check_valid(root, prev);
    }
};