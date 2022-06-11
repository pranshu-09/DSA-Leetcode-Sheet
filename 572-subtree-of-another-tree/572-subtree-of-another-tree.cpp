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
    
    bool check_same(TreeNode*&root, TreeNode*&subRoot){
        
        if(root==NULL and subRoot==NULL){
            return true;
        }
        
        if(root==NULL and subRoot!=NULL){
            return false;
        }
        
        if(root!=NULL and subRoot==NULL){
            return false;
        }
        
        if(root->val == subRoot->val){
            
            bool left = check_same(root->left, subRoot->left);
            bool right = check_same(root->right, subRoot->right);
            
            return (left & right);
        }
        
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL or subRoot==NULL){
            return false;
        }
        
        if(root->val == subRoot->val){
            if(check_same(root, subRoot)){
                return true;
            }
        }
            
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        return (left | right);
    }
};