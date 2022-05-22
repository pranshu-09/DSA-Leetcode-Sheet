// TC : O(N^2)
// SC : O(N^2)

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        
        if(n==1){
            return s;
        }
        
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        
        int max_len = 1;
        int start = 0;      // store the start of the longest palindromic substring
        
        // substrings of len 1 will always be palindrome => mark dp[i][i] as true
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        
        // Check for len 2 substrings => check whether s[i] is equal to s[i+1] or not
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                max_len = 2;            // max_len will become 2
                start = i;              // update start index with current index
            }
        }
        
        // now check for substrings from len => 3 to n
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;
                
                if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j] = true;
                    max_len = k;
                    start=i;
                }   
            }
        }
        
        // return substring starting from start and of length max_len
        return s.substr(start, max_len);        
    }
};