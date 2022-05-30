class Solution {
public:
    
    string count_sort(string s){
        
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        
        for(auto ch : s){
            cnt[ch-'a']++;
        }
        
        s = "";
        
        for(int i=0;i<26;i++){
            while(cnt[i]!=0){
                s += (i+'a');
                cnt[i]--;
            }
        }
        
        return s;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> m;
        
        for(string s: strs){
            string key = count_sort(s);
            m[key].push_back(s);            
        }
        
        vector<vector<string>> result;
    
        for(auto p: m){
            result.push_back(p.second);
        }
        
        return result;        
    }    
};