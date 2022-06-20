class Solution {
public:
    static bool compare (string&a, string&b) {
        return a.size() > b.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        unordered_map<string, int> m;
        sort(words.begin(), words.end(), compare);

        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        
        int ans = 0; 
        
        for(int i=0; i<words.size(); i++){
            
            int sz = words[i].size();
            
            if(m[words[i]] > 0){
                ans += (sz+1);
            }
            
            for(int j=sz-1; j>=0; j--){
                string s = words[i].substr(j, sz-j);
                m[s] = 0;
            }
        }
        
        return ans;
    }
};