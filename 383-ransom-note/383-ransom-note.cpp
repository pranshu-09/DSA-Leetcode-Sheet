class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int cnt2[26] = {0};
        
        for(auto x : magazine){
            cnt2[x-'a']++;
        }
        
        for(auto x : ransomNote){
            cnt2[x-'a']--;
            
            if(cnt2[x-'a'] < 0){
                return false;
            }
        }
        
        return true;
    }
};