// TC : O(N^2)
// SC : O(N^2)
class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int lcs[n+1][n+1];
        memset(lcs, 0, sizeof lcs);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == rev[j-1]){
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }
                else{
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        
        int chars = n - lcs[n][n];
        return chars;
    }
};