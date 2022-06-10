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
    
    int ans;
    
    void count_good_nodes(TreeNode*root, int max_val){
        
        if(root==NULL)
            return;
        
        if(root->val >= max_val){
            ans++;
            max_val = root->val;
        }
        
        count_good_nodes(root->left, max_val);
        count_good_nodes(root->right, max_val);        
    }
    
    int goodNodes(TreeNode* root) {
        
        ans = 0;
        
        count_good_nodes(root, root->val);
        
        return ans;        
    }
};