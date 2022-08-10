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
    
    TreeNode*build_bst(vector<int>& nums, int start, int end){
        
        TreeNode*root = NULL;
        
        if(start > end){
            return root;
        }
        
        int mid = start + (end - start)/2;
        
        root = new TreeNode(nums[mid]);
        
        root->left = build_bst(nums, start, mid-1);
        root->right = build_bst(nums, mid+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return build_bst(nums, 0, nums.size()-1);        
    }
};