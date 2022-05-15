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
// SC : O(N)  N => no of nodes
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        
        int sum = 0;
        
        if(root->left==NULL and root->right==NULL){
            return root->val;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int k = q.size();
            
            while(k--){
                auto f = q.front();
                q.pop();
                
                sum += f->val;
                
                if(f->left)
                    q.push(f->left);
                
                if(f->right)
                    q.push(f->right);
            }
            
            if(!q.empty())
                sum = 0;
        }
        
        return sum;
    }
};