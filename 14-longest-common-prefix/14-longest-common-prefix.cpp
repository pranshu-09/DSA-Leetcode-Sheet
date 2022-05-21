// TC : O(NxSxlog(N)) 
//      => N: size of string vector strs
//         S : max length of any string present in strs
// SC : O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        int n = strs.size();
        
        sort(strs.begin(),strs.end());
        
        for(int i=0;i<min(strs[0].size(), strs[n-1].size());i++){
            if(strs[0][i] == strs[n-1][i]){
                ans += strs[0][i];
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};