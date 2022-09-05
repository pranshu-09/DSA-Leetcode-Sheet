/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if (root == NULL){
			return {};
        }
        
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root); 
        
        while (!q.empty()){
            
            int k = q.size(); 
            vector<int> temp;
            
            while(k--){
                
                Node*f = q.front();
                q.pop();
                
                temp.push_back(f->val);
                
                for (auto n : f->children){
                     q.push(n); 
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};