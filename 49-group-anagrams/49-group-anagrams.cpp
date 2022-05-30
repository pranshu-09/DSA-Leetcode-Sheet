class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>,vector<string>> m;
        
        for(string s: strs){
            
            vector<int>chars(26,0);
            for(auto ch : s){
                chars[ch-'a']++;
            }

            m[chars].push_back(s);            
        }
        
        vector<vector<string>> result;
    
        for(auto p: m){
            result.push_back(p.second);
        }
        
        return result;        
    }    
};