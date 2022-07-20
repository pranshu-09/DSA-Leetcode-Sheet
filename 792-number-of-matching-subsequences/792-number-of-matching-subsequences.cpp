class node {
    public:
    
    string word;
    int idx;
    
    node(string word, int idx){
        this->word = word;
        this->idx = idx;
    }
};

class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<node> buckets[26];
        
        for (auto x : words) {
            char c = x[0];
            node t(x, 0);
            buckets[c-'a'].push_back(t);
        }
        
        int ans = 0;
        
        for (auto c : s) {
            
            auto currBucket = buckets[c-'a'];
            buckets[c-'a'].clear();
            
            for (auto x : currBucket) {
                
                ++x.idx; // Point to next character of node.word
                if (x.idx == x.word.size()) {
                    ++ans;
                } 
                else {
                    buckets[x.word[x.idx]-'a'].push_back(x);
                }
            }
        }
        
        return ans;
    }
};