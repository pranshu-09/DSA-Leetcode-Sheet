class Solution {
public:
    
    int find_chain(string s, unordered_set<string>&m, unordered_map<string, int>&dp){
    
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        
        int ans = 1;
        for(int i=0;i<s.size();i++){
            
            string temp = s.substr(0, i) + s.substr(i+1);
            
            if(m.find(temp) != m.end()){
                ans = max(ans, find_chain(temp, m, dp) + 1);
            }
        }
        
        return dp[s] = ans;
    }
    
    int longestStrChain(vector<string>& words) {
        
        if(words.size() == 1) return 1;
        
        int n = words.size();
        
        unordered_map<string, int>dp;
        
        unordered_set<string>m;
        for(auto x : words){
            m.insert(x);
        }
        
        int max_chain = 0;
        
        for(int i=0;i<n;i++){
            max_chain = max(max_chain, find_chain(words[i], m, dp));
        }
        
        return max_chain;
    }
};