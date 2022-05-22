// TC : O(N^2)
// SC : O(N^2)
class Solution {
public:
    
    int countSubstrings(string s) {
        
        int n = s.size();
        
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        int ans = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j] = 1;
                }
                else if(i+1 == j){
                    dp[i][j] = s[i]==s[j] ? 1 : 0;
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
};

/*
// Memoization
// TC : O(N^2)
// SC : O(N^2)
class Solution {
public:
    
    int dp[1001][1001];
    
    bool check_palin(string s, int i, int j){
        
        if(i==s.size()){
            return false;
        }
        
        if(i>=j){
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i]==s[j] and check_palin(s, i+1, j-1)){
            return dp[i][j] = true;
        }
    
        return dp[i][j] = false;        
    }
    
    int countSubstrings(string s) {
        
        int n = s.size();
        
        memset(dp, -1, sizeof dp);
        
        int ans = n;
        
        for(int k=2;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j = i+k-1;
                
                if(check_palin(s, i, j)){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
*/


// Recursive Solution
/*
class Solution {
public:
    
    bool check_palin(string s, int i, int j){
        
        if(i==s.size()){
            return false;
        }
        
        if(i>=j){
            return true;
        }
        
        if(s[i]==s[j] and check_palin(s, i+1, j-1)){
            return true;
        }
    
        return false;        
    }
    
    int countSubstrings(string s) {
        
        int n = s.size();
        
        int ans = n;
        
        for(int k=2;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j = i+k-1;
                
                if(check_palin(s, i, j)){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
*/