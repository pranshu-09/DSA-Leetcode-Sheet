// TC : O(N)
// SC : O(N)
class Solution {
public:
    
    int dp[101];
    
    int find_paths(int idx, string s){
        
        if(idx == s.size()){
            return 1;
        }
        
        if(s[idx]=='0'){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int ans = 0;
        
        ans += find_paths(idx+1, s);
        
        // To find all the 2 digit equivalent alphabets (can be 10,11,..19 and 20,21..26)
        if(idx < s.size()-1 and ((s[idx]=='1') or (s[idx]=='2' and s[idx+1]<'7'))){
            ans += find_paths(idx+2, s);
        }
        
        return dp[idx] = ans;
    }
    
    int numDecodings(string s) {
        
        if(s.size()==1 and s[0]!='0'){
            return 1;
        }
        
        memset(dp, -1, sizeof dp);
        
        return find_paths(0, s);
    }
};


// Recursion Solution
/*
class Solution {
public:
    
    int find_paths(int idx, string s){
        
        if(idx == s.size()){
            return 1;
        }
        
        if(s[idx]=='0'){
            return 0;
        }
        
        int ans = 0;
        
        ans += find_paths(idx+1, s);
        
        if(idx < s.size()-1 and ((s[idx]=='1') or (s[idx]=='2' and s[idx+1]<'7'))){
            ans += find_paths(idx+2, s);
        }
        
        return ans;
    }
    
    int numDecodings(string s) {
        
        if(s.size()==1 and s[0]!='0'){
            return 1;
        }
        
        return find_paths(0, s);
    }
};
*/