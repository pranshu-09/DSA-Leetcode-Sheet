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
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(root == NULL){
            return 0;
        }
        
        if(root->val >= low and root->val <= high){
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else if(root->val <= low){
            
            int sum = 0;
            if(root->val == low) sum = root->val;
            
            return sum + rangeSumBST(root->right, low, high);
        }
        else if(root->val >= high){
            
            int sum = 0;
            if(root->val == high) sum = root->val;
            
            return sum + rangeSumBST(root->left, low, high);
        }
        
        return 0;
    }
};