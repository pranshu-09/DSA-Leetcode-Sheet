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
    
    // returning 0  => current node has camera
    // returning 1  => current node has been covered by its child
    // returning -1 => current node need a camera
    int place_cameras(TreeNode*root, int&camera){
        
        if(root == NULL){
            return 1;
        }
        
        int left = place_cameras(root->left, camera);
        int right = place_cameras(root->right, camera);
        
        // if either left child or right child needs a camera, then curr node definitely should have a camera => return 0
        if(left==-1 or right==-1){
            camera++;
            return 0;
        }
        
        // in cases (left=0, right=1) or (left=1, right=0) or (left=0, right=0) => it means the current node can be taken care of by any of the child with 0 value => hence, return 1 (as it is covered)
        if(left==0 or right==0){
            return 1;
        }
        
        // if left==1 and right==1, which means both left and right childs are covered => so they won't need any camera but curr node still need a camera, hence we should return -1
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        
        int camera = 0;
        
        int val = place_cameras(root, camera);
        
        // if root of tree returns -1 => it means root requires a camera, but since there is no parent of root => manually add a camera for the root
        if(val == -1)
            camera++;
        
        return camera;
    }
};