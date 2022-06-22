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
    
    vector<string>ans;
    
     void store_paths(TreeNode*&root, string temp){
         
         if(root==NULL){
             return;
         }
         
         if(root->left==NULL and root->right==NULL){
             temp += (to_string(root->val));
             ans.push_back(temp);
             return;
         }
         
         temp += (to_string(root->val));
         temp += ("->");
         
         store_paths(root->left, temp);
         store_paths(root->right, temp);
     }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        ans.clear();
        
        store_paths(root, "");
        
        return ans;
    }
};