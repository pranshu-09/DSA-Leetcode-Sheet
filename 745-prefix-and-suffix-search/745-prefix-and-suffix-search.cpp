class WordFilter {
    
    unordered_map<string, int> mp;
    
public:
    WordFilter(vector<string>& words) {
        
        int n = words.size();
        
        for(int i = 0; i < n; i++){
            
            string word = words[i];
            int wordSize = word.size();
            
            for(int j = 1; j <= words[i].size(); j++){
                
                string temp = words[i].substr(0, j);
                
                for (int k = 0; k < words[i].size(); k++) {
                    
                    string s = words[i].substr(k, words[i].size());
                    
                    mp[temp + "_" + s] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        
        string str = prefix + "_" + suffix;
        return mp[str] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */