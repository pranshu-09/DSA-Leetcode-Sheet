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
    
    int find_max(TreeNode*root, int&max_diam){
        
        if(root == NULL){
            return 0;
        }
        
        int left = find_max(root->left, max_diam);
        int right = find_max(root->right, max_diam);
        
        max_diam = max(max_diam, left + right);
        
        return max(left, right) + 1;        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int max_diam = INT_MIN;
        
        find_max(root, max_diam);
        
        return max_diam;
    }
};