class Solution {
public:
    
    class trie_node {
        public:
        vector<trie_node*> children{vector<trie_node*>(26, NULL)};;
        string* word{};
    };
    
    void insert(trie_node* root, string& word) {
        for (char c : word) {
            
            c -= 'a';
            
            if (root->children[c] == NULL){
                root->children[c] = new trie_node();
            }
            
            root = root->children[c];
        }
        
        root->word = &word;
    }
    
    void dfs(trie_node* root, int limit, vector<string>& ans) {
        if (root == NULL) 
            return;
        
        if (ans.size() == limit) 
            return;
        
        if (root->word != NULL) 
            ans.push_back(*root->word);
        
        for (int i = 0; i < 26; ++i){
            dfs(root->children[i], limit, ans);
        }
    }
    
    vector<string> getWords(trie_node* root, int limit) {
        
        vector<string> result;
        
        dfs(root, limit, result);
        
        return result;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        trie_node* root = new trie_node();
        
        for(string &product : products){
            insert(root, product);
        }

        vector<vector<string>> ans;
        trie_node*curr = root;
        
        for(auto c : searchWord){
            
            c -= 'a';
            
            if(curr != NULL && curr->children[c] != NULL){
                curr = curr->children[c];
                ans.push_back(getWords(curr, 3));
            } 
            else{
                curr = nullptr;
                ans.emplace_back();
            }
        }
        
        return ans;
    }
};