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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        vector<int>ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int k = q.size();
            
            for(int p=0;p<k;p++){
                
                auto f = q.front();
                q.pop();
                
                if(p==0){
                    ans.push_back(f->val);
                }
                
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
            }
        }
        
        return ans;
    }
};