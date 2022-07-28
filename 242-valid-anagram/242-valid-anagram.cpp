class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        
        for(auto x : s){
            cnt1[x-'a']++;
        }
        
        for(auto x : t){
            cnt2[x-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(cnt1[i]!=cnt2[i]){
                return false;
            }
        }
        
        return true;
    }
};