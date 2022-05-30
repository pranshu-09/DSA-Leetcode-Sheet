// TC : O(N)
// SC : O(N)
class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        int i = n-1, j = n-1;
        
        string ans = "";
        
        while(j>=0){
            
            while(i>=0 and s[i] == ' '){
                i--;
            }
            j = i;
            
            if(i<0) break;
            
            while(j>=0 and s[j] != ' '){
                j--;
            }
            
            ans += s.substr(j+1, (i-j));
            ans += ' ';
            i = j;
        }
        
        ans = ans.substr(0, ans.size()-1);
        return ans;
    }
};