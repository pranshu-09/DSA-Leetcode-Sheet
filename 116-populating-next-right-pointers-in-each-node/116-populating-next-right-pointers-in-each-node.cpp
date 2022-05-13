/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// TC : O(N)
// SC : O(N)
// here N is the number of nodes

class Solution {
public:
    Node* connect(Node* root) {
     
        if(root == NULL){
            return NULL;
        }
        
        queue<Node*>q;
        q.push(root);
        
        
        while(!q.empty()){
            
            int k = q.size();
            Node*right_node = NULL;
            
            // traverse from right to left
            for(int i=0;i<k;i++){
                
                Node*f = q.front();
                q.pop();
                
                f->next = right_node;
                
                right_node = f;
                
                if(f->right){
                    q.push(f->right);
                }
                
                if(f->left){
                    q.push(f->left);
                }
            }
        }
        
        return root;
    }
};