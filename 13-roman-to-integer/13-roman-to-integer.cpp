// TC : O(N)
// SC : O(1)
class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.size();
        
        unordered_map<char, int>m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(i+1 < n and m[s[i]] < m[s[i+1]]){
                ans += (m[s[i+1]] - m[s[i]]);
                i++;
            }
            else{
                ans += (m[s[i]]);
            }
        }
        
        return ans;
    }
};