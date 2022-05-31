// TC : O(N)
// SC : O(N)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.size();
        unordered_set<string>m;
        int possible_codes = 1 << k;
        
        int i;
        for(i=0;i<=n-k;i++){
            string sub = s.substr(i, k);
            m.insert(sub);
            
            if(m.size() == possible_codes){
                return true;
            }
        }
        
        return false;
    }
};