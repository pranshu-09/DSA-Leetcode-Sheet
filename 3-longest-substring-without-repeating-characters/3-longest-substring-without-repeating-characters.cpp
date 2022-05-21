// TC : O(N)
// SC : O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // unordered map to store the index of a character of its last occurence
        unordered_map<char, int>m;
        
        int i=0, j=0;
        int n = s.size();
        
        int ans = INT_MIN;
        int cnt = 0;
        
        while(j<n){
            
            // if cur char is already present in the sliding window => compress + expand
            if(m.find(s[j]) != m.end()){
                
                ans = max(ans,cnt);
                
                // delete all the characters starting from i till index of the character s[j]. Also erase those elements from the map
                while(i<j and s[i]!=s[j]){
                    m.erase(s[i]);
                    i++;
                    cnt--;
                }
                
                // now at index of last occurence of s[j]
                m[s[j]] = j; 
                i++;
                j++;
            }
            // if current char is not present in sliding window => expand
            else{
                m[s[j]] = j;
                j++;
                cnt++;
            }
        }
        
        ans = max(ans, cnt);
        
        return ans;
    }
};