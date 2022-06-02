// TC : O(26)
// SC : O(26)
class Solution {
public:
    int minDeletions(string s) {
        
        int ch[26] = {0};
        for(auto x : s){
            ch[x-'a']++;
        }
        
        int ans = 0;
        
        set<int>freq;
        for(int i=0;i<26;i++){
            if(ch[i] != 0){
                
                if(freq.find(ch[i]) == freq.end()){
                    freq.insert(ch[i]);
                }
                else{
                    while(ch[i]!=0 and freq.find(ch[i]) != freq.end()){
                        ch[i]--;
                        ans++;
                    }
                    if(ch[i]!=0){
                        freq.insert(ch[i]);
                    }
                }
            }
        }
              
        return ans;
    }
};