// TC : O(N)
// SC : O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        
        int cnt[26] = {0};        
        
        int i=0, j=0;
        int max_char = 0, max_len = 0;
        
        while(j < n){
            
            max_char = max(max_char, ++cnt[s[j]-'A']);
            
            while((j-i+1)-max_char > k){
                cnt[s[i]-'A']--;
                i++;
            }
            
            max_len = max(max_len, j-i+1);
            j++;
        }
        
        return max_len;
    }
};