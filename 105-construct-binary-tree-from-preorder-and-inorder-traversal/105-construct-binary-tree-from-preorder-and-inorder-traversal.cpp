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
    
    TreeNode*construct_tree(vector<int>& preorder, vector<int>& inorder, int start, int end, int&i){
        
        if(start > end){
            return NULL;
        }
        
        TreeNode*root = new TreeNode(preorder[i]);
        
        int idx = -1;
        
        for(int x=start;x<=end;x++){
            if(preorder[i] == inorder[x]){
                idx = x;
            }
        }
        
        i++;
        
        root->left = construct_tree(preorder, inorder, start, idx-1, i);
        root->right = construct_tree(preorder, inorder, idx+1, end, i);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        
        TreeNode*root;
        
        if(n==1){
            root = new TreeNode(preorder[0]);
            return root;
        }
        
        int i = 0;
        
        root = construct_tree(preorder, inorder, 0, n-1, i);
        
        return root;
    }
};