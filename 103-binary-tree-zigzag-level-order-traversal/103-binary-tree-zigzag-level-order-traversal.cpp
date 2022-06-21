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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        vector<vector<int>>ans;
        
        int row = 0;
        
        while(!q.empty()){
            
            int k = q.size();
            vector<int>temp(k);
            
            for(int i=0;i<k;i++){
                
                TreeNode*f = q.front();
                q.pop();
                
                if(row&1){
                    temp[k-1-i] = f->val;
                }
                else{
                    temp[i] = f->val;   
                }
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }

            ans.push_back(temp);
            row++;            
        }
        
        return ans;
    }
};