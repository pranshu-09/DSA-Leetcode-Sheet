class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
     
        sort(tokens.begin(), tokens.end());
        
        int ans = 0, pt = 0; 
        int i=0, j=tokens.size()-1;
        
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                ans = max(ans, ++pt);
            } 
            else if (pt > 0) {
                pt--;
                power += tokens[j--];
            } 
            else {
                break;
            }
        }
        
        return ans;
    }
};