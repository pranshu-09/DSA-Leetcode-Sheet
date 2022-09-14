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
    
    int ans = 0;
    unordered_map<int, int> m;
    
public:
    void count_pseudo(TreeNode* root){
        
        if(root == NULL){
            return;
        }
        
        m[root->val]++;
        
        if(root->left==NULL and root->right==NULL){
            int odd = 0;
            for (auto x : m)
                if (x.second&1){
                    odd++;
                }

            if (odd <= 1){
                ans++;
            }
        }
        
        count_pseudo(root->left);
        count_pseudo(root->right);
        
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        count_pseudo(root);
        
        return ans;
    }
};