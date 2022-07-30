class Solution {
public:
    
    vector<int>get_freq(string w){
        
        vector<int>freq(26,0);
        
        for(auto x : w){
            freq[x-'a']++;
        }
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string>ans;
        
        vector<int>w2_cmb(26,0);  // adding all the freqs of words2 vector
        
        for(auto w2 : words2){
            
            vector<int>cur = get_freq(w2);
            
            for(int i=0;i<26;i++){
                w2_cmb[i] = max(w2_cmb[i], cur[i]);
            }
        }
        
        for(auto w1 : words1){
            
            vector<int>w1_cur = get_freq(w1);
            bool check = true;
            
            for(int i=0;i<26;i++){
                if(w1_cur[i] < w2_cmb[i]){
                    check = false;
                    break;
                }
            }
            
            if(check){
                ans.push_back(w1);
            }
        }
        
        return ans;
    }
};